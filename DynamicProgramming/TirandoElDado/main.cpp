
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>
  
DEFINICIONES
  k: caras del dado 
  s: suma 

RECURSION
  formasDistintas(i, j): formas distintas de conseguir la suma j, teniendo disponibles las caras del 1 al i del dado.

  formasDistintas(i, j):formasDistintas(i-1, j)                               si j < i 
                        formasDistintas(i-1, j) + formasDistintas(i, j - Ki)  si j >= i 

CASOS BASE
  formasDistintas(i, 0): 1 
  formasDistintas(0, j): 0  si j > 0

RESOLUCION
  Se utiliza programación dinámica ascendente. Se va rellenando la matriz de k+1 filas y s+1 columnnas de arriba a abajo y de izquierda a derecha. La primera columna será 1 y la
  primera fila 0, por los casos base, y a partir de ahí basta aplicar la función recursiva. La solución quedará almacenada en la posicion [k][s] de la matriz, correspondiente al 
  caso en que contamos con k caras del dado para la suma s. Para una posición sólo necesitamos posiciones de la fila superior (y en columnas <= j), por lo que podemos reducir el 
  espacio a un único vector que se va rellenando de izquierda a derecha.

COSTE
  El coste en tiempo está en el orden O(k * s), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1)
  El coste en espacio está en el orden O(s), por el vector donde guardamos las soluciones de los subproblemas
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int progDinamica(const int k, const int s){
  vector<int> sol(s+1, 1);

  for(int i = 2; i <= k; i++){
    for(int j = i; j <= s; j++){
      sol[j] += sol[j-i];
    }
  }

  return sol[s];
}

void resuelveCaso() {
  
  // leer los datos de la entrada
  int k, s; cin >> k >> s;

  cout << progDinamica(k, s) << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
   return 0;
}
