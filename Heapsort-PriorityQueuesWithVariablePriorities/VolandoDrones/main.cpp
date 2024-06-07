
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
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  int A, B; cin >> A >> B;
  priority_queue<int> nueveV;
  priority_queue<int> unoymedioV;

  int tiempoVuelo;
  for(int i = 0; i < A; i++){
    cin >> tiempoVuelo;
    nueveV.push(tiempoVuelo);
  }

  for(int i = 0; i < B; i++){
    cin >> tiempoVuelo;
    unoymedioV.push(tiempoVuelo);
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int totalHoras = 0; 
  while(!nueveV.empty() && !unoymedioV.empty()){
    vector<int> usadas9, usadas1_5;
   for (int i = 0; i < N && !nueveV.empty() && !unoymedioV.empty(); i++){
      int minimo, firstTop = nueveV.top(), secondTop = unoymedioV.top(); 
      nueveV.pop(); unoymedioV.pop();
      minimo = min(firstTop, secondTop);
      totalHoras += minimo;
      firstTop -= minimo;
      secondTop -= minimo;
      if(firstTop > 0) usadas9.push_back(firstTop);
      if(secondTop > 0) usadas1_5.push_back(secondTop);
    }
    cout << totalHoras << " ";
    totalHoras = 0;

    for(int bateria : usadas9)
      nueveV.push(bateria);
    
    for(int bateria : usadas1_5)
      unoymedioV.push(bateria);
  }
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
