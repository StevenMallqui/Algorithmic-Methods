/*@ *
* Nombre, apellidos y usuario del juez (TAISXXX) de los autores de la solución.
*
*@ */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Matriz.h"


using namespace std;

/*@ DEFINICIONES
- N: Número de canciones Lista 1
- M: Número de canciones Lista 2
- L1i : Cancion i de la Lista 1
- L2i : Cancion i de la Lista 2

RECURSION
lista(i, j) = longitud maxima de la lista de reproduccion

lista(i, j) = { 1 + lista(i-1, j-1)                 si L1[i] == L2[j]
              { max(lista(i-1, j), lista(i, j-1))   si L1[i] != L2[j]

CASOS BASES

lista(0, j) = 0
lista(i, 0) = 0

RECURSIÓN
Se utiliza la programación dinámica descendente. Se va generando la matriz con N+1 filas y  M+1 columnas. 
Por un lado, las columnas van de 0 a M. Por otro, las filas de 0 a M. Como tenemos que reconstruir la solución 
no podemos reducir el espacio. La solución quedará almacenada en la última posición de la última fila.

COSTE
- El coste en tiempo está en el orden O(N*M), porque N*M es el número de subproblemas que puede haber, y cada 
problema se resuelve a lo sumo 2 veces, y la segunda llamada no supone más trabajo.
- El coste en espacio está en el orden O(N*M), por la matriz donde guardamos las soluciones a los subproblemas. 

@ */

void reconstruir(vector<string> const &l1, vector<string> const &l2, Matriz<int> const &m, int i, int j, vector<string> & sol){
  if(i == 0 || j == 0) return;
  if(l1[i-1] == l2[j-1]){
    sol.push_back(l1[i-1]);
    reconstruir(l1, l2, m, i-1, j-1, sol);
  }else if(m[i][j] == m[i-1][j]){
    reconstruir(l1, l2, m, i-1, j, sol);
  }else
    reconstruir(l1, l2, m, i, j-1, sol);
}

int progDinamica(int i, int j, vector<string> const& l1, vector<string> const& l2, Matriz<int> &m) {
  int &res = m[i][j];
  if(res == -1){
    if(i == 0 || j == 0) res = 0;
    else if(l1[i-1] == l2[j-1])
      res = progDinamica(i-1, j-1, l1, l2, m) + 1;
    else
      res = max(progDinamica(i-1, j, l1, l2, m), progDinamica(i, j-1, l1, l2, m));
  }

  return res;
}

bool resuelveCaso() {
  // leer los datos de la entrada
  string input;
  getline(cin, input);
  if (!std::cin) // fin de la entrada
  return false;

  istringstream stream(input);
  string word;
  vector<string> lista1;
  while (stream >> word)
    lista1.push_back(word);

  getline(cin, input);
  istringstream stream2(input);
  vector<string> lista2;
  while (stream2 >> word)
    lista2.push_back(word);

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución

  int N = lista1.size(), M = lista2.size();
  Matriz<int> m(N+1, M+1, -1);

  int cont = progDinamica(N, M, lista1, lista2, m);
  if(cont != 0){
    vector<string> sol;
    reconstruir(lista1, lista2, m, N, M, sol);
    for(int i = sol.size(); i > 0; i--)
      cout << sol[i-1] << ' ';
  }

  cout << '\n';

  return true;
}

//@ // Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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