
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct Registro{
  int momento;
  long long int id;
  int periodo;
};

bool operator<(Registro const&a, Registro const&b){
  return a.momento < b.momento || (a.momento == b.momento && a.id < b.id);
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;
  
  PriorityQueue<Registro> queue;
  int id, periodo;
  for(int i = 0; i < N ; i++){
    cin >> id;
    cin >> periodo;
    queue.push({periodo, id, periodo});
  }
  int K; cin >> K;

  // resolver el caso posiblemente llamando a otras funciones
  for(int i = 0; i < K; i++){
    Registro aux = queue.top();
    cout << aux.id << '\n';
    queue.pop();
    aux.momento += aux.periodo;
    queue.push(aux);
  }
  // escribir la solución
  cout << "---" << '\n';

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
