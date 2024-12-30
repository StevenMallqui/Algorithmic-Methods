
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>
  
  DEFINICIONES
  . N = Número de películas que se proyectan
  . Di = Duración de la película i

  RECURSION
  maxTiempo(i) = Tiempo máximo (min) que puede estar viendo películas si están disponibles las películas de la i a la N-1

  maxTiempo(i) = max(maxTiempo(i+1), maxTiempo(j) + Di), donde j es la primera película que no solapa con la i (= N si no hay ninguna)
 
  CASOS BASE
  maxTiempo(N) = 0 (no quedan películas disponibles)

  RESOLUCION
  Se utiliza la programación dinámica ascendente. Como la recursión tiene solo 1 parámetro necesitamos un vector, que se irá rellenando 
  de derecha a izquierda ¡, ya que para una posición i necesitamos la i+1 y la j que será, en cualquier caso, posterior a la i. 
  La última posición del vector, correspondiente al caso base, será 0, y la solución quedará almacenada en la primera posición, correspondiente a
  tener disponibles todas las películas (i = 0).
  Por otro lado, para calcular la primera película que no solapa con una (es decir, la j) se utiliza una búsqueda binaria en el vector de películas(i, N)
  (no hace falta buscar en todo el vector), aprovechando que está ordenado por inicio, ya que necesitamos encontrar la primera película cuyo inicio sea mayor 
  o igual que un número (fin) dado, que es precisamente lo que encuentra la búsqueda binaria.

  COSTE
  El coste en tiempo está en el orden O(N log N). La ordenación del vector tiene este coste, y ademas al rellenar el vector de subproblemas (de tamaño N), para 
  cada posición hay que hacer una búsqueda binaria de orden O(log N).
  El coste en espacio está en el orden O(N), por el vector donde guardamos las soluciones de los subproblemas
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int descanso = 10;

struct pelicula {
  int ini;
  int fin;
  int duracion;
};

bool operator<(pelicula const& p1, pelicula const& p2){
  return p1.ini < p2.ini;
}

int maraton(vector<pelicula>& peliculas){
  int N = peliculas.size();
  sort(peliculas.begin(), peliculas.end());
  vector<int> v(N + 1, 0);
  for(int i = N-1; i >= 0; i--){
    int j = lower_bound(peliculas.begin() + i, peliculas.end(), pelicula{peliculas[i].fin + 10, 0, 0}) - peliculas.begin();
    v[i] = max(v[i+1], v[j] + peliculas[i].duracion);
  }

  return v[0];
} 

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  vector<pelicula> peliculas(N);
  int hora, min, dur;
  char aux;
  for(int i = 0; i < N; i++){
    cin >> hora >> aux >> min >> dur;
    int ini = hora * 60 + min;
    peliculas[i] = {ini, ini + dur, dur};
  }

  // resolver el caso posiblemente llamando a otras funciones
  cout << maraton(peliculas) << '\n';

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
