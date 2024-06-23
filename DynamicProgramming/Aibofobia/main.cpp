
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

DEFINICION
------------ 
palidromo(i, j) = numero minimo de letras que hay que añadir para que la palabra [i,j] sea un palindromo

RECURSION
----------

palindromo(i, j) = {  palindromo(i+1, j-1)                              si pal[i] == pal[j]
                   {  min(palindromo(i+1, j), palindromo(i, j-1)) + 1   si pal[i] != pal[j];      

CASO BASE:
palindromo(i, j) = 0      si i >= j

 @ </answer> */
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
using matriz = vector<vector<int>>;

struct solucion {
  int letras;
  string palindromo;
};

string reconstruir(const string& palabra, matriz& M, int i, int j){
  if(i > j) return {};
  if(i == j) return {palabra[i]};
  if(palabra[i] == palabra[j])
    return palabra[i] + reconstruir(palabra, M, i+1, j-1) + palabra[j];
  else if (M[i][j] - 1 == M[i][j - 1])
    return palabra[j] + reconstruir(palabra, M, i, j -1) + palabra[j];
  else  
    return palabra[i] + reconstruir(palabra, M, i+1, j) + palabra[i];
}

int pal(const string& palabra, matriz& M, int i, int j){
  int & res = M[i][j];
  int N = palabra.size();

  if(res == -1){
    if(i > j) res = 0;
    else if (i == j) res = 0;
    else if(palabra[i] == palabra[j])
      res = pal(palabra, M, i+1, j-1);
    else  
      res = min(pal(palabra, M, i+1, j), pal(palabra, M, i, j-1)) + 1;
  }

  return res;
}

solucion progDinamica(string palabra){
  int N = palabra.size();
  matriz M(N, vector<int>(N, -1));
  int minLetras = pal(palabra, M, 0, N-1);
  string pal = palabra;
  if(minLetras != 0)
    pal = reconstruir(palabra, M, 0, N-1);
  return {minLetras, pal};
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  string palabra; cin >> palabra;
  if (!std::cin)  // fin de la entrada
    return false;
  
  solucion sol = progDinamica(palabra);
  cout << sol.letras <<' ' << sol.palindromo <<'\n';

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
#endif
   return 0;
}
