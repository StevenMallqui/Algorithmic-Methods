
/*@ <answer>
 *
 * Nombre y Apellidos: STEVEN MALLQUI AGUILAR
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int minParches(vector<int> const& agujeros, int L){
   int numParches = 1;
   int aux = agujeros[0];
   for(int i = 1; i < agujeros.size(); i++){
      if(aux + L < agujeros[i]){
         numParches++;
         aux = agujeros[i];
      }
   }  

   return numParches;
}  


bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N; cin >> N;
   
   if (!std::cin)  // fin de la entrada
      return false;

   int L; cin >> L;
   vector<int> agujeros(N);

   for(int i = 0; i < N; i++)
      cin >> agujeros[i];
   
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución

   cout << minParches(agujeros, L) <<endl;

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
