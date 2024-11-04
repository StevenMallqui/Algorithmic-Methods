
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

    void relajar(AristaDirigida<Valor> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor();
        pq.update(w, dist[w]);
      }
    }

  public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()) {
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
  DigrafoValorado<int> comarca(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int O, P; cin >> O >> P;
  Dijkstra<int> sol(comarca, O-1);
  bool posible = true;
  int esfuerzo = 0;
  vector<int> repartos(P);

  for(int i = 0; i < P; i++)
    cin >> repartos[i];

  for(int i = 0; i < P && posible; i++){
    if(sol.hayCamino(repartos[i] - 1))
      esfuerzo += sol.distancia(repartos[i] - 1);
    else
      posible = false;
  }

  if(posible){
    DigrafoValorado<int> inv = comarca.inverso();
    Dijkstra<int> vuelta(inv, O-1);
    
    for(int i = 0; i < P && posible; i++){ 
      if(vuelta.hayCamino(repartos[i] - 1))
        esfuerzo += vuelta.distancia(repartos[i] - 1);
      else
        posible = false;
    }
  }

  if(!posible)
    cout << "Imposible\n";
  else
    cout << esfuerzo << '\n';

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
