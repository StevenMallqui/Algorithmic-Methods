
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <limits>
#include <deque>

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
using Camino = deque<AristaDirigida<Valor>>; 

template <typename Valor>
class Dijkstra {
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

  public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
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

    Camino<Valor> camino(int v) const {
      Camino<Valor> cam;
      // recuperamos el camino retrocediendo
      AristaDirigida<Valor> a;
      for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
        cam.push_front(a);
      cam.push_front(a);
      return cam;
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  DigrafoValorado<int> ciudad(N);
  int C; cin >> C;
  int v, w, coste;
  for(int i = 0; i < C; i++){
    cin >> v >> w >> coste;
    ciudad.ponArista({v-1, w-1, coste});
    ciudad.ponArista({w-1, v-1, coste});
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int K; cin >> K;
  for(int i = 0; i < K; i++){
    cin >> v >> w;
    Dijkstra<int> sol(ciudad, v-1);
    if(sol.hayCamino(w-1)){
      cout << sol.distancia(w-1) << ": ";
      auto cam = sol.camino(w-1);
      for(auto a : cam)
        cout << a.desde() + 1 << " -> ";
      cout << cam.back().hasta() + 1;
    }else
      cout << "NO LLEGA";
    
    cout << '\n';
  }
  
  cout << "---\n";
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
