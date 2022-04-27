#include <iostream>
using namespace std;
void fechaDividir(int f, int &a, int &m, int &d);
int main()
{
    int fecha, anio, mes, dia;
    cout << "Ingrese una fecha con formato aaaa/mm/dd : " << endl;
    cin >> fecha;
    fechaDividir(fecha, anio, mes, dia);
    cout << "Anio: " << anio << endl;
    cout << "Mes: " << mes << endl;
    cout << "Dia: " << dia << endl;
    return 0;
}
void fechaDividir(int f, int &a, int &m, int &d)
{
    a = f / 10000;
    m = (f / 100) - (a * 100);
    d = f % 100;
}