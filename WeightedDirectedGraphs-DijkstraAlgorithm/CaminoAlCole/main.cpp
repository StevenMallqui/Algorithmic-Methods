
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const int INF = numeric_limits<int>::max();

class CaminoCole{

private:
  int formas;
  vector<int> cam;
  vector<int> dist;
  IndexPQ<int> pq;

  void dijkstra(const DigrafoValorado<int> &g, int origen){
    dist[origen] = 0;
    cam[0] = 1;
    pq.push(origen, 0);
    while (!pq.empty()) {
      int v = pq.top().elem; pq.pop();
      for (auto a : g.ady(v))
        relajar(a);
    }
  }

  void relajar(AristaDirigida<int> a) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor()) {
      dist[w] = dist[v] + a.valor();
      cam[w] = cam[v];
      pq.update(w, dist[w]);
    }else if (dist[w] == dist[v] + a.valor())
      cam[w] += cam[v];
  }

public:
  CaminoCole(const DigrafoValorado<int> &g): pq(IndexPQ<int>(g.V())), formas(0), dist(vector<int>(g.V(), INF)), cam(vector<int>(g.V(), 0)){
    dijkstra(g, 0);
    formas = cam[g.V() - 1];
  }

  int formasDistintas(){
    return formas;
  }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  DigrafoValorado<int> pueblo(N);
  int C, origen, destino, longitud; cin >> C;
  for(int i = 0; i < C; i++){
    cin >> origen >> destino >> longitud;
    pueblo.ponArista({origen - 1, destino - 1, longitud});
    pueblo.ponArista({destino - 1, origen - 1, longitud});
  }

  CaminoCole sol(pueblo);
  cout << sol.formasDistintas() << '\n';

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
