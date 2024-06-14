
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <functional> // for greater
#include <algorithm>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct trabajo{
  int ini, fin;
};

bool operator<(const trabajo &a, const trabajo &b){
  return a.ini < b.ini;
}

pair<int, bool> voraz(vector<trabajo> & v, int C, int F){
  sort(v.begin(), v.end());
  int trabajos = 0, i = 0, ultimo = C;
  bool imposible = false;

  while(!imposible && ultimo < F){
    int mejorFin = -1;
    while(i < v.size() && v[i].ini <= ultimo){
      if(v[i].fin > mejorFin)
        mejorFin = v[i].fin;
      i++;
    }

    if(mejorFin != -1){
      trabajos++;
      ultimo = mejorFin;
    }else
      imposible = true;
  }

  return {trabajos, imposible};
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int C, F, N; cin >> C >> F >> N;
  if (C == 0 && F == 0 && N == 0)
    return false;
  

  vector<trabajo> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i].ini >> v[i].fin;
  }

  pair<int, bool> sol = voraz(v, C, F);

  if(sol.second)
    cout << "IMPOSIBLE";
  else 
    cout << sol.first;

  cout << '\n';
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
