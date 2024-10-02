
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
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

struct paciente{
  string nombre;
  int gravedad, tiempo;
};

bool operator< (const paciente &a, const paciente &b){
  return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && b.tiempo < a.tiempo);
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == 0)
    return false;
  
  priority_queue<paciente> urgencias;

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  
  char tipo;
  paciente aux;
  for(int i = 0; i < n; i++){
    cin >> tipo;
    if(tipo == 'I'){
      cin >> aux.nombre >> aux.gravedad;
      aux.tiempo = i;
      urgencias.push(aux);
    }else if(tipo == 'A'){
      aux = urgencias.top();
      urgencias.pop();
      cout << aux.nombre << '\n';
    }
  }

  cout << "---\n";
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
