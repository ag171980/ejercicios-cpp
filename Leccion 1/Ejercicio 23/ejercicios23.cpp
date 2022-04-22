#include <iostream>
using namespace std;
int main()
{
	int numero = 0, contador = 0, numMayorPositivo = 0, numeroMayorAMenosDiez = 0, numMayor = 0;
	while (contador < 100)
	{
		cout << "Ingrese valores positivos: " << endl;
		cin >> numero;
		if (contador == 0)
		{
			numMayorPositivo = numero;
			numeroMayorAMenosDiez = numero;
			numMayor = numero;
		}
		if (numero > -10 && numeroMayorAMenosDiez < numero)
		{
			numeroMayorAMenosDiez = numero;
		}
		if (numero > 0 && numMayorPositivo < numero)
		{
			numMayorPositivo = numero;
		}
		if (numMayor < numero)
		{
			numMayor = numero;
		}
		contador++;
	}
	if (numMayorPositivo > 0)
	{
		cout << "1. El mayor entero positivo es: " << numMayorPositivo << endl;
	}
	else
	{
		cout << "1. No se han ingresado valores enteros positivos " << endl;
	}
	if(numeroMayorAMenosDiez > -10){
		cout << "2. De los mayores a -10, el mayor es: " << numeroMayorAMenosDiez << endl;
	}else{
		cout << "2. No se han ingresado valores enteros mayores a -10" << endl;
	}
	cout << "3. El mayor es: " << numMayor << endl;
	return 0;
}
