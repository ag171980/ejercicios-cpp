#include <iostream>
#include "../../API/biblioteca/funciones/arrays.hpp"
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/funciones/files.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"

using namespace std;
// struct Persona
// {
//     string nombre;
//     int edad;
//     string direccion;
// };
// Persona persona(string n, int e, string d)
// {
//     return {n, e, d};
// }
// void inicializarArr(double arr[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         arr[i] = 0;
//     }
// }
// void agregar(int arr[], int n, int &len)
// {
//     arr[len] = n;
//     len++;
// }

int cmpInt(int a, int b)
{
    return a - b;
}
int main()
{
    //////////////////////////////////////
    // Persona arr[4];
    // arr[0] = persona("Marcos", 23, "Cabildo");
    // arr[1] = persona("Branco", 19, "Swanx");
    // arr[2] = persona("Samid", 29, "Diurno");
    // arr[3] = persona("Walter", 31, "Nashix");
    // cout << "ID | Nombre | Edad | Direccion" << endl;
    // for (int i = 0; i < 4; i++)
    // {

    //     cout << i << " | " << arr[i].nombre << " | " << arr[i].edad << " | " << arr[i].direccion << endl;
    // }
    //////////////////////////////////////
    // int a[3];
    // a[0] = 123;
    // a[1] = 456;
    // a[2] = 789;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << a[i] << endl;
    // }
    //////////////////////////////////////
    // int a[] = {321, 451, 819};

    // Ejemplo: Se ingresan pares {dia, totFac}, siendo dia el dia del mes y total facturado la facturacion total deese dia.
    // Los datos corrsponden a los ultimos anios. informar total facturado por dia.
    // Fin de datos: dia = 999;

    // double acum[5];
    // inicializarArr(acum);
    // int dia;
    // double tot;
    // cout << "Ingrese dia y total" << endl;
    // cin >> dia >> tot;

    // while (dia != 999)
    // {
    //     acum[dia - 1] += tot;
    //     cout << "Ingrese dia y total: " << endl;
    //     cin >> dia >> tot;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i + 1 << ": " << acum[i] << endl;
    // }

    // string a[200];
    // int len = 0;

    // int pos = orderedInsert<int>(arr, len, 4, cmpInt);

    // cout << "Pos: " << pos << endl;

    // add<string>(a, len, "Pablo");
    // add<string>(a, len, "Carlos");
    // add<string>(a, len, "Dario");
    // add<string>(a, len, "Julian");
    // add<string>(a, len, "Salinas");
    // add<string>(a, len, "Franco");

    // int numABuscar = 2;
    // int pos = find<string, string>(a, len, "Salinas", cmpString);
    // cout << "Pos: " << pos << endl;
    // 3. REMOVE

    // string a[5] = {"John", "George", "Ringo", "Jorge", "Halario"};
    // int len = 5;

    // remove<string>(a, len, 0);
    // for (int i = 0; i < len; i++)
    // {
    //     cout << a[i] << endl;
    // }

    // 4. FIND

    // int len = 4;
    // int arr[4] = {4, 5, 2, 1};

    // int pos = find<int, int>(arr, len, 1, cmpInt);

    // cout << "Pos: " << pos << endl;

    // 5. ORDERERINSERT

    // int arr[10] = {1, 2, 3, 5, 6, 7, 8, 9};
    // int len = 8;
    // cout << endl;
    // int pos = orderedInsert<int>(arr, len, 4, cmpInt);
    // cout << "Pos: " << pos << endl;
    // int contador = 0;
    // while (contador < len)
    // {
    //     cout << arr[contador] << endl;
    //     contador++;
    // }
    // 6. SORT

    int arr[] = {2, 41, 7, 15, 9, 11, 12, 91, 45};
    int len = 9;
    sort<int>(arr, len, cmpInt);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
