
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct solucion{
  EntInf min;
  vector<int> puntos;
};

solucion progDinamica(int valor, const vector<int>& puntuaciones){

  EntInf minDardos;
  vector<int> puntos;
  int S = puntuaciones.size();
  vector<EntInf> dardos(valor + 1, Infinito);

  dardos[0] = 0;
  //rellenar matriz;
  for(int i = 0; i <= S; i++)
    for(int j = puntuaciones[i - 1]; j <= valor; j++)
      dardos[j] = min(dardos[j], dardos[j - puntuaciones[i - 1]] + 1);
  minDardos = dardos[valor];

  if(minDardos != Infinito){
    int i = puntuaciones.size(), j = valor;
    while(j > 0){
      if(puntuaciones[i-1] <= j && dardos[j] == dardos[j - puntuaciones[i-1]] + 1){
        puntos.push_back(puntuaciones[i-1]);
        j = j - puntuaciones[i-1];
      }else
        i--;
    }
  }

  return {minDardos, puntos};
}

bool resuelveCaso() {
  
  int valor; cin >> valor;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int S; cin >> S;
  vector<int> puntuaciones(S);
  for(int i = 0; i < S; i++)
    cin >> puntuaciones[i];

  solucion sol = progDinamica(valor, puntuaciones);

  if(sol.min != Infinito){
    cout << sol.min <<":";
    for(int i : sol.puntos)
      cout << ' ' << i;
  }else 
    cout << "Imposible";

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
#endif
   return 0;
}
