#include <iostream>
// #include "../../API/biblioteca/funciones/arrays.hpp"
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/funciones/files.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
#include "../../API/biblioteca/tads/Array.hpp"

using namespace std;

int cmpInt(int a, int b)
{
    return a - b;
}
int main()
{

    // int a = 2;
    // int *b = &a;
    // cout << a << endl;
    // cout << b << endl;

    // crear un array dinamicamente y asignarle un tam
    // int *arr;
    // int n;
    // cout << "Ingrese el tam. de su array: " << endl;
    // cin >> n;

    // asignamos el tam. del array
    // arr = new int[n];
    
    // borramos un puntero
    // delete arr;

    // -----------------------------------------
    Array<int> x = array<int>();
    arrayAdd<int>(x, 21);
    arrayAdd<int>(x, 2);
    arrayAdd<int>(x, 4);
    arrayAdd<int>(x, 12);
    arrayAdd<int>(x, 15);
    arrayAdd<int>(x, 3);
    arrayAdd<int>(x, 5);
    arrayAdd<int>(x, 1);
    arrayAdd<int>(x, 9);

    // trabajo con el arrayRemoveAll
    // arrayRemoveAll<int>(x);
    // cout << arraySize<int>(x) << endl;

    // trabajo con el arrayRemove
    //  int n = arrayRemove<int>(x, 0);
    //  cout << n << endl;

    // trabajo con el arrayInsert
    //   arrayInsert<int>(x, 10, 0);

    // trabajo con el arraySort
    //    arraySort<int>(x, cmpInt);
    // trabajo con el arrayFind
    //    int pos = arrayFind<int>(x, 10, cmpInt);
    //    cout << "pos: " << pos << endl;

    // trabajo con el arraySet
    arraySet<int>(x, 1, 99);
    //  cout << " Array X contiene: " << endl;
    for (int i = 0; i < arraySize<int>(x); i++)
    {
        cout << "Dir Mem.: " << arrayGet<int>(x, i) << endl;
        cout << "valor:" << *arrayGet<int>(x, i) << endl;
        cout << "------------" << endl;
    }

    // cout << arraySize<int>(x) << endl;
    // cout << arrayGet<int>(x, 2) << endl;

    return 0;
}
