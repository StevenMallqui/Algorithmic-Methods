/*@ <answer>
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Necronomicon {

private:
    vector<bool> visit; // visit[i] = ¿hemos visitado el vértice i?
    vector<bool> apilado; // apilado[i] = ¿está el vértice i en la pila?
    bool hayCiclos;
    bool alcanzable;

    void dfs(Digrafo const& d, int v, int destino) {
        visit[v] = true;
        apilado[v] = true;
        for (int i = 0; i < d.ady(v).size(); ++i)
            if (d.ady(v)[i] == destino) // hemos llegado a la solución
                alcanzable = true;
            else if (apilado[d.ady(v)[i]]) // hemos encontrado un ciclo
                hayCiclos = true;
            else if (!visit[d.ady(v)[i]])
                dfs(d, d.ady(v)[i], destino);
        apilado[v] = false;
    }

public:
    Necronomicon(Digrafo const& d) : visit(vector<bool>(d.V(), false)), apilado(vector<bool>(d.V(), false)), hayCiclos(false), alcanzable(false) {
        dfs(d, 0, d.V() - 1);
    }

    bool esCiclico() {
        return hayCiclos;
    }

    bool termina() {
        return alcanzable;
    }

};

bool resuelveCaso() {

    // leer los datos de la entrada
    int L; cin >> L;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo d(L + 1);
    char instruccion;
    int N;
    for (int i = 0; i < L; ++i) {
        cin >> instruccion;
        switch (instruccion) {
        case 'A': {
            d.ponArista(i, i + 1); // de la instrucción pasamos a la siguiente
        } break;
        case 'J': {
            cin >> N;
            d.ponArista(i, N - 1); // saltamos a donde nos manda
        } break;
        case 'C': {
            cin >> N;
            d.ponArista(i, i + 1); // de la instrucción pasamos a la siguiente
            d.ponArista(i, N - 1); // o a donde nos manda el salto
        } break;
        }
    }

    // resolver el caso posiblemente llamando a otras funciones
    Necronomicon sol(d);

    // escribir la solución
    if (!sol.termina())
        cout << "NUNCA";
    else if (sol.esCiclico())
        cout << "A VECES";
    else
        cout << "SIEMPRE";
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