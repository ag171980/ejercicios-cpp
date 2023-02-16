#ifndef TMAP_TAD
#define TMAP_TAD

#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename K>
int cmpKK(K a, K b)
{
   if( a==b )
   {
      return 0;
   }
   else
   {
      return -1;
   }
}

template <typename K, typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int pos;
};

template <typename K, typename V>
Map<K, V> map()
{
   Map<K, V> m;
   m.keys = array<K>();
   m.values = array<V>();
   m.pos = 0;
   return m;
}

template <typename K, typename V>
V* mapGet(Map<K, V> m, K k)
{
   int pos = arrayFind<K, K>(m.keys,k,cmpKK);
   return arrayGet<V>(m.values,pos);
}

template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
   int pos = arrayFind<K>(m.keys,k,cmpKK);
   if( pos>=0 )
   {
      return true;
   }
   return false;
}

template <typename K, typename V>
V* mapPut(Map<K, V>& m, K k, V v)
{
   if(mapContains<K,V>(m,k))
   {
      int pos = arrayFind<K>(m.keys,k, cmpKK);
      arraySet<V>(m.values, pos, v);
      return mapGet<K, V>(m,k);
   }
   arrayAdd<K>(m.keys,k);
   arrayAdd<V>(m.values,v);
   return mapGet<K, V>(m,k);
}



template <typename K, typename V>
V mapRemove(Map<K, V>& m, K k)
{
   int pos = arrayFind<K, K>(m.keys,k,cmpKK);
   V v = arrayRemove<V>(m.values,pos);
   arrayRemove<K>(m.keys,pos);
   return v;
}

template <typename K, typename V>
void mapRemoveAll(Map<K, V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return m.keys.len;
}

template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   if( mapSize<K, V>(m)>m.pos )
   {
      return true;
   }
   return false;
}

template <typename K, typename V>
K mapNextKey(Map<K, V>& m)
{
   m.pos++;
   return *arrayGet<K>(m.keys,m.pos-1);
}

template <typename K, typename V>
V* mapNextValue(Map<K, V>& m)
{
   m.pos++;
   return arrayGet<V>(m.values,m.pos-1);
}

template <typename K, typename V>
void mapReset(Map<K, V>& m)
{
   m.pos = 0;
}

template <typename K, typename V>
void mapSortByKeys(Map<K, V>& m, int cmpKK(K, K))
{
   int len = arraySize<K>(m.keys);
   for( int i = 0; i<len; i++ )
   {
      for( int j = 0; j<len-1; j++ )
      {
         K k = m.keys.arr[j];
         K nextK = m.keys.arr[j+1];
         V v = m.values.arr[j];
         V nextV = m.values.arr[j+1];
         if( cmpKK(k,nextK)>0 )
         {
            m.keys.arr[j+1] = k;
            m.keys.arr[j] = nextK;
            m.values.arr[j+1] = v;
            m.values.arr[j] = nextV;
         }
      }
   }
}

template <typename K, typename V>
void mapSortByValues(Map<K, V>& m, int cmpVV(V, V))
{
   int len = arraySize<K>(m.keys);
   for( int i = 0; i<len; i++ )
   {
      for( int j = 0; j<len-1; j++ )
      {
         K k = m.keys.arr[j];
         K nextK = m.keys.arr[j+1];
         V v = m.values.arr[j];
         V nextV = m.values.arr[j+1];
         if( cmpVV(v,nextV)>0 )
         {
            m.keys.arr[j+1] = k;
            m.keys.arr[j] = nextK;
            m.values.arr[j+1] = v;
            m.values.arr[j] = nextV;
         }
      }
   }
}

#endif
