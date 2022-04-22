//============================================================================
// Name        : 1216.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int valor1, valor2, valor3;
	int mayor, medio, menor;

	cout<<"Ingrese 3 numeros: "<<endl;
	cin>>valor1;
	cin>>valor2;
	cin>>valor3;

	if(valor1 > valor2 && valor1 > valor3){
      if(valor2 > valor3){
         medio = valor2;
         menor = valor3;
      }else{
         medio = valor3;
         menor = valor2;
      }
      mayor = valor1;
	}else if(valor2 > valor1 && valor2 > valor3){
      if(valor1 > valor3){
         medio = valor1;
         menor = valor3;
      }else{
         medio = valor3;
         menor = valor1;
      }
      mayor = valor2;
	}else{
      if(valor1 > valor2){
         medio = valor1;
         menor = valor2;
      }else{
         medio = valor2;
         menor = valor1;
      }
      mayor = valor3;
	}
	cout<<"El mayor es: "<<mayor<<", el del medio es: "<<medio<<" y el menor es: "<<menor<<endl;
	return 0;
}
