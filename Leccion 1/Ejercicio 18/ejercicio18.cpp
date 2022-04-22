#include <iostream>
using namespace std;
int main(){
	int numero,factorial = 1;
	cout<<"Ingrese el numero del que desea sacar el factor: ";
	cin>>numero;
	int i = 1; 
	while(i <=numero){
		factorial*=i;
		cout<<"Factorial de "<<i<<" es: "<<factorial<<endl;
		i++;
	}
	return 0;
}
