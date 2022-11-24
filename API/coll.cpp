#include <iostream>
#include <string>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Fraccion
{
    int n;
    int d;
};
Fraccion fraccion(int n, int d)
{
    return {n, d};
}
string fraccionToString(Fraccion f)
{
    return to_string(f.n) + "/" + to_string(f.d);
}
Fraccion fraccionFromString(string s)
{
    int pos = indexOf(s, '/');
    int n = stringToInt(substring(s, 0, pos));
    int d = stringToInt(substring(s, pos + 1));

    Fraccion f = fraccion(n, d);
}
string stringFromString(string s)
{
    return s;
}

int cmpInt(int a, int b)
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
int intFromString(string s)
{
    return stringToInt(s);
}

int main()
{
    Coll<string> c = coll<string>();
    collAdd<string>(c, "z", stringToString);
    collAdd<string>(c, "B", stringToString);
    collAdd<string>(c, "C", stringToString);
    collAdd<string>(c, "D", stringToString);
    collAdd<string>(c, "E", stringToString);
    collAdd<string>(c, "F", stringToString);
    collAdd<string>(c, "G", stringToString);
    collAdd<string>(c, "H", stringToString);
    collAdd<string>(c, "I", stringToString);
    collAdd<string>(c, "J", stringToString);
    collAdd<string>(c, "K", stringToString);
    collAdd<string>(c, "L", stringToString);
    collAdd<string>(c, "M", stringToString);
    collAdd<string>(c, "N", stringToString);
    collAdd<string>(c, "O", stringToString);
    collAdd<string>(c, "P", stringToString);
    collSort<string>(c, cmpString, stringFromString, stringToString);

    // collRemoveAll
    // collRemoveAll<string>(c);

    // collRemoveAt
    // int pos = 1;
    // collRemoveAt<string>(c, pos);

    // collFind
    //  string buscar = "Darius";
    //  int pos = collFind<string, string>(c, buscar, cmpString, stringFromString);
    //  cout << buscar << " esta en la posicion " << pos << endl;

    bool endOfColl = false;
    string sT = collNext<string>(c, endOfColl, stringToString);
    while (!endOfColl)
    {
        cout << sT << endl;
        sT = collNext<string>(c, endOfColl, stringToString);
    }

    // collNext 2
    //  bool endOfColl = false;
    //  string s = collNext<string>(c, endOfColl, stringToString);
    //  while (!endOfColl)
    //  {
    //      cout << s << endl;
    //      s = collNext<string>(c, endOfColl, stringToString);
    //  }
    // cout << "-------------------" << endl;

    //----------------------------------------------------------------------

    // Coll<int> c1 = coll<int>();
    // collAdd<int>(c1, 1, intToString);
    // collAdd<int>(c1, 10, intToString);
    // collAdd<int>(c1, 5, intToString);
    // collAdd<int>(c1, 7, intToString);
    // collAdd<int>(c1, 2, intToString);
    // collAdd<int>(c1, 3, intToString);
    // collSort<int>(c1, cmpInt, intFromString, intToString);

    // collRemoveAt<int>(c1, 2);
    // int pos = 1;
    // int nuevo = 100;
    // collSetAt<int>(c1, nuevo, pos, intToString);
    // for (int i = 0; i < collSize<int>(c1); i++)
    // {
    //     cout << collGetAt<int>(c1, i, intFromString) << endl;
    // }
    // int encontrar = 2;
    // int pos = collFind<int>(c1, encontrar, cmpInt, stringToInt);
    // cout <<"Encontrado en: "<< pos << endl;
    // endOfColl = false;
    // int s = collNext<int>(c1, endOfColl, intFromString);
    // while (!endOfColl)
    // {
    //     cout << "s: " << s << endl;
    //     s = collNext<int>(c1, endOfColl, intFromString);
    // }

    //----------------------------------------------------------------------

    // Coll<Fraccion> c2 = coll<Fraccion>();
    // collAdd<Fraccion>(c2, fraccion(2, 3), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(7, 2), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(5, 6), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(7, 9), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(2, 8), fraccionToString);

    // collReset<Fraccion>(c2);

    // for (int i = 0; i < collSize<Fraccion>(c2); i++)
    // {
    //     Fraccion x = collGetAt<Fraccion>(c2, i, fraccionFromString);
    //     cout << fraccionToString(x) << endl;
    // }

    // while (collHasNext<Fraccion>(c2))
    // {
    //     Fraccion s = collNext<Fraccion>(c2, fraccionFromString);
    //     cout << fraccionToString(s) << endl;
    // }
    // bool endOfColl = false;
    // Fraccion s = collNext<Fraccion>(c2, endOfColl, fraccionFromString);

    // while (!endOfColl)
    // {
    //     cout << fraccionToString(s) << endl;
    //     s = collNext<Fraccion>(c2, endOfColl, fraccionFromString);
    // }

    return 0;
}