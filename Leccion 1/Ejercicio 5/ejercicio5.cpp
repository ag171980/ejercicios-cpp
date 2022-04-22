#include <iostream>
using namespace std;

int main() {
	int valor1, valor2;

	cout<<"Ingrese 2 valores: "<<endl;
	cin>>valor1;
	cin>>valor2;

	if(valor1>valor2){
	   cout<<"El mayor es: "<<valor1<< " y el menor es: "<<valor2<<endl;
	}else if(valor2 > valor1){
	   cout<<"El mayor es: "<<valor2<< " y el menor es: "<<valor1<<endl;
	}else{
	   cout<<"Los valores ingresados son iguales"<<endl;
	}

	return 0;
}
