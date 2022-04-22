#include <iostream>
using namespace std;

int main() {
   int numero, contador = 0;
   cout << "escriba un numero entero" << endl;
   cin>>numero;
   if(numero == 0 || numero == 4 || numero == 1){
      contador++;
   }
   else
   {
      for(int i = 2; i <numero / 2 ; i++){
         if(numero%i==0){
               contador++;
         }
      }
   }
   (contador>0)? cout<<numero<<" no Es primo"<<endl: cout<<numero<<" es primo"<<endl;
   return 0;

}
