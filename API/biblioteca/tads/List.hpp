
#include <iostream>
#include <stdlib.h>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List
{
   Node<T> *p = NULL;
   int contador = 0;
   int iteracion = 0;
};

template <typename T>
List<T> list()
{
   List<T> lst;
   return lst;
}

template <typename T>
T *listAdd(List<T> &lst, T e)
{
   Node<T> *aux = add<T>(lst.p, e);
   T *t = &aux->info;
   lst.contador++;
   return t;
}

template <typename T>
T *listAddFirst(List<T> &lst, T e)
{
   Node<T> *aux = addFirst<T>(lst.p, e);
   T *t = &aux->info;
   lst.contador++;
   return t;
}

template <typename T, typename K>
T listRemove(List<T> &lst, K k, int cmpTK(T, K))
{
   T t = remove<T, K>(lst.p, k, cmpTK);
   lst.contador--;
   return t;
}

template <typename T>
T listRemoveFirst(List<T> &lst)
{
   T t = removeFirst(lst.p);
   lst.contador--;
   return t;
}

template <typename T, typename K>
T *listFind(List<T> lst, K k, int cmpTK(T, K))
{
   Node<T> *aux = find<T>(lst.p, k, cmpTK);
   T *t = &aux->info;
   return t;
}

template <typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty(lst.p);
}

template <typename T>
int listSize(List<T> lst)
{
   return lst.contador;
}

template <typename T>
void listFree(List<T> &lst)
{
   free(lst.p);
   lst.contador = 0;
   lst.iteracion = 0;
}

template <typename T>
T *listOrderedInsert(List<T> &lst, T t, int cmpTT(T, T))
{
   Node<T> *aux = orderedInsert<T>(lst.p, t, cmpTT);
   T *x = &aux->info;
   return x;
}

template <typename T>
void listSort(List<T> &lst, int cmpTT(T, T))
{
   sort<T>(lst.p, cmpTT);
}

template <typename T>
void listReset(List<T> &lst)
{
   lst.iteracion = 0;
}

template <typename T>
bool listHasNext(List<T> lst)
{
   return (lst.iteracion < listSize(lst));
}

template <typename T>
T *listNext(List<T> &lst)
{
   int i = 0;
   T *t;
   Node<T> *aux = lst.p;
   for (i = 0; i < lst.iteracion; i++)
   {
      aux = aux->sig;
   }

   t = &aux->info;
   lst.iteracion++;
   return t;
}

template <typename T>
T *listNext(List<T> &lst, bool &endOfList)
{
   T *t = listNext(lst);
   if (listHasNext(lst))
      endOfList = false;
   else
      endOfList = true;
   return t;
}
