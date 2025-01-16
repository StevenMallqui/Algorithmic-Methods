
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;


int voraz(PriorityQueue<int> &pq){
   int gorras = 0;

   int aficion1, aficion2;
   while(!pq.empty()){
      aficion1 = pq.top();
      pq.pop();
      if(!pq.empty()){
         aficion2 = pq.top();
         pq.pop();
         gorras += aficion1 + aficion2;
         aficion1 += aficion2;
         pq.push(aficion1);
      }
   }

   return gorras;
}

bool resuelveCaso() {
   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   PriorityQueue<int> pq;
   int num;
   for(int i = 0; i < N; i++){
      cin >> num;
      pq.push(num);
   }

   cout << voraz(pq) << '\n';

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
