#include <iostream>
#include <string>
#include "../biblioteca/funciones/strings.hpp"
using namespace std;

int main()
{

    // 1)**length

    // string s = "Diagramas";
    // cout << length(s) << endl;

    // 2)**charCount

    // string s = "Esto es une prueba";
    // cout << charCount(s, 'e') << endl;

    // 3)**substring

    // string s = "Palabra larga texto largo";
    // cout << "[" << substring(s, 2, 10) << "]" << endl;

    // 4)**substring 2

    // string s = "Palabra larga texto largo";
    // cout << substring(s, 2) << endl;

    // 5)**indexOf

    // string s = "Brutus Pucus lucus";
    // cout << indexOf(s, 'P') << endl;

    // 6)**indexOf

    // string s = "Esto es una prueba";
    // cout << indexOf(s, 'n', 0) << endl;

    // 7)**indexOf

    // string s = "Esto es una prueba";
    // cout << indexOf(s, "jamon") << endl;

    // 8)**indexOf

    // string s = "Esta funcion es la funcion mas dificil";
    // cout << indexOf(s, "funcion", 13) << endl;

    // 9)**lastIndexOf

    // string s = "Esto es la algoritmosa";
    // cout << lastIndexOf(s, 'a') << endl;

    // 10)**indexOfN

    // string s = "John|Paul|George|Ringo";
    // cout << indexOfN(s, '|', 1) << endl;
    // cout << indexOfN(s, '|', 2) << endl;
    // cout << indexOfN(s, '|', 3) << endl;

    // 11)**charToInt

    // char c = 'D';
    // cout << charToInt(c) << endl;

    // 12)**intToChar

    // cout << intToChar(10) << endl;
    // cout << intToChar(13) << endl;
    // cout << intToChar(8) << endl;
    // cout << intToChar(2) << endl;

    // 13)**getDigit

    // int n = 1932;
    // int i = 2;
    // cout << getDigit(n, i) << endl;

    // 14)**digitCount

    // cout << digitCount(2512) << endl;
    // cout << digitCount(23892) << endl;
    // cout << digitCount(1234567891) << endl;

    // 15)**intToString

    // cout << intToString(12345) << endl;
    // cout << intToString(24) << endl;
    // cout << intToString(2512) << endl;

    // 16)**stringToInt

    // cout << stringToInt("AB", 16) << endl;
    // cout << stringToInt("111111", 2) << endl;

    // 17)**stringToInt

    // cout << stringToInt("12345") << endl;
    // cout << stringToInt("6571022") << endl;

    // 18)**charToString

    // string s = charToString(' ');
    // cout << s << endl; // muestra: A
    // cout << length(s) << endl;

    // 19)**stringToChar

    // string s = " ";
    // char c = stringToChar(s);
    // cout << c << endl;      // muestra:
    // cout << (int)c << endl; // muestra: 32

    // 20)**stringToString

    // cout << stringToString("Hola") << endl; // muestra: Hola

    // 21)**doubleToString

    // double d = 1390.23;
    // cout << doubleToString(d) << endl;

    // 22)**stringToDouble FALTA REVISAR

    // cout << stringToDouble("201.7") << endl; // muestra: 123.4

    // 23)**isEmpty

    // cout << isEmpty("Hola") << endl;

    // 24)**startsWith

    // string s1 = "cursoDeAlgoritmos";
    // string s2 = "curso";
    // if (startsWith(s1, s2))
    // {
    //     cout << s2 << " es prefijo de: " << s1 << endl;
    // }

    // 25)**endsWith

    // string s1 = "PalabrasDabrx";
    // string s2 = "Dabrx";
    // if (endsWith(s1, s2))
    // {
    //     cout << s2 << " es sufijo de: " << s1 << endl;
    // }
    // else
    // {
    //     cout << s2 << " no es sufijo de: " << s1 << endl;
    // }

    // 26)**contains

    // string s = "abcd";
    // char c = 'b';
    // if (contains(s, c))
    // {
    //     cout << s << " contiene a: " << c << endl;
    // }

    // 27)**replace

    // string s = "Palabras magicas doradas";
    // cout << replace(s, 'a', 'A') << endl;

    // 28)**insertAt

    // string s = "Esto es una prueba";
    // cout << insertAt(s, 5, 'X') << endl;

    // 29)**removeAt

    // string s = "Esto es una prueba";
    // cout << removeAt(s, 7) << endl;

    // 30)**ltrim

    // string s = "Esto es una prueba     ";
    // cout << "[" << ltrim(s) << "]" << endl;

    // 31)**rtrim FALTA

    // string s = "Esto es una prueba  ";
    // cout << "[" << rtrim(s) << "]" << endl;

    // 32)**trim

    // string s = "   Esto es una prueba   ";
    // cout << "[" << trim(s) << "]" << endl;

    // 33)**replicate

    // int n = 5;
    // cout << "[" << replicate('X', n) << "]" << endl;
    // cout << "[" << replicate(' ', n) << "]" << endl;

    // 34)**spaces

    // int n = 5;
    // cout << "[" << spaces(n) << "]" << endl;

    // 35)**lpad

    // string s = "Lavacalola";
    // cout << "[" << lpad(s, 15, 'X') << "]" << endl;

    // 36)**rpad

    // string s = "Especimenes";
    // cout << "[" << rpad(s, 20, 'X') << "]" << endl;

    // 37)**cpad

    // string s = "Manipulaciones";
    // cout << "[" << cpad(s, 30, 'X') << "]" << endl;

    // 38)**isDigit

    // char c = '0';
    // if (isDigit(c))
    // {
    //     cout << c << " es digito" << endl;
    // }
    // else
    // {
    //     cout << c << " no es digito" << endl;
    // }
    // c = 'L';
    // if (isDigit(c))
    // {
    //     cout << c << " es digito" << endl; // SALIDA
    // }
    // else
    // {
    //     cout << c << " no es digito" << endl;
    // }

    // 39)**isLetter

    // char c = '1';
    // if (isLetter(c))
    // {
    //     cout << c << " es letra" << endl; // SALIDA
    // }
    // else
    // {
    //     cout << c << " no es letra" << endl; // SALIDA
    // }

    // 40)**isUpperCase

    // char c = 'x';
    // if (isUpperCase(c))
    // {
    //     cout << c << " es letra mayuscula" << endl;
    // }
    // else
    // {
    //     cout << c << " NO es letra mayuscula" << endl;
    // }

    // 41)**isLowerCase

    // char c = 'a';
    // if (isLowerCase(c))
    // {
    //     cout << c << " es minuscula" << endl;
    // }
    // else
    // {
    //     cout << c << " NO es minuscula" << endl;
    // }

    // 42)**toUpperCase

    // char c = 'a';
    // cout << toUpperCase(c) << endl;

    // 43)**toLowerCase

    // char c = 'V';
    // cout << toLowerCase(c) << endl;

    // 44)**toUpperCase string

    // string s = "hola";
    // string r = toUpperCase(s);
    // cout << r << endl;

    // 45)**toLowerCase string

    // string s = "PAIASO";
    // string r = toLowerCase(s);
    // cout << r << endl;

    // 46)**cmpString

    // string s1 = "Ximena";
    // string s2 = "Xihii";
    // if (cmpString(s1, s2) < 0)
    // {
    //     cout << s1 << " es menor que " << s2 << endl;
    // }
    // else
    // {
    //     if (cmpString(s1, s2) > 0)
    //     {
    //         cout << s2 << " es menor que " << s1 << endl;
    //     }
    //     else
    //     {
    //         cout << s2 << " es igual que " << s1 << endl;
    //     }
    // }

    // 47)**cmpDouble

    // double x = 36.9;
    // double y = 36.9;
    // if (cmpDouble(x, y) < 0)
    // {
    //     cout << x << " es menor que: " << y << endl;
    // }
    // else
    // {
    //     if (cmpDouble(x, y) > 0)
    //     {
    //         cout << y << " es menor que: " << x << endl;
    //     }
    //     else
    //     {
    //         cout << y << " es igual que: " << x << endl;
    //     }
    // }

    return 0;
}
