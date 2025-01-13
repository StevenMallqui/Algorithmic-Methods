
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
  
  DEFINICIONES
  N: número de actividades
  Di : duración de la actividad i

  RECURSION
  minimaDuracion(i): minima duración del evento teniendo actividades del i al N-1

  minimaDuracion(i): 

  CASOS BASE

  RESOLUCION

  COSTE
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
  
  // leer los datos de la entrada
  
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  
  // escribir la solución

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
