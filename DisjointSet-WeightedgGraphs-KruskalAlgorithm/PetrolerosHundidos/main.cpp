
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
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
using direcciones = pair<int,int>;
const vector<direcciones> dirs ={{1,0}, {0,1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

class MareasNegras{

   private:
      ConjuntosDisjuntos cjtos;
      fotografia foto;
      int F, C, tamMax;

      bool validarCoord(int i, int j) const{
         return (i >= 0 && i < F) && (j >= 0 && j < C);
      }

      int coordAElem(int i, int j) const{
         return C * i + j;
      }

      void nuevaMancha(int i, int j){
         for(direcciones dir : dirs){
            int dirI = i + dir.first;
            int dirJ = j + dir.second;
            if(validarCoord(dirI, dirJ) && foto[dirI][dirJ] == '#' && !cjtos.unidos(coordAElem(i, j), coordAElem(dirI, dirJ)))
               cjtos.unir(coordAElem(i, j), coordAElem(dirI, dirJ));
         }

         tamMax = max(tamMax, cjtos.cardinal(coordAElem(i, j)));
      }

   public:

      MareasNegras(const fotografia& pic, const int &F, const int &C) : F(F), C(C), foto(pic), cjtos(ConjuntosDisjuntos(F * C)), tamMax(0){
         for(int i = 0; i < F; i++){
            for(int j = 0; j < C; j++){
               if(pic[i][j] == '#'){
                  nuevaMancha(i, j);
               }
            }
         }
      }

      void anyadirMancha(int i, int j){
         foto[i][j] = '#';
         nuevaMancha(i, j);
      }
      
      int manchaMasGrande(){
         return tamMax;
      }

};


bool resuelveCaso() {
   
   // leer los datos de la entrada
   int F, C; cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;
   
   fotografia foto(F);
   cin.ignore(1,'\n');

   for(int i = 0; i < F; i++){
      getline(cin, foto[i]);
   }

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   MareasNegras sol(foto, F, C);
   cout << sol.manchaMasGrande();

   int N; cin >> N;
   int aux1, aux2;
   for(int i = 0; i < N; i++){
      cin >> aux1 >> aux2;
      sol.anyadirMancha(aux1 - 1, aux2 -1);
      cout << ' ' << sol.manchaMasGrande();
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
