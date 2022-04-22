#include <iostream>
using namespace std;

int main() {
   int iterador = 0, numero, factorial = 1;
   //ingresamos 5
   //5*4*3*2*1 = 120
   cout<<"Ingrese un numero: "<<endl;
   cin>>numero;
   while(numero>iterador){
      factorial *= numero - iterador;
      iterador++;
   }
   cout<<"El factorial de "<<numero<<" es: "<<factorial<<endl;
   return 0;
}
