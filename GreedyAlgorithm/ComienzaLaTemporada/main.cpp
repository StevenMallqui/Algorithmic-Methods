
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

int voraz(vector<int> alumnos, vector<int> equipaciones){
  sort(alumnos.begin(), alumnos.end());
  sort(equipaciones.begin(), equipaciones.end());
  
  int comprar = alumnos.size();
  int i = 0, o = 0;
  while(o < equipaciones.size() && i < alumnos.size()){
    if(equipaciones[o] == alumnos[i] || equipaciones[o] - alumnos[i] == 1){
      comprar--;
      i++;
      o++;
    }else if(equipaciones[o] > alumnos[i]){
      i++;
    }else if(equipaciones[o] < alumnos[i]){
      o++;
    }
  }

  return comprar;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int M, elem; cin >> M;
  vector<int> alumnos(N), equipaciones(M);

  for(int i = 0; i < N; i++){
    cin >> elem;
    alumnos[i] = elem;
  }

  for(int i = 0; i < M; i++){
    cin >> elem;
    equipaciones[i] = elem;
  }
  
  cout << voraz(alumnos, equipaciones) <<'\n';

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
