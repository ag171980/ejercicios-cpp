#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../API/biblioteca/funciones/strings.hpp"
#include "../API/biblioteca/funciones/tokens.hpp"
#include "../API/biblioteca/tads/Coll.hpp"
using namespace std;

struct Alumno
{
    int legajo;
    char nombre[50];
};

struct Nota
{
    int legajo;
    int nota;
};
string alumnoToString(Alumno x)
{
	char sep = 1;
	string sLegajo=to_string(x.legajo);
	string sNombre=x.nombre;
	return sLegajo+sep+sNombre;
}

Alumno alumnoFromString(string s)
{
	char sep = 1;
	Alumno x;
	string t0 = getTokenAt(s,sep,0);
	x.legajo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string alumnoToDebug(Alumno x)
{
	stringstream sout;
	sout<< "[";
	sout << x.legajo;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string alumnoToDebug(string mssg,Alumno x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.legajo;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Alumno alumno(int legajo,string nombre)
{
	Alumno a;
	a.legajo = legajo;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool alumnoEquals(Alumno a,Alumno b)
{
	if(a.legajo!=b.legajo) return false;
	return true;
}

string notaToString(Nota x)
{
	char sep = 2;
	string sLegajo=to_string(x.legajo);
	string sNota=to_string(x.nota);
	return sLegajo+sep+sNota;
}

Nota notaFromString(string s)
{
	char sep = 2;
	Nota x;
	string t0 = getTokenAt(s,sep,0);
	x.legajo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.nota=stoi(t1);
	return x;
}

string notaToDebug(Nota x)
{
	stringstream sout;
	sout<< "[";
	sout << x.legajo;
	sout << ",";
	sout << x.nota;
	sout<< "]";
	return sout.str();
}

string notaToDebug(string mssg,Nota x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.legajo;
	sout << ",";
	sout << x.nota;
	sout<< "]";
	return sout.str();
}

Nota nota(int legajo,int nota)
{
	Nota a;
	a.legajo = legajo;
	a.nota = nota;
	return a;
}

bool notaEquals(Nota a,Nota b)
{
	if(a.legajo!=b.legajo) return false;
	if(a.nota!=b.nota) return false;
	return true;
}

#endif