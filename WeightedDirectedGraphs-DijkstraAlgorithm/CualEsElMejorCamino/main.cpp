
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
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

class MejorCamino{

  private:
    vector<int> dist; 
    vector<int> cont; 
    IndexPQ<int> pq;
    bool camino;
    bool posible;
    int distanciaMin;

    pair<bool, int> bfs(DigrafoValorado<int> const& g, int origen, int destino) {
      vector<bool> visit(g.V(), false);
      std::queue<int> q;
      vector<int> d(g.V(), -1);
      d[origen] = 0; visit[origen] = true;
      bool encontrado = false;
      q.push(origen);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto a : g.ady(v)) {
          int w = a.hasta();
          if (!visit[w]) {
            d[w] = d[v] + 1; visit[w] = true;
            if(w == destino){
              encontrado = true;
              break;
            }else
              q.push(w);
          }
        }
      }

      return {encontrado, d[destino]};
    }

    void relajar(AristaDirigida<int> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor();
        pq.update(w, dist[w]);
        cont[w] = cont[v] + 1;
      }else if (dist[v] + a.valor() == dist[w] && cont[v] + 1 < cont[w])
	      cont[w] = cont[v] + 1;
    }

    void Dijkstra(DigrafoValorado<int> const& g, int origen){
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty()) {
        int v = pq.top().elem; pq.pop();
        for (auto a : g.ady(v))
          relajar(a);
      }
    }

  public:

    MejorCamino(DigrafoValorado<int> const& g, int origen, int destino): dist(g.V(), INF), pq(g.V()), cont(g.V()), camino(false), posible(false){
      auto[encontrado, distancia] = bfs(g, origen, destino);
      if(encontrado){
        camino = true;
        Dijkstra(g, origen);
        if(cont[destino] == distancia)
          posible = true;
        distanciaMin = dist[destino];
      }
    }

    bool hayCamino() const {
      return camino;
    }

    int distanciaMinima() const {
      return distanciaMin;
    }

    bool esPosible() const {
      return posible;
    }

};

bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución

  int C; cin >> C;
  int v, w, coste;
  DigrafoValorado<int> ciudad(N);
  for(int i = 0; i < C; i++){
    cin >> v >> w >> coste;
    ciudad.ponArista({v-1, w-1, coste});
    ciudad.ponArista({w-1, v-1, coste});
  } 

  int K; cin >> K;
  for(int i = 0; i < K; i++){
    cin >> v >> w;
    MejorCamino sol(ciudad, v-1, w-1);
    if(sol.hayCamino()){
      cout << sol.distanciaMinima() << ' ';
      if(sol.esPosible())
        cout << "SI\n";
      else
        cout << "NO\n";
    }else 
      cout << "SIN CAMINO\n";
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
