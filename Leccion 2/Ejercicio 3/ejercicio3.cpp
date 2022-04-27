#include <iostream>
using namespace std;
bool fechaEsAnioBisiesto(int anio);
int fechaDiasMes(int mes, int anio);
int main()
{
    int mes, anio;
    cout << "Ingrese un numero que represente un mes, luego un anio (considerando que 1 es Enero, 2 es Febrero, etc...)" << endl;
    cin >> mes >> anio;

    cout << "El mes " << mes << " tiene " << fechaDiasMes(mes, anio) << " dias y es el anio " << anio << endl;
    return 0;
}

bool fechaEsAnioBisiesto(int anio)
{
    bool esBisiesto;
    ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) ? esBisiesto = true : esBisiesto = false;
    return esBisiesto;
}
int fechaDiasMes(int mes, int anio)
{
    int mes_en_dias = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        mes_en_dias = 30;
    }
    if (mes == 2)
    {
        mes_en_dias = fechaEsAnioBisiesto(anio) ? 29 : 28;
    }
    return mes_en_dias;
}