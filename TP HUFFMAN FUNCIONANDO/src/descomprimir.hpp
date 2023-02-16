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
//Lee cantidad de hojas del archivo original
/*Paso 2*/
HuffmanTreeInfo *leerRegistros(FILE *f, unsigned char hojas);
/*=>*/ void agregarAlArbol(HuffmanTreeInfo *raiz, string codificacion, unsigned char c);
/*Paso 3*/
//Lee tamaño del archivo original
/*Paso 4*/
void leerInfoComprimida(FILE *f, string fNameStr, HuffmanTreeInfo *raiz, unsigned int filesize);
/*=>*/ HuffmanTreeInfo *bajarIzquierda(HuffmanTreeInfo *htInfo);
/*=>*/ HuffmanTreeInfo *bajarDerecha(HuffmanTreeInfo *htInfo);

/*-----------------------------------------------------*/

HuffmanTreeInfo *leerRegistros(FILE *f, unsigned char hojas)
{
    HuffmanTreeInfo *raiz = new HuffmanTreeInfo();
    int cont = 0;
    int i = 0;
    int size;
    unsigned char caracter;
    unsigned char cod;
    while (cont < int(hojas))
    {
        i = 0;
        string codificacion = "";
        caracter = read<unsigned char>(f);
        size = read<unsigned char>(f);

        while (i < size)
        {
            cod = read<unsigned char>(f);
            cod = intToChar(int(cod));
            codificacion = insertAt(codificacion, i, cod);
            i++;
        }
        agregarAlArbol(raiz, codificacion, caracter);
        cont++;
    }

    return raiz;
}

void agregarAlArbol(HuffmanTreeInfo *raiz, string codificacion, unsigned char c)
{
    HuffmanTreeInfo *p = raiz;
    for (int i = 0; i != length(codificacion); i++)
    {
        if (codificacion[i] == 48)
        {
            // bajo a la izquierda
            if (p->left == NULL)
            {
                HuffmanTreeInfo *nodo = new HuffmanTreeInfo();
                nodo->c = 257;
                p->left = nodo;
            }
            p = p->left;
        }
        else
        {
            // bajo a la derecha
            if (p->right == NULL)
            {
                HuffmanTreeInfo *nodo = new HuffmanTreeInfo();
                nodo->c = 257;
                p->right = nodo;
            }
            p = p->right;
        }
    }
    p->c = c;
}

void leerInfoComprimida(FILE *f, string fNameStr, HuffmanTreeInfo *raiz, unsigned int filesize)
{
    string aux = fNameStr;
    string fName = getTokenAt(aux, '.', 0);
    string extFile = getTokenAt(aux, '.', 1);
    fName = fName + "Desc." + extFile;
    int lenAux = length(fName);
    char *fNameDesc = new char[lenAux + 1];
    strcpy(fNameDesc, fName.c_str());

    FILE *fn = fopen(fNameDesc, "w+b");
    BitReader br = bitReader(f);
    unsigned char c = bitReaderRead(br);
    int i = 0;
    HuffmanTreeInfo *htInfo = raiz;
    while (i < filesize)
    {

        // cout << filesize << "." << fileSize<unsigned char>(fn) << endl;
        if (c == '0')
        {
            htInfo = bajarIzquierda(htInfo);
        }
        else if (c == '1')
        {
            htInfo = bajarDerecha(htInfo);
        }
        if (htInfo->c < 256)
        {
            unsigned char caracter = htInfo->c;
            // cout << "Caracter: " << caracter << endl;
            write<unsigned char>(fn, caracter);
            i++;
            htInfo = raiz;
        }
        c = bitReaderRead(br);
    }

    fclose(fn);
}

HuffmanTreeInfo *bajarIzquierda(HuffmanTreeInfo *htInfo)
{
    HuffmanTreeInfo *izq = htInfo->left;

    return izq;
}

HuffmanTreeInfo *bajarDerecha(HuffmanTreeInfo *htInfo)
{
    HuffmanTreeInfo *der = htInfo->right;

    return der;
}

// HuffmanTreeInfo *newNodo(unsigned int c)
// {
//     HuffmanTreeInfo *nodo = new HuffmanTreeInfo;
//     nodo->c = c;
//     nodo->left = NULL;
//     nodo->right = NULL;
//     return nodo;
// }
