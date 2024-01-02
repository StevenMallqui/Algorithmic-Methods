
/*@ <answer>
 *
 * Nombre y Apellidos:
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
struct Paciente{
  string nombre;
  int gravedad, espera;
};

bool operator<(Paciente const&a, Paciente const&b){
  return b.gravedad < a.gravedad || (a.gravedad == b.gravedad && a.espera < b.espera);
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  PriorityQueue<Paciente> queue;
  char type;
  for(int i = 0; i < N; i++){
    cin >> type;
    if(type == 'I'){
      Paciente aux;
      cin >> aux.nombre;
      cin >> aux.gravedad;
      aux.espera = i;
      queue.push(aux);
    }else if(type == 'A'){
      Paciente aux = queue.top();
      queue.pop();
      cout << aux.nombre <<'\n';
    }
  }
  // escribir la solución
  cout << "---"<<'\n';
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
