
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

class Peaje{
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

  public:
    Peaje(Grafo const& g, int s) : visit(g.V(), false), dist(g.V()), s(s) {
      bfs(g);
    }

    int distancia(int lugar){
      return dist[lugar];
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int C, casaAlex, casaLucas, trabajo; cin >> C >> casaAlex >> casaLucas >> trabajo;
  --casaAlex; --casaLucas; --trabajo;
  Grafo ciudad(N);
  int v, w;

  for(int i = 0; i < C; i++){
    cin >> v >> w;
    ciudad.ponArista(v - 1, w - 1);
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Peaje desdeLucas(ciudad, casaLucas);
  Peaje desdeAlex(ciudad, casaAlex);
  Peaje desdeTrabajo(ciudad, trabajo);

  int peajeMin = desdeLucas.distancia(0) + desdeAlex.distancia(0) + desdeTrabajo.distancia(0);
  for(int i = 1; i < N; i++)
    peajeMin = min(peajeMin, desdeLucas.distancia(i) + desdeAlex.distancia(i) + desdeTrabajo.distancia(i));

  cout << peajeMin << '\n';

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
