
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
class SerpienteEscalera{

public: 
  SerpienteEscalera(Digrafo const& d, int K) : visit(d.V(), false) {
    bfs(d, K, 0, d.V() - 1);
  } 

  int movimientos_minimos(){
    return minMovs;
  }

private:
  vector<bool> visit;
  int minMovs = 0;

  void bfs(Digrafo const& d, int k, int origen, int destino){
    bool alcanzado = false;
    queue<par> q;
    visit[origen] = true;
    q.push({origen, 0});
    while(!alcanzado) {
      par actual = q.front();
      q.pop();
      int cont = 1;
      while(!alcanzado && cont <= k){
        int ady = actual.first + cont;
        if(d.ady(ady).size() > 0)
          ady = d.ady(ady)[0];
        if(ady == destino){
          alcanzado = true;
          minMovs = actual.second + 1;
        } else if(!visit[ady]){
          visit[ady] = true;
          q.push({ady, actual.second + 1});
        }
        ++cont;
      }
    }
  }

};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  int K, S, E; cin >> K >> S >> E; 
  Digrafo S_E(N * N); 
  int aux1, aux2;
  for(int i = 0; i < (S + E); i++){
    cin >> aux1 >> aux2;
    S_E.ponArista(aux1 - 1, aux2 - 1);
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  SerpienteEscalera sol(S_E, K);
  cout << sol.movimientos_minimos() << '\n';

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
