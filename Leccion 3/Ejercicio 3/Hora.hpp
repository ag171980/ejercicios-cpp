#include <iostream>
#include <string>
using namespace std;

struct Hora
{
    int hora;
    int min;
    int seg;
};

Hora hora(int h, int m, int s)
{
    return {h, m, s};
}

string horaToString(Hora h)
{
    if (h.hora > 12)
    {
        return to_string(h.hora) + ":" + to_string(h.min) + ":" + to_string(h.seg) + " PM";
    }
    else
    {
        return to_string(h.hora) + ":" + to_string(h.min) + ":" + to_string(h.seg) + " AM";
    }
}