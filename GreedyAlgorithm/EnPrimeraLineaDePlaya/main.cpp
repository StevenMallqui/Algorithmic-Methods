
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

struct edificio{
  int ini, fin;
};

bool operator<(edificio const&a, edificio const&b){
  return a.fin < b.fin;
}

int voraz(vector<edificio> &v){
  sort(v.begin(), v.end());
  int pasadizos = v.size(), i = 1;
  int ultimo = v[0].fin;

  while(i < v.size()){
    if(v[i].ini < ultimo)
      pasadizos--;
    else
      ultimo = v[i].fin;
    i++;
  }

  return pasadizos;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  vector<edificio> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i].ini >> v[i].fin;
  }

  cout << voraz(v) <<'\n';
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
