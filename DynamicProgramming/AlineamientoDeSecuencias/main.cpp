
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
  
  DEFICIONES
  a: matriz de sustitucion 
  u: cadena 1
  v: cadena 2
  N: tamaño de la cadena 1
  M: tamaño de la cadena 2

  RECURSION
  maximaPuntuacion(i, j): Puntuacion máxima con los caracteres disponibles del 1 al i de la cadena u y 
  del 1 al j de la cadena v.

  maximaPuntuacion(i, j): max{a[ui, -] + maximaPuntuacion(i-1, j),
                              a[-, vj] + maximaPuntuacion(i, j-1),
                              a[ui, vj] + maximaPuntuacion(i-1, j-1)}


  CASOS BASE
  maximaPuntuacion(0, 0) = 0
  maximaPuntuacion(0, j) = a[-,vj] + maximaPuntuacion(0, j-1)
  maximaPuntuacion(i, 0) = a[ui,-] + maximaPuntuacion(i-1, 0)

  RESOLUCION
  Se utiliza programación dinámica ascendente. Se va rellenando la matriz de N+1 filas y M+1 columnas de arriba a abajo y de izquierda a derecha. La primera fila corresponde al caso
  en el que la cadena u está vacía y la primera columna corresponde al caso en el que la cadena v está vacía, por los casos base. Se aplica la funcion recursiva que busca el maximo entre 
  3 opciones: 
  1) Dejar colocados los caracteres u_i y v_j, y sumarle la maxima puntuacion hasta sus caracteres anteriores (+ maximaPuntuacion(i-1, j-1))
  2) Dejar colocado el caracter u_i y un hueco, y sumarle la maxima puntuacion hasta el caracter anterior al u_i colocado y v_j (+ maximaPuntuacion(i-1, j))
  2) Dejar un hueco y el caracter v_j colocado, y sumarle la maxima puntuacion hasta u_i y el caracter anterior al v_j colocado (+ maximaPuntuacion(i, j-1))
  Podemos reducir el espacio a un único vector que se va rellenando de izquierda a derecha

  COSTE
  El coste en tiempo está en el orden O(N * M), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1)
  El coste en espacio está en el orden O(M), por el vector donde guardamos las soluciones de los subproblemas 
 
 @ </answer> */

int convert(char a){
   int index; 

   switch(a){
      case 'A':
         index = 0; 
         break;
      case 'C':
         index = 1;
         break;
      case 'G':
         index = 2;
         break;
      case 'T':
         index = 3;
         break;
      case '-':
         index = 4;
         break;
   }

   return index;
}

int progDinamica(const Matriz<int> &a, const string &u, const string &v){
   int N = u.size(); 
   int M = v.size();

   vector<int> sol(M+1, 0);
   for(int j = 1; j <= M; j++)
      sol[j] = a[4][convert(v[j-1])] + sol[j-1];


   for(int i = 1; i <= N; i++){
      int prevDiagonal = sol[0];
      sol[0] += a[convert(u[i-1])][4];
      for(int j = 1; j <= M; j++){
         int temp = sol[j];
         int t1 = a[convert(u[i-1])][4] + sol[j];
         int t2 = a[4][convert(v[j-1])] + sol[j-1];
         int t3 = a[convert(u[i-1])][convert(v[j-1])] + prevDiagonal;
         t1 = max(t1, t2);
         sol[j] = max(t1, t3);
         prevDiagonal = temp;
      }
   }

   return sol[M];
}

void resuelveCaso() {
  // leer los datos de la entrada
  Matriz<int> m(5, 5);

  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
        cin >> m[i][j];

  int P; cin >> P;

  string u, v; 
  for(int i = 0; i < P; i++){
    cin >> u >> v;
    cout << progDinamica(m, u, v) << '\n';
  }
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
