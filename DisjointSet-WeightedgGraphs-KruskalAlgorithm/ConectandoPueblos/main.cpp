
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"  

using namespace std;


/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */

template <typename Valor>
class ARM_Kruskal {
  private:
    vector<Arista<Valor>> _ARM;
    Valor minimoHoras;
    
  public:

    vector<Arista<Valor>> const& ARM() const {
      return _ARM;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g) : minimoHoras(-1) {
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

      if(cjtos.num_cjtos() == 1)
        minimoHoras = _ARM.back().valor();
    }

    Valor tiempoMinimo() const {
      return minimoHoras;
    }
};

void resuelveCaso() {
   
  GrafoValorado<int> pueblos(cin, 1);
  if(pueblos.V() > 1){
    ARM_Kruskal<int> sol(pueblos);
    int min = sol.tiempoMinimo();
    min == -1 ? cout << "Imposible" : cout << min;
  }else
    cout << 0;
  cout << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
