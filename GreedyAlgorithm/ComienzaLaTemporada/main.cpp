
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
  int N, M; cin >> N >> M;
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  vector<int> tallas(N);
  vector<int> equipaciones(M);

  for(int i = 0; i < N; i++)
    cin >> tallas[i];

  for(int i = 0; i < M; i++)
    cin >> equipaciones[i];

  sort(tallas.begin(), tallas.end());
  sort(equipaciones.begin(), equipaciones.end());

  int comprar = N;
  int i = 0, j = 0;
  while(i < tallas.size() && j < equipaciones.size()){
    if((tallas[i] == equipaciones[j]) || (tallas[i] + 1 == equipaciones[j])){
      comprar--;
      i++;
      j++;
    }else if(equipaciones[j] > tallas[i])
      i++;
    else if(equipaciones[j] < tallas[i])
      j++;
  }

  cout << comprar << '\n'; 
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
