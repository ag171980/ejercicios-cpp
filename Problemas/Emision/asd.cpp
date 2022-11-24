#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
#include "emision.hpp"
using namespace std;
int cmpDescripcion(Item a, Item b)
{
    return (b.descr < a.descr);
}
int main()
{

    // imprimirTicket(int& nroTk,Coll<Item> ticket,Coll<Ahorro> ahorro)
    int nroTicket = 0;
    cout << "Ingrese numero de ticket: " << endl;
    cin >> nroTicket;
    Coll<Rubro> rub = coll<Rubro>();
    collAdd<Rubro>(rub, rubro(1, "Lacteos", 0.20), rubroToString);
    collAdd<Rubro>(rub, rubro(2, "Pastas", 0.20), rubroToString);
    collAdd<Rubro>(rub, rubro(3, "Legumbres", 0.20), rubroToString);

    Coll<Producto> prod = coll<Producto>();
    collAdd<Producto>(prod, producto(1, "Yogur", 120, 1), productoToString);
    collAdd<Producto>(prod, producto(2, "Fideo", 150, 2), productoToString);
    collAdd<Producto>(prod, producto(3, "Lentejas", 150, 3), productoToString);
    collAdd<Producto>(prod, producto(4, "Queso", 110, 1), productoToString);
    
    Coll<Item> it = coll<Item>();
    collAdd<Item>(it, item(1, "Yogur", 120, 0.20, 3, 0), itemToString);
    collAdd<Item>(it, item(2, "Fideo", 150, 0.10, 2, 0), itemToString);
    collAdd<Item>(it, item(4, "Queso", 110, 0.40, 5, 0), itemToString);

    collSort<Item>(it, cmpDescripcion, itemFromString, itemToString);

    cout << "Numero de Ticket: " << nroTicket << endl;
    cout << "idProd | Producto | Precio | c/Dto | Cant | Total" << endl;
    double tot = 0;
    while (collHasNext<Item>(it))
    {
        double subtotal = 0;
        Item item = collNext<Item>(it, itemFromString);
        subtotal = item.precio * item.cant;

        cout << item.idProd << "      | " << item.descr << "     | " << item.precio << "    | " << item.precio - (item.precio * item.cDto) << "   | " << item.cant << "    | " << subtotal << endl;

        tot += subtotal;
    }
    cout << endl;
    cout << "                                      TOTAL: " << tot << endl;

    cout << "Ahorro por Rubro: " << endl;
    // for (int i = 0; i < collSize<Item>(it); i++)
    // {
    //     Item s = collGetAt<Item>(it, i, itemFromString);
    //     cout << s << endl;
    // }
    return 0;
}