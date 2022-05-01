#include <iostream>
#include <string>
#include <time.h>
using namespace std;
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
Fecha fecha(int d, int m, int a)
{
    return {d, m, a};
}
string fechaToString(Fecha f)
{
    return to_string(f.dia) + "/" + to_string(f.mes) + "/" + to_string(f.anio);
}

bool fechaEsAnioBisiesto(Fecha f)
{
    bool bisiesto;
    ((f.anio % 4 == 0 && f.anio % 100 != 0) || f.anio % 400 == 0) ? bisiesto = true : bisiesto = false;
    return bisiesto;
}
void _getDate(int &dia, int &mes, int &anio)
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
void fechaHoy(Fecha &f)
{
    _getDate(f.dia, f.mes, f.anio);
}

int fechaDiasDelMes(Fecha f)
{
    int mes_en_dias = 31;
    if (f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11)
    {
        mes_en_dias = 30;
    }
    if (f.mes == 2)
    {
        mes_en_dias = fechaEsAnioBisiesto(f) ? 29 : 28;
    }
    return mes_en_dias;
}

bool validarFecha(Fecha f)
{
    int maxDias = fechaDiasDelMes(f);
    bool ret;
    if ((f.dia > 0 && f.dia <= maxDias) && (f.mes > 0 && f.mes <= 12) && (f.anio >= 0))
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}
