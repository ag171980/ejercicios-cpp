#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;
// 1
int length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
// 2
int charCount(string s, char c)
{
    int i = 0;
    int cant = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            cant++;
        }
        i++;
    }
    return cant;
}
// 3
string substring(string s, int d, int h)
{
    string newStrings = "";
    for (int i = d; i < h; i++)
    {
        newStrings += s[i];
    }
    // while (d < h)
    // {
    //     newStrings += s[d];
    //     d++;
    // }
    return newStrings;
}
// 4
string substring(string s, int d) // ok
{
    string newStrings = "";

    while (d < length(s))
    {
        newStrings += s[d];
        d++;
    }
    return newStrings;
}
// 5
int indexOf(string s, char c)
{
    int pos = 0;
    bool encontrado = false;
    while (pos <= length(s) && encontrado == false)
    {
        if (s[pos] == c)
        {
            encontrado = true;
        }
        else
        {
            pos++;
        }
    }
    return (pos == length(s) + 1) ? -1 : pos;
}
// 6
int indexOf(string s, char c, int offSet) // ok
{
    bool encontrado = false;
    while (!encontrado)
    {
        (s[offSet] == c) ? encontrado = true : offSet++;
    }
    return offSet;
}
// 7
int indexOf(string s, string toSearch) // ok
{
    int posString = 0, posSearch = 0, posToStart = -1;
    string newString = "";
    bool encontrado = false;
    while (posString < length(s) && encontrado == false)
    {
        if (toSearch[posSearch] == s[posString])
        {
            if (posSearch == length(toSearch) - 1)
            {
                posToStart = posString - posSearch;
                encontrado = true;
            }
            posSearch++;
        }
        else
        {
            posSearch = 0;
        }
        posString++;
    }

    return posToStart;
}
// 8
int indexOf(string s, string toSearch, int offset) // ok
{
    int posString = offset;
    int posSearch = 0;
    int posToStart = -1;
    string newString = "";
    bool encontrado = false;
    while (posString < length(s) && encontrado == false)
    {
        if (toSearch[posSearch] == s[posString])
        {
            if (posSearch == length(toSearch) - 1)
            {
                posToStart = posString - posSearch;
                encontrado = true;
            }
            posSearch++;
        }
        else
        {
            posSearch = 0;
        }
        posString++;
    }

    return posToStart;
}
// 9
int lastIndexOf(string s, char c)
{
    int pos = 0;
    int posEncontrado = -1;
    while (pos <= length(s))
    {
        if (s[pos] == c)
        {
            posEncontrado = pos;
        }
        pos++;
    }
    return posEncontrado;
}
// 10
int indexOfN(string s, char c, int n)
{
    int posEncontrado = -1, cantCharacter = 1;
    for (int pos = 0; pos < length(s); pos++)
    {
        if (s[pos] == c)
        {
            if (cantCharacter == n)
            {
                posEncontrado = pos;
            }
            cantCharacter++;
        }
    }

    return (n > charCount(s, c)) ? length(s) : posEncontrado;
}
// 11
int charToInt(char c)
{
    int res;
    if (c >= 49 && c <= 57 || c >= 65 && c <= 70 || c >= 97 && c <= 102)
    {
        res = (c <= 57) ? c - 48 : ((c > 70 && c <= 102) ? c - 87 : c - 55);
    }
    else
    {
        res = c;
    }
    return res;
}
// 12
char intToChar(int i)
{
    char c;
    if (i >= 0 && i <= 9 || i >= 10 && i <= 15)
    {

        c = (i <= 9) ? i + 48 : i + 55;
    }
    else
    {
        c = i;
    }
    return c;
}
// 13
int getDigit(int n, int i)
{
    double p = pow(10, i);
    int x = n / (int)p;
    return x % 10;
}
// 14 dudosa
int digitCount(int n)
{
    string num = to_string(n);
    return length(num);
}
// 15
string intToString(int i)
{
    string ret = "";
    for (int a = digitCount(i); a > 0; a--)
    {
        ret += getDigit(i, a - 1) + 48;
    }
    return ret;
}
// 16
int stringToInt(string s, int b)
{
    int result = 0, conversion = 0, posW = 0;
    int numPow = 1;
    int stringLength = length(s);
    if (b == 2)
    {
        for (; stringLength > 0; stringLength--)
        {
            if (s[stringLength - 1] == '1')
            {
                for (int pow = 0; pow < posW; pow++)
                {
                    numPow *= 2;
                }
                conversion += numPow;
                numPow = 1;
            }
            posW++;
        }
    }
    else if (b == 16)
    {
        int valueConverted = 0;
        for (; stringLength > 0; stringLength--)
        {
            valueConverted = charToInt(s[stringLength - 1]);

            for (int pow = 0; pow < posW; pow++)
            {
                numPow *= 16;
            }
            conversion += valueConverted * numPow;
            numPow = 1;
            posW++;
        }
    }
    else
    {
        conversion = stoi(s);
    }
    result = conversion;
    return result;
}
// 17
int stringToInt(string s)
{
    double num = 0;
    int posReverse = length(s) - 1;
    for (int pos = 0; pos < length(s); pos++)
    {
        int val = (s[pos] - 48);
        num += val * pow(10, posReverse);
        posReverse--;
    }
    return num;
}
// 18
string charToString(char c)
{
    string result;
    result = c;
    return result;
}
// 19
char stringToChar(string s)
{
    char character;
    for (int pos = 0; pos < length(s); pos++)
    {
        character = s[pos];
    }
    return character;
}
// 20
string stringToString(string s)
{
    return s;
}
// 21
string doubleToString(double d)
{
    int count = 0, i = d;
    string newString = intToString(i), decimalString = "";
    double numComa = d - i;
    while (d > i)
    {
        d *= 10;
        i = d;
        count++;
    }
    numComa *= pow(10, count);
    decimalString += intToString(numComa);
    newString += "." + decimalString;
    return newString;
}
// 22
double stringToDouble(string s)
{
    double numFinal = 0, numFracc = 0, numEntero = 0;
    bool fraccion = false;
    int posReverse = indexOf(s, ".") - 1;
    for (int pos = 0; pos < length(s); pos++)
    {
        double val = (s[pos] - 48);
        if (val != -2 && !fraccion)
        {
            numEntero += (val * pow(10, posReverse));
            posReverse--;
        }
        else
        {
            fraccion = true;
        }
        if (fraccion)
        {
            if (val != -2)
            {
                numFracc += val * pow(10, posReverse);
                posReverse--;
            }
        }
    }

    return numEntero + numFracc;
}
// 23
bool isEmpty(string s)
{
    bool empty = false;
    if (length(s) == 0)
    {
        empty = true;
    }
    return empty;
}
// 24
bool startsWith(string s, string x)
{
    int posX = 0, lengthX = length(x) - 1;
    bool startWord = false;
    for (int pos = 0; pos < length(s) - 1; pos++)
    {
        if (s[pos] == x[posX] && s[0] == x[0])
        {
            if (posX == lengthX)
            {
                startWord = true;
            }
            posX++;
        }
    }
    return startWord;
}
// 25
bool endsWith(string s, string x)
{
    int lengthX = length(x), lengthS = length(s) - 1;
    int posX = lengthX - 1, posS = 0;
    bool endsWord = false;
    for (; lengthS >= 0; lengthS--)
    {
        if (s[lengthS] == x[posX])
        {
            posS++;
            posX--;
        }
    }
    if (posS == lengthX)
    {
        endsWord = true;
    }
    return endsWord;
}
// 26
bool contains(string s, char c)
{
    bool contain = false;
    for (int pos = 0; pos < length(s); pos++)
    {
        if (s[pos] == c)
        {
            contain = true;
        }
    }
    return contain;
}
// 27
string replace(string s, char oldChar, char newChar)
{
    for (int pos = 0; pos < length(s); pos++)
    {
        if (s[pos] == oldChar)
        {
            s[pos] = newChar;
        }
    }
    return s;
}
// 28
string insertAt(string s, int pos, char c)
{
    string text = s;
    s += " ";
    int len = length(text);
    char axe;

    for (int i = 0; i < len; i++)
    {
        if (pos == i)
        {
            axe = s[i];
            s[i] = c;
            s[i + 1] = axe;
        }
        if (pos < i)
        {
            s[i + 1] = text[i];
        }
    }
    return s;
}
// 29
string removeAt(string s, int pos)
{
    string newString, ant = "", desp = "";
    for (int i = 0; i < length(s); i++)
    {
        if (pos < i)
        {
            ant += s[i];
        }
        else
        {
            if (pos != i)
            {
                desp += s[i];
            }
        }
    }
    newString = desp + ant;
    return newString;
}

// 30
string ltrim(string s)
{
    string newString = "";
    bool firstL = false;
    for (int pos = 0; pos < length(s); pos++)
    {
        if (s[pos] != 32)
        {
            if (!firstL)
            {
                firstL = true;
            }
            newString += s[pos];
        }
        else if (s[pos] == 32 && firstL)
        {
            newString += s[pos];
        }
    }
    return newString;
}
// 31
string rtrim(string s)
{
    string otherString = "", newString = "";
    int posR = length(s) - 1;
    for (int pos = 0; pos < length(s); pos++)
    {
        newString += s[posR];
        posR--;
    }
    newString = ltrim(newString);
    posR = length(newString) - 1;
    for (int pos = 0; pos < length(newString); pos++)
    {
        otherString += newString[posR];
        posR--;
    }
    return otherString;
}
// 32
string trim(string s)
{
    return ltrim(rtrim(s));
}
// 33
string replicate(char c, int n)
{
    string newString = "";
    for (int i = 0; i < n; i++)
    {
        newString += c;
    }
    return newString;
}
// 34
string spaces(int n)
{
    string newString = "";
    for (int i = 0; i < n; i++)
    {
        newString += " ";
    }
    return newString;
}
// 35
string lpad(string s, int n, char c)
{
    string newString = "";
    int len = length(s);
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < (n - len))
        {
            newString += c;
        }
        else
        {
            newString += s[cont];
            cont++;
        }
    }
    return newString;
}
// 36
string rpad(string s, int n, char c)
{
    string newString = "";
    for (int i = 0; i < n; i++)
    {
        if (i < length(s))
        {
            newString += s[i];
        }
        else
        {
            newString += c;
        }
    }
    return newString;
}
// 37
string cpad(string s, int n, char c)
{
    string newString = "";
    int contador = 1;
    int cantX = (n - length(s)) / 2;
    for (int i = 0; i < n; i++)
    {
        if (i < cantX)
        {
            newString += c;
        }
        else if (i >= (length(s) + cantX))
        {
            newString += c;
        }
        else
        {
            newString += s[contador - 1];
            contador++;
        }
    }
    return newString;
}
// 38
bool isDigit(char c)
{
    bool digit = false;
    int num = c;
    if (num >= 48 && num <= 57)
    {
        digit = true;
    }
    return digit;
}
// 39
bool isLetter(char c)
{
    return (!isDigit(c)) ? true : false;
}
// 40
bool isUpperCase(char c)
{
    bool isUpper = false;
    int num = c;
    if (num >= 65 && num <= 90)
    {
        isUpper = true;
    }

    return isUpper;
}
// 41
bool isLowerCase(char c)
{
    return (!isUpperCase(c)) ? true : false;
}
// 42
char toUpperCase(char c)
{
    int res = c - 32;
    return res;
}
// 43
char toLowerCase(char c)
{
    int res = c + 32;
    return res;
}
// 44
string toUpperCase(string s)
{
    string newString = "";
    for (int i = 0; i < length(s); i++)
    {
        newString += (s[i] - 32);
    }
    return newString;
}
// 45
string toLowerCase(string s)
{
    string newString = "";
    for (int i = 0; i < length(s); i++)
    {
        newString += (s[i] + 32);
    }
    return newString;
}
// 46 FALTA
int cmpString(string a, string b)
{
    int result = 0;
    if (a != b)
    {
        result = (a > b) ? 1 : -1;
    }
    else
    {
        result = 0;
    }

    // int i = 0;
    // bool encontrado = false;
    // int n, n2;
    // while (i < length(a) && encontrado == false)
    // {
    //     n = a[i];
    //     n2 = b[i];
    //     if (n > n2)
    //     {
    //         result = 1;
    //         encontrado = true;
    //     }
    //     else
    //     {
    //         if (n < n2)
    //         {
    //             result = -1;
    //             encontrado = true;
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }
    // }
    return result;
}
// 47
int cmpDouble(double a, double b)
{
    int result;
    if (a != b)
    {
        result = (a > b) ? 1 : -1;
    }
    else
    {
        result = 0;
    }

    return result;
}

#endif
