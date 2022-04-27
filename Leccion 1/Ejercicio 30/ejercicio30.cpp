#include <iostream>
using namespace std;
int main()
{
	cout<<"Ingrese valores numericos: "<<endl;
	int a=1,b=0,cantel=0,contseg=0,cantultseg=0,pos=0,posmax=0,cantmax=0;
	while(a!=0)
	{
		cin>>a;
		if(a>b)
		{
			cantel++; 
			b=a;	
		}
		else
		{
			if(cantel>1)
			{
				cantel++;
				contseg++;
				cantultseg=cantel;
				pos=contseg;
				if(cantel>cantmax)
				{
					posmax=pos;
					cantmax=cantel;
				}
			}
			b=a;	
			cantel=0;
		}
	}
	cout<<"1. La cantidad de seguidillas es de "<<contseg<<endl;
	cout<<"2. Cantidad de elementos de cada seguidilla"<<endl;
	cout<<"3. La seguidilla mas larga se ingreso en la posicion relativa: "<<posmax<<endl;
}