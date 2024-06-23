
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

using ciudad = vector<vector<char>>;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int interAnterior(const int j, const vector<int>& sol){
   if(j < 0)
      return 0;
   else
      return sol[j];
}

int progDinamica(const ciudad& c, const int N, const int M){
   vector<int> sol(M, 0);
   sol[0] = 1;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         if(c[i][j] == 'X')
            sol[j] = 0;
         else{
            sol[j] += interAnterior(j-1, sol);
         }
      }
   }

   return sol[M-1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;

   int M; cin >> M;
   ciudad cuadracity(N, vector<char>(M)); 
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         cin >> cuadracity[i][j];
      }
   }

   cout << progDinamica(cuadracity, N, M) << '\n';
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
