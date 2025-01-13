
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
  
  DEFINICIONES
  N = número de tipos de moneda
  Mi = valor de la moneda de tipo i
  Ci = cantidad disponible de monedas de tipo i
  P = precio del coche

  RECURSION 
  monedasMinimas(i, j) = minimo numero de monedas con las que podemos pagar la cantidad j si tenemos disponibles los tipos
  de moneda del 1 al i (Infinito si no se puede)
  
  monedasMinimas(i, j) = min[0<= k <= Ci_k * Vi <= j](monedasMinimas(i-1, j-Vi*k) + k)

  CASO BASE
  monedasMinimas(0, j) = Infinito
  monedasMinimas(i, 0) = 0

  RESOLUCION
  Se utiliza programación dinámica ascendente. Se va rellenando la matriz de N+1 filas(se añade la fila 0 para el conjunto vacio) y P+1  columnas (precio a pagar desde 0 a P)
  de arriba a abjo y de derecha a izquierda. La primera columna será 0 y la primera fila Infinito (excepto la primera posición), por los casos base, y a partir de ahí basta 
  aplicar la función recursiva. La solución quedará alamacenada en la posición [N][P] de la matriz, correspondiente al caso en que contamos con todas las monedas y queda por 
  pagar el precio total del coche. Para una posición sólo necesitamos posiciones de la fila superior (y en columnas <= j), por lo que podemos reducir el espacio a un único 
  vector que se va rellenando de derecha a izquierda. 

  COSTE
  El coste en tiempo está en el orden O(N * P), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1)
  El coste en espacio está en el orden O(P), por el vector donde guardamos las soluciones de los subproblemas
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct moneda{
  int valor;
  int cantidad;
};

EntInf monedasMinimas(const vector<moneda> &monedas, int P){
  int N = monedas.size();
  vector<EntInf> solucion(P + 1, Infinito);
  solucion[0] = 0;

  for(int i = 1; i <= N; i++){
    for(int j = P; j > 0; j--){
      for(int k = 0; k <= monedas[i - 1].cantidad && k * monedas[i-1].valor <= j; k++){
        EntInf temp = solucion[j - k * monedas[i-1].valor] + k;
        solucion[j] = min(solucion[j], temp);
      } 
    }
  }

  return solucion[P];
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<moneda> monedas(N);
  for(int i = 0; i < N; i++)
    cin >> monedas[i].valor;

  for(int i = 0; i < N; i++)
    cin >> monedas[i].cantidad;
  
  int P; cin >> P;
  EntInf sol = monedasMinimas(monedas, P);
  if(sol == Infinito)
    cout << "NO";
  else
    cout << "SI " << sol;
  
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
