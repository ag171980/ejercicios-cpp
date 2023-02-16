#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
	//cadena tokenizada
	string s;
	char sep;
	int i;
};

template<typename T> //template es una funcion que parametriza los tipos de sus parametros
Coll<T> coll(char sep)
{
	Coll<T> c;
	c.s = "";
	c.sep = sep;
	return c;	
}

template<typename T>
Coll<T> coll()
{
	Coll<T> c;
	c.s = "";
	c.sep = '|';
	return c;
}

template<typename T>
int collSize(Coll<T> c)
{
	return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
	int i = collSize(c);
	for(int k=0;k<i;k++)
	{
		removeTokenAt(c.s,c.sep,0);
	}
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
	removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t)); //ahi agregue a la cadena tokenizada un token que representa al elemento t.
   return tokenCount(c.s,c.sep)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
	string x = tToString(t);
	setTokenAt(c.s,c.sep,x,p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s,c.sep,p)); //me devuelve un string.
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
  int h = tokenCount(c.s,c.sep);
  int i = 0 ;
  int ret = -1;

  while(i<h)
  {
     string x = getTokenAt(c.s,c.sep,i);
     T p = tFromString(x);
     if(cmpTK(p,k)==0)
     {
        ret = i;
     }
     i++;
  }
   return ret;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{ 
	T a, b, aux;
   bool ordenado = false;

   while(!ordenado)
   {
      ordenado = true;
      for(int i=0; i<collSize<T>(c)-1; i++)
	  {
         a = collGetAt<T>(c, i, tFromString);
         b = collGetAt<T>(c, i+1, tFromString);

         if(cmpTT(a, b) > 0)
		 {
            aux = a;
            a = b;
            b = aux;
            collSetAt<T>(c, a, i, tToString);
            collSetAt<T>(c, b, i+1, tToString);
            ordenado = false;
         }
      }
   }
}

template<typename T>
bool collHasNext(Coll<T>& c)
{
	return c.i<collSize(c);
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
	T t=collGetAt(c,c.i,tFromString);
	c.i++;
	return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
	endOfColl = false;
	T t;
	if(c.i<collSize<T>(c))
	{
		collGetAt<T>(c,c.i,tFromString);
		c.i++;
	}
	else
	{
		endOfColl = true;
	}
	return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
	c.i=0;
}

template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.s=substring(s,1);
	return c;
}


#endif
