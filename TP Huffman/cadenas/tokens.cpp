#include <iostream>
#include <string>
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
using namespace std;
int main()
{
    // **tokenCout

    // string s = "| | |";
    // string s = "MorocoLoco";
    // string s = "La vaca lola";
    // char sep = '|';
    // int n = tokenCount(s, sep);
    // cout << n << endl;

    // **addToken

    // string s = "";
    // char sep = '|';
    // addToken(s, sep, "John");
    // cout << s << endl; // Salida: John
    // addToken(s, sep, "Depp");
    // cout << s << endl; // Salida: John
    // addToken(s, sep, "Paul");
    // cout << s << endl; // Salida: John|Paul
    // addToken(s, sep, "George");
    // cout << s << endl; // Salida: John|Paul|George
    // addToken(s, sep, "Rooney");
    // cout << s << endl; // Salida: John
    // addToken(s, sep, "Ringo");
    // cout << s << endl; // Salida: John|Paul|George|Ringo

    // **getTokenAt

    // string s = "Paralelismo es un libro hilarante";
    // char sep = 'i';
    // int pos = 0;
    // string t = getTokenAt(s, sep, pos);
    // cout << t << endl;
    // pos = 1;
    // t = getTokenAt(s, sep, pos);
    // cout << t << endl;
    // pos = 2;
    // t = getTokenAt(s, sep, pos);
    // cout << t << endl;
    // pos = 3;
    // t = getTokenAt(s, sep, pos);
    // cout << t << endl; // Salida: Ringo

    // **removeTokenAt

    string s = "Aatrox|Akshan|Alistar|Amumu|Darius|Dr Mundo|Garen|Jayce|Jinx|Malzahar|Morgana|Pantheon|Quiyana|Trundle";
    char sep = '|';
    int i = 1;
    removeTokenAt(s, sep, i);
    cout << s << endl;
    // i = 0;
    // removeTokenAt(s, sep, i);
    // cout << s << endl;
    // cout << tokenCount(s, sep) << endl;
    // for (int n = 0; n <= tokenCount(s, sep); n++)
    // {

    //     if (n == tokenCount(s, sep))
    //     {
    //         s = "";
    //     }
    //     else
    //     {
    //         removeTokenAt(s, sep, 0);
    //     }
    // }
    // cout << "[" << s << "]" << endl;

    // **setTokenAt

    // string s = "Pelicano|Picanaso|Parametro";
    // string s = "Jayce|Pantheon|Amumu|Alistar|Aatrox|Malzahar|Darius";
    // char sep = '|';
    // int i = 3;
    // string t = "Jayce";
    // // setTokenAt(s, sep, t2, j);
    // // cout << s << endl;
    // setTokenAt(s, sep, t, i);
    // cout << s << endl;
    // cout << "--------------" << endl;
    // int j = 0;
    // string t2 = "Alistar";
    // setTokenAt(s, sep, t2, j);
    // cout << s << endl;

    // **findToken

    // string s = "John|Paul|George|Ringo";
    // char sep = '|';
    // string t = "Paul";
    // int p = findToken(s, sep, t);
    // cout << p << endl; // Salida: 1
    // t = "John";
    // p = findToken(s, sep, t);
    // cout << p << endl; // Salida: 0
    // t = "Marcos";
    // p = findToken(s, sep, t);
    // cout << p << endl; // Salida: -1
    // t = "Ringo";
    // p = findToken(s, sep, t);
    // cout << p << endl; // Salida: 3

    return 0;
}