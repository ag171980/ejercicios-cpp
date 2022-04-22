
#include <iostream>
using namespace std;

// bool esPrimo(int numero){
//    bool primo = true;
//    int i = 2;
//    while(i<numero && primo){
//       if(numero%i==0){
//          primo = false;
//       }else{
//          i++;
//       }
//    }
//    return primo;
// }
int main()
{
   int num1, num2, contador = 0, suma = 0;
   cout << "Ingrese 2 numero para multiplicarlos mediante sumas sucesivas" << endl;
   cin >> num1 >> num2;
   while (contador < num2)
   {
      suma+= num1;
      contador++;
   }
   cout<<suma<<endl;
   // int nroAEval = 2;
   // int cont = 0;
   // while (cont < n)
   // {

   //    if (esPrimo(nroAEval))
   //    {
   //       cout << nroAEval << endl;
   //       cont++;
   //    }
   //    nroAEval++;
   // }
   return 0;
}
