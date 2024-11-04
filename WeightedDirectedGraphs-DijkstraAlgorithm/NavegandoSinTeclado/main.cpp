
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
    vector<int> tiempoCarga;

    void relajar(AristaDirigida<Valor> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > (dist[v] + a.valor() + tiempoCarga[v])) {
        dist[w] = dist[v] + a.valor() + tiempoCarga[v];
        pq.update(w, dist[w]);
      }
    }

  public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, const vector<int> &tiempoCarga) : origen(orig), dist(g.V(), INF), pq(g.V()), tiempoCarga(tiempoCarga) {
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

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  vector<int> tiempoCarga(N);
  for(int i = 0; i < N; i++)
    cin >> tiempoCarga[i];

  DigrafoValorado<int> navegacion(N);
  int M; cin >> M;
  int a, b, t;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> t;
    navegacion.ponArista({a-1, b-1, t});
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Dijkstra<int> sol(navegacion, 0, tiempoCarga);
  if(sol.hayCamino(N-1))
    cout << sol.distancia(N-1) + tiempoCarga[N-1] << '\n';
  else 
    cout << "Imposible\n";
    

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
