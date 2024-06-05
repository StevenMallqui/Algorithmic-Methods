
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using fotografia = vector<string>;
using dir = pair<int, int>;
using elem = pair<int, int>;

const vector<dir> dirs = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

class MaxConjuntoDisconjunto {

private:
   ConjuntosDisjuntos mar;
   int tamMax;
   fotografia pic;
   int C;
   int F;

   int numElem(int i, int j) const{
      return i * C + j;
   }

   bool valida(const elem e) const {
      return ((e.first >= 0 && e.first < F) && (e.second >= 0 && e.second < C));
   }

   void comprobarUniones(int i, int j){
      elem sig;
      for(dir d : dirs){
         sig.first = i + d.first;
         sig.second = j + d.second;
         if(valida(sig) && pic[sig.first][sig.second] == '#' && !mar.unidos(numElem(i, j), numElem(sig.first, sig.second)))
            mar.unir(numElem(i, j), numElem(sig.first, sig.second));
      }
      tamMax = max(tamMax, mar.cardinal(numElem(i, j)));
   }

public:
   MaxConjuntoDisconjunto(int F, int C, fotografia pic) : mar(ConjuntosDisjuntos(F * C)), tamMax(0), pic(pic), F(F), C(C){
      for(int i = 0; i < F; i++){
         for(int j = 0; j < C; j++){
            if(pic[i][j] == '#')
               comprobarUniones(i, j);
         }
      } 
   }

   void anyadirMancha(elem mancha){
      pic[mancha.first][mancha.second] = '#';
      comprobarUniones(mancha.first, mancha.second);
   }

   int manchaMax(){
      return tamMax;
   }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int F; cin >> F;
   if (!std::cin)  // fin de la entrada
      return false;
   int C; cin >> C; 
   fotografia foto(F);
   cin.ignore(1,'\n');
   for(int i = 0; i < F; i++)
      getline(cin, foto[i]);

   MaxConjuntoDisconjunto sol(F, C, foto);
   cout << sol.manchaMax();
   
   int N; cin >> N;
   int aux1, aux2;
   for(int i = 0; i < N; i++){
      cin >> aux1 >> aux2;
      sol.anyadirMancha({aux1 - 1, aux2 -1});
      cout << ' ' << sol.manchaMax();
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
#endif
   return 0;
}
