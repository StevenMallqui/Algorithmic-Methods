
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
const int MAX = 10000;
const int INF = 1000000000;

int adjacent(int v, int i){
  switch (i) {
    case 0: return (v + 1) % MAX;
    case 1: return (v * 2) % MAX;
    case 2: return v / 3;
  }
}

int bfs(int origin, int destination){
  if(origin == destination) return 0;
  vector<int> distance(MAX, INF);
  distance[origin] = 0;
  queue<int> cola; cola.push(origin);
  while(!cola.empty()){
    int v = cola.front(); cola.pop();
    for(int i = 0; i < 3; i++){
      int w = adjacent(v, i);
      if(distance[w] == INF){
        distance[w] = distance[v] + 1;
        if(w == destination) return distance[w];
        else cola.push(w);
      }
    }
  }
}

int minimumNumberOfTaps(int origin, int destination){
  return bfs(origin, destination);
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int origin, destination;
  cin >> origin; cin >> destination;

  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  int min_taps = minimumNumberOfTaps(origin, destination);

  // escribir la solución
  cout << min_taps << endl;
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
