
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
   - N : Número de cubos
   - Ci : Cantidad de comida en el cubo i

   RECURSIÓN
   maximaComida(i, j) = Máxima cantidad de comida que puede comer la vaca si están disponibles los cubos que van de i a j
   siendo estos los extremos

   maximaComida(i, j) = max(Ci + { maximaComida(i+2, j)      si Ci + 1 > Cj
                                 { maximaComida(i+1, j-1)    si Ci + 1 < Cj,
                           Cj + { maximaComida(i, j-2)      si Cj - 1 > Ci
                                 { maximaComida(i+1, j-1)    si Cj - 1 < Ci

   CASOS BASE

   maximaComida(i, i) = Ci;
   maximaComida(i, j) = 0 si i > j

   Llamada inicial: maximaComida(0, N-1)

   RESOLUCIÓN
   Se utiliza la programación dinámica ascendente. Se va generando la tabla con N filas y N columnas. La diagonal principal
   será igual a Ci, como indica el primer caso base, y todas las posiciones que quedan por debajo de ella son 0, por cumplir
   i > j. Por tanto, sólo se rellena la mitad (diagonal) superior de abajo a arriba y de izquierda a derecha, aplicando la 
   función recursiva. Así, la solución del problema quedará almacenada en la posición superior derecha de la matriz, correspondiente
   al caso en que tenemos todos los cubos (i = 0, j = N -1).

   COSTE
   - El coste en tiempo está en el orden O(N^2/2) = O(N^2), porque recorremos "toda" la matriz y sobre cada elemento
   realizamos operaciones de coste O(1)
   - El coste en espacio está en el orden O(N^2), por la matriz donde guardamos las soluciones de los subproblemas

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int progDinamica(int N, vector<int> &cubos){
   Matriz<int> m(N, N, 0);
   for(int i = 0; i < N; i++)
      m[i][i] = cubos[i];
   
   int sol_i, sol_j;
   for(int i = N-2; i >= 0; i--){
      for(int j = i + 1; j < N; j++){
         if(cubos[i+1] > cubos[j])
            sol_i = m[i+2][j];
         else
            sol_i = m[i+1][j-1];

         if(cubos[j-1] > cubos[i])
            sol_j = m[i][j-2];
         else
            sol_j = m[i+1][j-1];

         m[i][j] = max(sol_i + cubos[i], sol_j + cubos[j]);
      }
   }

   return m[0][N-1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;
   if (N == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   vector<int> cubos(N);
   for(int i = 0; i < N; i++)
      cin >> cubos[i];

   cout << progDinamica(N, cubos) << '\n';

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
