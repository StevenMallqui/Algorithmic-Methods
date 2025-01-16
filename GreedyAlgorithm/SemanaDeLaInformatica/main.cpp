
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct intervalo{
  int ini, fin;
};

bool operator<(const intervalo &a, const intervalo &b){
  return a.ini < b.ini;
} 

int voraz(PriorityQueue<intervalo> &intervalos){
  int amigos = 0;
  int N = intervalos.size();

  intervalo aux = intervalos.top();
  intervalos.pop();
  PriorityQueue<int> finales;
  finales.push(aux.fin);

  for(int i = 1; i < N; i++){
    aux = intervalos.top();
    intervalos.pop();
    if(aux.ini < finales.top())
      amigos++;
    else
      finales.pop();
    finales.push(aux.fin);
  }

  return amigos;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  int ini, fin;
  PriorityQueue<intervalo> intervalos; 
  for(int i = 0; i < N; i++){
    cin >> ini >> fin;
    intervalos.push({ini, fin});
  }

  cout << voraz(intervalos)<< '\n';

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
