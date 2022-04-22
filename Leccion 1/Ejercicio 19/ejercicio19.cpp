#include <iostream>
using namespace std;
int main() {
	int contador =0,numero;
	int num_men_doce = 0, num_may_doce = 0, num_may_vein = 0, num_cero = 0;
	while(contador == 0) {
		cout<<"Ingrese valores numericos: ";
		cin>>numero;
		if(numero >=0){
			if(numero <=12) {
				num_men_doce++;
			} else if(numero>12 && numero<=24) {
				num_may_doce++;
			} else if(numero>24 && numero<=36) {
				num_may_vein++;
			}
			if(numero ==0) {
				num_cero++;
			}
		}else{
			contador = 1;
		}
	}
	cout<<"Cant. numeros iguales a cero: "<<num_cero<<endl;
	cout<<"Cant. numeros < = 12:   "<<num_men_doce<<endl;
	cout<<"Cant. numeros >12 y < = 24: "<<num_may_doce<<endl;
	cout<<"Cant. numeros > 24 y < = 36: "<<num_may_vein<<endl;
	return 0;
}
