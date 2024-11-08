
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

struct horario{
  int inicio;
  int final;
};


bool operator<(const horario &a, const horario&b){
  return a.final < b.final || (a.final == b.final && a.inicio < b.inicio); 
}

int converter(int horas, int minutos){
  return horas * 60 + minutos;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;
  
  string tiempo;
  vector<horario> horarios(N);
  int pos, horas, minutos;
  horario aux;
  for(int i = 0; i < N; i++){
    cin >> tiempo;
    pos = tiempo.find(":");
    horas = stoi(tiempo.substr(0, pos));
    minutos = stoi(tiempo.substr(pos + 1));
    aux.inicio = converter(horas, minutos);

    cin >> minutos;
    aux.final = aux.inicio + minutos + 10;
    horarios[i] = aux;
  }
  
  sort(horarios.begin(), horarios.end());

  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  int peliculas = 1, ult = horarios[0].final; 
  for(int i = 1; i < N; i++){
    if(ult <= horarios[i].inicio){
      peliculas++;
      ult = horarios[i].final;
    }
  }

  cout << peliculas << '\n';
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
