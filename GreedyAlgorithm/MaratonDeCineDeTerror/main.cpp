
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
struct pelicula{
  int inicio, fin;
};

bool operator<(pelicula const&a, pelicula const&b){
  return a.fin < b.fin ;
}

int voraz(vector<pelicula> peliculas){
  sort(peliculas.begin(), peliculas.end());
  int cont = 1;
  int ultimo = 0;
  for(int i = 1; i < peliculas.size(); i++){
    if(peliculas[ultimo].fin + 10 <= peliculas[i].inicio){
      cont++;
      ultimo = i;
    }

  }

  return cont;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  vector<pelicula> peliculas(N);
  int hora, minutos, duracion;
  char puntos;
  for(int i = 0; i < N; i++){
    cin >> hora >> puntos >> minutos >> duracion;
    peliculas[i].inicio = hora * 60 + minutos;
    peliculas[i].fin = peliculas[i].inicio + duracion;
  }

  cout << voraz(peliculas) <<'\n';
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
