#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
using namespace std;

struct Producto
{
    int idProd;
    char descr[20];
    double precio;
    int idRub;
};

struct RProducto
{
    Producto p;
    int acum;
};

struct Rubro
{
    int idRub;
    char descr[20];
    double promo;
};

struct Item
{
    int idProd;
    string descr;
    double precio;
    double cDto;
    int cant;
    double total;
};

struct Ahorro
{
    int idRub;
    string desc;
    double acum;
};

string productoToString(Producto x)
{
    char sep = 1;
    string sIdProd = to_string(x.idProd);
    string sDescr = x.descr;
    string sPrecio = to_string(x.precio);
    string sIdRub = to_string(x.idRub);
    return sIdProd + sep + sDescr + sep + sPrecio + sep + sIdRub;
}

Producto productoFromString(string s)
{
    char sep = 1;
    Producto x;
    string t0 = getTokenAt(s, sep, 0);
    x.idProd = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    strcpy(x.descr, t1.c_str());
    string t2 = getTokenAt(s, sep, 2);
    x.precio = stod(t2);
    string t3 = getTokenAt(s, sep, 3);
    x.idRub = stoi(t3);
    return x;
}

string productoToDebug(Producto x)
{
    stringstream sout;
    sout << "[";
    sout << x.idProd;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.precio;
    sout << ",";
    sout << x.idRub;
    sout << "]";
    return sout.str();
}

string productoToDebug(string mssg, Producto x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idProd;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.precio;
    sout << ",";
    sout << x.idRub;
    sout << "]";
    return sout.str();
}

Producto producto(int idProd, string descr, double precio, int idRub)
{
    Producto a;
    a.idProd = idProd;
    strcpy(a.descr, descr.c_str());
    a.precio = precio;
    a.idRub = idRub;
    return a;
}

bool productoEquals(Producto a, Producto b)
{
    if (a.idProd != b.idProd)
        return false;
    if (a.precio != b.precio)
        return false;
    if (a.idRub != b.idRub)
        return false;
    return true;
}

string rProductoToString(RProducto x)
{
    char sep = 2;
    string sP = productoToString(x.p);
    string sAcum = to_string(x.acum);
    return sP + sep + sAcum;
}

RProducto rProductoFromString(string s)
{
    char sep = 2;
    RProducto x;
    string t0 = getTokenAt(s, sep, 0);
    x.p = productoFromString(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.acum = stoi(t1);
    return x;
}

string rProductoToDebug(RProducto x)
{
    stringstream sout;
    sout << "[";
    sout << productoToDebug(x.p);
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

string rProductoToDebug(string mssg, RProducto x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << productoToDebug(x.p);
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

RProducto rProducto(Producto p, int acum)
{
    RProducto b;
    b.p = p;
    b.acum = acum;
    return b;
}

bool rProductoEquals(RProducto a, RProducto b)
{
    if (!productoEquals(a.p, b.p))
        return false;
    if (a.acum != b.acum)
        return false;
    return true;
}

string rubroToString(Rubro x)
{
    char sep = 3;
    string sIdRub = to_string(x.idRub);
    string sDescr = x.descr;
    string sPromo = to_string(x.promo);
    return sIdRub + sep + sDescr + sep + sPromo;
}

Rubro rubroFromString(string s)
{
    char sep = 3;
    Rubro x;
    string t0 = getTokenAt(s, sep, 0);
    x.idRub = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    strcpy(x.descr, t1.c_str());
    string t2 = getTokenAt(s, sep, 2);
    x.promo = stod(t2);
    return x;
}

string rubroToDebug(Rubro x)
{
    stringstream sout;
    sout << "[";
    sout << x.idRub;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.promo;
    sout << "]";
    return sout.str();
}

string rubroToDebug(string mssg, Rubro x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idRub;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.promo;
    sout << "]";
    return sout.str();
}

Rubro rubro(int idRub, string descr, double promo)
{
    Rubro a;
    a.idRub = idRub;
    strcpy(a.descr, descr.c_str());
    a.promo = promo;
    return a;
}

bool rubroEquals(Rubro a, Rubro b)
{
    if (a.idRub != b.idRub)
        return false;
    if (a.promo != b.promo)
        return false;
    return true;
}

string ahorroToString(Ahorro x)
{
    char sep = 4;
    string sIdRub = to_string(x.idRub);
    string sDesc = x.desc;
    string sAcum = to_string(x.acum);
    return sIdRub + sep + sDesc + sep + sAcum;
}

Ahorro ahorroFromString(string s)
{
    char sep = 4;
    Ahorro x;
    string t0 = getTokenAt(s, sep, 0);
    x.idRub = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.desc = t1;
    string t2 = getTokenAt(s, sep, 2);
    x.acum = stod(t2);
    return x;
}

string ahorroToDebug(Ahorro x)
{
    stringstream sout;
    sout << "[";
    sout << x.idRub;
    sout << ",";
    sout << x.desc;
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

string ahorroToDebug(string mssg, Ahorro x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idRub;
    sout << ",";
    sout << x.desc;
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

Ahorro ahorro(int idRub, string desc, double acum)
{
    Ahorro b;
    b.idRub = idRub;
    b.desc = desc;
    b.acum = acum;
    return b;
}

bool ahorroEquals(Ahorro a, Ahorro b)
{
    if (a.idRub != b.idRub)
        return false;
    if (a.desc != b.desc)
        return false;
    if (a.acum != b.acum)
        return false;
    return true;
}

string itemToString(Item x)
{
    char sep = 5;
    string sIdProd = to_string(x.idProd);
    string sDescr = x.descr;
    string sPrecio = to_string(x.precio);
    string sCDto = to_string(x.cDto);
    string sCant = to_string(x.cant);
    string sTotal = to_string(x.total);
    return sIdProd + sep + sDescr + sep + sPrecio + sep + sCDto + sep + sCant + sep + sTotal;
}

Item itemFromString(string s)
{
    char sep = 5;
    Item x;
    string t0 = getTokenAt(s, sep, 0);
    x.idProd = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.descr = t1;
    string t2 = getTokenAt(s, sep, 2);
    x.precio = stod(t2);
    string t3 = getTokenAt(s, sep, 3);
    x.cDto = stod(t3);
    string t4 = getTokenAt(s, sep, 4);
    x.cant = stoi(t4);
    string t5 = getTokenAt(s, sep, 5);
    x.total = stod(t5);
    return x;
}

string itemToDebug(Item x)
{
    stringstream sout;
    sout << "[";
    sout << x.idProd;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.precio;
    sout << ",";
    sout << x.cDto;
    sout << ",";
    sout << x.cant;
    sout << ",";
    sout << x.total;
    sout << "]";
    return sout.str();
}

string itemToDebug(string mssg, Item x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idProd;
    sout << ",";
    sout << x.descr;
    sout << ",";
    sout << x.precio;
    sout << ",";
    sout << x.cDto;
    sout << ",";
    sout << x.cant;
    sout << ",";
    sout << x.total;
    sout << "]";
    return sout.str();
}

Item item(int idProd, string descr, double precio, double cDto, int cant, double total)
{
    Item a;
    a.idProd = idProd;
    a.descr = descr;
    a.precio = precio;
    a.cDto = cDto;
    a.cant = cant;
    a.total = total;
    return a;
}

bool itemEquals(Item a, Item b)
{
    if (a.idProd != b.idProd)
        return false;
    if (a.descr != b.descr)
        return false;
    if (a.precio != b.precio)
        return false;
    if (a.cDto != b.cDto)
        return false;
    if (a.cant != b.cant)
        return false;
    if (a.total != b.total)
        return false;
    return true;
}

#endif
