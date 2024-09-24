
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
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
struct Caja{
  int id;
  int tiempoCobro = 0;
};

bool operator<(const Caja &a, const Caja &b){
  return a.tiempoCobro < b.tiempoCobro || (a.tiempoCobro == b.tiempoCobro && a.id < b.id);
}

int caja_Ismael( PriorityQueue<Caja> &cajas, const int &C){
  int tiempoCliente; 

  for(int i = 0; i < C; i++){
    cin >> tiempoCliente;
    Caja aux = cajas.top();
    cajas.pop();
    aux.tiempoCobro += tiempoCliente;
    cajas.push(aux);
  }

  return cajas.top().id;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N, C; cin >> N >> C;
  if (N == 0 && C == 0)
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  PriorityQueue<Caja> cajas;
  for(int i = 0; i < N; i++){
    cajas.push({i+1});
  }

  // escribir la solución
  cout << caja_Ismael(cajas, C) << '\n';

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
