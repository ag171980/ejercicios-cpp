#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include "potencia.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;
   while (s[i]!='\0')
   		i++;
   return i;
}

int charCount(string s,char c)
{
   int i=0,cont=0;
   while(s[i]!='\0')
	{
		if(s[i]==c)
			cont++;
		i++;	
	}
   return cont;
}

string substring(string s,int d,int h)
{
	string x="";
	int vueltas=(h-d);
	int i=d;
	for(int cantvueltas=0;cantvueltas<vueltas;cantvueltas++)
	{
		x+=s[i];
		i++;
	}
   return x;
}

string substring(string s,int d) // ok
{
   	string x;
	for(int i=d;s[i]!='\0';i++)
	{
		x+=s[i];
	}
   return x;
}

int indexOf(string s,char c) // ok
{
	int i=0;
	for(i ;s[i] != '\0'; i++ )
	{
		if(s[i]==c)
			return i;
	}
	if(i>=length(s))
		return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
	while(s[offSet]!=c)
	{
		offSet++;
	}
	return offSet;
}

int indexOf(string s,string toSearch) // ok
{
	int posicion_palabra=0;
	bool valorAsignado=false;
	for(int i=0;s[i]!='\0';i++)
	{
		if(substring(s,i,length(toSearch)+i)== toSearch && !valorAsignado)
		{
			posicion_palabra=i;
			valorAsignado=true;
		}
	}
	if(!valorAsignado)
		return -1;
 return posicion_palabra;
		
}

int indexOf(string s,string toSearch,int offset) // ok
{
	int posicion_palabra=0;
	bool valorAsignado=false;
	for(int i=offset;s[i]!='\0';i++)
	{
		if(substring(s,i,length(toSearch)+i)== toSearch && !valorAsignado)
		{
			posicion_palabra=i;
			valorAsignado=true;
		}
	}
	if(!valorAsignado)
		return -1;
	return posicion_palabra;
}

int lastIndexOf(string s,char c)
{
  	int i=length(s);
	while(s[i]!=c)
	{
		i--;
	}
	if(i<0)
		return -1;
	else
		return i; 
}

int indexOfN(string s,char c,int n)
{
   	int i=0,cont=0;
	bool aparicion=false;
	while(s[i]!='\0' && !aparicion)
	{
		i++;
		if(s[i]==c)
		{
			cont++;
			if(cont==n)
				aparicion=true;
		}
	}
	if(n==0)
		return -1;
	else if(n>cont)
		return length(s);
	else
		return i;
}

int charToInt(char c)
{
	int i,k;
	for(i=48;i!=c;i++)
	{
	}
	if(i==48)
		k=0;
	else if(i==49)
		k=1;
	else if(i==50)
		k=2;
	else if(i==51)
		k=3;
	else if(i==52)
		k=4;
	else if(i==53)
		k=5;
	else if(i==54)
		k=6;
	else if(i==55)
		k=7;
	else if(i==56)
		k=8;
	else if(i==57)
		k=9;
	if(i==65 || i==97)
		k=10;
	else if(i==66 || i==98)
		k=11;
	else if(i==67 || i==99)
		k=12;
	else if(i==68 || i==100)
		k=13;
	else if(i==69 || i==101)
		k=14;
	else if(i==70 || i==102)
		k=15;
	return k;
//Recibe entre 0 y 9
// si le mando '1' me devuelve int 1. asi hasta el 9
//Recibe entre A y F donde A es 10 y F es 15. minusculas tambien.
}

char intToChar(int i)
{
	char k;
	int s;
	if(i<10)
	{
		s=0;
		for(k=48;s<10;s++)
		{
			if(i==s)
			{
				return k;
			}
			k++;
		}
	}
	else if(i>=10)
	{
		s=10;
		for(k=65;s<35;s++)
		{
			if(i==s)
			{
				return k;
			}
			k++;
		}
	}
}

int getDigit(int n,int i)
{
	bool resolvio=false;
	int digit=0;
	for(int s=0;!resolvio;s++)
	{
		if(i==s)
		{
			digit=n%potencia(10,s+1);
			digit=digit/potencia(10,s);
			resolvio=true;
		}
	}
	return digit;
}

int digitCount(int n)
{
	bool resolvio=false;
	int cont=0;
	for(int i=0;!resolvio;i++)
	{
		if(getDigit(n,i)>0)
		{
			cont++;
		}
		else if(getDigit(n,i)==0)
		{
			if((n/potencia(10,cont))/1 >0)
				cont++;
			else if((n/potencia(10,cont))/1==0)
			{
				resolvio=true;
			}
		}
	}
	return cont;
}

string intToString(int i)
{
   string s ="";
   int tamanio,digito,cont=1;
   char digitochar;
   tamanio = digitCount(i);
   while(cont <= tamanio)
   {
		digito = getDigit(i,tamanio-cont);
   		digitochar = intToChar(digito);
   		s = s+digitochar;
   		cont++;
   }
   return s;
}

int stringToInt(string s,int b) // ok
{
	int n = length(s);
	int newInt = 0, m = n - 1;
	for (int j = 0; j < n; j++) 
	{
		int i = s[j];          //Asigna el valor ascii del caracter al int i.
		if (i >= 65 && i <= 70) //Si es una letra entre A y F
		{
			int k = (s[j] - 55);
			newInt += k * potencia(b, m);
		}
		else                   //si no es una letra
		{
			int k = (s[j] - 48);
			newInt += k * potencia(b, m);
		}
		m--;
	}
	return newInt;
}

int stringToInt(string s) // ok
{
   return stringToInt(s,10);
}

string charToString(char c)
{
   string s;
   s += c;
   return s;
}

char stringToChar(string s)
{
   int i=s[0];
   char c=i;
   return c;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
	char s[10];
	sprintf(s,"%.5f",d);
	return s;
}

double stringToDouble(string s)
{
   double d = atof(s.c_str());  
   return d;
}

bool isEmpty(string s)
{
	if(length(s)==0)
		return true;
	else
		return false;
}

bool startsWith(string s,string x)
{
	int desde=0,hasta = length(x);
	string subcadena = substring(s,desde,hasta);
	if(subcadena==x)
		return true;
	else
		return false;
}

bool endsWith(string s,string x)
{
   	int hasta = length(s), desde = hasta - length(x);
	string subcadena = substring(s,desde,hasta);
	if(subcadena==x)
		return true;
	else
		return false;
}

bool contains(string s,char c)
{
	if(charCount(s,c)>0)
		return true;
	else
		return false;
}

string replace(string s,char oldChar,char newChar)
{
	string x = "";
	if(contains(s,oldChar))
	{
		for(int i=0;i<length(s);i++)
		{
			if(s[i]==oldChar)
			{
				x += newChar;
			}
			else
				x += s[i];
		}
	}
	return x;
}

string insertAt(string s,int pos,char c)
{
	string x = "";
	x += substring(s,0,pos);
	x += c;
	x += substring(s,pos);
	return x;
}

string removeAt(string s,int pos)
{
   string x = "";
   x += substring(s,0,pos);
   x += substring(s,pos+1);
   return x;
   
}

string ltrim(string s)
{
	string vacio =" ";
	while(startsWith(s,vacio))
	{
		s= removeAt(s,0);
	}
	return s;
}

string rtrim(string s)
{
	string vacio=" ";
	while(endsWith(s,vacio))
	{
		s = removeAt(s,length(s)-1);
	}
	return s;
}

string trim(string s)
{
	s = ltrim(s);
	s = rtrim(s);
	return s;
}

string replicate(char c,int n)
{
	string x = "";
	int i = 0;
	while(length(x)<n)
	{
		x+=c;
		i++;
	}
	return x;
}

string spaces(int n)
{
	string x;
	x = replicate (' ',n);
	return x;
}

string lpad(string s,int n,char c)
{
	int longitud = length(s);
	int agregar = n - longitud;
	while(agregar>0)
	{
		s = insertAt(s,0,c);
		agregar--;
	}
	return s;
}

string rpad(string s,int n,char c)
{
	int longitud = length(s);
	int agregar = n - longitud;
	while(agregar>0)
	{
		s = insertAt(s,longitud,c);
		agregar--;
	}
	return s;
}

string cpad(string s,int n,char c)
{
	string x = s;
	int longitud = length(s);
	int agregar = n - longitud;
	while(agregar>0)
	{
		x = rpad(x,length(x)+1,c);
		agregar--;
		if(agregar>0)
			x = lpad(x,length(x)+1,c);
		agregar--;
	}
	return x;
}

bool isDigit(char c)
{
	if(charToInt(c)>=0 && charToInt(c)<10)
		return true;
	else
		return false;
}

bool isLetter(char c)
{
	int d = (int)c;
	if((d>=65 && d<=90) || (d>=97 && d<=122))  	
		return true;
	else
		return false;
}

bool isUpperCase(char c)
{
	int d = (int)c;
	if(d>=65 && d<=90) 	
		return true;
	else
		return false;
}

bool isLowerCase(char c)
{
	int d = (int)c;
	if(d>=97 && d<=122) 	
		return true;
	else
		return false;
}

char toUpperCase(char c)
{
	int d = (int)c;
	if(isLowerCase(c))
		c = d-32;
	return c;
}

char toLowerCase(char c)
{
	int d = (int)c;
	if(isUpperCase(c))
		c = d+32;
	return c;	
}

string toUpperCase(string s)
{
	string x = "";
	for(int i=0;i<length(s);i++)
	{
		char r = toUpperCase(s[i]);
		x += r;
	}
	return x;
}

string toLowerCase(string s)
{
	string x = "";
	for(int i=0;i<length(s);i++)
	{
		char r = toLowerCase(s[i]);
		x += r;
	}
	return x;
}

int cmpString(string a,string b)
{
	char c,d;
	int i = 0,letra1,letra2;
	bool entra=true;
	while(entra)
	{
		letra1 = (int)a[i];
		letra2 = (int)b[i];
		if(letra1>letra2)
			return 1;
		else if(letra1<letra2)
			return -1;
		else if(a==b)
			return 0;
		else if(letra1==letra2)
		{
			i++;
		}
	}
}

int cmpDouble(double a,double b)
{
	string c = doubleToString(a);
	string d = doubleToString(b);
	int result = cmpString(c,d);
	if(result>0)
		return result;
	else if(result<0)
		return result;
	else if(result==0)
		return result;
}

#endif







