
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 N = Nº de cajas abiertas
 C = Nº de clientes esperando

 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct cashier {
  int index, time;
};

bool operator<(const cashier& a, const cashier& b){
  return b.time < a.time || (b.time == a.time && b.index < a.index);
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  int C; cin >> C;
  
  if (N == 0 && C == 0)
    return false;
  
  priority_queue<cashier> super;

  // resolver el caso posiblemente llamando a otras funciones
  for(int i = 1; i <= N; i++){
    super.push({i, 0});
  }

  int timeC;
  for(int i = 0; i < C; i++){
    cin >> timeC;
    cashier counter = super.top();
    super.pop();
    super.push({counter.index, counter.time + timeC});
  }

  // escribir la solución
  cout << super.top().index << endl;

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
