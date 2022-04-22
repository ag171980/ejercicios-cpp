#include <iostream>
using namespace std;

int main() {
	int lado1, lado2, lado3;
	cout<<"Ingrese 3 valores para su triangulo: "<<endl;
	cin>>lado1;
	cin>>lado2;
	cin>>lado3;

	if(lado1 == lado2 && lado2 == lado3 ){
	   cout<<"Es un triangulo equilatero"<<endl;
	}else if(lado1 != lado2 && lado2 != lado3){
	   cout<<"Es un triangulo escaleno"<<endl;
	}else{
	   cout<<"Es un triangulo isosceles"<<endl;
	}
	return 0;
}
