#include <iostream>
#include <string>
#include "../../API/biblioteca/funciones/strings.hpp"
using namespace std;
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
int main()
{

    // Creamos archivo y guardamos
    //  FILE* f = fopen("fracciones.qq", "w+b");

    // write<Fraccion>(f,fraccion(2,3));
    // write<Fraccion>(f,fraccion(4,5));
    // write<Fraccion>(f,fraccion(9,2));

    // fclose(f);

    // Leemos archivo y mostramos

    // FILE *f = fopen("fracciones.qq", "r+b");
    // Fraccion p = read<Fraccion>(f);
    
    // while (!feof(f))
    // {
    //     cout << fraccionToString(p) << endl;
    //     p = read<Fraccion>(f);
    // }

    // fclose(f);
    return 0;
}