#include <iostream>
using namespace std;
int main()
{
	int numero = 0, contador = 0, numMenorNegativos = 0, numeroMayorADiez = 0, numMenor = 0;
	while (contador < 5)
	{
		cout << "Ingrese valores: " << endl;
		cin >> numero;
		if (contador == 0)
		{
			numMenorNegativos = numero;
			numeroMayorADiez = numero;
			numMenor = numero;
		}
		// 1.
		if (numero < 0 && numMenorNegativos < numero)
		{
			numMenorNegativos = numero;
		}
		if (numero > 10 && numeroMayorADiez < numero)
		{
			numeroMayorADiez = numero;
		}
		if (numMenor < numero)
		{
			numMenor = numero;
		}
		contador++;
	}
	cout << "----------------" << endl;
	
	if (numMenorNegativos < 0)
	{
		cout <<"1. El menor valor entero negativo es: "<< numMenorNegativos << endl;
	}
	else
	{
		cout << "1. No se han ingresado valores enteros negativos " << endl;
	}
	if(numeroMayorADiez > 10){
		cout << "2. De los mayores a -10, el mayor es: " << numeroMayorADiez << endl;
	}else{
		cout << "2. No se han ingresado valores enteros mayores a 10" << endl;
	}
	cout << "3. El mayor es: " << numMenor << endl;
	return 0;
}
