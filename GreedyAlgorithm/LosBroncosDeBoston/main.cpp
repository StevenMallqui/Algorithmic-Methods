
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
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
  int n; cin >> n;
  if (n == 0)
    return false;
  
  vector<int> rivales(n), broncos(n);
  for(int i = 0; i < n; i++)
    cin >> rivales[i];
  sort(rivales.begin(), rivales.end());

  for(int i = 0; i < n; i++)
    cin >> broncos[i];
  sort(broncos.begin(), broncos.end(), greater<int>());

  // resolver el caso posiblemente llamando a otras funciones
  int maxi = 0;
  bool parar = false;
  for(int i = 0; i < n && !parar; i++){
    if(broncos[i] > rivales[i])
      maxi += broncos[i] - rivales[i];
    else
      parar = true;
  }
  
  // escribir la solución
  cout << maxi <<'\n';

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
