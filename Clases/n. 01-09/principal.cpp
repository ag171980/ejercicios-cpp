#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/arrays.hpp"
#include "../../API/biblioteca/tads/Array.hpp"
#include "../../API/biblioteca/tads/Map.hpp"

using namespace std;

int cmpInt(int a, int b)
{
    return a - b;
}
int main()
{
    Map<string, int> m = map<string, int>();
    mapPut<string, int>(m, "nine", 9);
    mapPut<string, int>(m, "siete", 7);
    mapPut<string, int>(m, "dos", 2);
    mapPut<string, int>(m, "uno", 1);
    mapPut<string, int>(m, "cuatro", 4);
    mapPut<string, int>(m, "tres", 3);
    mapPut<string, int>(m, "nine", 99);
    mapPut<string, int>(m, "uno", 12);

    // cout << mapContains<string, int>(m, "uno") << endl;

    // mapRemove<string, int>(m, "tres");

    // int *h = mapGet<string, int>(m, "cuatro");
    // cout << *h << endl;

    // mapSortByKeys<string, int>(m, cmpString);

    // mapSortByValues<string, int>(m, cmpInt);

    mapReset<string, int>(m);
    while (mapHasNext<string, int>(m))
    {
        string k = mapNextKey<string, int>(m);
        int *v = mapGet<string, int>(m, k);
        cout << k << ", " << *v << endl;
    }
}
