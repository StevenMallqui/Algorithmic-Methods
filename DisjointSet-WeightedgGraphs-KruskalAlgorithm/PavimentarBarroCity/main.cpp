
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

template <typename Valor>
class ARM_Kruskal {
private:
  vector<Arista<Valor>> _ARM;
  Valor coste;

public:
  Valor costeARM() const {
    return coste;
  }

  ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
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

    if(cjtos.num_cjtos() > 1)
      coste = -1;
  }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  GrafoValorado<int> BarroCity(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  if(BarroCity.V() > 1){
    ARM_Kruskal<int> sol(BarroCity);
    int coste = sol.costeARM();
    coste == -1 ? cout << "Imposible": cout << coste; 
  }else
    cout << 0;
    
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
