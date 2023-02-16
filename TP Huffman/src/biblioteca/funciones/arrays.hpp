#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
	arr[len]= e;
	len++;
	return len;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   for (int i = len; i > p; i-- ) 
   {
      arr[i] = arr[i-1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret;
   ret=arr[p];
   int pos=p;
   for(int i = len; i >= pos;i--)
   {
   		arr[pos]=arr[pos+1];
   		pos++;
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
	int i = 0;
	while(i<len && cmpTK(arr[i],k)!=0)
	{
		i++;
	}
	if(i>=len)
		return -1;
   return i;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i = 0;
   while(cmpTT(e,arr[i]) > 0)
   {
   		i++;
   }
   insert(arr,len,e,i);
   
   
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   T a;
   T b;
   
   for(int i=0;i<len;i++)
   {
   		for(int k =0;k<len-1;k++)
   		{
   			if(cmpTT(arr[i],arr[k])<0)
   			{
   				b=arr[k];
   				a=arr[i];
   				arr[i]=b;
   				arr[k]=a;
			   }
		   }
   }
}



#endif
