
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"

using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct elemento{
  int v, c;
};

EntInf progDinamica(const int P, const vector<elemento> &elementos){
  int N = elementos.size();
  vector<EntInf> solucion(P+1, Infinito);
  solucion[0] = 0;

  for(int i = 1; i <= N; i++){
    for(int j = P; j > 0; j--){
      for(int k = 0; k <= min(elementos[i-1].c, j/elementos[i-1].v); k++){
        EntInf temp = solucion[j - k * elementos[i-1].v] + k;
        solucion[j] = min(solucion[j], temp);
      }
    }
  }

  return solucion[P];
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<elemento> elementos(N);
  for(int i = 0; i < N; i++)
    cin >> elementos[i].v;

  for(int i = 0; i < N; i++)
    cin >> elementos[i].c;

  int P; cin >> P;

  EntInf sol = progDinamica(P, elementos);

  if(sol != Infinito)
    cout << "SI " << sol;
  else
    cout << "NO";

  cout << '\n';
  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
