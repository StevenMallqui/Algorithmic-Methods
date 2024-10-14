
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
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

void pajaro_en_primera_posicion(priority_queue<int> &pequenos, priority_queue<int, vector<int>,greater<int>> &grandes, const int &parejas, int&primero){
  int edad;
  for(int i = 0; i < parejas; i++){
    int j = 2; 
    while(j > 0){
      cin >> edad;
      if(edad > primero)
        grandes.push(edad);
      else
        pequenos.push(edad);
      
      j--;
    }

    if(pequenos.size() > grandes.size()){
      grandes.push(primero);
      primero = pequenos.top();
      pequenos.pop();
    }
    else if(pequenos.size() < grandes.size()){
      pequenos.push(primero);
      primero = grandes.top();
      grandes.pop();
    }

    cout << primero;
    if(i < parejas - 1)
      cout << ' ';
  }

  cout << '\n';
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int primero, parejas; cin >> primero >> parejas;
  if (primero == 0 && parejas == 0)
    return false;
  
  priority_queue<int> pequenos;
  priority_queue<int, vector<int>,greater<int>> grandes;

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  pajaro_en_primera_posicion(pequenos, grandes, parejas, primero);

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
