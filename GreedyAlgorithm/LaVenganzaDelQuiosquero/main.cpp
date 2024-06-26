
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
using namespace std;
// propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int voraz(long long int suma, long long S, long long N){
  long long mas = N;
  for(long long i = 1; i < S; i++){
    long long y = S - i;
    if(i < y){
      mas++;
      suma -= y;
      suma += mas;
    }
  }

  return suma;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  long long N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  long long S; cin >> S;
  long long int suma = 0;
  for(long long  i = 1; i <= N; i++){
    suma += i;
  }

  cout << voraz(suma, S, N) <<'\n';
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
