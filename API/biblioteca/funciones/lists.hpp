#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

int cmpInt(int a, int b)
{
   return a - b;
}
template <typename T>
struct Node
{
   T info;
   Node<T> *sig;
};

template <typename T>
Node<T> *add(Node<T> *&p, T e)
{
   Node<T> *nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if (p != NULL)
   {
      Node<T> *aux = p;
      while (aux->sig != NULL)
      {
         aux = aux->sig;
      }

      aux->sig = nuevo;
   }
   else
   {
      p = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T> *addFirst(Node<T> *&p, T e)
{
   Node<T> *nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if (p == NULL)
   {
      p = nuevo;
   }
   else
   {
      Node<T> *aux = new Node<T>();
      aux = p;
      p = nuevo;
      nuevo->sig = aux;
   }

   return nuevo;
}

template <typename T, typename K>
T remove(Node<T> *&p, K k, int cmpTK(T, K))
{
   Node<T> *aux = p;
   Node<T> *aux2 = aux;

   while (cmpTK(aux->info, k) != 0 && aux->sig != NULL)
   {
      aux2 = aux;
      aux = aux->sig;
   }

   if (aux->info == aux2->info)
   {
      return removeFirst(p);
   }

   else if (aux->info == k)
   {
      aux2->sig = aux->sig;
      return aux->info;
   }
   else
   {
      return NULL;
   }
}

template <typename T>
T removeFirst(Node<T> *&p)
{
   T t = p->info;
   Node<T> *aux = p->sig;
   p = aux;

   return t;
}

template <typename T, typename K>
Node<T> *find(Node<T> *p, K k, int cmpTK(T, K))
{
   while (p != NULL)
   {
      if (cmpTK(p->info, k) == 0)
      {
         return p;
      }
      p = p->sig;
   }
   return NULL;
}

template <typename T>
Node<T> *orderedInsert(Node<T> *&p, T e, int cmpTT(T, T))
{
   Node<T> *nuevo = new Node<T>();
   nuevo->info = e;

   Node<T> *ant = NULL;
   Node<T> *aux = p;

   if (p == NULL)
   {
      p = nuevo;
      p->sig = NULL;
   }
   else
   {
      while (cmpTT(aux->info, e) <= 0 && aux->sig != NULL)
      {
         ant = aux;
         aux = ant->sig;
      }
      // si sale puede ser por: 1. aux->sig es null 2. hay un num mayor o igual.
      if (cmpTT(aux->info, e) >= 0)
      {
         if (ant == NULL)
         {
            ant = nuevo;
            ant->sig = aux;
            p = nuevo;
         }
         else
         {
            ant->sig = nuevo;
            nuevo->sig = aux;
         }
      }
      else
      {
         aux->sig = nuevo;
         nuevo->sig = NULL;
      }
   }
   return nuevo;
}

template <typename T>
Node<T> *searchAndInsert(Node<T> *&p, T e, bool &enc, int cmpTT(T, T))
{
   Node<T> *ret = find<T>(p, e, cmpTT);
   if (ret == NULL)
   {
      enc = false;
      ret = orderedInsert<T>(p, e, cmpTT);
   }
   else
   {
      enc = true;
   }
   return ret;
}

template <typename T>
void sort(Node<T> *&p, int cmpTT(T, T))
{
   Node<T> *aux = p;
   Node<T> *nuevo = NULL;
   while (aux != NULL)
   {
      orderedInsert<T>(nuevo, aux->info, cmpTT);
      aux = aux->sig;
   }
   p = nuevo;
}

template <typename T>
bool isEmpty(Node<T> *p)
{
   if (p != NULL)
   {
      return false;
   }
   else
      return true;
}

template <typename T>
void free(Node<T> *&p)
{
   while (p != NULL)
   {
      Node<T> *aux = p->sig;
      delete p;
      p = aux;
   }
}

template <typename T>
Node<T> *push(Node<T> *&p, T e)
{
   Node<T> *ret = addFirst<T>(p, e);
   return ret;
}

template <typename T>
T pop(Node<T> *&p)
{
   T t = removeFirst(p);
   return t;
}

template <typename T>
Node<T> *enqueue(Node<T> *&p, Node<T> *&q, T e)
{
   Node<T> *nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;

   if (q != NULL)
   {
      q->sig = nuevo;
   }
   else
   {
      p = nuevo;
   }

   q = nuevo;

   return nuevo;
}

template <typename T>
Node<T> *enqueue(Node<T> *&q, T e)
{
   Node<T> *nuevo = new Node<T>();
   nuevo->info = e;

   if (q != NULL)
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   else
   {
      nuevo->sig = nuevo;
   }

   q = nuevo;

   return nuevo;
}

template <typename T>
T dequeue(Node<T> *&p, Node<T> *&q)
{
   T ret = p->info;
   Node<T> *aux = p;
   p = p->sig;
   delete aux;
   if (p == NULL)
   {
      q = NULL;
   }
   return ret;
}

template <typename T>
T dequeue(Node<T> *&q)
{
   Node<T> *aux = q->sig;
   q->sig = aux->sig;
   T ret = aux->info;

   if (aux == q)
   {
      q = NULL;
   }

   delete aux;
   return ret;
}

#endif
