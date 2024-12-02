
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

   DEFINICIONES
   T = Segundos máximos que le permite la botella estar debajo del agua
   N = Numero de cofres
   Pi = Profundidad a la que se encuentra el cofre i
   Oi = Cantidad de oro que hay en el cofre i

   RECURSIÓN 
   maximoOro(i, j) = Cantidad máxima de oro que se puede conseguir cuando quedan j segundos debajo del agua y
   podemos recoger los cofres del 1 al i

   maximoOro(i, j) = { maximoOro(i-1, j)                                        si j < 3Pi
                     { max(maximoOro(i-1, j), maximoOro(i-1, j-3Pi) + Oi)    si j >= 3Pi

   CASOS BASE
   maximoOro(0, j) = 0
   maixmoOro(i, 0) = 0

   Llamada inicial: maximoOro(N, T);

   RESOLUCIÓN
   Se utiliza la programación dinámica ascendente, de manera que se guarda en un matriz la solución a los 
   subproblemas que se van resolviendo, dado que en la recursión se calculan varias veces de forma innecesaria.
   Nótese que la matriz es de tamaño N+1, T+1. Por un lado, las columnas van de 0 a T. Por otro, en la matriz 
   se numeran los cofres de 1 a N, como en la definición recursiva anterior, y se añade la fila 0 para indicar 
   el conjunto vacío de cofres.

   COSTE
   - El coste en tiempo está en el orden O(N*T), porque N*T es el número de subproblemas que puede haber, y cada
   problema se resuelve a lo sumo 2 veces, y la segunda llamada no supone más trabajo.
   - El coste en espacio está en el orden O(N*T), por la matriz donde guardamos las soluciones de los subproblemas
   

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct cofre{
   int profundidad;
   int oro;
};

int progDinamica(int i, int j, vector<cofre> const& cofres, Matriz<int> &m){
   if(m[i][j] != -1)
      return m[i][j];
   if(i == 0 || j == 0) m[i][j] = 0;
   else if((3*cofres[i-1].profundidad) > j){
      m[i][j] = progDinamica(i-1, j, cofres, m);
   }else
      m[i][j] = max(progDinamica(i-1, j, cofres, m), progDinamica(i-1, j-(3*cofres[i-1].profundidad), cofres, m) + cofres[i-1].oro);

   return m[i][j];
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int T; cin >> T;
   if (!std::cin)  // fin de la entrada
      return false;
   
   int N; cin >> N;
   vector<cofre> cofres(N);
   for(int i = 0; i < N; i++)
      cin >> cofres[i].profundidad >> cofres[i].oro;

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   Matriz<int> m(N+1, T+1, -1);
   int maximoOro = progDinamica(N, T, cofres, m);

   int i = N, j = T;
   vector<cofre> sol;
   while(i > 0 && j > 0){
      if(m[i][j] != m[i-1][j]){
         sol.push_back(cofres[i-1]); 
         j -= 3 * cofres[i-1].profundidad; 
      }
      i--;
   }

   cout << maximoOro << '\n';
   cout << sol.size() << '\n';
   for(int i = sol.size(); i > 0; i--)
      cout << sol[i-1].profundidad << ' ' << sol[i-1].oro << '\n';
   cout << "---\n";
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
