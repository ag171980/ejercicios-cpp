#include <iostream>
using namespace std;

int main() {
   int dia,mes,anio,fecha;
   cout<<"Ingrese dia"<<endl;
   cin>>dia;
   cout<<"Ingrese mes"<<endl;
   cin>>mes;
   cout<<"Ingrese anio"<<endl;
   cin>>anio;
   fecha = (anio*10000) + (mes*100) + dia;
   cout<<"Fecha ingresada: "<<fecha<<endl;
	return 0;
}
