
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
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

void horas_de_vuelo(priority_queue<int> &largeV, priority_queue<int> &smallV, const int &drones){
  int horas = 0, smallT, largeT;
  while (!smallV.empty() && !largeV.empty()){
    vector<int> smallUsadas, largeUsadas;
    for(int i = 0; i < drones && !smallV.empty() && !largeV.empty(); i++){
      smallT = smallV.top();
      largeT = largeV.top();
      smallV.pop();
      largeV.pop();

      if(smallT > largeT){
        smallUsadas.push_back(smallT-largeT);
        horas += largeT;
      }else if(smallT < largeT){
        largeUsadas.push_back(largeT-smallT);
        horas += smallT;
      }else{
        horas += smallT;
      }
    }

    cout << horas << ' ';
    horas = 0;
    for(int a : smallUsadas)
      smallV.push(a);
    
    for(int b : largeUsadas)
      largeV.push(b);
  }

  cout << '\n';
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N, A, B; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  cin >> A >> B;
  priority_queue<int> largeV;
  priority_queue<int> smallV;

  int pila;
  for(int i = 0; i < A; i++){
    cin >> pila;
    largeV.push(pila);
  } 

  for(int i = 0; i < B; i++){
    cin >> pila;
    smallV.push(pila);
  } 

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  horas_de_vuelo(largeV, smallV, N);

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
