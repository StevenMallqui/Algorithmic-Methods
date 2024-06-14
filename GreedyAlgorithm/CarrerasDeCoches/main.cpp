
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int voraz(vector<int> &pilas, int V){
  sort(pilas.begin(), pilas.end());
  int coches = 0, i = 0, j = pilas.size()-1;

  while(i < j){
    if(pilas[i] + pilas[j] >= V){
      i++;
      j--;
      coches++;
    }else 
      i++;
  }

  return coches;
}

void resuelveCaso() {
   
  // leer los datos de la entrada
  int N, V; cin >> N >> V;
  vector<int> pilas(N);
  for(int i = 0; i < N; i++){
    cin >> pilas[i];
  }

  cout << voraz(pilas, V) <<'\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
#endif
   return 0;
}
