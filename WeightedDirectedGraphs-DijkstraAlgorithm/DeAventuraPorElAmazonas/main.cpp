
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "IndexPQ.h"
#include "DigrafoValorado.h"
using namespace std;

template <typename Valor>
class Dijkstra {
public:
  Dijkstra(DigrafoValorado<Valor> const& g, int origen) : origen(origen),
    dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
    dist[origen] = 0;
    pq.push(origen, 0);
    while (!pq.empty()) {
      int v = pq.top().elem; pq.pop();
      for (auto a : g.ady(v))
        relajar(a);
    }
  }

  bool hayCamino(int v) const { return dist[v] != INF; }
  Valor distancia(int v) const { return dist[v]; }
private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  std::vector<Valor> dist;
  std::vector<AristaDirigida<Valor>> ulti;
  IndexPQ<Valor> pq;

  void relajar(AristaDirigida<Valor> a) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor()) {
      dist[w] = dist[v] + a.valor(); ulti[w] = a;
      pq.update(w, dist[w]);
    }
  }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  DigrafoValorado<int> amazonas(N);
  int K = N-1, valor;
  for(int i = 0; i < K; i++){
    for(int j = i + 1; j <= K ; j++){
      cin >> valor;
      amazonas.ponArista({i,j,valor});
    }
  }

  for(int i = 0; i < N; i++){
    Dijkstra<int> sol(amazonas, i);
    for(int j = i+1; j < N; j++){
      cout << sol.distancia(j) << ' ';
    }
    cout << '\n';
  }
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
