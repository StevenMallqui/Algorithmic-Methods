
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

int voraz(vector<int> ciudades, vector<int> defensas){
  sort(ciudades.begin(), ciudades.end());
  sort(defensas.begin(), defensas.end());
  int cont = 0;
  for(int i = 0; i < defensas.size(); i++){
    if(defensas[i] >= ciudades[cont]){
      cont++;
    }
  }
  return cont;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<int> ciudades(N), defensas(N);
  int elem;
  for(int i = 0; i < N; i++){
    cin >> elem;
    ciudades[i] = elem;
  }

  for(int i = 0; i < N; i++){
    cin >> elem;
    defensas[i] = elem;
  }

  cout << voraz(ciudades, defensas) << '\n';

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
