#include <iostream>
#include "Fraccion.hpp"
using namespace std;
/*
Crear un TAD para encapsular la lógica de los números fraccionarios.
1. Analizar qué atributos debe tener su estructura.
Si hablamos de operaciones con numeros fraccionarios entonces necesitamos 
2 fracciones, que las mismas se componen con 4 numeros. Para eso un
struct Fraccion con 4 numeros, 2 para los numeradores y 2 para los denominadores.


2. Analizar qué funcionalidad debe proveer.
3. Desarrollar las funciones y la estructura del TAD.
4. Probar el desarrollo anterior.
*/

int main()
{
    Fraccion frac1 = fraccion(3, 4, 2, 5);
    cout << "Suma: " << sumaFraccion(frac1) << endl;
    cout << "Resta: " << restaFraccion(frac1) << endl;
    cout << "Producto: " << productoFraccion(frac1) << endl;
    cout << "Cociente: " << cocienteFraccion(frac1) << endl;

    return 0;
}
