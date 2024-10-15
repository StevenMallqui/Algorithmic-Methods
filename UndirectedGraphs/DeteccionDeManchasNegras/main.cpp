
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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Mapa = vector<string>;

class Manchas{
  private:
    int F, C;
    vector<vector<bool>>visit;
    int num;
    int maxim;

    const vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    bool esCorrecta(int i, int j) const {
      return 0 <= i && i < F && 0 <= j && j < C;
    }

    int dfs(const Mapa &bitmap, int i, int j){
      visit[i][j] = true;
      int tam = 1;
      for(auto d : dirs){
        int ni = i + d.first, nj = j + d.second;
        if(esCorrecta(ni, nj) && bitmap[ni][nj] == '#' && !visit[ni][nj])
          tam += dfs(bitmap, ni, nj);
      }
      return tam;
    }

  public:
    Manchas(const Mapa &bitmap): F(bitmap.size()), C(bitmap[0].size()), visit(F, vector<bool>(C, false)), num(0), maxim(0){
      for(int i = 0; i < F; i++){
        for(int j = 0; j < C; j++){
          if(!visit[i][j] && bitmap[i][j] == '#'){
            num++;
            int nuevoTam = dfs(bitmap, i, j);
            maxim = max(maxim, nuevoTam);
          }
        }
      }

    }

    int numero() const{
      return num;
    }

    int maximo() const{
      return maxim;
    }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int F; cin >> F;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int C; cin >> C;
  Mapa bitmap(F);

  for (string & linea : bitmap)
    cin >> linea;

  // resolver el caso posiblemente llamando a otras funciones
  Manchas manchas(bitmap);

  // escribir la solución
  cout << manchas.numero() <<' ' << manchas.maximo() << '\n';

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
