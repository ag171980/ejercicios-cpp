#include <iostream>
using namespace std;
/*Se ingresan por teclado dos valores numéricos enteros: a y b, se pide calcular e
informar el cociente a/b, validando que b sea distinto de cero. En tal caso, mostrar
un mensaje de error en la consola.
*/
int main()
{
    int a, b;
    cout << "Ingrese 2 valores: " << endl;
    cin >> a;
    cin >> b;

    if (b != 0)
    {
        cout << "El cociente entre los 2 numeros es: " << a / b << endl;
    }
    else
    {
        cout << "No se puede dividir un numero con cero" << endl;
    }

    return 0;
}