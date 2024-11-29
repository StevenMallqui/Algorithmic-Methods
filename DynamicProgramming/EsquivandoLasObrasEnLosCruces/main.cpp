
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*@ <answer>

  . DEFINICIONES . 
  - Oij = 'X' si hay obras en la intersección [i][j], '.' si no
  - N : Número de calles de Norte a Sur
  - M : Calles de Este a Oeste
  
  . RECURSION .
  caminos(i, j) = Número de caminos distintos para llegar a la intersección [i][j] desde [1][1]
  con un camino de longitud i-1+j-1

  caminosDistintos(i, j) = { 0                                    si Oij = 'X'
                           { maneras(i-1, j) + maneras(i, j-1)    si Oij = '.'

  . CASOS BASE .
  - caminos(i, j) = 1 si i = 1 /\ j = 1 (Intersección inicial)
  - caminos(i, j) = 0 si i < 1 \/ i > N \/ j < 1 \/ j > M (hemos sobrepasado los límites de la ciudad)

   Llamada inicial: caminos(N, M)

  . RESOLUCIÓN .
  Se utiliza la programación dinámica ascendente, de forma que se va generando la matriz con N filas y M columnas de arriba a abajo
  y de izquierda a derecha, ya que para calcular un subproblema necesitampos su superior y el de su izquierda, tal y como dice la 
  función recursiva. La solución del problema quedará almacenada en la última posición de la matriz. Ahora bien, como sólo necesitamos
  esas posiciones, podemos reducir el espacio a un vector

  . COSTE . 
  El coste en tiempo está en el orden O(N * M), dado que recorremos toda la matriz realizando operaciones de coste O(1) sobre cada uno de ellos 
  El coste en espacio está en el orden O(M), por el vector donde mantenemos las soluciones de los subproblemas

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int casilla(int j, vector<int> const& v){
   if(j < 0)
      return 0;
   return v[j];
}

int progDinamica(vector<string> const& ciudad, int M){
   int N = ciudad.size();
   vector<int> v(M, 0);
   
   v[0] = 1;
   for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
         if(ciudad[i][j] == '.')
            v[j] += casilla(j-1, v);
         else
            v[j] = 0;

   return v[M-1];
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int N; cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   int M; cin >> M;

   vector<string> ciudad(N);
   for(int i = 0; i < N; i++)
      cin >> ciudad[i];
   
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cout << progDinamica(ciudad, M) <<'\n';

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
