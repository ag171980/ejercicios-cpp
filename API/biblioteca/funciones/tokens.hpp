#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// 1
int tokenCount(string s, char sep)
{
   return (length(s) == 0) ? charCount(s, sep) : charCount(s, sep) + 1;
}
// 2
void addToken(string &s, char sep, string t)
{
   (length(s) == 0) ? s += t : s += sep + t;
}
// 3
string getTokenAt(string s, char sep, int i)
{
   string newString = "";
   int cantSep = 0;
   bool ready = false;
   int pos = 0;
   while (pos < length(s) && ready == false)
   {
      if (s[pos] != sep)
      {
         if (!(cantSep < i))
         {
            newString += s[pos];
         }
      }
      if (s[pos] == sep)
      {
         if (cantSep != i)
         {
            cantSep++;
         }
         else
         {
            ready = true;
         }
      }
      pos++;
   }

   return newString;
}
// 4
void removeTokenAt(string &s, char sep, int i)
{
   int contToken = 0, pos = 0;
   string tokenToFind = getTokenAt(s, sep, i);
   int posToDelete = (i == 0) ? indexOf(s, tokenToFind) + length(tokenToFind) + 1 : indexOf(s, tokenToFind);
   string sModified = removeAt(s, posToDelete);
   string newString = "";
   bool ready = false;
   while (pos < length(sModified) && ready == false)
   {
      if (sModified[pos] != tokenToFind[contToken])
      {
         newString += sModified[pos];
      }
      else
      {
         contToken++;
      }
      pos++;
   }
   s = newString;
}
// 6
void setTokenAt(string &s, char sep, string t, int i)
{
   int contToken = 0, pos = 0, posT = 0;
   string tokenToFind = getTokenAt(s, sep, i);
   string newString = "";
   while (pos < length(s))
   {
      if (s[pos] != tokenToFind[contToken])
      {

         newString += s[pos];
      }
      else
      {
         while (posT < length(t))
         {
            newString += t[posT];
            posT++;
         }
         contToken++;
      }
      pos++;
   }
   s = newString;
}

int findToken(string s, char sep, string t)
{

   int cantSep = 0;
   string newString = "";
   int pos = 0, posT = 0;
   bool ready = false;
   int posToken = -1;
   while (pos < length(s))
   {
      if (s[pos] != sep)
      {
         if (s[pos] == t[posT])
         {
            posT++;
         }
         else
         {
            posT = 0;
         }

         if (posT == length(t))
         {
            posToken = cantSep;
         }
         newString += s[pos];
      }
      else
      {
         cantSep++;
      }
      pos++;
   }
   return posToken;
}

#endif
