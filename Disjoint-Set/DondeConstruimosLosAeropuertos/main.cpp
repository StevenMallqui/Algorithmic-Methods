
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Transporte {

private:
  int coste;
  int numAeropuertos;
  int costeAeropuerto;

  int kruskal(GrafoValorado<int> const& g){
    int puentes = 0;
    PriorityQueue<Arista<int>> pq(g.aristas());
    ConjuntosDisjuntos cjtos(g.V());
    while (!pq.empty()) {
      auto a = pq.top(); pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (a.valor() < costeAeropuerto && !cjtos.unidos(v,w)) {
        cjtos.unir(v, w);
        coste += a.valor();
        puentes++;
        if (puentes == g.V() - 1) break;
      }
    }

    return cjtos.num_cjtos();
  }

public:
  Transporte(GrafoValorado<int> const& g, int A): coste(0), costeAeropuerto(A){
    numAeropuertos = kruskal(g);
    coste += numAeropuertos * A;
  }

  int costeTotal() const {
    return coste;
  }

  int aeropuertos(){
    return numAeropuertos;
  }

};


bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int M, A, elem; cin >> M >> A; 

  GrafoValorado<int> region(N);
  int origen, destino, coste;
  for(int i = 0; i < M; i++){
    cin >> origen >> destino >> coste;
    region.ponArista({origen - 1, destino - 1, coste});
  }

  Transporte t(region, A);
  cout << t.costeTotal() <<" " << t.aeropuertos() <<'\n';

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
