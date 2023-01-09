using namespace std;
#ifndef _MAIN
#define _MAIN
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

void vaciarTabla(HuffmaneTable tabla[])
{
	int i = 0;
	while(i<256)
	{
		tabla[i].n=0;
		i++;
	}
}

void contarOcurrencias(string fName, HuffmaneTable tabla[])
{
	FILE* f = fopen("prueba.txt","r+b");
	int pos;
	char c = read<char>(f);
	while(!feof(f))
	{
		pos = int(c);
		tabla[pos].n++;
		c=read<char>(f);
	}
	fclose(f);
}

int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
	return b.n - a.n;
}

void crearLista(List<HuffmanTreeInfo>& lista, HuffmaneTable tabla[])
{
	int indice = 0;
	int contador;
	HuffmanTreeInfo nodo;
	
	while(indice<=255)
	{
		contador = tabla[indice].n;
		if(contador>0)
		{
			nodo.c = indice;
			nodo.n = contador;
			listOrderedInsert<HuffmanTreeInfo>(lista,nodo,cmpHuff);
		}
		indice++;
	}
	
}


void cargarCodigosEnTabla(HuffmanTreeInfo* raiz, HuffmaneTable tabla[])
{
    HuffmanTree ht = huffmanTree(raiz);
    string code;

    while(!huffmanTreeHasNext(ht))
    {
        HuffmanTreeInfo* x = huffmanTreeNext(ht, code);
        tabla[x->c].code = code;
    }
}

void grabarArchivoComprimido(string fName,HuffmaneTable tabla[])
{
}


void comprimir (string fName)
{
	//paso 1 
	HuffmaneTable tabla[256];
	vaciarTabla(tabla);
	contarOcurrencias (fName,tabla);
	
	//paso 2
	List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
	crearLista(lista,tabla);
	
	//paso 3
//	HuffmanTreeInfo* raiz = crearArbol (lista);
	
	// Recorro el arbol para obtener los codigos y los cargo en el array de contadores, en el campo code
//	cargarCodigosEnTabla(raiz,tabla);
	
	//Grabo el archivo comprimido
	grabarArchivoComprimido (fName,tabla);
}

void descomprimir(string fName)
{
	
}

int main()
{
	//recibo el nombre del archivo
	//string fName = argv[1];
	
	string fName = "prueba.txt";
	
	// si no termina con ".huf" comprimo
	if(!endsWith(fName,".huf"))
	{
		comprimir(fName);
	}
	else //descomprimo
	{
		descomprimir(fName);
	}
	
	return 0;
}


#endif







