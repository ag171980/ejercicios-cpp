#include <iostream>
#include <string>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/funciones/files.hpp"
using namespace std;

int main()
{
    // 1.Write
    //  FILE *f = fopen("fracciones.qq", "w+b");
    //  write<short>(f, 2111);
    //  write<short>(f, 1212);
    //  write<short>(f, 2901);
    //  write<short>(f, 4506);
    //  write<short>(f, 3498);
    //  write<short>(f, 12200);
    //  write<short>(f, 23);
    //  write<short>(f, -1);
    //  fclose(f);

    // 2.Read
    // FILE *f = fopen("fracciones.qq", "r+b");

    // short s = read<short>(f);
    // while (!feof(f))
    // {
    //     cout << s << endl;
    //     s = read<short>(f);
    // }

    // cout << "--------------" << endl;
    // fclose(f);

    // 3.Seek
    // FILE *f = fopen("fracciones.qq", "r+b");

    // seek<short>(f, 3);
    // short v = read<short>(f);
    // cout << v << endl;

    // fclose(f);

    // 4.fileSize
    // FILE *f = fopen("fracciones.qq", "r+b");

    // for (int i = fileSize<short>(f) - 1; i >= 0; i--)
    // {
    //     seek<short>(f, i);
    //     short s = read<short>(f);
    //     cout << s << endl;
    // }

    // fclose(f);

    // 5.filePos
    FILE *f = fopen("fracciones.qq", "r+b");

    for (int i = fileSize<short>(f) - 1; i >= 0; i--)
    {
        seek<short>(f, i);
        int pos = filePos<short>(f);
        short s = read<short>(f);

        cout << "Registro Nro. " << pos << ", " << s << endl;
    }

    fclose(f);
    return 0;
}