
/*@ <answer>
 *
 * Nombre y Apellidos: Steven Mallqui 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

#include "bintree.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename T> struct sol{
    bool avl;
    int altura;
    T min, max;
};

template <typename T> sol<T> arbol_avl_rec(const BinTree<T>& tree) {

    // CASO BASE:
    if (tree.empty()) 
        return { true, 0, numeric_limits<T>::min(), numeric_limits<T>::max()};

    // CASO RECURSIVO:
    else {

        sol izq = arbol_avl_rec(tree.left());
        sol dch = arbol_avl_rec(tree.right());

        bool avl = izq.avl && dch.avl;
        avl = avl && (izq.max == numeric_limits<T>::max() || izq.max < tree.root()) && (dch.min == numeric_limits<T>::min() || dch.min > tree.root());
        avl = avl && abs(izq.altura - dch.altura) <= 1;

        T mx, mn;
        if (tree.right().empty())
            mx = tree.root();
        else
            mx = dch.max;
        if (tree.left().empty())
            mn = tree.root();
        else
            mn = izq.min;

        return { avl, max(izq.altura, dch.altura) + 1, mn, mx };

    }

}

template <typename T> bool es_AVL(const BinTree<T>& tree) {
    return arbol_avl_rec(tree).avl;
}

bool resuelveCaso() {
   
  // leer los datos de la entrada
  char type; cin >> type;
  if (!std::cin)  // fin de la entrada
    return false;
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
   bool sol; 

   if( type == 'N'){
      BinTree<int> tree;
      tree = read_tree<int>(cin);
      sol = es_AVL(tree);
   }else if(type == 'P'){
      BinTree<string> tree;
      tree = read_tree<string>(cin);
      sol = es_AVL(tree);
   }

   if(sol)
      cout << "SI\n";
   else
      cout << "NO\n";

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


