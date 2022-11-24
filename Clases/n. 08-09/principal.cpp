#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/arrays.hpp"
#include "../../API/biblioteca/tads/Array.hpp"
#include "../../API/biblioteca/tads/Map.hpp"
#include "../../API/biblioteca/funciones/lists.hpp"

using namespace std;

struct Nodo
{
    int info;
    Nodo *sig;
};
// Lista enlazada
// p->[1,]->[2,]->[3,]->[4,]->[5,]->[6,]

// Estrategia:
int cmpInt(int a, int b)
{
    return a - b;
}
// void agregar(Nodo *&p, int v)
// {
//     Nodo *nuevo = new Nodo();

//     nuevo->info = v;
//     nuevo->sig = NULL;

//     if (p != NULL)
//     {

//         Nodo *aux = p;
//         while (aux->sig != NULL)
//         {
//             aux = aux->sig;
//         }
//         aux->sig = nuevo;
//     }
//     else
//     {
//         p = nuevo;
//     }
// }

// void mostrar(Nodo *p)
// {

//     // Utilizo una variable aux solo por prolijidad, podria haber usado solo p
//     //  para borrar
//     Nodo *aux = p;
//     while (aux != NULL)
//     {
//         cout << aux->info << endl;
//         aux = aux->sig;
//     }
// }
// void liberar(Nodo *p)
// {
//     while (p != NULL)
//     {
//         // utilizo una variable auxiliar porque si utilizo p para apuntar
//         // a los elementos de la lista enlazada pierdo la referencia.
//         //  Por es guardo el siguiente nodo en aux, elimino p y le asigno a p el siguiente nodo
//         // para borarrlo asi sucesivamente
//         Nodo *aux = p->sig;
//         delete p;
//         p = aux;
//     }
// }

int main()
{
    Node<int> *p = NULL;

    add<int>(p, 1);
    add<int>(p, 2);
    add<int>(p, 3);
    // agregar(p, 1);
    // agregar(p, 2);
    // agregar(p, 3);
    // agregar(p, 4);
    // agregar(p, 5);
    // agregar(p, 6);
    // mostrar(p);

    // liberar(p);
}
