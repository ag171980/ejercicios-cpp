
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename K, typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int lenMap;
   int posCurr;
};

template <typename K, typename V>
Map<K, V> map()
{
   Map<K, V> m;
   m.keys = array<K>();
   m.values = array<V>();
   m.lenMap = 0;
   m.posCurr = 0;
   return m;
}

template <typename K, typename V>
V *mapGet(Map<K, V> m, K k)
{
   int pos = -1;
   for (int i = 0; i < m.lenMap; i++)
   {
      if (m.keys.arr[i] == k)
      {
         pos = i;
      }
   }
   return (pos != -1) ? &m.values.arr[pos] : NULL;
}

template <typename K, typename V>
V *mapPut(Map<K, V> &m, K k, V v)
{
   int *aux = mapGet<K, V>(m, k);
   if (aux == 0)
   {
      arrayAdd<K>(m.keys, k);
      arrayAdd<V>(m.values, v);
      m.lenMap++;
   }
   else
   {
      for (int i = 0; i < m.lenMap; i++)
      {
         if (k == m.keys.arr[i])
         {
            m.values.arr[i] = v;
         }
      }
   }
   return &m.values.arr[m.lenMap - 1];
}

template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
   return (mapGet<K, V>(m, k) != NULL);
}

template <typename K, typename V>
V mapRemove(Map<K, V> &m, K k)
{
   V v;
   for (int i = 0; i < m.lenMap; i++)
   {
      if (m.keys.arr[i] == k)
      {
         v = m.values.arr[i];
         arrayRemove<K>(m.keys, i);
         arrayRemove<V>(m.values, i);
      }
   }

   return v;
}

template <typename K, typename V>
void mapRemoveAll(Map<K, V> &m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
   m.lenMap = 0;
   // delete m.keys.arr;
   // delete m.values.arr;
}

template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return arraySize<K>(m.keys);
}

template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   return mapSize<K, V>(m) > m.posCurr;
}

template <typename K, typename V>
K mapNextKey(Map<K, V> &m)
{
   K k = *arrayGet<K>(m.keys, m.posCurr);
   m.posCurr++;
   return k;
}

template <typename K, typename V>
V *mapNextValue(Map<K, V> &m)
{
   // V v = *arrayGet<V>(m.values, m.posCurr);
   m.posCurr++;
   return &m.values.arr[m.posCurr - 1];
   // return *v;
}

template <typename K, typename V>
void mapReset(Map<K, V> &m)
{
   m.posCurr = 0;
}

template <typename K, typename V>
void mapSortByKeys(Map<K, V> &m, int cmpKK(K, K))
{
   K *newArrKeys = new K[100];
   V *newArrValues = new V[100];
   int cantInNewArray = 0;
   for (int i = 0; i < mapSize<K>(m); i++)
   {
      newArrKeys[i] = m.keys.arr[i];
      newArrValues[i] = m.values.arr[i];
      cantInNewArray++;
   }

   arraySort<K>(m.keys, cmpKK);

   for (int i = 0; i < mapSize<K>(m); i++)
   {
      string nextK = mapNextKey<K, V>(m);
      for (int j = 0; j < cantInNewArray; j++)
      {
         if (nextK == newArrKeys[j])
         {
            mapPut<K, V>(m, nextK, newArrValues[j]);
         }
      }
   }
}

template <typename K, typename V>
void mapSortByValues(Map<K, V> &m, int cmpVV(V, V))
{
   K *newArrKeys = new K[100];
   V *newArrValues = new V[100];
   int cantInNewArray = 0;
   for (int i = 0; i < mapSize<K>(m); i++)
   {
      newArrKeys[i] = m.keys.arr[i];
      newArrValues[i] = m.values.arr[i];
      cantInNewArray++;
   }

   arraySort<V>(m.values, cmpVV);

   for (int i = 0; i < mapSize<K>(m); i++)
   {
      string nextK = mapNextKey<K, V>(m);
      int *nextV = mapGet<K, V>(m, nextK);
      for (int j = 0; j < cantInNewArray; j++)
      {
         if (*nextV == newArrValues[j])
         {
            m.keys.arr[i] = newArrKeys[j];
         }
      }
   }
}

#endif
