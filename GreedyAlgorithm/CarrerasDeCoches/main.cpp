
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

void resuelveCaso() {
   
  // leer los datos de la entrada
  int N, V; cin >> N >> V;
  vector<int> pilas(N);

  for(int i = 0; i < N; i++)
    cin >> pilas[i];
  sort(pilas.begin(), pilas.end());

  // resolver el caso posiblemente llamando a otras funciones
  int i = 0, j = N -1, coches = 0;
  while(i < j){
    if(pilas[i] + pilas[j] >= V){
      i++;
      j--;
      coches++;
    }else
      i++;
  }
  
  // escribir la solución
  cout << coches << '\n'; 
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
   system("PAUSE");
#endif
   return 0;
}
