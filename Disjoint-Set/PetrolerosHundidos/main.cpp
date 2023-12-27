
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using fotografia = vector<string>;

class MaxConjuntoDisconjunto
{
private:
   ConjuntosDisjuntos conjuntos;
   int tamMax;
   fotografia pic;
   int C;
   int F;

public:
   MaxConjuntoDisconjunto(fotografia pic, int F, int C) : pic(pic), F(F), C(C){
      for(int i = 0; i < F; i++){
         for(int j = 0; j < C; j++){
            
         }
      } 
   }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int F; cin >> F;
   
   if (!std::cin)  // fin de la entrada
      return false;

   int C; cin >> C; 

   fotografia pic(F);

   cin.ignore(1,'\n');
   for(int i = 0; i < F; i++)
      getline(cin, pic[i]);
   
   
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
