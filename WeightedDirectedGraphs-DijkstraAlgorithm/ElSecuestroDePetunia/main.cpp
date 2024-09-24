
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
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
const int INF = std::numeric_limits<int>::max();
class Secuestro{
  private:
    int distancia;
    vector<int> dist;
    IndexPQ<int> pq;
    set<int> pueblos;

    void dijkstra(DigrafoValorado<int> const& g){
      while (!pq.empty()) {
        int v = pq.top().elem;
        pq.pop();
        if (dist[v] <= distancia){
          pueblos.insert(v);
          for (auto a : g.ady(v)) {
                relajar(a);
          }
        }
      }
    }

    void relajar(AristaDirigida<int> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor();
        pq.update(w, dist[w]);
      }
    }
  public:
    Secuestro(const DigrafoValorado<int>& g, int D, const vector<int>& origenes): distancia(D), dist(g.V(), INF), pq(g.V()){
      for(int i = 0; i < origenes.size(); i++){
        dist[origenes[i]] = 0;
        pq.push(origenes[i], 0);
      }
      dijkstra(g);
    }

  int sospechosos(){
    return pueblos.size();
  }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int D; cin >> D;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int P, C; cin >> P >> C;
  DigrafoValorado<int> mapa(P);
  int origen, destino, tiempo;
  for(int i = 0; i < C; i++){
    cin >> origen >> destino >> tiempo;
    mapa.ponArista({origen - 1, destino - 1, tiempo});
    mapa.ponArista({destino - 1, origen - 1, tiempo});
  }

  int B; cin >> B;
  vector<int> origenes(B);
  for(int i = 0; i < B; i++){
    cin >> origen;
    origenes[i] = origen-1;
  }

  Secuestro sol(mapa, D, origenes);

  cout << sol.sospechosos() <<'\n';
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
