
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
const int INF = std::numeric_limits<int>::max();
class Secuestro{
  private:
    int pueblosSospechosos;
    int distancia;
    vector<int> dist;
    IndexPQ<int> pq;
    vector<bool> visit;

    int dijkstra(DigrafoValorado<int> const& g, int origen){
      int cont = 0;
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty()) {
        int v = pq.top().elem;
        if (dist[v] <= distancia){
          pq.pop();
          if(!visit[v]){
            visit[v] = true;
            cont++;
          }
          for (auto a : g.ady(v)) {
              if(dist[v] + a.valor() <= distancia)
                relajar(a);
          }
        }else
          break;
      }
      return cont;
    }

    void relajar(AristaDirigida<int> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor();
        pq.update(w, dist[w]);
      }
    }
  public:
    Secuestro(const DigrafoValorado<int>& g, int D, const vector<int>& borriquines): pueblosSospechosos(0), distancia(D), dist(g.V(), INF), pq(g.V()), visit(g.V(), false){
      for(int i = 0; i < borriquines.size(); i++){
        pueblosSospechosos += dijkstra(g, borriquines[i]);
      }
    }

  int sospechosos(){
    return pueblosSospechosos;
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
  int pueblos = 0;
  vector<int> burr;
  for(int i = 0; i < B; i++){
    cin >> origen;
    burr.push_back(origen - 1);
  }
  Secuestro sol(mapa, D, burr);
  pueblos = sol.sospechosos();

  cout << pueblos <<'\n';
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
