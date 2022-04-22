#include <iostream>
using namespace std;
int main()
{
	int numero, men_diez = 0;
	float promedio, cant_may = 0.0, contador = 0;
	while (contador < 8)
	{
		cout << "Ingrese un valor numerico: ";
		cin >> numero;
		if (numero > 100)
		{
			cant_may++;
		}
		else if (numero < -10)
		{
			men_diez += numero;
		}
		contador++;
	}
	promedio = (cant_may / contador)*100;
	cout << "1. Promedio de mayores a 100: " << promedio <<"%"<< endl;
	cout << "2. Suma de los menores a -10: " << men_diez << endl;
	return 0;
}
