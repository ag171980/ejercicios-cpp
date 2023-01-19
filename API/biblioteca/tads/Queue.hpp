#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
	Node<T>* p = NULL;
	int contador = 0;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   Node<T>* aux = add<T>(q.p,e);
	T* t = &aux->info;
	q.contador++;
   return t;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   T t = removeFirst(q.p);
   q.contador--;
   return t;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
	if(q.contador==0)
		return true;
	else
		return false;
}

template<typename T>
int queueSize(Queue<T> q)
{
   return q.contador;
}

#endif
