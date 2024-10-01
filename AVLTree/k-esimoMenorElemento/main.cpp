
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;

  Set<int> conjunto; 
  int elem;

  for(int i = 0; i < N; i++){
    cin >> elem;
    conjunto.insert(elem);
  } 
  
  int M; cin >> M;
  int c_elem;

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  for(int i = 0; i < M; i++){
    cin >> c_elem;
    try{
      cout << conjunto.kesimo(c_elem) <<'\n';
    } catch(out_of_range& e){
      cout << e.what() << '\n';
    }
  }
  
  cout << "---\n";
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
