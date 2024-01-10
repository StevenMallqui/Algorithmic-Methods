
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct tweets{
  int citas, tiempoAct;
};

bool operator<(tweets const& a, tweets const&b){
  return a.citas > b.citas || (a.citas == b.citas && a.tiempoAct < b.tiempoAct);
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  IndexPQ<string, tweets> cola; 
  unordered_map<string, tweets> preCola;
  string opcion, nombre; 
  int citas;
  // resolver el caso posiblemente llamando a otras funciones
  for(int i = 0; i < N; i++){
    cin >> opcion;
    if(opcion == "C"){ 
      cin >> nombre; cin >> citas;
      if(preCola.find(nombre) != preCola.end()){
        preCola[nombre].citas += citas;
        preCola[nombre].tiempoAct = i;
      }else{
        preCola.insert({nombre, {citas, 0}});
      }

      cola.update(nombre, preCola[nombre]);

    }else if(opcion == "E"){
      cin >> nombre; cin >> citas;
      if(preCola.find(nombre) != preCola.end()){
        preCola[nombre].citas -= citas;
        preCola[nombre].tiempoAct = i;
      }else{
        preCola.insert({nombre, {citas, 0}});
      }

      cola.update(nombre, preCola[nombre]);

    }else if(opcion == "TC"){

      string primero, segundo;
      bool prim = false, secon = false;

      if(!cola.empty()){
        primero = cola.top().elem; cola.pop();
        prim = true;
        cout << "1 " << primero << '\n';
      }

      if(!cola.empty()){
        segundo = cola.top().elem; cola.pop();
        secon = true;
        cout << "2 " << segundo << '\n';
      }

      if(!cola.empty()){
        cout << "3 " << cola.top().elem << '\n';
      }

      if(prim) cola.push(primero, preCola[primero]);
      if(prim) cola.push(segundo, preCola[segundo]);

    }
  }
  // escribir la solución
  cout << "---" <<'\n';
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
