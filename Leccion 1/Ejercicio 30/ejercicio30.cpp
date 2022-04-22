#include <iostream>
using namespace std;

int main()
{
   cout<<"Ingrese valores numericos: "<<endl;
   int valor1=1, valor2=0, posicion=0, posicionMaxima=0, cantidadMaxima=0, contadorSeguidillas=0, cantidadElementos=0,cantultseg=0;
//   int arr[4];

   while(valor1 != 0)
   {
      cin>>valor1;
      cout<<"valor 2: "<<valor2<<endl;
      //entra por primera vez para q valor2 tenga el primer
      if(valor1 > valor2)
      {
         valor2 = valor1;
      }
      else
      {
         contadorSeguidillas++;
         cantultseg = cantidadElementos;
         posicion = contadorSeguidillas;
         if(cantidadElementos > cantidadMaxima)
         {
            posicionMaxima = posicion;
            cantidadMaxima = cantidadElementos;
//            arr[posicion] = cantidadElementos;
            cout<<"Cantidad de elementos: "<<cantidadElementos<<endl;
         }

         valor2 = valor1;
         cantidadElementos = 0;
      }
      cantidadElementos++;
   }
//   for(int i = 0; i < 4;i++){
//      cout<<arr[i]<<endl;
//   }
   cout<<"a"<<endl;
   cout<<"1. La cantidad de seguidillas es de "<<contadorSeguidillas<<endl;
   cout<<"2. Cantidad de elementos de cada seguidilla"<<endl;
   cout<<"3. La seguidilla mas larga se ingreso en la posicion relativa: "<<posicionMaxima<<endl;
   return 0;
}
