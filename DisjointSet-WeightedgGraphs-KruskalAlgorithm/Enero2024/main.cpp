
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


class Trajano{

private: 
  vector<Arista<int>> _ARM;
  ConjuntosDisjuntos cjtos;
  int maximo;
  bool camino;

  void kruskal(GrafoValorado<int> const& g, const int origen, const int destino){
    PriorityQueue<Arista<int>> pq(g.aristas());
    while (!pq.empty()) {
      auto a = pq.top(); pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (!cjtos.unidos(v,w)) {
        cjtos.unir(v, w);
        _ARM.push_back(a);

        if(cjtos.unidos(origen, destino)){
          camino = true;
          break;
        }
        if (_ARM.size() == g.V() - 1) break;
      }
    }
    if(cjtos.unidos(origen, destino))
      camino = true;
  }

public: 
  Trajano(const GrafoValorado<int>& mina, const int origen, const int destino): maximo(0), camino(false), cjtos(mina.V()){
    kruskal(mina, origen, destino);
    if(hayCamino()){
      bool end = false;
      for(int i = _ARM.size()-1; i >= 0 && !end; i--){
        if(cjtos.unidos(_ARM[i].uno(), destino)){
          maximo = _ARM[i].valor();
          end = true;
        }
      }
    }
  }

  bool hayCamino(){
    return camino;
  }

  int tiempoMaximo(){
    return maximo;
  }

};

bool resuelveCaso() {
  
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int M; cin >> M; 
  GrafoValorado<int> mina(N);
  int origen, destino, coste;
  for(int i = 0; i < M; i++){
    cin >> origen >> destino >> coste;
    mina.ponArista({origen - 1, destino - 1, coste});
  }

  cin >> origen >> destino;
  Trajano t(mina, origen - 1, destino - 1);
  if(t.hayCamino())
    cout << t.tiempoMaximo();
  else
    cout << "IMPOSIBLE";

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
