#include <iostream>
using namespace std;
int main()
{
	int numero, contador = 0, mayor_negativos, menor_positivos, primerNumeroPositivo = 0, primerNumeroNegativo = 0;
	while (contador == 0)
	{
		cout << "Ingrese un valor numerico. Para finalizar ingrese 0: ";
		cin >> numero;
		if (numero > 0)
		{
			if (primerNumeroPositivo == 0)
			{
				menor_positivos = numero;
				primerNumeroPositivo++;
			}
			if (numero < menor_positivos)
			{
				menor_positivos = numero;
			}
		}
		if (numero < 0)
		{
			if (primerNumeroNegativo == 0)
			{
				mayor_negativos = numero;
				primerNumeroNegativo++;
			}
			if (numero > mayor_negativos)
			{
				mayor_negativos = numero;
			}
		}
		if (numero == 0)
		{
			contador++;
		}
	}
	cout << "------------------------------------------------" << endl;
	cout << "El numero mayor negativo de los ingresados es: " << mayor_negativos << endl;
	cout << "El numero menor positivo de los ingresados es: " << menor_positivos << endl;
	return 0;
}
