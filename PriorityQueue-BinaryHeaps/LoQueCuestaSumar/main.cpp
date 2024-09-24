
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
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

long long int min_esfuerzo(priority_queue<long long int, vector<long long int>, greater<long long int>> &sumandos, const int &N){
   long long int esfuerzo = 0, sum = 0, sum1, sum2;
   
   for(int i = 0; i < N - 1; i++){
      sum1 = sumandos.top();
      sumandos.pop();
      sum2 = sumandos.top();
      sumandos.pop();
      sum = sum1 + sum2;
      sumandos.push(sum);
      esfuerzo += sum;
   }

   return esfuerzo;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;
   if (N == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<long long int, vector<long long int>, greater<long long int>> sumandos;
   long long int number;

   for(int i = 0; i < N; i++) {
      cin >> number;
      sumandos.push(number);
   }

   // escribir la solución
   cout << min_esfuerzo(sumandos, N) <<'\n';

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
