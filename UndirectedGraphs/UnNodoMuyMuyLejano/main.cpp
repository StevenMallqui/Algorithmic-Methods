
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

class redTTL{
  private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int V;
    Grafo g;

    int bfs(const int &s, const int &ttl) {
      std::queue<int> q;
      dist[s] = 0; visit[s] = true;
      q.push(s);
      int cont = 1;
      while (!q.empty()) {
        int v = q.front(); q.pop();
        if(dist[v] < ttl){
          for (int w : g.ady(v)) {
            if (!visit[w]) {
              dist[w] = dist[v] + 1; visit[w] = true;
              q.push(w);
              cont++;
            }
          }
        }else
          break;
      }
      return cont;
    }

  public:
    redTTL(Grafo const& g) : visit(g.V(), false), dist(g.V()), V(g.V()), g(g) {}

    int inalcanzables(const int &s, const int &ttl){
      int cont = bfs(s, ttl);
      return V - cont;
    }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  Grafo red(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  int K; cin >> K;
  int s, ttl;

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución

  for(int i = 0; i < K; i++){
    cin >> s >> ttl;
    redTTL sol(red);
    cout << sol.inalcanzables(s - 1, ttl) << '\n';
  }

  cout << "---\n";
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
