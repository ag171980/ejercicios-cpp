#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T> *sig;
};

template <typename T>
Node<T> *add(Node<T> *&p, T e)
{

   Node<T> *newNode = new Node();
   newNode->info = e;
   newNode->sig = NULL;

   if (p != NULL)
   {

      Node *aux = p;
      while (aux->sig != NULL)
      {
         aux = aux->sig;
      }
      aux->sig = newNode;
   }
   else
   {
      p = newNode;
   }

   return &p;
}

template <typename T>
Node<T> *addFirst(Node<T> *&p, T e)
{
   return NULL;
}

template <typename T, typename K>
T remove(Node<T> *&p, K k, int cmpTK(T, K))
{
   T t;
   return t;
}

template <typename T>
T removeFirst(Node<T> *&p)
{
   T t;
   return t;
}

template <typename T, typename K>
Node<T> *find(Node<T> *p, K k, int cmpTK(T, K))
{
   return NULL;
}

template <typename T>
Node<T> *orderedInsert(Node<T> *&p, T e, int cmpTT(T, T))
{
   return NULL;
}

template <typename T>
Node<T> *searchAndInsert(Node<T> *&p, T e, bool &enc, int cmpTT(T, T))
{
   return NULL;
}

template <typename T>
void sort(Node<T> *&p, int cmpTT(T, T))
{
}

template <typename T>
bool isEmpty(Node<T> *p)
{
   return true;
}

template <typename T>
void free(Node<T> *&p)
{
}

template <typename T>
Node<T> *push(Node<T> *&p, T e)
{
   return NULL;
}

template <typename T>
T pop(Node<T> *&p)
{
   T t;
   return t;
}

template <typename T>
Node<T> *enqueue(Node<T> *&p, Node<T> *&q, T e)
{
   return NULL;
}

template <typename T>
Node<T> *enqueue(Node<T> *&q, T e)
{
   return NULL;
}

template <typename T>
T dequeue(Node<T> *&p, Node<T> *&q)
{
   T t;
   return t;
}

template <typename T>
T dequeue(Node<T> *&q)
{
   T t;
   return t;
}

#endif