
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

recuperar(i, j) = maximo valor de oro que podemos recuperar con un tiempo j 
                  de bombona considerando los tesoros del 1 al i


recuperar(i, j) = { recuperar(i-1, j)         si pi > j
                  { max(recuperar(i-1, j), recuperar(i-1, j-pi)+Vi)  pi <= j
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct solucion{
   int maxOro = 0;
   int cofres = 0;
   vector<pair<int, int>> info;
};

using matriz = vector<vector<int>>;

int oro_rec(const vector<pair<int, int>>& cofres, int i, int j, matriz& oro){
   if(oro[i][j] != -1)
      return oro[i][j];
   else if(i == 0 || j == 0){
      oro[i][j] = 0;
      return oro[i][j];
   }else{
      if((3 * cofres[i-1].first) > j)
         oro[i][j] = oro_rec(cofres, i-1, j, oro);
      else 
         oro[i][j] = max(oro_rec(cofres, i-1, j, oro),
                        oro_rec(cofres, i-1, j - (cofres[i-1].first * 3), oro) + cofres[i-1].second);
   }
   return oro[i][j];
}


solucion progDinamica(const vector<pair<int, int>>& cofres, const int T, const int N){
   matriz oro(N+1, vector<int>(T+1, -1));
   solucion sol;
   sol.maxOro = oro_rec(cofres, N, T, oro); 

   int i = N, j = T;
   while(i > 0 && j > 0){
      if(oro[i][j] != oro[i-1][j]){
         sol.info.push_back(cofres[i-1]);
         j -= (cofres[i-1].first * 3);
         sol.cofres++;
      }
      i--;
   }
   return sol;
}


bool resuelveCaso() {

   int T; cin >> T;
   if (!std::cin)
      return false;
   int N; cin >> N;

   vector<pair<int, int>> cofres(N);
   for(int i = 0; i < N; i++){
      cin >> cofres[i].first >> cofres[i].second;
   }

   solucion sol = progDinamica(cofres, T, N);
   cout << sol.maxOro << '\n';
   cout << sol.cofres << '\n';
   for(int i = sol.cofres-1; i >= 0; i--)
      cout << sol.info[i].first <<' ' << sol.info[i].second <<'\n';

   cout <<"---\n";
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
