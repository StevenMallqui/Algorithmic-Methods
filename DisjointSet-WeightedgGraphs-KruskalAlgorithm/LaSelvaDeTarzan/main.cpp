
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

template <typename Valor>
class ARM_Kruskal {
  private:
    std::vector<Arista<Valor>> _ARM;
    bool conexo;
  
  public:

    std::vector<Arista<Valor>> const& ARM() const {
      return _ARM;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g) : conexo(false) {
      PriorityQueue<Arista<Valor>> pq(g.aristas());
      ConjuntosDisjuntos cjtos(g.V());
      while (!pq.empty()) {
        auto a = pq.top(); pq.pop();
        int v = a.uno(), w = a.otro(v);
        if (!cjtos.unidos(v,w)) {
          cjtos.unir(v, w);
          _ARM.push_back(a);
          if (_ARM.size() == g.V() - 1) break;
        }
      }

      if(_ARM.size() == g.V() - 1)
        conexo = true;
    }

    int longitudMinima(){
      return _ARM.back().valor();
    }

    bool esConexo(){
      return conexo;
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  GrafoValorado<int> selva(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución

  if(selva.V() > 1){
    ARM_Kruskal<int> sol(selva);

    if(sol.esConexo())
      cout << sol.longitudMinima() << '\n';
    else  
      cout << "Imposible\n";

  }else
    cout << 0 << '\n';

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
