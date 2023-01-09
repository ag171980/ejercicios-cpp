#include <iostream>
#include "../API/biblioteca/funciones/lists.hpp"
#include "../API/biblioteca/tads/List.hpp"
#include "../API/biblioteca/tads/huffman/HuffmanSetup.hpp"
using namespace std;

// struct Nodo
// {
//     int dato;
//     Nodo *derecha;
//     Nodo *izquierda;
// };
// Nodo *arbol = NULL;
// Nodo *crearNodo(int n)
// {
//     Nodo *nuevo = new Nodo();
//     nuevo->dato = n;
//     nuevo->derecha = NULL;
//     nuevo->izquierda = NULL;

//     return nuevo;
// }

// void insertarNodo(Nodo *&arbol, int n)
// {
//     if (arbol == NULL)
//     {
//         Nodo *nuevo = crearNodo(n);

//         arbol = nuevo;
//     }
//     else
//     {
//         int raiz = arbol->dato;
//         if (n < raiz)
//         {
//             insertarNodo(arbol->izquierda, n);
//         }
//         else
//         {
//             insertarNodo(arbol->derecha, n);
//         }
//     }
// }

// void mostrarArbol(Nodo *arbol, int contador)
// {
//     if (arbol == NULL)
//     {
//         return;
//     }
//     else
//     {
//         mostrarArbol(arbol->derecha, contador + 1);
//         for (int i = 0; i < contador; i++)
//         {
//             cout << "   ";
//         }
//         cout << arbol->dato << endl;
//         mostrarArbol(arbol->izquierda, contador + 1);
//     }
// }

int main()
{

    List<int> lst = list<int>();
    listAdd<int>(lst, 1);
    listAdd<int>(lst, 5);
    listAdd<int>(lst, 3);

    listReset<int>(lst);
    cout << listSize<int>(lst) << endl;
    int e = listRemoveFirst<int>(lst);
    cout << e << endl;

    cout << listSize<int>(lst) << endl;

    e = listRemoveFirst<int>(lst);
    cout << e << endl;

    cout << listSize<int>(lst) << endl;

    e = listRemoveFirst<int>(lst);
    cout << e << endl;
    cout << listSize<int>(lst) << endl;

    e = listRemoveFirst<int>(lst);
    cout << e << endl;
    // while (listSize<int>(lst))
    // {
    //     int *e = listNext<int>(lst);
    //     cout << *e << endl;
    // }

    listFree<int>(lst);

    // int dato, opcion, contador = 0;

    // do
    // {
    //     cout << "Menu" << endl;
    //     cout << "1.Insertar nuevo nodo" << endl;
    //     cout << "2.Mostrar Arbol" << endl;
    //     cout << "3.Salir" << endl;

    //     cout << "Opcion: ";
    //     cin >> opcion;
    //     switch (opcion)
    //     {
    //     case 1:
    //         cout << "Ingresa un numero: " << endl;

    //         cin >> dato;

    //         insertarNodo(arbol, dato);
    //         cout << endl;

    //         break;
    //     case 2:
    //         cout << "Arbol: \n\n";
    //         mostrarArbol(arbol, contador);
    //         break;
    //     default:
    //         break;
    //     }

    // } while (opcion != 3);

    // HuffmanTreeInfo *root = huffmanTreeCreateDemoTree();

    // HuffmanTree ht = huffmanTree(root);
    // cout << &root << endl;
    // string cod;
    // while (huffmanTreeHasNext(ht))
    // {
    //     HuffmanTreeInfo *x = huffmanTreeNext(ht, cod);
    //     cout << x->c << ", (" << x->n << "), "
    //          << "[" << cod << "]" << endl;
    // }
    return 0;
}