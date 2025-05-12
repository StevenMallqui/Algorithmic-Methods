
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>
  
DEFINICIONES
  N: Tipos de bombilla
  PMax: potencia maxima
  PMin: potencia minima
  Pi: potencia de la bombilla de tipo i
  Ci: coste de la bombilla de tipo i

RECURSION
  minimoCoste(i, j): minimo coste de instalacion con potencia j, teniendo bombillas de 1 a i


  minimoCoste(i, j):{minimoCoste(i-1, j)   si Pi > j}
                    {min(minimoCoste(i-1, j), minimoCoste(i, j-Pi) + Ci) si Pi <= j}

CASOS BASE
  minimoCoste(0, j): Infinito j > 0
  minimoCoste(i, 0): 0

RESOLUCION
COSTE
 
 @ </answer> */
const int INFINITO = 1000000000;

struct bombilla{
  int potencia, precio;
};

pair<int, int> progDinamica(const vector<bombilla> &bombillas, const int PMax, const int PMin){
  int N = bombillas.size();
  vector<int> sol(PMax+1, INFINITO);
  sol[0] = 0;

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= PMax; j++){
      if(bombillas[i-1].potencia <= j)
        sol[j] = min(sol[j], sol[j-bombillas[i-1].potencia] + bombillas[i-1].precio);
    }
  }

  int mini = sol[PMin], p = PMin;
  for(int i = PMin; i <= PMax; i++){
    if(mini > sol[i]){
      mini = sol[i];
      p = i;
    }
  }

  return {mini, p};
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  int N; cin >> N;
  if (!std::cin)  // fin de la entrada
    return false;
  
  int PMax, PMin; cin >> PMax >> PMin;
  vector<bombilla> bombillas(N);
  for(int i = 0; i < N; i++)
    cin >> bombillas[i].potencia;

  for(int i = 0; i < N; i++)
    cin >> bombillas[i].precio;

  pair<int, int> sol = progDinamica(bombillas, PMax, PMin); 
  sol.first == INFINITO ? cout << "Imposible" : cout << sol.first << ' ' << sol.second;
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
