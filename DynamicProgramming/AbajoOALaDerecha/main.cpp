
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
using namespace std;


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int progDinamica(const Matriz<int> &nums, const int n, const int m){
  Matriz<int> sol(n, m, 0);
  sol[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(sol[i][j] != 0){
        int a = nums[i][j];
        if(j + a < m)
          sol[i][j + a] += sol[i][j];
        if(i + a < n)
          sol[i + a][j] += sol[i][j]; 
      } 
    }
  }
  return sol[n-1][m-1];
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n, m; cin >> n >> m;
  if (!std::cin)  // fin de la entrada
    return false;
  
  Matriz<int> nums(n, m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> nums[i][j];

  cout << progDinamica(nums, n, m) << '\n';

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
