
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"
#include "PriorityQueue.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class CosteMinimo{

  private:
    std::vector<Arista<int>> _ARM;
    int coste, numAeropuertos;
    
  public:
    CosteMinimo(GrafoValorado<int> const& g, int A) : coste(0), numAeropuertos(0){
      PriorityQueue<Arista<int>> pq(g.aristas());
      ConjuntosDisjuntos cjtos(g.V());
      while (!pq.empty()) {
        auto a = pq.top(); pq.pop();
        int v = a.uno(), w = a.otro(v);
        if (!cjtos.unidos(v,w) && a.valor() < A) {
          cjtos.unir(v, w);
          _ARM.push_back(a); coste += a.valor();
          if (_ARM.size() == g.V() - 1) break;
        }
      }

      numAeropuertos = cjtos.num_cjtos();
      coste += (numAeropuertos * A);
    }

    pair<int, int> costeARM() const {
      return {coste, numAeropuertos};
    }


};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N, M, A; cin >> N >> M >> A;
  if (!std::cin)  // fin de la entrada
    return false;
  
  GrafoValorado<int> region(N);

  int X, Y, C; 
  for(int i = 0; i < M; i++){
    cin >> X >> Y >> C;
    region.ponArista({X-1, Y-1, C});
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  CosteMinimo sol(region, A);
  cout << sol.costeARM().first << ' ' << sol.costeARM().second << '\n';

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
