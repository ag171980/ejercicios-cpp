#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int valor1, valor2;
    cout << "Ingrese 2 valores: " << endl;
    cin >> valor1 >> valor2;

    cout << "La suma es: " << valor1 + valor2 << endl;
    cout << "La resta es: " << valor1 - valor2 << endl;
    cout << "La multiplicacion es: " << valor1 * valor2 << endl;
    if (valor2 != 0)
    {
        cout << "La division es: " << valor1 / valor2 << endl;
    }
    else
    {
        cout << "No se puede dividir por cero" << endl;
    }
    system("PAUSE");
    return 0;
}