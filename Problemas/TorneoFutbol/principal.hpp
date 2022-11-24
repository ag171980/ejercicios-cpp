// #ifndef _MAINHPP
// #define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/funciones/files.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
using namespace std;

struct Equipo
{
    int idEq;
    char nombre[20];
    int puntos;
};

struct Resultado
{
    int idEq1;
    int idEq2;
    int codRes;
    char estadio[20];
};

struct REquipo
{
    Equipo e;
    int acum;
};

string equipoToString(Equipo x)
{
    char sep = 1;
    string sIdEq = to_string(x.idEq);
    string sNombre = x.nombre;
    string sPuntos = to_string(x.puntos);
    return sIdEq + sep + sNombre + sep + sPuntos;
}

Equipo equipoFromString(string s)
{
    char sep = 1;
    Equipo x;
    string t0 = getTokenAt(s, sep, 0);
    x.idEq = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    strcpy(x.nombre, t1.c_str());
    string t2 = getTokenAt(s, sep, 2);
    x.puntos = stoi(t2);
    return x;
}

string equipoToDebug(Equipo x)
{
    stringstream sout;
    sout << "[";
    sout << x.idEq;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.puntos;
    sout << "]";
    return sout.str();
}

string equipoToDebug(string mssg, Equipo x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idEq;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.puntos;
    sout << "]";
    return sout.str();
}

Equipo equipo(int idEq, string nombre, int puntos)
{
    Equipo a;
    a.idEq = idEq;
    strcpy(a.nombre, nombre.c_str());
    a.puntos = puntos;
    return a;
}

bool equipoEquals(Equipo a, Equipo b)
{
    if (a.idEq != b.idEq)
        return false;
    if (a.puntos != b.puntos)
        return false;
    return true;
}

string resultadoToString(Resultado x)
{
    char sep = 2;
    string sIdEq1 = to_string(x.idEq1);
    string sIdEq2 = to_string(x.idEq2);
    string sCodRes = to_string(x.codRes);
    string sEstadio = x.estadio;
    return sIdEq1 + sep + sIdEq2 + sep + sCodRes + sep + sEstadio;
}

Resultado resultadoFromString(string s)
{
    char sep = 2;
    Resultado x;
    string t0 = getTokenAt(s, sep, 0);
    x.idEq1 = stoi(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.idEq2 = stoi(t1);
    string t2 = getTokenAt(s, sep, 2);
    x.codRes = stoi(t2);
    string t3 = getTokenAt(s, sep, 3);
    strcpy(x.estadio, t3.c_str());
    return x;
}

string resultadoToDebug(Resultado x)
{
    stringstream sout;
    sout << "[";
    sout << x.idEq1;
    sout << ",";
    sout << x.idEq2;
    sout << ",";
    sout << x.codRes;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

string resultadoToDebug(string mssg, Resultado x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << x.idEq1;
    sout << ",";
    sout << x.idEq2;
    sout << ",";
    sout << x.codRes;
    sout << ",";
    sout << x.estadio;
    sout << "]";
    return sout.str();
}

Resultado resultado(int idEq1, int idEq2, int codRes, string estadio)
{
    Resultado a;
    a.idEq1 = idEq1;
    a.idEq2 = idEq2;
    a.codRes = codRes;
    strcpy(a.estadio, estadio.c_str());
    return a;
}

bool resultadoEquals(Resultado a, Resultado b)
{
    if (a.idEq1 != b.idEq1)
        return false;
    if (a.idEq2 != b.idEq2)
        return false;
    if (a.codRes != b.codRes)
        return false;
    return true;
}

string rEquipoToString(REquipo x)
{
    char sep = 3;
    string sE = equipoToString(x.e);
    string sAcum = to_string(x.acum);
    return sE + sep + sAcum;
}

REquipo rEquipoFromString(string s)
{
    char sep = 3;
    REquipo x;
    string t0 = getTokenAt(s, sep, 0);
    x.e = equipoFromString(t0);
    string t1 = getTokenAt(s, sep, 1);
    x.acum = stoi(t1);
    return x;
}

string rEquipoToDebug(REquipo x)
{
    stringstream sout;
    sout << "[";
    sout << equipoToDebug(x.e);
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

string rEquipoToDebug(string mssg, REquipo x)
{
    stringstream sout;
    sout << mssg << ":[";
    sout << equipoToDebug(x.e);
    sout << ",";
    sout << x.acum;
    sout << "]";
    return sout.str();
}

REquipo rEquipo(Equipo e, int acum)
{
    REquipo b;
    b.e = e;
    b.acum = acum;
    return b;
}

bool rEquipoEquals(REquipo a, REquipo b)
{
    if (!equipoEquals(a.e, b.e))
        return false;
    if (a.acum != b.acum)
        return false;
    return true;
}
