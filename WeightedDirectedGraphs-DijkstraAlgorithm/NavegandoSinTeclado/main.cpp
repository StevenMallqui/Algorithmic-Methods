
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
const int INF = numeric_limits<int>::max();

class Navegar{

private:
  vector<int> tiempoCarga;
  vector<int> dist;
  IndexPQ<int> pq;
  int coste;
  bool alcanzado;

  void dijkstra(const DigrafoValorado<int> &d, int origen){
    dist[origen] = tiempoCarga[0];
    pq.push(origen, tiempoCarga[0]);
    while (!pq.empty()) {
      int v = pq.top().elem; pq.pop();
      for (auto a : d.ady(v))
        relajar(a);
    }
  } 

  void relajar(AristaDirigida<int> a) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor() + tiempoCarga[w]) {
      dist[w] = dist[v] + a.valor() + tiempoCarga[w]; 
      pq.update(w, dist[w]);
    }
  }

public: 
  Navegar(const DigrafoValorado<int> &d, const vector<int> &c): tiempoCarga(c), dist(vector<int>(d.V(), INF)), pq(IndexPQ<int>(d.V())), coste(0), alcanzado(false){
    dijkstra(d, 0);
    alcanzado = dist[d.V()-1] != INF;
    coste = dist[d.V()-1];
  }

  bool esAlcanzado(){
    return alcanzado;
  }

  int milisegundos(){
    return coste;
  }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  int elem;
  vector<int> cargas;
  for(int i = 0; i < N; i++){
    cin >> elem;
    cargas.push_back(elem);
  }

  DigrafoValorado<int> historial(N);
  int A, origen, destino, tiempo; cin >> A;
  for(int i = 0; i < A; i++){
    cin >> origen >> destino >> tiempo;
    historial.ponArista({origen - 1, destino - 1, tiempo});
  }

  Navegar sol(historial, cargas);

  if(sol.esAlcanzado())
    cout << sol.milisegundos();
  else
    cout << "IMPOSIBLE";
  
  cout << "\n";

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
