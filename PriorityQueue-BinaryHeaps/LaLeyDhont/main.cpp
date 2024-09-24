
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

struct Candidatura{
  int indice;
  int votos;
  float coeficiente;
};

bool operator<(const Candidatura &a, const Candidatura &b){
  return b.coeficiente < a.coeficiente || (a.coeficiente == b.coeficiente && b.votos < a.votos) || (a.coeficiente == b.coeficiente && a.votos == b.votos && a.indice < b.indice);
}

void escanos_asignados(PriorityQueue<Candidatura> &candidaturas, const int &N, const int &C){
  vector<int> escanos(C, 0);
  Candidatura aux;

  for(int i = 0; i < N; i++){
    aux = candidaturas.top();
    candidaturas.pop();
    escanos[aux.indice-1]++;
    aux.coeficiente = float(aux.votos)/(1+escanos[aux.indice-1]);
    candidaturas.push(aux);
  }

  cout << escanos[0];

  for(int i = 1; i < C; i++){
    cout << ' ' << escanos[i];
  }

  cout << '\n';
} 

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int C, N; cin >> C >> N;
  if (C == 0 && N == 0)
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  PriorityQueue<Candidatura> candidaturas;
  int votos;
  for(int i = 0; i < C; i++){
    cin >> votos;
    candidaturas.push({i+1, votos, float(votos)});
  }
  
  // escribir la solución
  escanos_asignados(candidaturas, N, C);

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
