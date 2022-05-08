#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int longitud(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

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

string substring(string s, int d, int h)
{
    string newStrings = "";
    while (d < h)
    {
        newStrings += s[d];
        d++;
    }
    return newStrings;
}

string substring(string s, int d) // ok
{
    string newStrings = "";

    while (d < longitud(s))
    {
        newStrings += s[d];
        d++;
    }
    return newStrings;
}

int indexOf(string s, char c) // ok
{
    int pos = 0;
    bool encontrado = false;
    while (encontrado == false)
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
    return pos;
}

int indexOf(string s, char c, int offSet) // ok
{
    bool encontrado = false;
    while (encontrado == false)
    {
        if (s[offSet] == c)
        {
            encontrado = true;
        }
        else
        {
            offSet++;
        }
    }
    return offSet;
}
int indexOf(string s, string toSearch) // ok
{
    int posString = 0;
    int posSearch = 0;
    int posToStart = -1;
    string newString = "";
    bool encontrado = false;
    while (posString < longitud(s) && encontrado == false)
    {
        if (toSearch[posSearch] == s[posString])
        {
            if (posSearch == longitud(toSearch) - 1)
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
int indexOf(string s, string toSearch, int offset) // ok
{
    int posString = offset;
    int posSearch = 0;
    int posToStart = -1;
    string newString = "";
    bool encontrado = false;
    while (posString < longitud(s) && encontrado == false)
    {
        if (toSearch[posSearch] == s[posString])
        {
            if (posSearch == longitud(toSearch) - 1)
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

int lastIndexOf(string s, char c)
{
    int pos = 0;
    int posEncontrado = 0;
    while (pos <= longitud(s))
    {
        if (s[pos] == c)
        {
            posEncontrado = pos;
        }
        pos++;
    }
    return posEncontrado;
}

int indexOfN(string s, char c, int n)
{
    int pos = 0, posEncontrado = 0, cantCharacter = 1;
    while (pos < longitud(s))
    {
        if (s[pos] == c)
        {
            if (cantCharacter == n)
            {
                posEncontrado = pos;
            }
            cantCharacter++;
        }
        pos++;
    }
    return posEncontrado;
}

int charToInt(char c)
{
    return (char)c;
}

char intToChar(int i)
{
    return (int)i;
}

// falta esta
int getDigit(int n, int i)
{
    string num = to_string(n);
    int pos = longitud(num), posEncontrado = 0, contador = 0;
    int lol = 0;
    while (pos >= 0)
    {
        if (contador == i)
        {
            posEncontrado = num[pos - 1];
        }
        contador++;
        pos--;
    }
    lol = charToInt(posEncontrado);
    cout << "pos encontrado  = " << (char)posEncontrado << endl;
    cout << "lol  = " << lol << endl;
    return posEncontrado;
}
// falta esta
int digitCount(int n)
{

    return 0;
}

string intToString(int i)
{
    return to_string(i);
}

int stringToInt(string s, int b)
{
    int result = 0, conversion = 0, posW = 0;
    int numPow = 1;
    int stringLength = longitud(s);
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
            if (s[stringLength - 1] == 'A' || s[stringLength - 1] == 'B' || s[stringLength - 1] == 'C' || s[stringLength - 1] == 'D' || s[stringLength - 1] == 'E' || s[stringLength - 1] == 'F')
            {
                switch (s[stringLength - 1])
                {
                case 'A':
                    valueConverted = 10;
                    break;
                case 'B':
                    valueConverted = 11;
                    break;
                case 'C':
                    valueConverted = 12;
                    break;
                case 'D':
                    valueConverted = 13;
                    break;
                case 'E':
                    valueConverted = 14;
                    break;
                case 'F':
                    valueConverted = 15;
                    break;
                }
            }
            else
            {
                switch (s[stringLength - 1])
                {
                case '0':
                    valueConverted = 0;
                    break;
                case '1':
                    valueConverted = 1;
                    break;
                case '2':
                    valueConverted = 2;
                    break;
                case '3':
                    valueConverted = 3;
                    break;
                case '4':
                    valueConverted = 4;
                    break;
                case '5':
                    valueConverted = 5;
                    break;
                case '6':
                    valueConverted = 6;
                    break;
                case '7':
                    valueConverted = 7;
                    break;
                case '8':
                    valueConverted = 8;
                    break;
                case '9':
                    valueConverted = 9;
                    break;
                }
            }
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

int stringToInt(string s)
{
    return stoi(s);
}

string charToString(char c)
{
    string result;
    result = c;
    return result;
}

char stringToChar(string s)
{
    char character;
    for (int pos = 0; pos < longitud(s); pos++)
    {
        character = s[pos];
    }
    return character;
}

string stringToString(string s)
{
    return s;
}

string doubleToString(double d)
{
    return to_string(d);
}

double stringToDouble(string s)
{
    return stod(s);
}
// 23
bool isEmpty(string s)
{
    bool empty = false;
    if (longitud(s) == 0)
    {
        empty = true;
    }
    return empty;
}
// 24
bool startsWith(string s, string x)
{
    int posX = 0, lengthX = longitud(x) - 1;
    bool startWord = false;
    for (int pos = 0; pos < longitud(s) - 1; pos++)
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
    int lengthX = longitud(x), lengthS = longitud(s) - 1;
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
    for (int pos = 0; pos < longitud(s); pos++)
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
    for (int pos = 0; pos < longitud(s); pos++)
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
    int length = longitud(text);
    char axe;
    cout << length << endl;
    for (int i = 0; i < length; i++)
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
    string text = s;
    s += " ";
    int length = longitud(text);
    char axe;
    for (int i = 0; i < longitud(s) - 1; i++)
    {
        if (pos <= i)
        {
            s[i - 1] = text[i];
        }
    }
    return s;
}
//30, aca me quedoooo
string ltrim(string s)
{
    return "";
}

string rtrim(string s)
{
    return "";
}

string trim(string s)
{
    return "";
}

string replicate(char c, int n)
{
    return "";
}

string spaces(int n)
{
    return "";
}

string lpad(string s, int n, char c)
{
    return "";
}

string rpad(string s, int n, char c)
{
    return "";
}

string cpad(string s, int n, char c)
{
    return "";
}

bool isDigit(char c)
{
    return true;
}

bool isLetter(char c)
{
    return true;
}

bool isUpperCase(char c)
{
    return true;
}

bool isLowerCase(char c)
{
    return true;
}

char toUpperCase(char c)
{
    return 'X';
}

char toLowerCase(char c)
{
    return 'X';
}

string toUpperCase(string s)
{
    return "";
}

string toLowerCase(string s)
{
    return "";
}

int cmpString(string a, string b)
{
    return 0;
}

int cmpDouble(double a, double b)
{
    return 0;
}

#endif
