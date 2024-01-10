
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

class ArbolLibre {
public: 
   ArbolLibre(Grafo const& g) : visit(g.V(), false), V(g.V()), A(g.A()){
      dfs(g, 0);
   }
  
   bool libre() const {
      return (V == tam) && (A == V - 1);
   }

private:
   std::vector<bool> visit; 
   int tam = 0, V, A;

   void dfs(Grafo const& G, int v) {
      tam++;
      visit[v] = true;
      for (int w : G.ady(v)) {
         if (!visit[w]) {
            dfs(G, w);
         }
      }
   }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   Grafo g(cin);
   
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   ArbolLibre ab(g);

   // escribir la solución
   if(ab.libre()) cout << "SI" << '\n';
   else cout << "NO" << '\n';

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
