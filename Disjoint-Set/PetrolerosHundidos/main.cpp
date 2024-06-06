
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
using direccion = pair<int, int>;
const vector<direccion> dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,-1},{1,1},{-1,-1},{-1,1}};

class MaxMancha{

private:
  fotografia foto;
  int tamanoMax;
  int F;
  int C;
  ConjuntosDisjuntos mar;

  int coordAElem(int i, int j) const{
    return i * C + j;
  }

  bool validarCoord(int i, int j) const{
    return (i >= 0 && i < F) && (j >= 0 && j < C);
  }

  void nuevaMancha(int i, int j){
    for(direccion dir : dirs){
      int dirI = i + dir.first;
      int dirJ = j + dir.second;
      if(validarCoord(dirI, dirJ) && foto[dirI][dirJ] == '#' && !mar.unidos(coordAElem(i, j), coordAElem(dirI, dirJ))){
        mar.unir(coordAElem(i, j), coordAElem(dirI, dirJ));
      }
    }
    tamanoMax = max(tamanoMax, mar.cardinal(coordAElem(i, j)));
  }

public:

  MaxMancha(const fotografia& pic, int f, int c): foto(pic), F(f), C(c), mar(ConjuntosDisjuntos(F * C)), tamanoMax(0){
    for(int i = 0; i < F; i++){
      for(int j = 0; j < C; j++){
        if(foto[i][j] == '#'){
          nuevaMancha(i , j);
        }
      }
    }
  }

  void anyadirMancha(int i, int j){
    foto[i][j] = '#';
    nuevaMancha(i, j);
  }

  int manchaMasGrande(){
    return tamanoMax;
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

   MaxMancha sol(foto, F, C);
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
#endif
   return 0;
}
