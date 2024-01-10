
/*@ <answer>
 *
 * Nombre y Apellidos:
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

using Camino = std::deque<int>;

class OrdenarTareas {
public:
   OrdenarTareas(Digrafo const& g) : visit(g.V(),false), apilado(g.V(),false), hayCiclo(false) {
      for (int v = 0; v < g.V(); ++v){
         if(hayCiclo) return;
         else if(!visit[v]) hayCiclo = dfs(g, v);
      }
   }
   bool aciclico() const { return !hayCiclo; }
   Camino const& tareasOrdenadas() const { return _camino; }
private:
   std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
   std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
   Camino _camino; // ciclo dirigido (vacío si no existe)
   bool hayCiclo;

   bool dfs(Digrafo const& g, int v) {
      apilado[v] = true;
      visit[v] = true;
      bool ciclo = false;
      for (int w : g.ady(v)) {
         if (ciclo) // si hemos encontrado un ciclo terminamos
            return true;
         if (!visit[w]) { // encontrado un nuevo vértice, seguimos
            ciclo = dfs(g, w);
         } else if (apilado[w]) { // hemos detectado un ciclo
            // se recupera retrocediendo
            ciclo = true;
         }
      }
      _camino.push_front(v);
      apilado[v] = false;
      return ciclo;
   }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   Digrafo dg(cin, 1);
   
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   OrdenarTareas  tareas(dg);

   if(tareas.aciclico()){
      for(int aux : tareas.tareasOrdenadas())
         cout << aux + 1 << ' ';
   }else{
      cout << "Imposible";
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
