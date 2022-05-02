#include <iostream>
#include "Hora.hpp"
using namespace std;
int main()
{
    Hora h1 = hora(14, 15, 30);
    cout << horaToString(h1) << endl;
    return 0;
}