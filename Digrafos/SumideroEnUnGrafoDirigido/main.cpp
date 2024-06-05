
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class GrafoConSumidero{

  private:
    bool existeSumidero;
    int sumidero;

  public:
    GrafoConSumidero(Digrafo const& d){
      int cont = 0;
      int hay = false;
      while(cont < d.V() && !hay){
        if(d.ady(cont).size() == 0){
          hay = true;
          sumidero = cont;
        }
        cont++;
      }
      if(hay){
        Digrafo inv = d.inverso();
        if(inv.ady(sumidero).size() != (d.V() - 1)){
          hay = false;
        }
      
      }
      existeSumidero = hay;
    }

    bool haySumidero(){
      return existeSumidero;
    }

    int verticeSumidero(){
      return sumidero;
    }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   Digrafo d(cin);
   if (!std::cin)  // fin de la entrada
      return false;
   
   GrafoConSumidero D_G(d);
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   
   if(D_G.haySumidero()) cout << "SI " << D_G.verticeSumidero() << '\n';
   else cout << "NO" << '\n';

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
