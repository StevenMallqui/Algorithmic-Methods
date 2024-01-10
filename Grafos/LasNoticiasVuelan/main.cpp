
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

class Amigos {
public:
  Amigos(Grafo const& g) : visit(g.V(), false), solucion(g.V()){
    for(int i = 0; i < g.V(); i++){
      if(!visit[i]){
        vector<int> conexo;
        int tam = dfs(g, i, conexo);
        for(int i = 0; i < conexo.size(); i++){
          solucion[conexo[i]] = tam;
        }
      }
    }
  }

  void resultado(){
    for(int i = 0; i < solucion.size() - 1; i++){
      cout << solucion[i] << ' ';
    }
    cout << solucion[solucion.size() - 1] << '\n';
  }

private:
  std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
  std::vector<int> solucion;

  int dfs(Grafo const& G, int v, vector<int> &conexo) {
    visit[v] = true;
    int tam = 1;
    conexo.push_back(v);
    for (int w : G.ady(v)) {
      if (!visit[w]) {
        tam += dfs(G, w, conexo);
      }
    }
    return tam;
  }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int M; cin >> M;
  Grafo g(N);
  int usuarios, v, w;

  for(int i = 0; i < M; i++){
    cin >> usuarios;
    if(usuarios != 0){
      cin >> v;
      for(int i = 1; i < usuarios; i++){
        cin >> w;
        g.ponArista(v - 1, w - 1);
        v = w;
      }
    }
  }

  Amigos usuariosNoticias(g);
  usuariosNoticias.resultado();

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
