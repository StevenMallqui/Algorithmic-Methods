
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

class MaximaCompConexa{
public: 
  MaximaCompConexa(Grafo const& g): visit(g.V(), false), maxim(0) {
    for(int v = 0; v < g.V(); v++){
      if(!visit[v]) {
        int tam = dfs(g, v);
        maxim = max(maxim, tam);
      }
    }
  }

  int maximo() const {
    return maxim;
  }

private:
  vector<bool> visit;
  int maxim;

  int dfs(Grafo const& g, int v){
    visit[v] = true;
    int tam = 1;
    for(int w : g.ady(v)){
      if(!visit[w])
        tam += dfs(g, w);
    }
    return tam;
  }
};

void resuelveCaso() {
   
  // leer los datos de la entrada
  Grafo amigos(cin, 1);

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  MaximaCompConexa mcc(amigos);
  cout << mcc.maximo() << '\n';
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
