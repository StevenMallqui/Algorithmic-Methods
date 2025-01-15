
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
  N: tipos de chorizo disponibles
  masa: cantidad de gramos de masa de pan
  Ci: cantidad disponible de chorizo i
  CHi: cantidad necesaria de chorizo i 
  Mi: cantidad de masa necesaria para el chorizo i
  Pi: precio del bollo de chorizo i

RECURSION
  maximoBeneficio(i, j): maximo beneficio teniendo disponibles chorizos de 1 a i para una cantidad j de masa de pan

  maximoBeneficio(i, j): max(maximoBeneficio(i-1, j), maximoBeneficio(i-1, j - k * Mi))+ k * Pi) siendo k 1 <= k <= min(j/Mi, Ci/CHi)

CASOS BASE
  maximoBeneficio(i, 0): 0
  maximoBeneficio(0, j): 0

RESOLUCION
  Se utiliza programación dinámica ascendente. Se va rellenando la matriz de N+1 filas y masa+1 columnas de arriba a abajo y de derecha a izquierda. La primera columna será 0
  y la primera fila 0, por los casos base, y a partir de ahí basta aplicar la funcion recursiva. La solución quedará almacenada en la posicion [N][masa] de la matriz, correspondiente
  al caso en que contamos con todos los tipos de chorizo y queda la cantidad de masa total. Para una posición sólo necesitamos posiciones de la fila superior (y en columnas <= j), por lo que
  podemos reducir el espacio a un único vector que se va rellenando de derecha a izquierda.

COSTE
  El coste en tiempo está en el orden O(N * P), porque recorremos la matriz y sobre cada elemento realizamos operaciones de coste O(1)
  El coste en espacio está en el orden O(P), por el vector donde guardamos las soluciones de los subproblemas

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct bollo{
  int C, CH, M, P;
};

long long int progDinamica(const vector<bollo> &bollos, int masa){
  int N = bollos.size();
  vector<long long int> sol(masa + 1, 0);

  for(int i = 1; i <= N; i++){
    for(int j = masa; j >= bollos[i-1].M; j--){
      for(int k = 1; k <= min(j / bollos[i-1].M, bollos[i-1].C / bollos[i-1].CH); k++){
        sol[j] = max(sol[j], sol[j - k * bollos[i-1].M] + k * bollos[i-1].P);
      }
    }
  }

  return sol[masa];
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int N, masa; cin >> N >> masa;
  if (!std::cin)  // fin de la entrada
    return false;
  
  vector<bollo> bollos(N);
  for(int i = 0; i < N; i++)
    cin >> bollos[i].C >> bollos[i].CH >> bollos[i].M >> bollos[i].P;

  cout << progDinamica(bollos, masa) << '\n';

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
