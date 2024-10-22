
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class OrdenTareas{

  public:
    // g es DAG
    OrdenTareas(Digrafo const& g) : visit(g.V(), false), apilado(g.V(), false), hayciclo(false){
      for (int v = 0; v < g.V(); ++v)
        if (!visit[v])
          dfs(g, v);
    }
    // devuelve la ordenación topológica
    std::deque<int> const& orden() const {
      return _orden;
    }

    bool hayCiclo() const { return hayciclo; }

  private:
    std::vector<bool> visit;
    std::deque<int> _orden; // ordenación topológica
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    bool hayciclo;

    void dfs(Digrafo const& g, int v) {
      apilado[v] = true;
      visit[v] = true;
      for (int w : g.ady(v)){
        if(hayciclo)
          return;
        if (!visit[w])
          dfs(g, w);
        else if(apilado[w]){
          hayciclo = true;
        }
      }
      _orden.push_front(v);
      apilado[v] = false;
    }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  Digrafo tareas(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  OrdenTareas sol(tareas);

  // escribir la solución
  if(sol.hayCiclo())
    cout << "IMPOSIBLE";
  else
    for(int i : sol.orden())
      cout << i + 1 << ' ';
  
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
