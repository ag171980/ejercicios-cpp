#include <iostream>
#include <string>
#include "../../API/biblioteca/funciones/strings.hpp"
using namespace std;
// double fact(int n);
// void invocar(string msg, double x(int));
template <typename T>
void comparaYMuestra(T a, T b, T c, int cmpTT(T, T), string tToString(T))
{
    T mayor, medio, menor;
    if (cmpTT(a, b) > 0 && cmpTT(a, c) > 0)
    {
        mayor = a;
        if (cmpTT(b, c) > 0)
        {
            medio = b;
            menor = c;
        }
        else
        {
            medio = c;
            menor = b;
        }
    }
    else
    {
        if (cmpTT(b, a) > 0 && cmpTT(b, c) > 0)
        {
            mayor = b;
            if (cmpTT(a, c) > 0)
            {
                medio = a;
                menor = c;
            }
            else
            {
                medio = c;
                menor = a;
            }
        }
        else
        {
            mayor = c;
            if (cmpTT(a, b) > 0)
            {
                medio = a;
                menor = b;
            }
            else
            {
                medio = b;
                menor = a;
            }
        }
    }
    cout << "Mayor: " << tToString(mayor) << endl;
    cout << "Medio: " << tToString(medio) << endl;
    cout << "Menor: " << tToString(menor) << endl;
}
// Fraccion
struct Fraccion
{
    int n;
    int d;
};
Fraccion fraccion(int n, int d)
{
    return {n, d};
}
string fraccionToString(Fraccion f)
{
    return to_string(f.n) + "/" + to_string(f.d);
}
int cmpFraccion(Fraccion a, Fraccion b)
{
    double ra = (double)a.n / a.d;
    double rb = (double)b.n / b.d;

    return (ra < rb) ? -1 : ((ra > rb) ? 1 : 0);
}
// Persona
struct Persona
{
    int dni;
    string nombre;
};
Persona persona(int d, string n)
{
    return {d, n};
}

string personaToString(Persona p)
{
    return to_string(p.dni) + ", " + p.nombre;
}
int cmpPersona(Persona a, Persona b)
{
    return a.dni - b.dni;
}
int cmpPersona2(Persona a, Persona b)
{
    return (a.nombre < b.nombre) ? -1 : ((a.nombre > b.nombre) ? 1 : 0);
}
int cmpPersona3(Persona a, Persona b)
{
    return (length(a.nombre) < length(b.nombre)) ? -1 : ((length(a.nombre) > length(b.nombre)) ? 1 : 0);
}
int main()
{
    comparaYMuestra<Fraccion>(fraccion(3, 5), fraccion(2, 3), fraccion(1, 2), cmpFraccion, fraccionToString);
    cout << "----" << endl;
    comparaYMuestra<Persona>(persona(123, "Pedro"), persona(412, "Juan"), persona(125, "Carlos"), cmpPersona, personaToString);
    cout << "----" << endl;
    comparaYMuestra<Persona>(persona(123, "Pedro"), persona(412, "Juan"), persona(125, "Carlos"), cmpPersona2, personaToString);
    cout << "----" << endl;
    comparaYMuestra<Persona>(persona(123, "Pedro"), persona(412, "Juan"), persona(125, "Carlos"), cmpPersona3, personaToString);
    // invocar("Factorial", fact);
    return 0;
}
// double fact(int n)
// {
//     double f = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         f *= i;
//     }
//     return f;
// }
// void invocar(string msg, double x(int))
// {
//     for (int i = 1; i < 5; i++)
//     {
//         double d = x(i);
//         cout << msg << " de " << i << " = " << d << endl;
//     }
// }