
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
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
struct tweet{
  int citas = 0, tiempoAct;
};

bool operator<(const tweet &a, const tweet &b){
  return b.citas < a.citas || (a.citas == b.citas && b.tiempoAct < a.tiempoAct);
}
 
bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  IndexPQ<string, tweet> cola; 
  unordered_map<string, tweet> preCola;
  string opcion, nombre; 
  int citas;

  // resolver el caso posiblemente llamando a otras funciones
  for(int i = 0; i < N; i++){
    cin >> opcion;
    
    if(opcion != "TC"){ 
      cin >> nombre >> citas;

      if (opcion == "E")
        citas = -citas;

      if(preCola.find(nombre) == preCola.end()){
        preCola[nombre] = {citas, i};
        cola.push(nombre, preCola[nombre]);
      }else{
        tweet &prio = preCola[nombre];  // Referencia directa para evitar búsquedas repetidas
        prio.tiempoAct = i;
        prio.citas += citas;
        cola.update(nombre, prio);
      }
    }else{
      stack<string> top;
      int tam = cola.size();

      for (int i = 0; i < 3 && i < tam; i++) {
        auto aux = cola.top();
        if (aux.prioridad.citas != 0)
            cout << i + 1 << " " << aux.elem << "\n";
        top.push(aux.elem);
        cola.pop();
      }

      while (!top.empty()) {
          string t = top.top();
          top.pop();
          cola.push(t, preCola[t]);
      }
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
