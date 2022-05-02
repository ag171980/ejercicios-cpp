#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
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

string fechaToString(Fecha f)
{
    return to_string(f.dia) + "/" + to_string(f.mes) + "/" + to_string(f.anio);
}

void fechaMasCercana(Fecha &f1, Fecha &f2, Fecha &fActual)
{
    cout << "La fecha actual es: " << fechaToString(fActual) << endl;
    int diffAnio1 = abs(fActual.anio - f1.anio);
    int diffAnio2 = abs(fActual.anio - f2.anio);
    if (diffAnio1 == diffAnio2)
    {
        int diffMes1 = abs(fActual.mes - f1.mes);
        int diffMes2 = abs(fActual.mes - f2.mes);
        if (diffMes1 == diffMes2)
        {
            int diffDia1 = abs(fActual.dia - f1.dia);
            int diffDia2 = abs(fActual.dia - f2.dia);
            if (diffDia1 == diffDia2)
            {
                cout << "Las fechas son exactamente iguales!!" << endl;
            }
            else if (diffDia1 < diffDia2)
            {
                cout << "La fecha: " << fechaToString(f1) << " es la mas cercana a la actual" << endl;
            }
            else
            {
                cout << "La fecha: " << fechaToString(f2) << " es la mas cercana a la actual" << endl;
            }
        }
        else if (diffMes1 < diffMes2)
        {
            cout << "La fecha: " << fechaToString(f1) << " es la mas cercana a la actual" << endl;
        }
        else
        {
            cout << "La fecha: " << fechaToString(f2) << " es la mas cercana a la actual" << endl;
        }
    }
    else if (diffAnio1 < diffAnio2)
    {
        cout << "La fecha: " << fechaToString(f1) << " es la mas cercana a la actual" << endl;
    }
    else
    {
        cout << "La fecha: " << fechaToString(f2) << " es la mas cercana a la actual" << endl;
    }
    // cout << "diffAnio1: " << diffAnio1;
    // cout << "diffAnio1: " << diffAnio2;
}