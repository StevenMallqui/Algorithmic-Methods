
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct comic{
   int id;
   int pila;

   bool opetator<(const comic &other) const{
      return other.id < id;
   }
};

bool resuelveCaso() {
   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   vector<deque<int>> pilas(N);
   int K, id, mejorEjemplar = INF;
   for(int i = 0; i < N; i++){
      cin >> K; 
      for(int j = 0; j < K; j++){
         cin >> id;
         mejorEjemplar = min(mejorEjemplar, id);
         pilas[i].push_front(id);
      }
   }

   int posicion = 1;
   priority_queue<comic> cimas;
   for(int i = 0; i < N; i++){
      if(!pilas[i].empty()){
         cimas.push({pilas[i].front(), i});
         pilas[i].pop_front();
      }
   }

   while(cimas.top().id != mejorEjemplar){
      comic c = cimas.top();
      cimas.pop();
      if(!pilas[c.pila].empty()){
         cimas.push({pilas[c.pila].front(), c.pila});
         pilas[c.pila].pop_front();
      }
      posicion++;
   }

   cout << posicion << '\n';

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
