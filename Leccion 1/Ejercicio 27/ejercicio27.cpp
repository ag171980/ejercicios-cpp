#include <iostream>
using namespace std;
int main()
{
	int contador = 0, fechaMasVieja, fechaMasJoven, primerPos = 0;
	string nombreMasVieja, nombreMasJoven;

	while (contador < 3)
	{
		int fecha;
		string nombre;
		cout << "Ingrese un nombre: " << endl;
		cin >> nombre;
		cout << "Ingrese la fecha de nacimiento (aaaammdd): " << endl;
		cin >> fecha;
		cout<<"----------------------"<<endl;

		if (primerPos == 0)
		{
			fechaMasJoven = fecha;
			nombreMasJoven = nombre;
			fechaMasVieja = fecha;
			nombreMasVieja = nombre;

			primerPos++;
		}
		if (fecha > fechaMasJoven)
		{
			fechaMasJoven = fecha;
			nombreMasJoven = nombre;
		}
		if (fecha < fechaMasVieja)
		{
			fechaMasVieja = fecha;
			nombreMasVieja = nombre;
		}
		contador++;
	}
	cout << "Mas joven: " << nombreMasJoven << endl;
	cout << "Mas viejo: " << nombreMasVieja << endl;

	return 0;
}
