#include <iostream>
using namespace std;
int main() {
	int contador = 0,numero, positivos = 0,num_positivo = 0, negativos = 0, num_negativo = 0,num_ingresado = 0,num_par = 0;
	float promedio;
	while(contador == 0) {
		cout<<"Ingrese valores. Finaliza al elegir 0"<<endl;
		cin>>numero;
		if(numero == 0) {
			contador++;
		} else {
			if(numero > 0) {
				num_positivo += numero;
				positivos++;
			} else if(numero < 0) {
				num_negativo += numero;
				negativos++;
			}
			if(numero%2 == 0) {
				num_par++;
			}
			num_ingresado++;
		}
	}
	promedio = num_positivo/positivos;
	cout<<"1. Nros Positivos: "<<positivos<<endl;
	cout<<"2. Nros Negativos: "<<negativos<<endl;
	cout<<"3. % de pares: "<<(num_par*100)/num_ingresado<<"%"<<endl;
	cout<<"4. Promedio de los positivos: "<<promedio<<endl;
	cout<<"5. % de negativos: "<<(negativos*100)/num_ingresado<<"%"<<endl;
	return 0;
}
