#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
	Node<T>* p = NULL;
	int contador=0;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   Node<T>* aux = push(st.p,e);
   T* t = &aux->info;
   st.contador++;
   return t;
}

template<typename T>
T stackPop(Stack<T>& st)
{
	T t = pop(st.p);
	st.contador--;
   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
	if(st.contador==0)
		return true;
   	else
   		return false;
}

template<typename T>
int stackSize(Stack<T> st)
{
   return st.contador;
}

#endif
