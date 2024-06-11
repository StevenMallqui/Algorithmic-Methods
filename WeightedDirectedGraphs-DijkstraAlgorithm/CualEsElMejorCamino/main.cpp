
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
const int INF = std::numeric_limits<int>::max();

class MejorCamino
{
private:
   int distanciaMin;
   bool posible;
   bool alcanzable;
   vector<int> dist;
   IndexPQ<int> pq;
   vector<int> aristas;

   int bfs(DigrafoValorado<int> const& g, int origen, int destino) {
      vector<bool> visit(g.V(), false);
      queue<int> q;
      vector<int> d(g.V());
      d[origen] = 0;
      visit[origen] = true;
      q.push(origen);
      while (!alcanzable && !q.empty()) {
         int v = q.front(); q.pop();
         int cont = 0;
         while(!alcanzable && cont < g.ady(v).size()){
            int w = g.ady(v)[cont].hasta(); 
            if(w == destino){
               alcanzable = true;
               d[w] = d[v] + 1;
            }else if(!visit[w]){
               visit[w] = true;
               d[w] = d[v] + 1; 
               q.push(w);
            }
            cont++;
         }
      }
      return d[destino];
   }

   void dijkstra(DigrafoValorado<int> const& g, int orig){
      dist[orig] = 0;
      pq.push(orig, 0);
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
         aristas[w] = aristas[v] + 1;
         pq.update(w, dist[w]);
      }else if(dist[w] == dist[v] + a.valor() && aristas[v] + 1 < aristas[w]){
         aristas[w] = aristas[v] + 1;
      }
   }
public:
   MejorCamino(DigrafoValorado<int> const& g, int orig, int dest): distanciaMin(0), posible(false), alcanzable(false), dist(g.V(), INF), pq(g.V()), aristas(g.V(), 0){
      int minAristas = bfs(g, orig, dest);
      if(alcanzable){
         dijkstra(g, orig);
         distanciaMin = dist[dest];
         if(minAristas == aristas[dest])
            posible = true;
      }
   }

   int distanciaMinima(){
      return distanciaMin;
   }

   bool esPosible(){
      return posible;
   }

   bool hayCamino(){
      return alcanzable;
   }
};



bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  DigrafoValorado<int> ciudad(N);
  int C; cin >> C;
  int origen, destino, longitud;
  for(int i = 0; i < C; i++){
    cin >> origen >> destino >> longitud;
    ciudad.ponArista({origen-1, destino-1, longitud});
    ciudad.ponArista({destino-1, origen-1, longitud});
  }
  int K; cin >> K;
  for(int i = 0; i < K; i++){
    cin >> origen >> destino;
    MejorCamino sol(ciudad, origen - 1, destino - 1);
    if(sol.hayCamino()){
      cout << sol.distanciaMinima() << " ";
      if(sol.esPosible())
         cout << "SI\n";
      else
         cout << "NO\n";
    }else{
      cout <<"SIN CAMINO\n";
    }
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
#endif
   return 0;
}
