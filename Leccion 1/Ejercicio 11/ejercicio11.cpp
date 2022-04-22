#include <iostream>
using namespace std;

bool esBisiesto(int anio){
   bool bisiesto;
   ((anio%4 == 0 && anio%100!=0) || anio%400==0)? bisiesto = true : bisiesto = false;
   return bisiesto;
}

int cantidad_dias_mes(int mes, int anio){
   int mes_en_dias = 31;
   if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
      mes_en_dias = 30;
   }
   if(mes == 2){
      mes_en_dias = esBisiesto(anio) ? 29 : 28;
   }
   return mes_en_dias;
}

int main() {
   int mes, anio;
   cout<<"Ingrese un mes considerando que 1 es enero, 2 es febrero... y el anio de ese mes"<<endl;
   cin>>mes>>anio;
   cout<<"El mes "<<mes<<" tiene "<<cantidad_dias_mes(mes, anio)<<" dias y es el anio "<<anio<<endl;
   return 0;
}
