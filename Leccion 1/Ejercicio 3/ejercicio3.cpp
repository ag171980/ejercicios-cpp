#include <iostream>
using namespace std;

int main() {
	int valor,quintaParte,restoDivision, septimaParte;

	cout<<"ingrese un valor: "<<endl;
	cin>>valor;

	quintaParte = valor/5;
	restoDivision = valor%5;
	septimaParte = quintaParte/7;

	cout<<"Quinta Parte "<<quintaParte<<endl;
	cout<<"Resto de la division "<<restoDivision<<endl;
	cout<<"Septima Parte "<<septimaParte<<endl;

	return 0;
}
