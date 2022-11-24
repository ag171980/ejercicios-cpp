#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array
{
   T *arr;
   int cap;
   int len;
};

template <typename T>
Array<T> array()
{
   Array<T> ret;
   ret.arr = new T[100];
   ret.len = 0;
   ret.cap = 100;
   return ret;
}

template <typename T>
int arrayAdd(Array<T> &a, T t)
{
   if (a.len == a.cap)
   {
      int cap = a.cap;
      int len = a.len;
      T *nuevo = new T[cap * 2];

      for (int i = 0; i < cap; i++)
      {
         nuevo[i] = a.arr[i];
      }
      delete a.arr;
      a.arr = nuevo;
      a.len = len;
      a.cap = cap * 2;
   }

   return add<T>(a.arr, a.len, t);
}

template <typename T>
T *arrayGet(Array<T> a, int p)
{

   T *t = &a.arr[p];
   return t;
}

template <typename T>
void arraySet(Array<T> &a, int p, T t)
{
   a.arr[p] = t;
}

template <typename T>
void arrayInsert(Array<T> &a, T t, int p)
{
   insert<T>(a.arr, a.len, t, p);
}

template <typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template <typename T>
T arrayRemove(Array<T> &a, int p)
{
   return remove<T>(a.arr, a.len, p);
}

template <typename T>
void arrayRemoveAll(Array<T> &a)
{
   a.len = 0;
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return find<T>(a.arr, a.len, k, cmpTK);
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T))
{
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T))
{
   sort<T>(a.arr, a.len, cmpTT);
}

#endif
