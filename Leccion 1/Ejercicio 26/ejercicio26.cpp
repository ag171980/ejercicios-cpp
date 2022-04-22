#include <iostream>
using namespace std;
int main() {
	int numero,condicion = 0, numero_menor, contador=0;
	while(condicion==0) {
		cout<<"Ingresa un numero: ";
		cin>>numero;
		if(numero !=0) {
			if(numero >= -16 && numero <= 27) {
				if(contador == 0) {
					numero_menor = numero;
					contador++;
				}
				if(numero_menor>numero) {
					numero_menor = numero;
				}
			}
		} else {
			condicion++;
		}
	}
	cout<<"El numero menor dentro del intervalo [-16,27] es: "<<numero_menor<<endl;
	return 0;
}
