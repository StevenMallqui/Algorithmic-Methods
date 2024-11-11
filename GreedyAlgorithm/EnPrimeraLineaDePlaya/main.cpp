
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
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct edificio{
  int inicio, fin;
};

bool operator<(const edificio &a, const edificio &b){
  return (a.fin < b.fin) || (a.fin == b.fin && a.inicio < b.inicio);
}


int voraz(const vector<edificio> &edificios){
  int puentes = 1;
  int fin = edificios[0].fin;
  for(int i = 1; i < edificios.size(); i++){
    if(edificios[i].inicio >= fin){
      puentes++;
      fin = edificios[i].fin;
    }
  }

  return puentes;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N; 
  if (N == 0)
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  vector<edificio> edificios(N);
  for(int i = 0; i < N; i++)
    cin >> edificios[i].inicio >> edificios[i].fin;

  sort(edificios.begin(), edificios.end());

  cout << voraz(edificios) << '\n';

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
 