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
#include "comprimir.hpp"
#include "descomprimir.hpp"

void comprimir(string fNameStr)
{
	// string to char al .bmp
	string fNameAux = fNameStr;
	int lenAux = length(fNameAux);
	char *fNameNormal = new char[lenAux + 1];
	strcpy(fNameNormal, fNameAux.c_str());

	// string to char al .bmp.huf
	string fNameAuxHuf = fNameStr;
	fNameAuxHuf = fNameAuxHuf + ".huf";
	int len = length(fNameAuxHuf);
	char *fNameCompressed = new char[len + 1];
	strcpy(fNameCompressed, fNameAuxHuf.c_str());

	// paso 1

	HuffmaneTable tabla[256];
	vaciarTabla(tabla);
	contarOcurrencias(fNameNormal, tabla);

	// paso 2
	List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
	crearLista(lista, tabla);

	// paso 3
	HuffmanTreeInfo *raiz = crearArbol(lista);

	// paso 4: Recorro el arbol para obtener los codigos y los cargo en el array de contadores, en el campo code
	cargarCodigosEnTabla(raiz, tabla);

	// paso 5: Grabo el archivo comprimido
	grabarArchivoComprimido(fNameNormal, fNameCompressed, tabla);
}

void descomprimir(string fNameStr)
{
	string fNameAux = fNameStr;
	int lenAux = length(fNameAux);
	char *fNameCompressed = new char[lenAux + 1];
	strcpy(fNameCompressed, fNameAux.c_str());

	FILE *f = fopen(fNameCompressed, "r+b");

	// paso 1
	unsigned char hojas = read<unsigned char>(f);

	// paso 2
	unsigned int filesize;
	HuffmanTreeInfo *raiz = leerRegistros(f, hojas);

	// paso 3
	filesize = read<unsigned int>(f);

	//paso 4
	leerInfoComprimida(f, fNameStr, raiz, filesize);

	fclose(f);
}

int main()
{
	string fName = "";
	cout << "Hola! Ingresa el nombre del archivo que queres comprimir :)" << endl;
	cin >> fName;
	// si no termina con ".huf" comprimo
	if (!endsWith(fName, ".huf"))
	{
		cout << "Comienza la compresion" << endl;
		comprimir(fName);
		cout << "Listo, archivo comprimido!" << endl;
	}
	else
	{
		cout << "Comienza la descompresion de tu archivo!!" << endl;
		descomprimir(fName);
		cout << "Archivo descomprimido!" << endl;
	}
	return 0;
}

#endif
