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

int main()
{
    // Coll<string> c = coll<string>();
    // collAdd<string>(c, "John", stringToString);
    // collAdd<string>(c, "Paul", stringToString);
    // collAdd<string>(c, "George", stringToString);
    // collAdd<string>(c, "Marto", stringToString);
    // collAdd<string>(c, "Ringo", stringToString);

    // for (int i = 0; i < collSize<string>(c); i++)
    // {
    //     string x = collGetAt<string>(c, i, stringToString);
    //     cout << x << endl;
    // }

    //----------------------------------------------------------------------

    // Coll<int> c1 = coll<int>();
    // collAdd<int>(c1, 5, intToString);
    // collAdd<int>(c1, 1, intToString);
    // collAdd<int>(c1, 3, intToString);

    // for (int i = 0; i < collSize<int>(c1); i++)
    // {
    //     int x = collGetAt<int>(c1, i, stringToInt);
    //     cout << x << endl;
    // }

    //----------------------------------------------------------------------

    // Coll<Fraccion> c2 = coll<Fraccion>();
    // collAdd<Fraccion>(c2, fraccion(2, 3), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(7, 2), fraccionToString);
    // collAdd<Fraccion>(c2, fraccion(5, 6), fraccionToString);

    // for (int i = 0; i < collSize<Fraccion>(c2); i++)
    // {
    //     Fraccion x = collGetAt<Fraccion>(c2, i, fraccionFromString);
    //     cout << fraccionToString(x) << endl;
    // }

    // collReset<string>(c);

    // while(collHasNext<string>(c)){
    // string s = collNext<string>(c,stringToString);

    // }

    return 0;
}