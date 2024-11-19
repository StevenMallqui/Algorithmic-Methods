
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

template <typename Valor>
class Dijkstra {
  private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
  std::vector<Valor> dist;
  IndexPQ<Valor> pq;

  void relajar(AristaDirigida<int> a) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor()) {
      dist[w] = dist[v] + a.valor();
      pq.update(w, dist[w]);
    }
  }

  public:
  Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()) {
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
};

struct pueblo{
  int64_t ventaja;
  int id;
};

bool operator<(const pueblo &a, const pueblo &b){
  return a.ventaja < b.ventaja;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N, M; cin >> N >> M;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int v, w, valor;
  DigrafoValorado<int> isla(N);
  for(int i = 0; i < M; i++){
    cin >> v >> w >> valor;
    isla.ponArista({v-1, w-1, valor});
    isla.ponArista({w-1, v-1, valor});
  }

  Dijkstra<int64_t> norte(isla, 0);
  Dijkstra<int64_t> sur(isla, N-1);

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  priority_queue<pueblo> pueblos;
  for(int i = 1; i < N - 1; i++)
    pueblos.push({norte.distancia(i) - sur.distancia(i), i});

  int c = 0;
  int mitad = (N-2)/2;
  int64_t suma = 0;
  while(c < mitad){
    suma += sur.distancia(pueblos.top().id);
    pueblos.pop();
    c++;
  }

  while(c < (N-2)){
    suma += norte.distancia(pueblos.top().id);
    pueblos.pop();
    c++;
  }

  cout << suma * 2 << '\n';
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
