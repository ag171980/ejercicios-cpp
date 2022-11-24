#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
#include "emision.hpp"
using namespace std;

int cmpItemId(Item i, int id)
{
    return i.idProd - id;
}

int cmpRProdId(RProducto rp, int idProd)
{
    int idRProd = rp.p.idProd;
    return idRProd - idProd;
}

int cmpAhorroId(Ahorro a, int id)
{
    return a.idRub - id;
}

int cmpRubId(Rubro r, int idRub)
{
    int idRubro = r.idRub;
    return idRubro - idRub;
}
int cmpDescripcion(Item a, Item b)
{
    return (b.descr < a.descr);
}
int cmpDescAhorro(Ahorro a, Ahorro b)
{
    return (b.desc < a.desc);
}
Coll<Rubro> subirRubros()
{
    return {};
}
Coll<RProducto> subirProductos()
{
    return {};
}

Producto buscarProducto(int idProd, Coll<RProducto> cPro)
{
    int pos = collFind<RProducto, int>(cPro, idProd, cmpRProdId, rProductoFromString);
    Producto p = collGetAt<RProducto>(cPro, pos, rProductoFromString);
    return p;
}
Rubro buscarRubro(int idRub, Coll<Rubro> cRub)
{
    int pos = collFind<Rubro, int>(cRub, idRub, cmpRubId, rubroFromString);
    Rubro r = collGetAt<Rubro>(cRub, pos, rubroFromString);
    return r;
}
void procesar(int cant, Producto producto, Rubro rubro, Coll<Item> &ticket, Coll<Ahorro> &cAhorro)
{
    // ticket
    int pos = collFind<Item, int>(ticket, producto.idProd, cmpItemId, itemFromString);
    if (pos < 0)
    {
        string desc = producto.descr;
        double total = producto.precio * rubro.promo * cant;
        Item x = item(producto.idProd, desc, producto.precio, producto.precio * rubro.promo, 0, total);
        pos = collAdd<Item>(ticket, x, itemToString);
    }

    Item it = collGetAt<Item>(ticket, pos, itemFromString);
    it.cant += cant;
    collSetAt<Item>(ticket, it, pos, itemToString);

    // ahorro
    pos = collFind<Ahorro, int>(cAhorro, producto.idRub, cmpAhorroId, ahorroFromString);
    if (pos < 0)
    {
        string desc = rubro.descr;
        Ahorro x = ahorro(producto.idRub, desc, 0);
        pos = collAdd<Ahorro>(cAhorro, x, ahorroToString);
    }

    Ahorro z = collGetAt<Ahorro>(cAhorro, pos, ahorroFromString);
    z.acum += cant;
    collSetAt<Ahorro>(cAhorro, z, pos, ahorroToString);
}

void imprimirTicket(int &nroTk, Coll<Item> ticket, Coll<Ahorro> ahorro)
{
    // cout << "Numero de ticket: " << nroTk << endl;
    // cout << "idProd | Producto | Precio | c/Dto | Cant | Total" << endl;
    double total = 0;
    collSort<Item>(ticket, cmpDescripcion, itemFromString, itemToString);
    while (collHasNext<Item>(ticket))
    {
        double subtotal = 0;
        Item item = collNext<Item>(ticket, itemFromString);
        subtotal = item.precio * item.cant;

        // cout << item.idProd << "      | " << item.descr << "     | " << item.precio << "    | " << item.precio - (item.precio * item.cDto) << "   | " << item.cant << "    | " << subtotal << endl;

        total += subtotal;
    }
    // cout << "                                      TOTAL: " << tot << endl;
    collSort<Ahorro>(ahorro, cmpDescAhorro, ahorroFromString, ahorroToString);
    cout << "Ahorro por Rubro: " << endl;
    cout << " Rubro | Total " << endl;
    while (collHasNext<Ahorro>(ahorro))
    {
        Ahorro aho = collNext<Ahorro>(ahorro, ahorroFromString);
        cout << aho.desc << " | " << aho.acum << endl;
    }
    // ticket
}
void procesarDemandaProd(Coll<Item> ticket, Coll<RProducto> cPro) {}
int cmpRProducto(RProducto a, RProducto b)
{
    return (b.acum - a.acum);
}
void mostrarDemandaXProd(Coll<RProducto> cPro)
{
    // Informar cuáles fueron los 10 productos más demandados, ordenando el lis-
    // tado decrecientemente según la cantidad demandada.
    collSort<RProducto>(cPro, cmpRProducto, rProductoFromString, rProductoToString);
    collReset<RProducto>(cPro);
    for (int i = 0; i < 10; i++)
    {
        RProducto x = collNext<RProducto>(cPro, rProductoFromString);
        string desc = x.p.descr;
        cout << desc << ", " << x.acum << endl;
    }
}
int main()
{
    Coll<Rubro> cRub = subirRubros();
    Coll<RProducto> cPro = subirProductos();
    int nroTk;
    cout << "Ingrese nro ticket inicial: " << endl;
    cin >> nroTk;
    int idCli;
    cout << "Ingrese el id del cliente: " << endl;
    cin >> idCli;
    while (idCli != 0)
    {
        Coll<Item> ticket = coll<Item>();
        Coll<Ahorro> ahorro = coll<Ahorro>();
        int idProd, cant;
        cout << "Ingrese producto/cantidad" << endl;
        cin >> idProd >> cant;
        while (idProd != 0)
        {
            Producto producto = buscarProducto(idProd, cPro);
            Rubro rubro = buscarRubro(producto.idRub, cRub);
            procesar(cant, producto, rubro, ticket, ahorro);
        }

        imprimirTicket(nroTk, ticket, ahorro);

        // procesar demanda x prod 2)
        procesarDemandaProd(ticket, cPro);

        // siguiente
        cout << "Ingrese cliente: " << endl;
        cin >> idCli;
    }
    // p 2
    mostrarDemandaXProd(cPro);

    return 0;
}