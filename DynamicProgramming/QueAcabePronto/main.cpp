
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
  N: número de actividades
  Di : duración de la actividad i
  C : capacidad del aula 

  RECURSION
  minimaDuracion(i, j): minima duración del evento teniendo actividades del i al N-1 para un tiempo j

  minimaDuracion(i, j): max(minimaDuracion(i-1, j), minimaDuracion(i-1, j-Di) + Di)

  CASOS BASE
  minimaDuracion(0, j) = 0
  minimaDuracion(i, 0) = 0

  RESOLUCION
  Se utiliza programacion dinámica ascendente. Se va rellenando la matriz de N+1 fila y C + 1 de arriba a abajo y de derecha a izquierda. La primera columna será 0 y la primera
  fila 0, por los casos base, y a partir de ahí basta aplicar la función recursiva. La solución quedará almacenada en la posición [N][C] de la matriz. Para una posición sólo necesitamos
  posiciones de la fila superior (y en columnas <= j), por lo que podemos reducir el espacio a un único vector que se va rellando de derecha a izquierda.

  COSTE
  El coste en tiempo está en el orden O(N * C), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1)
  El coste en espacio está en el orden O(C), por el vector donde guardamos las soluciones de los subproblemas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int minimaDuracion(const vector<int> &actividades, const int duracionTotal){
  int N = actividades.size();
  int capacidad = duracionTotal/2;
  vector<int> sol(capacidad + 1, 0);

  for(int i = 0; i < N; i++)
    for(int j = capacidad; j >= actividades[i]; j--)
      sol[j] = max(sol[j], sol[j - actividades[i]] + actividades[i]);

  int aula1 = sol[capacidad];
  int aula2 = duracionTotal - aula1;

  return max(aula1, aula2);
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<int> actividades(N);
  int duracionTotal = 0;
  for(int i = 0; i < N; i++){
    cin >> actividades[i];
    duracionTotal += actividades[i];
  }

  cout << minimaDuracion(actividades, duracionTotal) << '\n';

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
