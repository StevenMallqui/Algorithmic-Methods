
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class RapidEats{

private:
  bool existeCam;
  int tiempoMin;
  vector<int> dist;
  IndexPQ<int> pq;
  vector<AristaDirigida<int>> ulti;
  deque<AristaDirigida<int>> caminoMin;

  void dijkstra(const DigrafoValorado<int> &d, int origen){
    dist[origen] = 0;
    pq.push(origen, 0);
    while (!pq.empty()) {
      int v = pq.top().elem; pq.pop();
      for (auto a : d.ady(v))
        relajar(a);
    }
  }

  void relajar(AristaDirigida<int> a) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor()) {
      dist[w] = dist[v] + a.valor(); ulti[w] = a;
      pq.update(w, dist[w]);
    }
  }

   deque<AristaDirigida<int>> camino(int origen, int v) const {
    deque<AristaDirigida<int>> cam;
    // recuperamos el camino retrocediendo
    AristaDirigida<int> a;
    for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
      cam.push_front(a);
    cam.push_front(a);
    return cam;
  }

public:
  RapidEats(const DigrafoValorado<int> &d, int origen, int destino): existeCam(false), tiempoMin(0), dist(vector<int>(d.V(), INF)), pq(IndexPQ<int>(d.V())), ulti(d.V()){
    dijkstra(d, origen);
    existeCam = dist[destino] != INF;
    tiempoMin = dist[destino];
    if(existeCam)
      caminoMin = camino(origen, destino);
  }

  void imprimeCamino(){
    for(auto a : caminoMin){
      cout << a.desde() + 1 << " -> ";
    }
    cout << caminoMin.back().hasta() + 1;
  }

  int tiempoMinimo(){
    return  tiempoMin;
  }

  bool hayCamino(){
    return existeCam;
  }
};


bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  DigrafoValorado<int> Deliciaville(N);
  int C; cin >> C;
  int origen, destino, tiempo;
  for(int i = 0; i < C; i++){
    cin >> origen >> destino >> tiempo;
    Deliciaville.ponArista({origen - 1, destino - 1, tiempo});
    Deliciaville.ponArista({destino - 1, origen - 1, tiempo});
  }

  int K; cin >> K;
  for(int i = 0; i < K; i++){
    cin >> origen >> destino;
    RapidEats sol(Deliciaville, origen - 1, destino - 1);
    if(sol.hayCamino()){
      cout << sol.tiempoMinimo() << ": "; 
      sol.imprimeCamino();
    }
    else
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
