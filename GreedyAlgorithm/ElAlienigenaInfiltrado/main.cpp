
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
struct intervalo{
  int inicio, fin;
};

bool operator<(const intervalo &a, const intervalo &b){
   return a.inicio < b.inicio || (a.inicio == b.inicio && b.fin < a.fin);
}

bool resuelveCaso() {
  
   // leer los datos de la entrada
   int C, F, N; cin >> C >> F >> N;
   if (C == 0 && F == 0 && N == 0)
      return false;

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
   vector<intervalo> intervalos(N);
   for(int i = 0; i < N; i++)
      cin >> intervalos[i].inicio >> intervalos[i].fin;
   sort(intervalos.begin(), intervalos.end());

   bool imposible = false;
   int ult = C, cont = 0, i = 0;
   while(ult < F && !imposible){
      int mejorFin = -1;
      while(i < intervalos.size() && intervalos[i].inicio <= ult){
         if(intervalos[i].fin > mejorFin)
            mejorFin = intervalos[i].fin;
         i++;
      }  
   
      if(mejorFin == -1)
         imposible = true;
      else{
         cont++;
         ult = mejorFin;
      }
   }

   if(imposible)
      cout << "Imposible";
   else
      cout << cont;

   cout << '\n';

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