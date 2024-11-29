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

  . DEFINICIONES .
  - Vij:  Número de la casilla [i][j]
  - N: Dimensión del tablero

  . RECURSIÓN .
  tablero(i, j) = máxima puntuación que se puede conseguir empezando en la casilla [i][j]
  
  tablero(i, j) = max(tablero(i-1, j) + Vij, tablero(i-1, j-1) + Vij, tablero(i-1, j+1) + Vij)  
                  
  . CASOS BASE .
  tablero(i, j) = 0 si i < 1 || i > N
  tablero(i, j) = 0 si j < 1 || j > N

  . RESOLUCION .
  Se utiliza la programación dinámica ascendente, de forma que se va construyendo una matriz de N filas y N columnas, y se va recorriendo 
  de arriba a abajo y de derecha a izquierda. Para cada casilla, se aplica la función de recurrencia, de forma que la solución consistirá 
  en encontrar el valor máximo de entre los que queden en la última fila tras recorrer toda la tabla. 

  . COSTE .
  El coste en tiempo es del orden O(N^2), puesto que recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste(1)
  El coste en espacio es del orden O(N^2), por la matriz donde mantenemos las soluciones de los subproblemas 
 
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using matriz = vector<vector<int>>;

int casilla(int j, vector<int> const& v) {
    int N = v.size();
    if (j < 0 || j >= N)
        return 0;
    else
        return v[j];
}

void progDinamica(matriz const& tablero) {
    int puntuacion = 0, inicio = 0;
    int N = tablero.size();
    int aux = 0;
    vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            int v1 = casilla(j - 1, v);
            int v2 = casilla(j, v);
            int v3 = aux;
            aux = v[j];
            v[j] = max(v1, max(v2, v3));
            v[j] += tablero[i][j];
            if (i == N - 1) { 
                if (v[j] >= puntuacion) {
                    puntuacion = v[j];
                    inicio = j;
                }
            }
        }
        aux = 0;
    }

    cout << puntuacion << ' ' << inicio + 1 <<'\n';
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    matriz tablero(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> tablero[i][j];

    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    progDinamica(tablero);

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