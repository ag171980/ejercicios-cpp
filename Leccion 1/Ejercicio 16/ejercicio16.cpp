#include <iostream>
using namespace std;
//Ejercicio 16
/*Dado un valor entero n, informar el n-�simo t�rmino de la sucesi�n de Fibonacci. Por
ejemplo: si n==6, la salida del programa debe ser 8(1, 1, 2, 3, 5, 8).*/
int main() {
	int n;
	int num_aux = 1;
	int num_fibo = 0;
	cout<<"Ingresar un valor: ";
	cin>>n;
	for(int i =1; i<=n; i++) {
		num_aux= num_aux + num_fibo;
		num_fibo = num_aux - num_fibo;
		cout<<num_fibo<<" ";
	}

	return 0;
}

