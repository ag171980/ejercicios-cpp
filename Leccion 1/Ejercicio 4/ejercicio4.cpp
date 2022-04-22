#include <iostream>
using namespace std;

int main() {
	int valor1, valor2, mayor;
	cout<<"Ingrese 2 numeros: "<<endl;
	cin>>valor1;
	cin>>valor2;

	if(valor1>valor2){
	   mayor = valor1;
	}else{
	   mayor = valor2;
	}
	cout<<"El mayor es: "<<mayor<<endl;
	return 0;
}
