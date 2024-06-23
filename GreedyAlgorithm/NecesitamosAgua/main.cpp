
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

bool operator<(const pair<int, int> &a, const pair<int, int> &b){
   return a.first < b.first;
}

const int INF = std::numeric_limits<int>::max();
class voraz{
   private:
      int coste;
      int maxNorte;
      int maxSur;
      vector<pair<int, int>> distN;
      vector<pair<int, int>> distS;
      IndexPQ<int> pq;

      void relajar(AristaDirigida<int> a, vector<pair<int, int>> &dist) {
         int v = a.desde(), w = a.hasta();
         if (dist[w].first > dist[v].first + a.valor()) {
            dist[w] = {dist[v].first + a.valor(), w};
            pq.update(w, dist[w].first);
         }
      }

      void dijkstra(DigrafoValorado<int> const& g, int orig, vector<pair<int, int>> &dist){
         dist[orig] = {0, orig};
         pq.push(orig, 0);
         while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
               relajar(a, dist);
         }
      }

   public:
      voraz(const DigrafoValorado<int> &dv, int N): distN(N, {INF, 0}), distS(N, {INF, 0}), pq(N), coste(0), maxNorte((N-2)/2), maxSur((N-2)/2){
         dijkstra(dv, 0, distN);
         dijkstra(dv, N-1, distS);
         sort(distN.begin(), distN.end());
         int i = 1;

         while(i < N -1 && maxNorte && maxSur){
            if(distN[i].first < distS[distN[i].second].first){
               maxNorte--;
               coste += (distN[i].first * 2);
            }else{
               maxSur--;
               coste += (distS[distN[i].second].first * 2);
            }
            i++;
         }

         if(maxNorte){
            while(i < N-1){
               coste += (distN[i].first * 2);
               maxNorte--;
               i++;
            }
         }else if(maxSur){
            while(i < N-1){
               coste += (distS[distN[i].second].first * 2);
               maxSur--;
               i++;
            }
         }
      }

   int menorCoste(){
      return coste;
   }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   
   int M; cin >> M;
   DigrafoValorado<int> dv(N);
   int inicio, fin, distancia;
   for(int i = 0; i < M; i++){
      cin >> inicio >> fin >> distancia;
      dv.ponArista({inicio-1, fin-1, distancia});
      dv.ponArista({fin-1, inicio-1, distancia});
   }

   voraz sol(dv, N);
   cout << sol.menorCoste() <<'\n';

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
