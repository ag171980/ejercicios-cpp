#include <iostream>
using namespace std;
int minimo(int num1, int num2, int num3);
int maximo(int num1, int num2, int num3);
int medio(int num1, int num2, int num3);
int main()
{
    int numero1, numero2, numero3;
    int max, min, med;
    cout << "Ingrese 3 valores numericos diferentes entre si: " << endl;
    cin >> numero1 >> numero2 >> numero3;
    cout << "Maximo: " << maximo(numero1, numero2, numero3) << endl;
    cout << "Minimo: " << minimo(numero1, numero2, numero3) << endl;

    return 0;
}
// int medio(int num1, int num2, int num3){
    
// }
int maximo(int num1, int num2, int num3)
{
    int ret;
    if (num1 > num2 && num1 > num3)
    {
        ret = num1;
    }
    else if (num2 > num1 && num2 > num3)
    {
        ret = num2;
    }
    else
    {
        ret = num3;
    }
    return ret;
}
int minimo(int num1, int num2, int num3)
{
    int ret;
    if (num1 < num2 && num1 < num3)
    {
        ret = num1;
    }
    else if (num2 < num1 && num2 < num3)
    {
        ret = num2;
    }
    else
    {
        ret = num3;
    }
    return ret;
}