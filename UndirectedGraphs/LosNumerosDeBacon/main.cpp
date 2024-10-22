
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
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

class CaminoMasCorto {
   public:

   CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false), dist(g.V()), s(s) {
      bfs(g);
   }

   // ¿hay camino del origen a v?
   bool hayCamino(int v) const {
      return visit[v];
   }

   // número de aristas entre s y v
   int distancia(int v) const {
      return dist[v];
   }

   private:
   std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
   std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
   int s;

   void bfs(Grafo const& g) {
      std::queue<int> q;
      dist[s] = 0; visit[s] = true;
      q.push(s);
      while (!q.empty()) {
         int v = q.front(); q.pop();
         for (int w : g.ady(v)) {
            if (!visit[w]) {
               dist[w] = dist[v] + 1; visit[w] = true;
               q.push(w);
            }
         }
      }
   }
};

struct pelicula{
   string nombre;
   vector<string> actores;
};

void construir_grafo(const unordered_map<string, int> &actores, const vector<pelicula> &peliculas, Grafo &a){

   for(int i = 0; i < peliculas.size(); i++){
      pelicula p = peliculas[i];
      for(int j = 0; j < p.actores.size(); j++){
         for(int k = j+1; k < p.actores.size(); k++){
            a.ponArista(actores.at(p.actores[j]), actores.at(p.actores[k]));
         }
      }
   }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int P; cin >> P;
   if (!std::cin)  // fin de la entrada
      return false;

   unordered_map<string, int> actores;
   actores["KevinBacon"] = 0;
   int cont = 1;

   vector<pelicula> peliculas(P);
   string actor;
   int num_A;

   for(int i = 0; i < P; i++){
      cin >> peliculas[i].nombre >> num_A;
      for(int j = 0; j < num_A; j++){
         cin >> actor;
         peliculas[i].actores.push_back(actor);
         if(actores.find(actor) == actores.end()){
            actores[actor] = cont;
            cont++;
         }
      }
   }

   Grafo hollywood(actores.size());
   construir_grafo(actores, peliculas, hollywood);

   CaminoMasCorto cm(hollywood, 0);

   int casos; cin >> casos;
   for(int i = 0; i < casos; i++){
      cin >> actor;
      cout << actor;
      if(cm.hayCamino(actores[actor]))
         cout << ' ' << cm.distancia(actores[actor]);
      else 
         cout << " INF";
      cout << '\n';
   }

   cout << "---\n";
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución

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
