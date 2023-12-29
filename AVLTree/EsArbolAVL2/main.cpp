
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
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


int converter(string number){

  if(number == "cero"){
    return 0;
  }else if(number == "uno"){
    return 1;
  }else if(number == "dos"){
    return 2;
  }else if(number == "tres"){
    return 3;
  }else if(number == "cuatro"){
    return 4;
  }else if(number == "cinco"){
    return 5;
  }else if(number == "seis"){
    return 6;
  }else if(number == "siete"){
    return 7;
  }else if(number == "ocho"){
    return 8;
  }else if(number == "nueve"){
    return 9;
  }

  return -1;
}

// Función para convertir un BinTree de std::string a BinTree de int
BinTree<int> convertStringTreeToIntTree(const BinTree<std::string> &strTree) {
    if (strTree.empty()) {
        return BinTree<int>();  // Devolver un árbol vacío si el árbol de cadenas es vacío
    } else {
        // Convertir la raíz y los subárboles recursivamente
        int rootValue = converter(strTree.root());
        BinTree<int> leftTree = convertStringTreeToIntTree(strTree.left());
        BinTree<int> rightTree = convertStringTreeToIntTree(strTree.right());

        // Construir el nuevo árbol de enteros
        return BinTree<int>(leftTree, rootValue, rightTree);
    }
}

Solution is_AVL(BinTree<int> tree){
  if(tree.empty())
    return {true, 0, -1, -1};
  else{
    Solution left = is_AVL(tree.left());
    Solution right = is_AVL(tree.right());

    bool is_avl = (abs(left.height - right.height) <= 1) && left.is_avl && right.is_avl 
                    && (left.max < tree.root() || left.max == -1) 
                    && (right.min > tree.root() || right.min == -1);    
    
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

bool resuelveCaso() {
   
   // leer los datos de la entrada
  char mode; cin >> mode;
  if (!std::cin)  // fin de la entrada
    return false;

  Solution result;
  BinTree<int> tree;  
   // resolver el caso posiblemente llamando a otras funciones
  if(mode == 'N'){
    tree = read_tree<int>(cin);
  }else if(mode == 'P'){
    BinTree<string> aux = read_tree<string>(cin);
    tree = convertStringTreeToIntTree(aux);
  }

  result = is_AVL(tree);
   // escribir la solución
  if(result.is_avl)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

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
