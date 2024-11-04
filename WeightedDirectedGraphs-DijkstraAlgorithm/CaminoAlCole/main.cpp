
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <limits>

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

template <typename Valor>
class Dijkstra {
 private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    IndexPQ<Valor> pq;
    vector<int> caminos;

    void relajar(AristaDirigida<Valor> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor();
        pq.update(w, dist[w]);
        caminos[w] = caminos[v];
      }else if(dist[w] == dist[v] + a.valor()){
        caminos[w] += caminos[v];
      }
    }

  public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
      dist(g.V(), INF), pq(g.V()), caminos(g.V(), 0) {
      dist[origen] = 0;
      caminos[origen] = 1;
      pq.push(origen, 0);
      while (!pq.empty()) {
        int v = pq.top().elem; pq.pop();
        for (auto a : g.ady(v))
          relajar(a);
      }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    Valor distancia(int v) const { return dist[v]; }

    int caminosDistintos(int n){
      return caminos[n];
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int C; cin >> C;
  int v, w, coste;
  DigrafoValorado<int> pueblo(N);
  for(int i = 0; i < C; i++){
    cin >> v >> w >> coste;
    pueblo.ponArista({v-1, w-1, coste});
    pueblo.ponArista({w-1, v-1, coste});
  }
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Dijkstra<int> sol(pueblo, 0);
  cout << sol.caminosDistintos(N-1) << '\n';

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
