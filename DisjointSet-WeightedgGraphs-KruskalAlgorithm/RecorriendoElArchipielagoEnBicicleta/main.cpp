
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
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
class ARM_Kruskal {
  private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    bool conexo;

  public:
    Valor costeARM() const {
      return coste;
    }

    std::vector<Arista<Valor>> const& ARM() const {
      return _ARM;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), conexo(false) {
      PriorityQueue<Arista<Valor>> pq(g.aristas());
      ConjuntosDisjuntos cjtos(g.V());
      while (!pq.empty()) {
        auto a = pq.top(); pq.pop();
        int v = a.uno(), w = a.otro(v);
        if (!cjtos.unidos(v,w)) {
          cjtos.unir(v, w);
          _ARM.push_back(a); coste += a.valor();
          if (_ARM.size() == g.V() - 1) break;
        }
      }

      if(g.V() - 1 == _ARM.size())
        conexo = true;
     }

    bool puentesSuficientes(){
      return conexo;
    }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  GrafoValorado<int> archipielago(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  ARM_Kruskal<int> sol(archipielago);
  if(sol.puentesSuficientes())
    cout << sol.costeARM();
  else 
    cout << "No hay puentes suficientes";
  
  cout << '\n';

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
