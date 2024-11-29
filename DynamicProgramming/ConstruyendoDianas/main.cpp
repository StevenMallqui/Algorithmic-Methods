
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"
using namespace std;

/*@ <answer>
  
  . DEFINICIONES .
  - Si = Puntuacion i
  - S = Número de puntuaciones
  - V = Valor a obtener

  . RECURSION .
   tirosMinimos(i, j) = mínimo número de tiros para obtener la puntuacion j tirar dardos a los sectores del 1 al i 
   (Infinito si no es posible) 

   tirosMinimos(i, j) = { tirosMinimos(i-1, j)                         Si > j
                        { min(tirosMinimos(i-1, j), (i, j-Si) + 1)     Si <= j

  . CASOS BASE .
   tirosMinimos(0, j) = Infinito
   tirosMinimos(i, 0) = 0
   tirosMinimos(0, 0) = 0
  
  . RESOLUCIÓN .
   Se utiliza la programación dinámica ascendente. Se va generando la tabla con S + 1 filas (la primera para i = 0 representando el conjunto vacio) y V + 1 columnas
   (puntuaciones de 0 a V). La posición [0][0] será 0 y la primera fila (exceptuando la primera posición) serán Infinito, tal y como dicen los casos base. A partir de ahí, 
   se recorre la matriz de arriba a abajo y de izquierda a derecha aplicando la función recursiva, de forma que la solución al problema quedará almacenado en la última posición 
   de la matriz, correspondiente al caso de disponer de los S sectores y tener que obtener la puntuacion V. Ahora bien, aunque podamos almacenar la tabla en una matriz, realmente
   para generar una fila sólo necesitamos el elemento superior [i-1][j] y el de esa misma fila [i][j-Si]. la anterior. Para cada posición, cuando nos desplacemos a la derecha no
   necesitaremos más el elemento superior, por lo que podemos mantener un único vector en el que se va cambiando la posición correspondiente a la j por la que vamos.

  . COSTE .
   El coste en tiempo de resolver el problema está en el orden O(S * V), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1)
   El coste en tiempo de reconstruir la solución está en el orden O(K), donde K = max(S, V), dado que en cada vuelta disminuimos una columna o una fila como mínimo 
   El coste en espacio está en el orden O(S), por el vector donde almacenamos la fila por la que vamos

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct solucion{
   EntInf min;
   vector<int> puntos;
};

solucion devolver_puntuaciones(vector<int> const& P, int S){
   EntInf minDardos;
   vector<int> puntos;
   int N = P.size();
   vector<EntInf> tirosMinimos(S+1, Infinito);

   tirosMinimos[0] = 0;
   for(int i = 1; i <= N; i++)
      for(int j = P[i-1]; j <= S; j++)
         tirosMinimos[j] = min(tirosMinimos[j], tirosMinimos[j - P[i-1]] + 1);
   minDardos = tirosMinimos[S];

   if(minDardos != Infinito){
      int i = N, j = S;
      while(j > 0){
         if(P[i-1] <= j && tirosMinimos[j] == tirosMinimos[j - P[i-1]] + 1){
            puntos.push_back(P[i-1]);
            j = j - P[i-1];
         }else
            i--;
      }
   }
   
   return {minDardos, puntos};
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int V; cin >> V;
   if (!std::cin)  // fin de la entrada
      return false;

   int S; cin >> S;
   vector<int> puntuaciones(S);
   for(int i = 0; i < S; i++)
      cin >> puntuaciones[i];

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   solucion sol = devolver_puntuaciones(puntuaciones, V);
   if(sol.min != Infinito){
      cout << sol.min <<":";
      for(int a : sol.puntos)
         cout <<' ' << a;
   }else
      cout << "Imposible";
   cout << "\n";

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
