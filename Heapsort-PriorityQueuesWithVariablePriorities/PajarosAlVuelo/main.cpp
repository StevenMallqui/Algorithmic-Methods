
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


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int mediana, parejas; cin >> mediana; cin >> parejas;
   
   if (mediana == 0 && parejas == 0)
      return false;
   
   priority_queue<int> menores;
   priority_queue<int,vector<int>,greater<int> > mayores;
   
   for(int j = 0; j < 2 * parejas; j++){
      
      int nuevo, minSize, maxSize; cin >> nuevo;
     
      if(nuevo < mediana){
         menores.push(nuevo);
      }else{
         mayores.push(nuevo);
      }
      
      minSize = menores.size();
      maxSize = mayores.size();

      if(minSize - maxSize > 1){
         mayores.push(mediana);
         mediana = menores.top();   
         menores.pop();
      }else if(maxSize - minSize > 1){
         menores.push(mediana);
         mediana = mayores.top();
         mayores.pop();
      }

      if(j % 2 != 0)
         cout << mediana << " ";
   }

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
