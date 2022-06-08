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
    // Coll<string> c = coll<string>();
    // collAdd<string>(c, "Rammus", stringToString);
    // collAdd<string>(c, "Alistar", stringToString);
    // collAdd<string>(c, "Malzahar", stringToString);
    // collAdd<string>(c, "Pantheon", stringToString);
    // collAdd<string>(c, "Darius", stringToString);
    // collAdd<string>(c, "Jayce", stringToString);
    // // collSort<string>(c, cmpString, stringToString, stringToString);

    // // collFind
    // string text = "Alistar";
    // int pos = collFind<string>(c, text, cmpString, stringToString);
    // cout << pos << endl;

    // collNext 2
    //  bool endOfColl = false;
    //  string s = collNext<string>(c, endOfColl, stringToString);
    //  while (!endOfColl)
    //  {
    //      cout << s << endl;
    //      s = collNext<string>(c, endOfColl, stringToString);
    //  }
    cout << "-------------------" << endl;

    //----------------------------------------------------------------------

    Coll<int> c1 = coll<int>();
    collAdd<int>(c1, 5, intToString);
    collAdd<int>(c1, 1, intToString);
    collAdd<int>(c1, 7, intToString);
    collAdd<int>(c1, 10, intToString);
    collAdd<int>(c1, 2, intToString);
    collAdd<int>(c1, 3, intToString);
    // collSort<int>(c1, cmpInt, intFromString, intToString);
    // collRemoveAt<int>(c1, 2);
    // int pos = 1;
    // int nuevo = 111;
    // collSetAt<int>(c1, nuevo, pos, intToString);
    // for (int i = 0; i < collSize<int>(c1); i++)
    // {
    //     cout << collGetAt<int>(c1, i, intFromString) << endl;
    // }
    // int encontrar = 2;
    // int pos = collFind<int>(c1, encontrar, cmpInt, stringToInt);
    // cout << pos << endl;
    // bool endOfColl = false;
    // int s = collNext<int>(c1, endOfColl, stringToInt);
    // while (!endOfColl)
    // {
    //     cout << s << endl;
    //     s = collNext<int>(c1, endOfColl, stringToInt);
    // }

    //----------------------------------------------------------------------

    Coll<Fraccion> c2 = coll<Fraccion>();
    collAdd<Fraccion>(c2, fraccion(2, 3), fraccionToString);
    collAdd<Fraccion>(c2, fraccion(7, 2), fraccionToString);
    collAdd<Fraccion>(c2, fraccion(5, 6), fraccionToString);
    collAdd<Fraccion>(c2, fraccion(7, 9), fraccionToString);
    collAdd<Fraccion>(c2, fraccion(2, 8), fraccionToString);

    // collReset<Fraccion>(c2);

    // for (int i = 0; i < collSize<Fraccion>(c2); i++)
    // {
    //     Fraccion x = collGetAt<Fraccion>(c2, i, fraccionFromString);
    //     cout << fraccionToString(x) << endl;
    // }

    // while (collHasNext<Fraccion>(c2))
    // {
    //     string s = collNext<Fraccion>(c2, fraccionToString);
    //     cout << s << endl;
    // }
    // bool endOfColl = false;
    // while (collHasNext<Fraccion>(c2))
    // {
    //     string s = collNext<Fraccion>(c2, fraccionToString);
    //     cout << s << endl;
    // }

    return 0;
}