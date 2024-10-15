
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Amigos{
  private:
    vector<bool> visit; 
    int maximo = 0;

  int dfs(Grafo const& G, int v) {
    visit[v] = true;
    int cont = 1;
    for (int w : G.ady(v)) {
      if (!visit[w]) {
        cont += dfs(G, w);
      }
    }
    return cont;
  }
  public:
    Amigos(const Grafo &ciudad) : visit(ciudad.V(), false){
      for(int i = 0; i < ciudad.V(); i++){
        if(!visit[i]){
          int tam = dfs(ciudad, i);
          maximo = max(maximo, tam);
        }
      }
    }

    int maximoIntegrantes(){
      return maximo;
    }
};


void resuelveCaso() {
  
  // leer los datos de la entrada
  Grafo ciudad(cin, 1);
  
  // resolver el caso posiblemente llamando a otras funciones
  Amigos grupoMasGrande(ciudad);

  // escribir la solución
  cout << grupoMasGrande.maximoIntegrantes() << '\n';
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
    system("PAUSE");
  #endif
  return 0;
}
