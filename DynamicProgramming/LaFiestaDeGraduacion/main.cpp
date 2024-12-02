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

@ */

vector<string> progDinamica(int M, vector<string> const& l1, vector<string> const& l2) {
  int N = l1.size();
  vector<int> canciones(M + 1, 0);

  for (int i = 1; i <= N; i++){
    int diag = 0;
    for (int j = 1; j <= M; j++){
      int nextDiag = canciones[j];
      if (l1[i-1] == l2[j-1])
        canciones[j] = 1 + diag;
      else
        canciones[j] = max(canciones[j], canciones[j-1]);
      diag = nextDiag;
    }
  }

  vector<string> resultado;
  int i = N, j = M;

  while (i > 0 && j > 0) {
    if (l1[i - 1] == l2[j - 1]) {
      resultado.push_back(l1[i - 1]); 
      --i;
      --j;
    } else if (canciones[j] == canciones[j - 1])
      --j; 
    else
      --i; 
  }

  reverse(resultado.begin(), resultado.end());
  return resultado;
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

  vector<string> sol = progDinamica(lista2.size(), lista1, lista2);
  for (string a : sol)
    cout << a << ' ';
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