
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


using matriz = vector<vector<int>>;
/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
LEYENDA
---------
. Vij = valor de la casilla [i][j]
. N = dimension del tablero

RECURSION
----------
tablero(i, j) = puntuacion máxima que se puede conseguir empezando en la casilla [i][j]

tablero(i, j) = max(tablero(i-1, j) + Vij    // empezar en [i][j] y subir arriba
                    tablero(i-1, j-1) + Vij  // empezar en [i][j] e ir a la diagonal izquierda
                    tablero(i-1, j+1) + Vij  // empezar en [i][j] e ir a la diagonal derecha

CASO BASE
----------
tablero(i, j) = 0 si i < 1 || i > N
tablero(i, j) = 0 si j < 1 || j > N

sol = max(tablero(N, j)), j € {1,...,N}

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int casilla(const int i, const int j, const matriz& tablero){
  if(i >= 0 && i < tablero.size() && j >= 0 && j < tablero.size())
    return tablero[i][j];
  return 0;
}

pair<int, int> progDinamica(const matriz& tablero,const int N){
  int maximo = -1;
  int fila = -1;
  matriz M(N, vector<int>(N, 0));
  for(int i = 0; i < N; i++){
    for(int j = N - 1; j >= 0; j--){
      int v1 = casilla(i - 1, j, M) + tablero[i][j];
      int v2 = casilla(i - 1, j - 1, M) + tablero[i][j];
      int v3 = casilla(i - 1, j +1, M) + tablero[i][j];
      M[i][j] = max(v1, max(v2, v3));
      if(M[i][j] >= maximo){
        maximo = M[i][j];
        fila = j;
      }
    }
  }

  return {maximo, fila + 1};
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;

  matriz tablero(N, vector<int>(N));  
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> tablero[i][j];

  pair<int, int> sol = progDinamica(tablero, N);
  cout << sol.first <<' ' << sol.second <<'\n'; 
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
