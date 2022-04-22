#include <iostream>
#include <string.h>
using namespace std;
struct Persona {
	char nombre[20];
	int fecha_nacimiento;
};
int main() {
	int contador =0,validar=0, mayor_fecha, menor_fecha;
	char menor_nombre[20];
	char mayor_nombre[20];
	Persona p[3];
	while(contador<3) {
		cout<<"Ingrese un nombre: ";
		cin>>p[contador].nombre;
		cout<<"Ingrese la fecha de nacimiento: ";
		cin>>p[contador].fecha_nacimiento;
		contador++;
	}
	for(int i =0; i<contador; i++) {
		if(validar == 0) {
			strcpy(menor_nombre, p[i].nombre);
			strcpy(mayor_nombre, p[i].nombre);
			menor_fecha = p[i].fecha_nacimiento;
			mayor_fecha = p[i].fecha_nacimiento;
			validar++;
		}
		if(p[i].fecha_nacimiento < menor_fecha) {
			menor_fecha = p[i].fecha_nacimiento;
			strcpy(menor_nombre, p[i].nombre);
		}
		if(p[i].fecha_nacimiento > mayor_fecha) {
			mayor_fecha = p[i].fecha_nacimiento;
			strcpy(mayor_nombre, p[i].nombre);
		}
	}
	cout<<"Persona mas joven: "<<endl;
	cout<<"Nombre: "<<menor_nombre<<endl;
	cout<<"Fecha de Nacimiento: "<<menor_fecha<<endl;
	cout<<"Persona mas vieja: "<<endl;
	cout<<"Nombre: "<<mayor_nombre<<endl;
	cout<<"Fecha de Nacimiento: "<<mayor_fecha<<endl;

	return 0;
}
