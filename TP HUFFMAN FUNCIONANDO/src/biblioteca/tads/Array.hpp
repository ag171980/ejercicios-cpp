#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
	T* arr;
	int len;
};

template<typename T>
Array<T> array()
{
   Array<T> ret;
   ret.arr = new T[1000];
   ret.len = 0;
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
	add<T>(a.arr,a.len,t);
	return a.len-1;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* x = &a.arr[p];
   return x;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
	remove<T>(a.arr,a.len,p);
	insert<T>(a.arr,a.len,t,p);
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
	insert<T>(a.arr,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t = remove<T>(a.arr,a.len,p);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
	for(int i=0;i<=a.len+1;i++)
	{
		arrayRemove<T>(a,0);
	}
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   int f = find<T,K>(a.arr,a.len,k,cmpTK);
   
   return f;
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   int x = orderedInsert<T>(a.arr,a.len,t,cmpTT);
   return x;
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
	sort<T>(a.arr,a.len,cmpTT);
}

#endif
