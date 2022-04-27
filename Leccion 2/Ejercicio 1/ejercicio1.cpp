#include <iostream>
using namespace std;
double factorial(int ing, int num);
int main()
{
    int numero, i = 1, fac = 1;
    cout << "Ingrese el numero de factoriales que desea ver: " << endl;
    cin >> numero;
    factorial(numero, i);
    return 0;
}
double factorial(int ing, int num)
{
    int factorial = 1;
    while (num <= ing)
    {
        factorial *= num;
        cout << "Factorial de " << num << " es: " << factorial << endl;
        num++;
    }

    return factorial;
}