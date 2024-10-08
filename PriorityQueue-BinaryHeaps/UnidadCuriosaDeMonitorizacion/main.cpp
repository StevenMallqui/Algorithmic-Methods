
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

struct usuario {
   int id;
   int periodo;
   int momento;
};

bool operator<(usuario a, usuario b){
   return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}

void k_envios(priority_queue<usuario, vector<usuario>> &usuarios, const int &K){
   for(int i = 0; i < K; i++){
      usuario siguiente = usuarios.top();
      usuarios.pop();
      cout << siguiente.id <<'\n';
      siguiente.momento += siguiente.periodo;
      usuarios.push(siguiente);
   }

   cout << "---\n";
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N; cin >> N;
   if (N == 0)
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<usuario> usuarios;
   usuario aux; 

   for(int i = 0; i < N; i++){
      cin >> aux.id >> aux.periodo;
      aux.momento = aux.periodo;
      usuarios.push(aux);
   }

   int K; cin >> K;

   // escribir la solución
   k_envios(usuarios, K);

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
