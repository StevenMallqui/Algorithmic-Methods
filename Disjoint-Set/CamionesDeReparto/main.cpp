
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class CamionesReparto {

private:
  vector<bool> visit;
  bool alcanzado;

  void dfs(const GrafoValorado<int> & G, int v, int umbral) {
    visit[v] = true;
    for (auto a : G.ady(v)) {
      if (a.valor() >= umbral) {
        int w = a.otro(v);
        if (!visit[w])
          dfs(G, w, umbral);
      }
    }
  }

public:
  CamionesReparto(const GrafoValorado<int> & G, int u, int v, int umbral) : visit(vector<bool>(G.V(), false)), alcanzado(false){
    dfs(G, u, umbral);
    alcanzado = visit[v];
  }

  bool puedeCircular(){
    return alcanzado;
  }

};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  GrafoValorado<int> ciudad(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;

  int K; cin >> K;
  int u, v, valor;
  for(int i = 0; i < K; i++){
    cin >> u >> v >> valor;
    CamionesReparto sol(ciudad, u - 1, v - 1, valor);
    if(sol.puedeCircular())
      cout << "SI\n";
    else  
      cout << "NO\n";
  }

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
#endif
   return 0;
}
