#include <iostream>
#include <string>
#include "Fecha.hpp"
using namespace std;

struct Direccion
{
    string calle;
    int nro;
};
struct Persona
{
    string nombre;
    int dni;
    Fecha fechaNacimiento;
    Direccion direccion;
};

Direccion direccion(string n, int nro)
{
    return {n, nro};
}
string direccionToString(Direccion dir)
{
    return dir.calle + "" + to_string(dir.nro);
}

Persona persona(string n, int dni, Fecha fec, Direccion dir)
{
    return {n, dni, fec, dir};
}
string personaToString(Persona p)
{
    string x = "";
    x = x + p.nombre + ", ";
    x = x + to_string(p.dni) + ", ";
    x = x + direccionToString(p.direccion) + ", ";
    x = x + fechaToString(p.fechaNacimiento);
    return x;
}
Fecha fechaAddDias(Fecha fecha, int n)
{
    Fecha ret;
    ret.dia = fecha.dia + n;
    ret.mes = fecha.mes;
    ret.anio = fecha.anio;
    return ret;
}
int main()
{

    // Persona per = persona("Mateo", 11222333, fecha(27, 04, 2022), direccion("Calle Falsa ", 123));
    // cout << personaToString(per) << endl;

    Fecha f1 = fecha(2, 3, 2021);
    cout << fechaToString(f1) << endl;
    Fecha fh2;
    fechaHoy(fh2);
    cout << "Hoy es: " << fechaToString(fh2) << endl;
    // Fecha f2 = fecha("4/5/2022");

    // int d, m, a;
    // cout << "Ingrese dia, mes y anio: " << endl;
    // cin >> d >> m >> a;
    // Fecha f1 = fecha(d, m, a);
    // cout << "Usted ingreso la fecha: " << fechaToString(f1) << endl;

    // int n;
    // cout << "Ingrese una cantidad de dias: " << endl;
    // cin >> n;

    // Fecha f2 = fechaAddDias(f1, n);
    // string s = fechaToString(f2);
    // cout << "Dentro de " << n << "dias sera: " << s << endl;
    return 0;
}