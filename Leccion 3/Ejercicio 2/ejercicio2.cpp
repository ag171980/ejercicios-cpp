#include <iostream>
#include "Fecha.hpp"
using namespace std;
int main()
{
    // fecha actual es 1/5/2022
    // si le resto un dia queda en 30/4/2022
    // fecha 1: 23/3/2021 /// 1 anio, 1 mes y 8 dias

    // fecha 2: 12/7/2023 /// 1 anio, 2 meses y 11 dias
    Fecha fec1 = fecha(23, 3, 2021);
    Fecha fec2 = fecha(12, 7, 2023);

    Fecha fechaActual;
    fechaHoy(fechaActual);
    fechaMasCercana(fec1, fec2, fechaActual);
    // cout << "Hoy es: " << fechaToString(fechaActual) << endl;
    return 0;
}