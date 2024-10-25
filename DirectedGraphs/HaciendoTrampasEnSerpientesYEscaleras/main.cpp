
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
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
using par = pair<int, int>;

class Trampa{

  private:
    vector<bool> visit;
    int minTiradas;

    void bfs(const Digrafo &d, int k, int origen, int destino){
      bool alcanzado = false;
      queue<par> q;
      visit[origen] = true;
      q.push({origen, 0});
      while(!alcanzado){
        par actual = q.front();
        q.pop();
        int cont = 1;
        while(!alcanzado && cont <= k){
          int ady = actual.first + cont;
          if(d.ady(ady).size() > 0)
            ady = d.ady(ady)[0];
          if(ady == destino){
            alcanzado = true;
            minTiradas = actual.second + 1;
          }else if(!visit[ady]){
            visit[ady] = true;
            q.push({ady, actual.second + 1});
          }
          cont++;
        }
      }
    }

  public:
    Trampa(const Digrafo &dg, const int &K): visit(dg.V(), false), minTiradas(0){
      bfs(dg, K, 0, dg.V()-1);
    }

    int tiradas_minimas(){
      return minTiradas;
    }

};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N, K, S, E; cin >> N >> K >> S >> E;
  if (N == 0 && K == 0 && S == 0 && E == 0)
    return false;
  
  Digrafo tablero(N*N);
  int v, w;
  
  for(int i = 0; i < (S+E); i++){
    cin >> v >> w;
    tablero.ponArista(v-1, w-1);
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Trampa sol(tablero, K);
  cout << sol.tiradas_minimas() << '\n';

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
