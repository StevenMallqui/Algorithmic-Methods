
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct canal{
  int id; 
  int tiempo;
};

bool operator<(const canal &a, const canal &b){
  return b.tiempo < a.tiempo || (a.tiempo == b.tiempo && a.id < b.id);
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int D; cin >> D;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int C, N; cin >> C >> N;
  
  IndexPQ<int, canal> masVistos;
  vector<int> tiemposAcumulados(C + 1, 0); 
  IndexPQ<int, int, greater<int>> televidentes;

  int e, m, c;
  for(int i = 0; i < C; i++){
    cin >> e;
    televidentes.push(i + 1, e);
  }

  int anterior = 0, actual;
  for(int i = 0; i < N; i++){
    cin >> m;
    actual = m - anterior;

    auto topTelevidentes = televidentes.top();
    tiemposAcumulados[topTelevidentes.elem] += actual;
    masVistos.update(topTelevidentes.elem, {topTelevidentes.elem, tiemposAcumulados[topTelevidentes.elem]});
    
    anterior = m;

    while (cin >> c && c != -1) {
      int e;
      cin >> e;
      televidentes.update(c, e);
    }
  }

  actual = D - anterior;
  auto topTelevidentes = televidentes.top();
  tiemposAcumulados[topTelevidentes.elem] += actual;
  masVistos.update(topTelevidentes.elem, {topTelevidentes.elem, tiemposAcumulados[topTelevidentes.elem]});


  while (!masVistos.empty()) {
      auto top = masVistos.top();
      cout << top.elem << ' ' << top.prioridad.tiempo << '\n';
      masVistos.pop();
  }

  cout << "---\n";

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
