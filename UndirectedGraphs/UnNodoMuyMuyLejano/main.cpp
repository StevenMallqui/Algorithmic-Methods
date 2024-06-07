
/*@ <answer>
 *
 * Nombre y Apellidos:
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
class Red{

public:
  Red(Grafo const& g) : visit(g.V(), false), ant(g.V()), dist(g.V()), g(g){};

  int alcance(int origen, int ttl){
    s = origen;
    bfs();
    int cont = 1;
    for(int i = 0; i < dist.size(); i++){
      if(dist[i] <= ttl && dist[i] != 0 && i != origen) cont++;
    }
    return cont;
  };

private:
  std::vector<bool> visit; 
  std::vector<int> ant; 
  std::vector<int> dist; 
  Grafo g;
  int s;

  void bfs() {
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
  Grafo g(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  int K; cin >> K;

  for(int i = 0; i < K; i++){
    int s, ttl; cin >> s >> ttl;
    Red miRed(g);
    cout << g.V() - miRed.alcance(s - 1, ttl) <<'\n';
  }
  cout << "---" << '\n';
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
