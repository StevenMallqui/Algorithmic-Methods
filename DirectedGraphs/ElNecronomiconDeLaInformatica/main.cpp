
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

class DFSDirigido {
public:
  DFSDirigido(Digrafo const& g, int s) : visit(g.V(), false), apilado(g.V(),false), hayciclo(false) {
    dfs(g, s);
  }

  bool alcanzable(int v) const {
    return visit[v];
  }

  bool hayCiclo() const { return hayciclo; }

private:
  std::vector<bool> visit; // visit[v] = ¿hay camino dirigido de s a v?
  std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
  bool hayciclo;

  void dfs(Digrafo const& g, int v) {
    apilado[v] = true;
    visit[v] = true;
    for (int w : g.ady(v)) {
      if (!visit[w]) { 
        dfs(g, w);
      } else if (apilado[w]) {
        hayciclo = true;
      }
    }
    apilado[v] = false;
  }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int L; cin >> L; 
  if (!std::cin)  // fin de la entrada
    return false;
  
  Digrafo programa(L + 1);
  char letter; 
  int v;
  for(int i = 0; i < L; i++){
    cin >> letter;
    if(letter == 'A'){
      programa.ponArista(i, i + 1);
    }else{
      cin >> v;
      if(letter == 'J'){
        programa.ponArista(i, v - 1);
      }else if(letter == 'C'){
        programa.ponArista(i, v - 1);
        programa.ponArista(i, i + 1);
      } 
    } 
  }

  DFSDirigido sol(programa, 0);
  // resolver el caso posiblemente llamando a otras funciones

  // escribir la solución
  if(!sol.alcanzable(L))
    cout << "NUNCA";
  else{
    if(sol.hayCiclo())
      cout << "A VECES";
    else  
      cout << "SIEMPRE";
  }

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
