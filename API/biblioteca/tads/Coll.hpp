#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;
// OKcollSize
// OKcollRemoveAll
// OKcollRemoveAt
// OKcollAdd
// OKcollSetAt
// OKcollGetAt
// OKcollFind
// OKcollSort

// OKcollHasNext
// OKcollNext
// OKcollNext
// OKcollReset
template <typename T>
struct Coll
{
   int pos = 0;
   char sep;
   string s = "";
};
// OK
template <typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep = sep;
   c.pos = 0;
   return c;
}
// OK
template <typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   c.pos = 0;
   return c;
}
// OK
template <typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s, c.sep);
}
// OK
template <typename T>
void collRemoveAll(Coll<T> &c)
{

   for (int i = 0; i <= collSize<T>(c); i++)
   {
      if (i == collSize<T>(c))
      {
         c.s = "";
      }
      else
      {
         removeTokenAt(c.s, c.sep, 0);
      }
   }
}
// OK
template <typename T>
void collRemoveAt(Coll<T> &c, int p)
{
   removeTokenAt(c.s, c.sep, p);
}
// OK
template <typename T>
int collAdd(Coll<T> &c, T t, string tToString(T))
{
   addToken(c.s, c.sep, tToString(t));
   return collSize<T>(c) - 1;
}
// OK
template <typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T))
{
   setTokenAt(c.s, c.sep, tToString(t), p);
}
// OK
template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   string s = (tokenCount(c.s, c.sep) > 1) ? getTokenAt(c.s, c.sep, p) : c.s;
   T t = tFromString(s);
   return t;
}
// OK
template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   T f;
   bool encontrado = false;
   int aux = 0;
   f = collGetAt<T>(c, aux, tFromString);
   while (aux < collSize<T>(c) && encontrado == false)
   {
      if (cmpTK(f, k) != 0)
      {
         aux++;
         f = collGetAt<T>(c, aux, tFromString);
      }
      else
      {
         encontrado = true;
      }
   }

   return (encontrado) ? aux : -1;
}
// a probar
template <typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   bool sort = false;
   while (!sort)
   {
      sort = true;
      for (int i = 0; i < collSize<T>(c) - 1; i++)
      {
         T cmp1 = collGetAt<T>(c, i, tFromString);
         T cmp2 = collGetAt<T>(c, i + 1, tFromString);
         if (cmpTT(cmp1, cmp2) > 0)
         {
            collSetAt<T>(c, cmp1, i + 1, tToString);
            collSetAt<T>(c, cmp2, i, tToString);
            sort = false;
         }
      }
   }
}
// a probar
template <typename T>
bool collHasNext(Coll<T> c)
{
   return collSize<T>(c) > c.pos;
}
// a probar
template <typename T>
T collNext(Coll<T> &c, T tFromString(string))
{
   T t;
   string f = tFromString(getTokenAt(c.s, c.sep, c.pos));
   t = f;
   c.pos++;
   return t;
}
// Nao Nao
template <typename T>
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string))
{
   T t;
   if (c.pos < collSize<T>(c))
   {
      t = collNext<T>(c, tFromString);
   }
   else
   {
      endOfColl = true;
   }
   return t;
}
// OK
template <typename T>
void collReset(Coll<T> &c)
{
   c.pos = 0;
}

#endif
