
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

pair<bool, EntInf> progDinamica(const int P, const vector<int> &v, const vector<int> &c){
  vector<EntInf> solucion(P + 1, Infinito);
  solucion[0] = EntInf(0);

  int N = v.size();
  for(int i = 0; i < N; i++)
    for(int j = P; j >= 0; j--)
      for(int k = 1; k <= c[i] && k * v[i] <= j; k++)
        solucion[j] = min(solucion[j], solucion[j - k * v[i]] + k);

  return {solucion[P] != Infinito, solucion[P]};
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<int> v(N);
  for(int i = 0; i < N; i++)
    cin >> v[i];

  vector<int> c(N);
  for(int i = 0; i < N; i++)
    cin >> c[i];

  int P; cin >> P;

  pair<bool, EntInf> sol = progDinamica(P, v, c);

  if(sol.first)
    cout << "SI " << sol.second;
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
