
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

class carreteras
{
private:
  bool conexo;
  int tiempo;


  void kruskal(GrafoValorado<int> const& g){
    PriorityQueue<Arista<int>> pq(g.aristas());
    ConjuntosDisjuntos cjtos(g.V());
    int cont = 0;
    while (!pq.empty()) {
      auto a = pq.top(); pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (!cjtos.unidos(v,w)) {
        cjtos.unir(v, w);
        if(a.valor() > tiempo)
          tiempo = a.valor();
        cont++;
        if (cont == g.V() - 1) break;
      }
    }

    if(cjtos.num_cjtos() == 1)
      conexo = true;
  }

public:
  carreteras(const GrafoValorado<int>& pueblos): conexo(false), tiempo(0){
    kruskal(pueblos);
  }

  bool conectados(){
    return conexo;
  }

  int tiempoMinimo(){
    return tiempo;
  }
};

void resuelveCaso() {
  int N, M; cin >> N >> M;
  GrafoValorado<int> pueblos(N);
  int origen, destino, tiempo;
  for(int i = 0; i < M; i++){
    cin >> origen >> destino >> tiempo;
    pueblos.ponArista({origen - 1, destino - 1, tiempo});
  }

  carreteras sol(pueblos);
  if(sol.conectados())
    cout << sol.tiempoMinimo();
  else
    cout << "Imposible";
  
  cout <<'\n';
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
#endif
   return 0;
}
