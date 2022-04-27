#include <iostream>
#include <time.h>
using namespace std;
int today();

int main()
{

    cout << "Hoy es: " << today() << endl;
    return 0;
}

int today()
{
    time_t timestamp;
    time(&timestamp);
    // separo la fecha actual en atributos
    struct tm *fechaActual = localtime(&timestamp);
    return ((fechaActual->tm_year + 1900)*10000) + ((fechaActual->tm_mon + 1)*100) + fechaActual->tm_mday;
}