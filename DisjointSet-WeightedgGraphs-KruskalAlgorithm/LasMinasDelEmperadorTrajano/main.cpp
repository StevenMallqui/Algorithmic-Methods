
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


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
template <typename Valor>
class ARM_Kruskal{
  private:
    vector<Arista<Valor>> _ARM; 
    Valor maxT;

  public:

    ARM_Kruskal(GrafoValorado<Valor> const& g, const int origen, const int destino) :_ARM(g.V()), maxT(-1){
      bool unidos = false;
      PriorityQueue<Arista<Valor>> pq(g.aristas());
      ConjuntosDisjuntos cjtos(g.V());
      while(!pq.empty() && !unidos){
        auto a = pq.top(); pq.pop();
        int v = a.uno(), w = a.otro(v);
        if(!cjtos.unidos(v, w)){
          cjtos.unir(v, w);
          _ARM.push_back(a);
          if(cjtos.unidos(origen, destino)){
            unidos = true;
            maxT = a.valor();
          } 
          if(_ARM.size() == g.V() - 1) break;
        }
      }
    }

    Valor tiempoMaximo() const{
      return maxT;
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  GrafoValorado<int> camaras(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;

  int origen, destino; cin >> origen >> destino;

  if(origen != destino){
    ARM_Kruskal<int> sol(camaras, origen-1, destino-1);
    auto max = sol.tiempoMaximo();
    max == -1 ? cout << "IMPOSIBLE" : cout << max;
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
