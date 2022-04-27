 #include <iostream>
using namespace std;

int main() {
   int fecha, anio, mes, dia;
   cout<<"Ingrese una fecha en formato aaaammdd: "<<endl;
   cin>>fecha;
   anio = fecha/10000; // anio vale: 2020
   mes = (fecha/100) - (anio*100);
   dia = fecha%100;
   cout<<"anio: "<<anio<<endl;
   cout<<"mes: "<<mes<<endl;
   cout<<"dia: "<<dia<<endl;
   cout<<"Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
	return 0;
}
