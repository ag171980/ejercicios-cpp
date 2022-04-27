#include <iostream>
#include <time.h>
using namespace std;
void getDate(int &dia, int &mes, int &anio);
int main()
{
    int d, m, a;
    getDate(d, m, a);
    cout << "Dia: " << d << endl;
    cout << "Mes: " << m << endl;
    cout << "Anio: " << a << endl;
    return 0;
}
void getDate(int &dia, int &mes, int &anio)
{
    // fecha actual expresada en segundos
    time_t timestamp;
    time(&timestamp);
    // separo la fecha actual en atributos
    struct tm *fechaActual = localtime(&timestamp);
    dia = fechaActual->tm_mday;
    mes = fechaActual->tm_mon + 1;
    anio = fechaActual->tm_year + 1900;
}