
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class DFS {
  private:
    vector<bool> visit;
    vector<int> cantidades;
    int coste;

    int dfs(Grafo const& G, int v) {
      visit[v] = true;
      int minimo = cantidades[v];
      for (int w : G.ady(v)) {
        if (!visit[w]) {
          minimo = min(minimo, dfs(G, w));
        }
      }
      return minimo;
    }

  public:
    DFS(Grafo const& g, const vector<int> &oro) : visit(g.V(), false), coste(0), cantidades(oro){
      int i = 0; 
      while(i < g.V()){
        if(!visit[i]){
          coste += dfs(g, i);
        }
        i++;
      }
    }

    int cantidadOro() const {
      return coste;
    }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int N, M; cin >> N >> M;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<int> oro(N);
  for(int i = 0; i < N; i++)
    cin >> oro[i];

  Grafo Overcity(N);
  int v, w;
  for(int i = 0; i < M; i++){
    cin >> v >> w;
    v--; w--;
    Overcity.ponArista(v, w);
  }

  DFS sol(Overcity, oro);
  cout << sol.cantidadOro() << '\n';

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
