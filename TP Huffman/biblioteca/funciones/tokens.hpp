#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
	if(isEmpty(s))
		return 0;
	else
	{
		int count = charCount(s,sep) + 1;
		return count;
	}
}

void addToken(string& s,char sep,string t)
{
	if(!isEmpty(s))
		s += sep;
	s += t;
}

string getTokenAt(string s,char sep, int i)
{
	int possubstring,posfinal;
	possubstring = (indexOfN(s,sep,i)) + 1;
	posfinal = (indexOfN(s,sep,i+1));
	string x = substring(s,possubstring,posfinal);
	return x;
}

void removeTokenAt(string& s,char sep, int i)
{
	string x = "";
	string agregar ="";
	int cont=0;
	while(cont!=i)
	{	
		agregar += getTokenAt(s,sep,cont);
		addToken(x,sep,agregar);
		agregar = "";
		cont++;
	}
	cont++;
	while(cont<tokenCount(s,sep))
	{
		agregar += getTokenAt(s,sep,cont);
		addToken(x,sep,agregar);
		agregar = "";
		cont++;
	}
	s = x;
}

void setTokenAt(string& s,char sep, string t,int i)
{
	removeTokenAt(s,sep,i);
	string x = "";
	string agregar=x;
	int cont = 0;
	while(cont!=i)
	{
		agregar +=getTokenAt(s,sep,cont);
		addToken(x,sep,agregar);
		agregar= "";
		cont++;
	}
	addToken(x,sep,t);
	while(cont<tokenCount(s,sep))
	{
		agregar += getTokenAt(s,sep,cont);
		addToken(x,sep,agregar);
		agregar = "";
		cont++;
	}
	s=x;
}

int findToken(string s,char sep, string t)
{
	string token = "";
	int i=0;
	while(i<tokenCount(s,sep))
	{
		token += getTokenAt(s,sep,i);
		if(token == t)
			return i;
		else
			i++;
		token = "";
	}
}

#endif
