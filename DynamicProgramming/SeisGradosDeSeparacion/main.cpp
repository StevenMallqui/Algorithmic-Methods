
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include "EnterosInf.h"

/*@ <answer>

  RESOLUCIÓN 
  El problema se representa mediante un grafo dirigido donde los vertices representan las personas 
  y las aristas las relaciones que existen entre ellas. Nótese que para cada par de vértices relacionados
  se colocan dos aristas que los unen en sentidos opuestos. Para calcular el grado de separación entre dos 
  personas basta calcular el camino mínimo entre los vértices. Como necesitamos saber el grado de separación 
  de la red, habrá que calcular los caminos mínimos entre cada par de vértices del grafo. Por eso, aplicamos 
  el algoritmo de Floyd. Después, recorremos la matriz resultante buscando el máximo y, si este es Infinito, 
  significa que hay al menos un par de vértices que no están conectados y, por tanto, la red no está conectada.

  COSTE
  - Rellenar el grafo inicial tiene coste en el orden O(N^2), donde N = número de vértices 
  - El algoritmo de Floyd tiene coste en el orden O(N^3)
  - Recorrer la matriz tiene coste en el orden O(N^2)

  Por tanto, el coste total del problema estará en el orden O(N^3)

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void Floyd(Matriz<EntInf> const& G, Matriz<EntInf>& C) {
  int N = G.numfils(); 
  C = G;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        auto temp = C[i][k] + C[k][j];
        if (temp < C[i][j])
          C[i][j] = temp;
      }
    }
  }
}

EntInf gradoMaximo(Matriz<EntInf> const& C){
  EntInf grado = EntInf(0);

  for(int i = 0; i < C.numfils(); i++)
    for(int j = 0; j < C.numcols(); j++)
      grado = max(grado, C[i][j]);

  return grado;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N, R; cin >> N >> R;
  if (!std::cin)  // fin de la entrada
    return false;

  Matriz<EntInf> G(N, N, Infinito);
  for(int i = 0; i < N; i++)
    G[i][i] = EntInf(0);

  unordered_map<string, int> personas(N);
  string a, b;
  int id = 0;
  for(int i = 0; i < R; i++){
    cin >> a >> b;
    if(!personas.count(a)){
      personas[a] = id;
      id++;
    }

    if(!personas.count(b)){
      personas[b] = id;
      id++;
    }

    G[personas[a]][personas[b]] = EntInf(1);
    G[personas[b]][personas[a]] = EntInf(1);
  } 

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  
  Matriz<EntInf> C(N, N, Infinito);
  Floyd(G, C);
  EntInf grado = gradoMaximo(C);

  if(grado == Infinito)
    cout << "DESCONECTADA";
  else
    cout << grado;

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
