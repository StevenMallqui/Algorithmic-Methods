
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using matriz = vector<vector<int>>;

int conversor(int pos, string s){
  char a = s[pos];
  if(a == 'A')
    return 0;
  else if(a == 'C')
    return 1;
  else if(a == 'G')
    return 2;
  else if(a == 'T')
    return 3;
}

int progDinamica(const matriz& S, const string seq1, const string seq2){
  int m = seq1.size();
  int n = seq2.size();

  matriz puntuaciones(m+1, vector<int>(n+1, -1));

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      int ma = puntuaciones[i-1][j-1] + S[conversor(i-1, seq1)][conversor(j-1, seq2)];
      int de = puntuaciones[i-1][j] -1;
      int in = puntuaciones[i][j-1] -1;
      puntuaciones[i][j] = max({ma, de, in});
    }
  }

  return puntuaciones[m][n];
}

void resuelveCaso() {

  matriz S(5, vector<int>(5));
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> S[i][j];
    }
  }

  int pares; cin >> pares;
  for(int i = 0; i < pares; i++){
    string seq1, seq2;
    cin >> seq1 >> seq2;

    cout << progDinamica(S, seq1, seq2) <<'\n';
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
