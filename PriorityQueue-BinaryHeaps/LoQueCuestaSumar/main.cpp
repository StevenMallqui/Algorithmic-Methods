
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */

 long long int cuestaSumar(PriorityQueue<long long int> queue, int N){
   long long int sum1 = 0, sum2 = 0, total = 0, effort = 0;
   for(int i = 0; i < N - 1; i++){
      sum1 = queue.top();
      queue.pop();
      sum2 = queue.top();
      queue.pop();
      total = sum1 + sum2;
      queue.push(total);  
      effort += total;    
   }

   return effort;
 }


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;

   if (N == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   PriorityQueue<long long int> queue;
   long long int valor; 

   for(int i = 0; i < N; i++){
      cin >> valor;
      queue.push(valor);
   }

   // escribir la solución
   cout << cuestaSumar(queue, N) << endl;

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
