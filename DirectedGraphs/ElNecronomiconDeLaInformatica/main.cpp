
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Necronomicon{
  public:
    Necronomicon(Digrafo const& g) : visit(g.V(),false), apilado(g.V(),false), hayciclo(false), alcanzable(false) {
          dfs(g, 0, g.V() - 1);
    }
    bool hayCiclo() { return hayciclo; }
    bool termina() { return alcanzable; } 
  private:
    std::vector<bool> visit; 
    std::vector<bool> apilado; 
    bool hayciclo;
    bool alcanzable;

    void dfs(Digrafo const& g, int v, int destino) {
      apilado[v] = true;
      visit[v] = true;
      for (int w : g.ady(v)) {
        if (w == destino)
          alcanzable = true;
        else if (apilado[w])
          hayciclo = true;
        else if (!visit[w]) 
          dfs(g, w, destino);
      }
      apilado[v] = false;
    }
};

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  Digrafo dg(N + 1);
  for(int i = 0; i < N; i++){
    char opcion; cin >> opcion; 
    if(opcion == 'A'){
      dg.ponArista(i, i + 1);
    }else if(opcion == 'J'){
      int j; cin >> j;
      dg.ponArista(i, j - 1);
    }else if(opcion == 'C'){
      int c; cin >> c;
      dg.ponArista(i, c - 1);
      dg.ponArista(i, i + 1);
    } 
  }
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Necronomicon sol(dg);

  if(!sol.termina()){
    cout << "NUNCA";
  }else if(sol.hayCiclo()){
    cout << "A VECES";   
  }else {
    cout << "SIEMPRE";
  }

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
   system("PAUSE");
#endif
   return 0;
}
