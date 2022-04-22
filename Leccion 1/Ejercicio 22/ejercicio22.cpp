#include <iostream>
using namespace std;
// ej: n=10, a=5, b=3
// salida: 5,10,20,25,35,40,50,55,65,70
int main()
{
	int numA, numB, numero, contador = 1, iterador = 1;
	cout << "Ingresa 3 numeros, e informar el n-esimo multiplo de a que no es multiplo de b (n, a y b): " << endl;
	cin >> numero >> numA >> numB;
	while (contador <= numero)
	{
		while (iterador <= numero)
		{
			if ((numA * contador) % numB != 0)
			{
				cout << "[" << iterador << "]=> ";
				cout << numA * contador << endl;
				iterador++;
			}
			contador++;
		}
	}
	return 0;
}
