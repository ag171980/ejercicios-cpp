#include <iostream>
using namespace std;

int main() {
   int numA,numB,numero,contador = 1,iterador = 1;
   cout<<"Ingrese 3 numeros"<<endl;
   cin>>numero>>numA>>numB;
   while(contador <= numero) {
      while(iterador<=numero) {
         if((numA*contador)%numB != 0) {
            cout<<" ["<<iterador<<"] =>";
            cout<<numA*contador<<endl;
            iterador++;
         }
         contador++;
      }
   }
   return 0;
}
