#include <iostream>
using namespace std;
int fechaUnificar(int anio, int mes, int dia);
int main()
{
    int anio, mes, dia;
    cout << "Ingrese anio, mes y dia. En ese orden: " << endl;
    cin >> anio >> mes >> dia;
    cout << "La fecha ingresada (aaaa/mm/dd) es: " << fechaUnificar(anio, mes, dia) << endl;
    return 0;
}
int fechaUnificar(int anio, int mes, int dia)
{
    return (anio * 10000) + (mes * 100) + dia;
}