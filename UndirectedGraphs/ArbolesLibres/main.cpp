
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class ArbolLibre {
  private:
    vector<bool> visit; 
    int components, V, A; 

    void dfs(Grafo const& G, int v) {
      visit[v] = true;
      components++;
      for (int w : G.ady(v))
        if (!visit[w])
          dfs(G, w);
    }

  public:
    ArbolLibre(Grafo const& g, const int &V, const int &A) : visit(g.V(), false), components(0), V(V), A(A) {
      dfs(g, 0);
    }

    bool esLibre(){
      return (V == components) && (A == V - 1);
    }

};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int V; cin >> V;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int A; cin >> A;
  Grafo arbol(V);

  int v, w;
  for(int i = 0; i < A; i++){
    cin >> v >> w;
    arbol.ponArista(v , w);
  }

  // resolver el caso posiblemente llamando a otras funciones
  ArbolLibre sol(arbol, V, A);

  // escribir la solución
  if(sol.esLibre())
    cout << "SI\n";
  else 
    cout << "NO\n";

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
