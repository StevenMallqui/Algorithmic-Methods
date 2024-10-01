
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
struct Tarea{
  int inicio, fin, periodo;
};

bool operator<(Tarea const&a, Tarea const&b){
  return b.inicio < a.inicio || (a.inicio == b.inicio && b.fin < a.fin);
}

bool hayConflictos( priority_queue<Tarea> queue, int T){
  
  bool conflicto = false;
  while (queue.top().inicio < T && !conflicto && queue.size() > 1) {
    Tarea aux = queue.top(); queue.pop();
    if(aux.fin > queue.top().inicio && queue.top().inicio < T) {conflicto = true;}
    if(aux.periodo != 0) {queue.push({aux.inicio + aux.periodo, aux.fin + aux.periodo, aux.periodo});}
  }
  return conflicto;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
      return false;
  
  int M, T; cin >> M >> T;
  priority_queue<Tarea> queue;

  Tarea aux;
  for(int i = 0; i < N; i++){
    cin >> aux.inicio >> aux.fin;
    aux.periodo = 0;
    queue.push(aux);
  }

  for (int i = 0; i < M; i++) { // tareas periódicas
    cin >> aux.inicio >> aux.fin >> aux.periodo;
    queue.push(aux);
  }
   
  // resolver el caso posiblemente llamando a otras funciones 
  // escribir la solución
  if(hayConflictos(queue, T)){
    cout << "SI" <<'\n'; 
  }else{
    cout << "NO" <<'\n';
  }

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
