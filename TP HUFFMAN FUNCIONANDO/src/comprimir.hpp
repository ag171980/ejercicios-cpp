#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "biblioteca/tads/BitReader.hpp"
#include "biblioteca/tads/BitWriter.hpp"

using namespace std;

// declaracion de funciones
/*Paso 1*/
void vaciarTabla(HuffmaneTable tabla[]);
void contarOcurrencias(char *fName, HuffmaneTable tabla[]);
/*Paso 2*/
void crearLista(List<HuffmanTreeInfo> &lista, HuffmaneTable tabla[]);
/**/
/*Paso 3*/
HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> &lista);
/*=>*/ HuffmanTreeInfo *crearNodo(HuffmanTreeInfo *nododer, HuffmanTreeInfo *nodoizq, int i);

/*Paso 4*/
void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmaneTable tabla[]);

/*Paso 5*/
void grabarArchivoComprimido(char *fName, char *fNameCompressed, HuffmaneTable tabla[]);
/*=>*/ unsigned char contarHojas(HuffmaneTable tabla[]);
/*=>*/ bool Leyo(unsigned char c, int contador[]);
/*=>*/ void escribirRegistro(FILE *fc, string code, unsigned char caracter);
/*=>*/ void escribirCodificado(HuffmaneTable tabla[], FILE *f, FILE *fc);

/*Extras*/
int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b);
// void recorrerArbol(List<HuffmanTreeInfo> &lista);
// void mostrarLista(List<HuffmanTreeInfo> lista);

/*-----------------------------------------------------*/

int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
    return (a.n < 256 && b.n < 256) ? a.n - b.n : a.c - b.c;
}

void vaciarTabla(HuffmaneTable tabla[])
{
    for (int i = 0; i < 256; i++)
    {
        tabla[i].n = 0;
    }
}

void contarOcurrencias(char *fName, HuffmaneTable tabla[])
{
    FILE *f = fopen(fName, "r+b");
    unsigned char c = read<unsigned char>(f);
    while (!feof(f))
    {
        tabla[int(c)].n++;
        c = read<unsigned char>(f);
    }
    fclose(f);
}

void crearLista(List<HuffmanTreeInfo> &lista, HuffmaneTable tabla[])
{
    int indice = 0;
    int contador;
    HuffmanTreeInfo nodo;

    while (indice <= 255)
    {
        contador = tabla[indice].n;
        if (contador > 0)
        {
            nodo.c = indice;
            nodo.n = contador;
            nodo.left = NULL;
            nodo.right = NULL;
            listOrderedInsert<HuffmanTreeInfo>(lista, nodo, cmpHuff);
        }
        indice++;
    }
}

HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> &lista)
{
    int i = 1;
    while (listSize(lista) > 1) // mientras que la lista tenga mas de un elemento
    {
        HuffmanTreeInfo *nododer = new HuffmanTreeInfo();
        HuffmanTreeInfo *nodoizq = new HuffmanTreeInfo();

        // elimino los dos primeros nodos de la lista
        *nododer = listRemoveFirst(lista);
        *nodoizq = listRemoveFirst(lista);

        // creo un nuevo nodo = newnodo
        HuffmanTreeInfo *newnodo = new HuffmanTreeInfo();
        newnodo = crearNodo(nododer, nodoizq, i);
        listOrderedInsert<HuffmanTreeInfo>(lista, *newnodo, cmpHuff);

        i++;
    }
    HuffmanTreeInfo *root = listNext(lista);

    return root;
}

HuffmanTreeInfo *crearNodo(HuffmanTreeInfo *nododer, HuffmanTreeInfo *nodoizq, int i)
{
    // Creo un nuevo nodo.
    HuffmanTreeInfo *newnodo = new HuffmanTreeInfo();
    newnodo->c = 255 + i;
    newnodo->n = nodoizq->n + nododer->n;
    newnodo->right = nododer;
    newnodo->left = nodoizq;

    return newnodo;
}

void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmaneTable tabla[])
{
    HuffmanTree ht = huffmanTree(raiz);
    string code;

    while (huffmanTreeHasNext(ht))
    {
        HuffmanTreeInfo *x = huffmanTreeNext(ht, code);
        tabla[x->c].code = code;
    }
}

void grabarArchivoComprimido(char *fName, char *fNameCompressed, HuffmaneTable tabla[])
{
    FILE *f = fopen(fName, "r+b");
    FILE *fc = fopen(fNameCompressed, "w+b");
    unsigned int filesize = fileSize<unsigned char>(f);

    // 1. 1 byte indicando cuantas hojas conforman el arbol.
    write<unsigned char>(fc, contarHojas(tabla));

    // Creo un contador para saber si un caracter del archivo ya fue leido
    int contador[256];
    for (int i = 0; i < 256; i++)
    {
        contador[i] = 0;
    }

    // 2. t registros (uno por cada hoja del arbol)
    unsigned char c = read<unsigned char>(f);
    while (!feof(f))
    {
        if (!Leyo(c, contador))
        {
            string code = tabla[int(c)].code;
            escribirRegistro(fc, code, char(c));
        }
        c = read<unsigned char>(f);
    }

    // 3. 4 bytes indicando longitud del archivo original. Un valor entero sin signo indicando la long. en bytes.
    write<unsigned int>(fc, filesize);

    // 4. Informacion codificada y comprimida.
    escribirCodificado(tabla, f, fc);

    fclose(f);
    fclose(fc);
}

unsigned char contarHojas(HuffmaneTable tabla[])
{
    int cont = 0;
    for (int i = 0; i <= 255; i++)
    {
        if (tabla[i].n != 0)
        {
            cont++;
        }
    }
    return char(cont);
}

bool Leyo(unsigned char c, int contador[])
{
    if (contador[c] > 0)
        return true;
    else
    {
        contador[c]++;
        return false;
    }
}

void escribirRegistro(FILE *fc, string code, unsigned char caracter)
{
    write<unsigned char>(fc, caracter);
    write<unsigned char>(fc, length(code));
    for (int i = 0; i < length(code); i++)
    {
        write<unsigned char>(fc, (char(code[i]) == 49));
    }
}

void escribirCodificado(HuffmaneTable tabla[], FILE *f, FILE *fc)
{
    BitWriter bw = bitWriter(fc);

    seek<unsigned char>(f, 0);
    unsigned char c = read<unsigned char>(f);
    while (!feof(f))
    {
        string code = tabla[int(c)].code;
        bitWriterWrite(bw, code);
        c = read<unsigned char>(f);
    }

    bitWriterFlush(bw);
}

// void recorrerArbol(List<HuffmanTreeInfo> &lista)
// {
//     // obtengo el arbol
//     HuffmanTreeInfo *raiz = crearArbol(lista);

//     // recorro el arbol usando TAD HuffmanTree
//     HuffmanTree ht = huffmanTree(raiz);

//     string cod;
//     while (huffmanTreeHasNext(ht))
//     {
//         HuffmanTreeInfo *x = huffmanTreeNext(ht, cod);
//         cout << char(x->c) << ", (" << x->n << "), "
//              << "[" << cod << "]" << endl;
//     }
// }

// void mostrarLista(List<HuffmanTreeInfo> lista)
// {
//     while (listHasNext(lista))
//     {
//         HuffmanTreeInfo *p = listNext<HuffmanTreeInfo>(lista);
//         cout << "[" << p->c << "],{" << p->n << "}" << endl;
//     }
// }
