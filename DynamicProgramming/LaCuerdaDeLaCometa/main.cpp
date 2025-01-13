/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"

/*@ <answer>
  
  DEFINICIONES
  - Li = longitud del cordel i
  - N = Número de cordeles
  - L = Longitud de la cuerda a formar
  - Ci = precio del cordel i

---- PROBLEMA MATEMÁTICO ----
  
  . RECURSION .
  maneras(i, j) = cuantas maneras hay de conseguir la cuerda con longitud j pudiendo usar los 
  cordeles del 1 al i

  maneras(i, j) = { maneras(i-1, j)                       si Li > j
                  { maneras(i-1, j) + maneras(i-1, j-Li)  si Li <= j
 
  . CASO BASE .
  maneras(0, j) = 0
  maneras(i, 0) = 1
  maneras(0, 0) = 1 

  . RESOLUCIÓN .
  Se utiliza la programación dinámica descendente, de manera que se guarda en una matriz la solución a los 
  subproblemas que se van resolviendo, dado que en la recursión se calculan varias veces de forma innecesaria. 
  Nótese que la matriz es de tamaño N+1, L+1. Por un lado, las columnas van de 0 a L. Por otro, en la matriz
  se numeran los cordeles de 1 a N, como en la definicion recursiva anterior, y se añade la fila 0 para indicar
  el conjunto vacío de cordeles. Por eso para el subproblema maneras(i-1, j) accedemos a la posición [i-1+1=i][j]
  de la matriz. Además, los casos base se ponen como i = -1 porque los cordeles están numerados de 0 a N-1.

  . COSTE . 
  El coste en tiempo está en el orden O(N * L), porque N * L es el número de llamadas distintas que se pueden
  hacer (realmente se harán muchas menos), y cada una se invoca a lo sumo 2 veces, pero la segunda no genera 
  más trabajo (ya se habrá guardado el resultado en la matriz)
  El coste en espacio está en el orden O(N * L), por la matriz donde se guardan las soluciones

---- PROBLEMA INGENIERO ----

   . RECURSION .
   cordelesMinimos(i, j) = mínimo número de cordeles para formar la cuerda de longitud j pudiendo usar los 
   cordeles del 1 al i (Infinito si no es posible)

   cordelesMinimos(i, j) = { cordelesMinimos(i-1, j)                                       si Li > j
                           { min(cordelesMinimos(i-1, j), cordelesMinimos(i-1, j-Li) + 1)  si Li <= j

   . CASO BASE .
   cordelesMinimos(0, j) =  Infinito
   cordelesMinimos(i, 0) = 0
   cordelesMinimos(0, 0) = 0

   . RESOLUCIÓN .
   Misma explicación que para resolver el problema del matemático.
   
   . COSTE .
   Mismo coste y justificación que para resolver el problema del matemático.

---- PROBLEMA ECONOMISTA ----

   . RECURSION .
   costeMinimo(i, j) = mínimo coste para formar la cuerda de longitud j pudiendo usar los cordeles del 1 al i
   (Infinito si no es posible)

   costeMinimo(i, j) = { costeMinimo(i-1, j)  }                                  si Li > j
                       { min(costeMinimo(i-1, j), costeMinimo(i-1, j-Li) + Ci)   si Li <= j

   . CASO BASE .
   costeMinimo(0, j) = Infinito
   costeMinimo(i, 0) = 0
   costeMinimo(0, 0) = 0

   . RESOLUCIÓN .
   Misma explicación que para resolver el problema del matemático y el ingeniero

   . COSTE .
   Mismo coste y justificación que para resolver el problema del matemático y el ingeniero

 @ </answer> */


struct cordel {
   int longitud;
   int coste;
};

struct solucion {
   long long int nManeras;
   EntInf minCordeles;
   EntInf minCoste;
};

long long int maneras(int L, vector<cordel> const& cordeles) {
   int N = cordeles.size();
   vector<long long int> maneras(L + 1, 0);
   maneras[0] = 1;
   for (int i = 1; i <= N; ++i)
      for (int j = L; j >= cordeles[i - 1].longitud; --j)
         maneras[j] = maneras[j] + maneras[j - cordeles[i - 1].longitud];
   return maneras[L];
}

EntInf cordelesMinimos(int L, vector<cordel> const& cordeles) {
   int N = cordeles.size();
   vector<EntInf> cordelesMinimos(L + 1, Infinito);
   cordelesMinimos[0] = 0;
   for (int i = 1; i <= N; ++i)
      for (int j = L; j >= cordeles[i - 1].longitud; --j)
         cordelesMinimos[j] = min(cordelesMinimos[j], cordelesMinimos[j - cordeles[i - 1].longitud] + 1);
   return cordelesMinimos[L];
}

EntInf costeMinimo(int L, vector<cordel> const& cordeles) {
   int N = cordeles.size();
   vector<EntInf> costeMinimo(L + 1, Infinito);
   costeMinimo[0] = 0;
   for (int i = 1; i <= N; ++i)
      for (int j = L; j >= cordeles[i - 1].longitud; --j)
         costeMinimo[j] = min(costeMinimo[j], costeMinimo[j - cordeles[i - 1].longitud] + cordeles[i - 1].coste);
   return costeMinimo[L];
}

solucion progDinamica(int L, vector<cordel> const& cordeles) {
   long long int nManeras = maneras(L, cordeles);
   EntInf minCordeles = -1, minCoste = -1;
   if (nManeras != 0) { // si no se puede formar la cuerda no hace falta calcular lo demás
      minCordeles = cordelesMinimos(L, cordeles);
      minCoste = costeMinimo(L, cordeles);
   }
   return { nManeras,minCordeles,minCoste };
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   int L; cin >> L;
   vector<cordel> cordeles(N);
   int longitud, coste;
   for (int i = 0; i < N; ++i) {
      cin >> longitud >> coste;
      cordeles[i] = { longitud,coste };
   }

   // resolver el caso posiblemente llamando a otras funciones
   solucion sol = progDinamica(L, cordeles);

   // escribir la solución
   if (sol.nManeras != 0) cout << "SI " << sol.nManeras << ' ' << sol.minCordeles << ' ' << sol.minCoste;
   else cout << "NO";
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