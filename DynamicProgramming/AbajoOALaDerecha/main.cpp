
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
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int progDinamica(const matriz& tablero, const int n, const int m){
  matriz M(n, vector<int>(m, 0));
  M[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ 
      int a = i + tablero[i][j];
      if(a < n){
        M[a][j] += M[i][j];
      }
      a = j + tablero[i][j];
      if(a < m){
        M[i][a] += M[i][j];
      }
    }
  }

  return M[n-1][m-1];
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int n; cin >> n;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int m; cin >> m;
  matriz tablero(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> tablero[i][j];
    }
  }

  cout << progDinamica(tablero, n, m) <<'\n';

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
