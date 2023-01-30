#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>
using namespace std;
template <typename T>
int add(T arr[], int &len, T e)
{
   arr[len] = e;
   len++;
   return len - 1;
}

template <typename T>
void insert(T arr[], int &len, T e, int p)
{
   for (int i = len; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[], int &len, int p)
{
   T ret = arr[p];

   for (int i = p + 1; i < len; i++)
   {
      arr[i - 1] = arr[i];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   int contador = 0;
   bool encontrado = true;

   while (contador < len && encontrado)
   {
      (cmpTK(arr[contador], k)) ? contador++ : encontrado = false;
   }
   return (encontrado) ? -1 : contador;
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T))
{
   int contador = 0;
   int postoInserted = 0;
   bool inserted = true;
   while (contador < len && inserted)
   {
      if (cmpTT(arr[contador], e) > 0 && inserted)
      {
         postoInserted = contador;
         inserted = false;
      }
      contador++;
   }
   insert<T>(arr, len, e, postoInserted);
   return postoInserted;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   for (int i = 0; i < len; i++)
   {
      for (int j = 0; j < len - 1; j++)
      {
         if (cmpTT(arr[i], arr[j]) < 0)
         {
            T aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
         }
      }
   }
}

#endif
