
/*@ <answer>
 *
 * Nombre y Apellidos:
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
using Camino = deque<int>;

class CaminoMasCorto {
  public:
  CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s) {
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

  // devuelve el camino más corto desde el origen a v (si existe)
  Camino camino(int v) const {
    if (!hayCamino(v)) throw std::domain_error("No existe camino");
    Camino cam;
    for (int x = v; x != s; x = ant[x])
      cam.push_front(x);
    cam.push_front(s);
    return cam;
  }

  private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
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
          ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
          q.push(w);
        }
      }
    }
  }
};


bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  
  if (!std::cin)  // fin de la entrada
    return false;
  
  int C, casaAlex, casaLucas, trabajo, v, w; cin >> C >> casaAlex >> casaLucas >> trabajo;
  Grafo g(N);

  for(int i = 0; i < C; i++){
    cin >> v >> w;
    g.ponArista(v-1, w-1);
  }
  casaAlex -= 1; casaLucas -= 1; trabajo -= 1;

  CaminoMasCorto OrigenAlex(g, casaAlex);
  Camino DestinoLucas= OrigenAlex.camino(casaLucas);
  CaminoMasCorto OrigenLucas(g, casaLucas);

  int precioMinimo = 0;
  bool enElCamino = false;
  for(int i = 0; i < DestinoLucas.size() && !enElCamino; i++){
    int aux = 0; 
    if(DestinoLucas[i] == trabajo){
      precioMinimo = OrigenAlex.distancia(trabajo) + OrigenLucas.distancia(trabajo);
      enElCamino = true;
    }else {
      CaminoMasCorto OrigenI(g, DestinoLucas[i]);
      aux = OrigenAlex.distancia(DestinoLucas[i]) + OrigenLucas.distancia(DestinoLucas[i]) + OrigenI.distancia(trabajo);
      if(i == 0)
        precioMinimo = aux;
      precioMinimo = min(aux, precioMinimo);
    }
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  cout << precioMinimo << '\n';

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
