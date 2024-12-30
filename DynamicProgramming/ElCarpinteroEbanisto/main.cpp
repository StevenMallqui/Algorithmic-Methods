
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "Matriz.h"
using namespace std;

/*@ <answer>
  
   RECURSION 

   minimoEsfuerzo(i, j): Menor coste para cortar un tronco que va desde la i a la j donde
   los cortes que me quedan por hacer van de i+1 a j-1.

   Caso Recursivo:
   minimoEsfuerzo(i,j) = min(minimoEsfuerzo(i,k) + minimoEsfuerzo(k,j)) + 2 * (M[j] - M[i])  i<j-1	&& i<k<j
   
   Caso Base:
   minimoEsfuerzo(i, i+1) = 0. Si los extremos consecutivos, no hay marcas por las que cortar.

   Caso extra:
   minimoEsfuerzo(i, i) = 0. Tronco vacío.

 @ </answer> */

int cortar_madera(vector<int> const& D) {
   int n = D.size();
   Matriz<int> tablones(n, n, 0);
   for (int d = 2; d <= n - 1; ++d) // recorre diagonales
      for (int i = 0; i < n - d; ++i) { // recorre elementos de diagonal
         int j = i + d;
         tablones[i][j] = INT_MAX;
         for (int k = i+1 ; k < j; ++k) {
            int temp = tablones[i][k] + tablones[k][j] + 2 * (D[j] - D[i]);
            if (temp < tablones[i][j]) { // es mejor partir por k
               tablones[i][j] = temp;
         }
      }
   }
   return tablones[0][n-1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int L, N; cin >> L >> N;
   if (L == 0 && N == 0)
      return false;

   vector<int> elementos(N+1);
   for(int i = 1; i <= N; i++)
      cin >> elementos[i]; 
   elementos.push_back(L);

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cout << cortar_madera(elementos) << '\n';

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
