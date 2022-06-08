#include <iostream>
#include <string>
#include "../../API/biblioteca/funciones/strings.hpp"
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
int main()
{

    
    // FILE *f = fopen("fracciones.qq", "w+b");

    // write<short>(f,1234);
    // write<short>(f,4321);
    // write<short>(f,-1);

    // Representacion de lo que tenemos,
    //  01 23 45
    //   1, 2, 3, 4,...

    // FILE *f = fopen("x.afh", "r+b");
    // fseek(f, 2, SEEK_SET);
    // cout << ftell(f) << endl;
    // short s;
    // fread(&s, sizeof(short), 1, f);
    // cout << s << endl;

    // Abrimos el archivo para lectura y recorremos lo que tiene adentro y mostramos.

    //  FILE *f = fopen("y.afh", "r+b");
    //  short c;
    //  fread(&c, sizeof(short), 1, f);
    //  while (!feof(f))
    //  {
    //      cout << c << endl;
    //      fread(&c, sizeof(short), 1, f);
    //  }

    // Creamos un archivo .pdf e ingresamos numeros, se guardan pero no al igual que antes por el tipo de dato short que ocupa 2 bytes.
    // Esto ocurre por el tipo de dato y no por el tipo de archivo, esto ultimo es indistinto

    // FILE *f = fopen("y.afh", "w+b");
    // short s = 1;
    // fwrite(&s, sizeof(short), 1, f);
    // s = 2;
    // fwrite(&s, sizeof(short), 1, f);
    // s = 3;
    // fwrite(&s, sizeof(short), 1, f);
    // s = 4;
    // fwrite(&s, sizeof(short), 1, f);

    // Abrimos un archivo ya creado y usamos el fseek con SEEK_END para posicionarnos en el final del archivo.
    // Tambien usamos ftell que nos devuelve la cantidad de lo que hay en el archivo

    // FILE *f = fopen("x.afh", "r+b");
    // // movete al byte 2
    // fseek(f, 0, SEEK_END);
    // char c;
    // cout << ftell(f) << endl;
    // fread(&c, sizeof(char), 1, f);
    // cout << c << endl;

    // FILE *f = fopen("x.afh", "r+b");
    // // leo primer char
    // unsigned char c;
    // fread(&c, sizeof(char), 1, f);
    // while (!feof(f))
    // {
    //     cout << c;
    //     fread(&c, sizeof(char), 1, f);
    // }
    // c++;
    // fwrite(&c, sizeof(char),1,f);

    // FILE *f = fopen("x.afh", "w+b");
    // string texto = "Quiero insertar este texto al archivo";
    // for (int i = 0; i < length(texto); i++)
    // {
    //     fwrite(&texto[i], sizeof(char), 1, f);
    // }
    // char c = 'A';
    // c = 'B';
    // fwrite(&c, sizeof(char), 1, f);
    // c = 'C';
    // fwrite(&c, sizeof(char), 1, f);
    // c = 'D';
    // fwrite(&c, sizeof(char), 1, f);

    // fclose(f);
}