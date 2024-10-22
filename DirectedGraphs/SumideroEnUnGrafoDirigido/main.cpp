
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

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
  Digrafo sol(cin, 0);
  if (!std::cin)  // fin de la entrada
    return false;
  

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  bool sumidero = false; 
  int index;
  for(int i = 0; i < sol.V() && !sumidero; i++){
    if(sol.ady(i).size() == 0){
      sumidero = true;
      index = i;
    }
  }

  sol = sol.inverso();
  if(sol.ady(index).size() != sol.V() - 1)
    sumidero = false;

  if(!sumidero)
    cout << "NO";
  else
    cout << "SI " << index;

  cout << '\n';

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
