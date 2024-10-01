
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
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

struct Grupo{
  int maximo;
  int instrumentos;
  int partituras = 1;
};

bool operator<( const Grupo &a, const Grupo &b){
  return a.maximo < b.maximo;
}

void atril_mas_compartido(priority_queue<Grupo> &grupos, const int &resto){
  for(int i = 0; i < resto; i++){
    Grupo aux = grupos.top();
    grupos.pop();

    aux.partituras++;
    aux.maximo = ceil(float(aux.instrumentos) / aux.partituras);
    grupos.push(aux);
  }

  cout << grupos.top().maximo <<'\n';
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int p, n; cin >> p >> n;
  if (!std::cin)  // fin de la entrada
    return false;
  
  priority_queue<Grupo> grupos;
  int num;

  for(int i = 0; i < n; i++){
    cin >> num;
    grupos.push({num, num});
  }

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución

  atril_mas_compartido(grupos, p-n);

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
