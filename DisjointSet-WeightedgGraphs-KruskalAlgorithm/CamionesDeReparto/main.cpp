
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
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

class Reparto{
  private:
    vector<bool> visit;

    void dfs(GrafoValorado<int> const& G, int v, int umbral) {
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

    Reparto(GrafoValorado<int> const& G, int v, int umbral) : visit(G.V(), false){
      dfs(G, v, umbral);
    }

    bool esPosible(int d){
      return visit[d];
    }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  GrafoValorado<int> ciudad(cin, 1);
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int K; cin >> K;
  int a, b, umbral;
  for(int i = 0; i < K; i++){
    cin >> a >> b >> umbral;
    Reparto sol(ciudad, a - 1, umbral);
    if(sol.esPosible(b - 1))
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
   system("PAUSE");
#endif
   return 0;
}
