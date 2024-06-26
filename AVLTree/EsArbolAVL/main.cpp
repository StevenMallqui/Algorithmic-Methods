
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui Aguilar
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;
#include "BinTree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Solution{
  bool is_avl;
  int height, max, min;
};

Solution is_AVL(BinTree<int> tree){
  if(tree.empty())
    return {true, 0, -1, -1};
  else{
    Solution left = is_AVL(tree.left());
    Solution right = is_AVL(tree.right());

    bool is_avl = (abs(left.height - right.height) <= 1) && left.is_avl && right.is_avl 
                    && (left.max < tree.root() || left.max == -1) && (right.min > tree.root() || right.min == -1);    
    
    int mx, mn;
    if(tree.right().empty())
      mx = tree.root();
    else
      mx = right.max;

    if(tree.left().empty())
      mn = tree.root();
    else
      mn = left.min;

    return {is_avl, max(left.height, right.height) + 1, mx, mn};
  }
}

void resuelveCaso() {
   
  // leer los datos de la entrada
  BinTree<int> tree = read_tree<int>(cin);
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  Solution result = is_AVL(tree);
  if(result.is_avl)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
