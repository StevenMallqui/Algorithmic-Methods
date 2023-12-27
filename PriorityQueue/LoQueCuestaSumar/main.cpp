
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */

 int cuestaSumar(priority_queue<int, std::vector<int>, std::greater<int>> q){
   
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
   priority_queue<int, std::vector<int>, std::greater<int>> minQueue;
   int valor; 

   for(int i = 0; i < N; i++){
      cin >> valor;
      minQueue.push(valor);
   }
   // escribir la solución
   cout << cuestaSumar(minQueue) << endl;

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
