#include <iostream>
#include <string>
using namespace std;
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
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
Fecha fecha(int d, int m, int a)
{
    return {d, m, a};
}
string fechaToString(Fecha f)
{
    return to_string(f.dia) + "/" + to_string(f.mes) + "/" + to_string(f.anio);
}

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
int main()
{
    Persona per = persona("Mateo", 11222333, fecha(27, 04, 2022), direccion("Calle Falsa ", 123));
    cout << personaToString(per) << endl;
    return 0;
}