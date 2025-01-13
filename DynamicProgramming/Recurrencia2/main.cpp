
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Matriz.h"
using namespace std;



/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int convert(char a){
   int index; 

   switch(a){
      case 'A':
         index = 0; 
         break;
      case 'C':
         index = 1;
         break;
      case 'G':
         index = 2;
         break;
      case 'T':
         index = 3;
         break;
      case '-':
         index = 4;
         break;
   }

   return index;
}

int progDinamica(const Matriz<int> &a, const string &u, const string &v){
   int N = u.size(); 
   int M = v.size();

   vector<int> sol(M+1, 0);
   for(int j = 1; j <= M; j++)
      sol[j] = a[4][convert(v[j-1])] + sol[j-1];


   for(int i = 1; i <= N; i++){
      int prevDiagonal = sol[0];
      sol[0] += a[convert(u[i-1])][4];
      for(int j = 1; j <= M; j++){
         int temp = sol[j];
         int t1 = a[convert(u[i-1])][4] + sol[j];
         int t2 = a[4][convert(v[j-1])] + sol[j-1];
         int t3 = a[convert(u[i-1])][convert(v[j-1])] + prevDiagonal;
         t1 = max(t1, t2);
         sol[j] = max(t1, t3);
         prevDiagonal = temp;
      }
   }

   return sol[M];
}

void resuelveCaso() {
   
   // leer los datos de la entrada
   Matriz<int> m(5, 5);

   for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
         cin >> m[i][j];

   int P; cin >> P;

   string u, v; 
   for(int i = 0; i < P; i++){
      cin >> u >> v;
      cout << progDinamica(m, u, v) << '\n';
   }
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
