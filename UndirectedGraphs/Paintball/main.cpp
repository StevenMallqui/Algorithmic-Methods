
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#include "Grafo.h"

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

class Asignacion {
  public:
    Asignacion(Grafo const& g) : equipo(g.V(), false), posible(true) {
      int v = 0;
      while(v < g.V() && posible){
        if(equipo[v] == false)
          posible = bfs(g, v);
        v++;
      }
    }

    bool esPosible() const {
      return posible;
    }

  private:
    vector<bool> equipo;
    bool posible;

  bool bfs(Grafo const& g, int v) {
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int w : g.ady(v)) {
        if (equipo[w] == false) {
          equipo[w] = !equipo[v];
          q.push(w);
        }else if(equipo[w] == equipo[v])
          return false;
      }
    }
    return true;
  }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  Grafo rivalidades(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  Asignacion sol(rivalidades);

  if(sol.esPosible())
    cout << "SI";
  else 
    cout << "NO";

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