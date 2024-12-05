
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
  - N = Longitud la palabra
  - Li = Letra i de la palabra

  RECURSIÓN
  minimoLetras(i, j) = número minimo de letras que hay que añadir para que palabra[i, j] sea un palíndromo

  minimoLetras(i, j) =  {minimoLetras(i+1, j-1)                                 si Li == Lj
                        {min(minimoLetras(i+1, j) , minimoLetras(i, j-1)) + 1   si Li != Lj

  Llamada inicial: minimoLetras(0, N-1)

  CASOS BASE
  minimoLetras(i, j) = 0 si i >= j

  RESOLUCIÓN
  Se utiliza la programación dinámica ascendente. Se va generando la tabla con N filas y N columnas. La diagonal 
  principal y todas las posiciones que quedan por debajo de ellas son 0, por cumplir i >= j. Por tanto, sólo se 
  rellena la mitad (diagonal) superior de abajo a arriba y de izquierda a derecha, aplicando la función recursiva. 
  Así, la solución del problema quedará almacenada en la posición superior derecha de la matriz, correspondiente a caso
  en que tenemos la palabra original completa (i = 0, j = N - 1). Como tenemos que reconstruir la solución no
  podemos reducir el espacio.

  COSTE
  - El coste en tiempo está en el orden O(N^2/2) = O(n^2), porque recorremos "toda" la matriz y sobre cada 
  elemento realizamos operaciones de coste O(1)
  - El coste en tiempo de reconstruir la solución está en el orden O(N), dado que en cada vuelta disminuimos 
  una columna o una fila como mínimo
  - El coste en espacio está en el orden O(N^2), por la matriz donde guardamos las soluciones de los subproblemas.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int progDinamica(int i, int j, string const& palabra, Matriz<int> &m){
  int &res = m[i][j];
  if(res == -1){
    if(i >= j) res = 0;
    else if(palabra[i] == palabra[j])
      res = progDinamica(i+1, j-1, palabra, m);
    else
      res = min(progDinamica(i+1, j, palabra, m), progDinamica(i, j-1, palabra, m)) + 1;
  }
  return res;
}

void reconstruir(string const& palabra, Matriz<int> const& m, int i, int j, string & sol){
  if(i > j) return;
  if(i == j) sol.push_back(palabra[i]);
  else if(palabra[i] == palabra[j]){
    sol.push_back(palabra[i]);
    reconstruir(palabra, m, i+1, j-1, sol);
    sol.push_back(palabra[j]);
  }else if(m[i][j] == (m[i+1][j] + 1)){
    sol.push_back(palabra[i]);
    reconstruir(palabra, m, i+1, j, sol);
    sol.push_back(palabra[i]);
  }else{
    sol.push_back(palabra[j]);
    reconstruir(palabra, m, i, j-1, sol);
    sol.push_back(palabra[j]);
  }  
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  string palabra; cin >> palabra;
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int N = palabra.size();
  Matriz<int> m(N, N, -1);
  cout << progDinamica(0, N-1, palabra, m) << ' ';

  string sol;
  reconstruir(palabra, m, 0, N-1, sol);
  cout << sol << '\n';

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
