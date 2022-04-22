#include <iostream>
using namespace std;

int main()
{
	int conjuntos, valores, contadorConjuntos = 1, contadorValores = 0;
	int maxValor = 0, sumaValores = 0, cantValoresPositivos = 0;
	int minValorLote = 0, sumaValoresLote = 0, cantTotalValores = 0, cantValoresNegativosTotal = 0, primerEntrada = 0;
	cout << "Ingrese cantidad de conjuntos: " << endl;
	cin >> conjuntos;
	while (contadorConjuntos <= conjuntos)
	{
		cout << "Cantidad de valores para el Conjunto[" << contadorConjuntos << "]" << endl;
		cin >> valores;
		int valor;
		cout << "contValores: " << contadorValores << " valores: " << valores << endl;
		while (contadorValores < valores)
		{
			cout << "Ingrese un valor: " << endl;
			cin >> valor;
			if (contadorValores == 0)
			{
				if(primerEntrada == 0){
					minValorLote = valor;
				}
				maxValor = valor;
				primerEntrada++;
			}
			if (valor > maxValor)
			{
				maxValor = valor;
			}
			if (valor < minValorLote)
			{
				minValorLote = valor;
			}
			if (valor > 0)
			{
				cantValoresPositivos++;
			}
			if (valor < 0)
			{
				cantValoresNegativosTotal++;
			}
			cantTotalValores++;

			sumaValores += valor;
			contadorValores++;
		}
		cout << "----------------------------------------" << endl;
		cout << "Conjunto[" << contadorConjuntos << "]" << endl;
		cout << "A. Promedio: " << sumaValores / valores << endl;
		cout << "B. Maximo valor: " << maxValor << endl;
		cout << "C. Porcentaje de valores positivos: " << (cantValoresPositivos * 100) / valores << "%" << endl;
		cout << "----------------------------------------" << endl;

		sumaValoresLote += sumaValores;

		sumaValores = 0;
		maxValor = 0;
		cantValoresPositivos = 0;
		contadorValores = 0;
		contadorConjuntos++;
	}
	cout << "Lote de datos: " << endl;
	cout << "A. Valor promedio: " << sumaValoresLote / cantTotalValores << endl;
	cout << "B. Porcentaje de valores negativos: " << (cantValoresNegativosTotal * 100) / cantTotalValores << "%" << endl;
	cout << "C. Valor minimo: " << minValorLote << endl;
	// cout << "Conjuntos: " << conjuntos << endl;
	// cout << "Valores: " << valores << endl;
	return 0;
}
