#include <iostream>
#include <string>
#include "../funciones/strings.hpp"
using namespace std;
int main()
{
    // char c1 = 65;
    // char c2 = 'A';
    // int i = 'A';
    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << i << endl;
    // string s = "El caracter \" ya no es un problema";
    // cout << s << endl;
    //////////////////////////////////////////////////////////////////////
    // Si imprimimos s[4] imprimira un caracter vacio que representa al \0
    // si vamos mas alla del s[4] nos metemos con los espacios en memoria.
    //////////////////////////////////////////////////////////////////////
    // string s = "Pablo";
    // cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << " " << endl;
    // cout << "La cantidad de caracteres de " << s << " es: " << longitud(s) << endl;
    //////////////////////////////////////////////////////////////////////
    // string texto = "Hola esto es un ejemplo elemental elefante";
    // deberia devolver 4
    // cout << charCount(texto, 'e') << endl;
    string texto1 = "Esta funcion es la funcion mas dificil";
    string texto2 = "John|Paul|George|Ringo|Nico|Mateo";
    // cout << "Cant de caracteres: " << longitud(texto1) << endl;
    // cout << "Cant de 'a' en el texto: " << charCount(texto1, 'a') << endl;
    // cout << substring(texto1, 2, longitud(texto1)) << endl;
    // cout << substring(texto1, 5) << endl;
    // cout << indexOf(texto1, 'e') << endl;
    // cout << indexOf(texto1, 'e', 12) << endl;
    // cout << indexOf(texto1, "una") << endl;
    // cout << indexOf(texto1, "funcion", 0) << endl;
    // cout << indexOf(texto1, "funcion", 13) << endl;

    // cout << lastIndexOf(texto1, 'a') << endl;
    // cout << indexOfN(texto2, '|', 1) << endl;
    // cout<< charToInt(63)<<endl;
    // falta desde aca
    // cout << intToChar(35) << endl;
    // cout << getDigit(12345, 0) << endl;
    // hasta aca
    // cout << stringToInt("123123", 10) << endl;
    // cout << stringToInt("123312") << endl;
    // cout << longitud(charToString('a')) << endl;
    // cout << stringToChar("x") << endl;
    // cout << doubleToString(123.4) << endl;
    // cout << stringToDouble("123.4") << endl;
    // isEmpty("") ? cout << "true" << endl : cout << "false" << endl;

    // string t1 = "callejeros";
    // string t2 = "meros";
    // startsWith(t1, t2) ? cout << t2 << " es prefijo de: " << t1 << endl : cout << t2 << " no es prefijo de: " << t1 << endl;
    // endsWith(t1, t2) ? cout << t2 << " es sufijo de: " << t1 << endl : cout << t2 << " no es sufijo de: " << t1 << endl;

    // string t1 = "abcd";
    // char c = 'n';
    // contains(t1, c) ? cout << t1  << " contiene a: " << c << endl : cout << t1 << " no contiene a: " << c << endl;

    // string t1 = "Esto es una prueba";
    // string r = replace(t1, 's', 'X');
    // cout << r << endl;

    // string t1 = "Esto";
    // int pos = 2;
    // char c = 'X';
    // cout << insertAt(t1, pos, c) << endl;

    string t1 = "Esto podria ser algoritmos prueba";
    int pos = 8;
    string r = removeAt(t1, pos);
    cout << r << endl;
    return 0;
}
