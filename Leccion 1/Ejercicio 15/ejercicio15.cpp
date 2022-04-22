#include <iostream>
#include <math.h>
using namespace std;

bool esPrimo(int v)
{
   int i=2;
   bool esPrimo=true;

   while( i<v && esPrimo )
   {
      if( v%i==0 )
      {
         esPrimo=false;
      }
      i++;
   }
   return esPrimo;
}

int main() {
   int i=2, contador = 0, numeroDePrimos;
      cout << "Ingrese cuantos primos quiere ver: " << endl;
      cin >> numeroDePrimos;

      cout<<"Los numeros primos son: ";
      while( contador < numeroDePrimos)
      {
         if(esPrimo(i))
         {
            cout << i<<" ";
            contador++;
         }
         i++;
      }
      return 0;
}
