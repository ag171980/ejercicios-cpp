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
#include "BitReader.hpp"
#include "BitWriter.hpp"

void vaciarTabla(HuffmaneTable tabla[])
{
	for (int i = 0; i < 256; i++)
	{
		tabla[i].n = 0;
	}
}

void contarOcurrencias(string fName, HuffmaneTable tabla[])
{
	FILE *f = fopen("prueba.txt", "r+b");
	char c = read<char>(f);
	while (!feof(f))
	{
		tabla[int(c)].n++;
		c = read<char>(f);
	}
	fclose(f);
}

int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
	return (a.n < 256 && b.n < 256) ? a.n - b.n : a.c - b.c;
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

void mostrarLista(List<HuffmanTreeInfo> lista)
{
	while (listHasNext(lista))
	{
		HuffmanTreeInfo *p = listNext<HuffmanTreeInfo>(lista);
		// cout << "[" << p->c << "],{" << p->n << "}" << endl;
	}
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

char contarHojas(HuffmaneTable tabla[])
{
	int cont = 0;
	for (int i = 0; i <= 255; i++)
	{
		if (tabla[i].n != 0)
		{
			cont++;
		}
	}

	return intToChar(cont);
}

void escribirRegistro(FILE *fc, string code, char caracter)
{
	//	cout << caracter << "(" << sizeof(caracter) << "), " << length(code) << "(" << sizeof(intToChar(length(code))) << "), " << code << "(" << sizeof(code) << ")" << endl;
	write<unsigned char>(fc, caracter);
	write<unsigned char>(fc, char(length(code)));
	for (int i = 0; i < length(code); i++)
	{
		if (char(code[i]) == 49)
		{
			write<unsigned char>(fc, '1');
		}
		else
		{
			write<unsigned char>(fc, '0');
		}
	}
}

bool Leyo(char c, int contador[])
{
	if (contador[c] > 0)
		return true;
	else
	{
		contador[c]++;
		return false;
	}
}

void escribirCodificado(HuffmaneTable tabla[], FILE *f, FILE *fc)
{
	seek<char>(f, 0);
	seek<char>(fc, 0);
	BitWriter bw = bitWriter(fc);
	//	char c = read<char>(f);
	for (int i = 0; i < 256; i++)
	{
		if (tabla[i].n != 0)
		{
			string code = tabla[i].code;
			//			cout<<code<<endl;
			bitWriterWrite(bw, code);
			//			c = read<char>(f);
		}
	}
	//	while (!feof(f))
	//	{
	//		string code = tabla[int(c)].code;
	//		bitWriterWrite(bw, code);
	//		c = read<char>(f);
	//	}
	//	 if (bw.cont != 0)
	//	 {
	//	 	int codigo = stringToInt(arrayToString(bw.bits, bw.cont), 2);
	//	 	char ch = static_cast<char>(codigo);
	//	 	write<unsigned char>(bw.f, ch);
	//	 }
	bitWriterFlush(bw);
}

void grabarArchivoComprimido(string fName, HuffmaneTable tabla[])
{
	FILE *f = fopen("prueba.txt", "r+b");
	FILE *fc = fopen("pruebax.txt", "w+b");
	seek<char>(f, 0);
	seek<char>(fc, 0);
	int filesize = fileSize<char>(f);
	// 1. 1 byte indicando cuantas hojas conforman el arbol.
	write<char>(fc, contarHojas(tabla));
	int canthojas = charToInt(contarHojas(tabla));

	// Creo un contador para saber si un caracter del archivo ya fue leido
	int contador[256];
	for (int i = 0; i < 256; i++)
	{
		contador[i] = 0;
	}

	// 2. t registros (uno por cada hoja del arbol)
	char c = read<char>(f);
	//	while (!feof(f))
	//	{
	//		if (!Leyo(c, contador))
	//	 	{
	//	 		string code = tabla[int(c)].code;
	//	 		cout << "caracter: " << char(c) << ", LengthCode: " << length(code) << ", Code: " << code << endl;
	//	 		escribirRegistro(fc, code, char(c));
	//	 	}
	//	 	c = read<char>(f);
	//	}
	int i = 0;
	while (i < 256)
	{
		if (tabla[i].n != 0)
		{
			string code = tabla[i].code;
			// cout << "caracter: " << char(i) << ", LengthCode: " << length(code) << ", Code: " << code << endl;
			cout << char(i) << "" << length(code) << "" << code << endl;
			escribirRegistro(fc, code, char(i));
		}
		i++;
	}

	// 3. 4 bytes indicando longitud del archivo original. Un valor entero sin signo indicando la long. en bytes.
	write<unsigned int>(fc, filesize);

	// 4. Informacion codificada y comprimida.
		escribirCodificado(tabla, f, fc);

	fclose(f);
	fclose(fc);
}

void recorrerArbol(List<HuffmanTreeInfo> &lista)
{
	// obtengo el arbol
	HuffmanTreeInfo *raiz = crearArbol(lista);

	// recorro el arbol usando TAD HuffmanTree
	HuffmanTree ht = huffmanTree(raiz);

	string cod;
	while (huffmanTreeHasNext(ht))
	{
		HuffmanTreeInfo *x = huffmanTreeNext(ht, cod);
	}
}

void comprimir(string fName)
{
	// paso 1
	HuffmaneTable tabla[256];
	vaciarTabla(tabla);
	contarOcurrencias(fName, tabla);

	// paso 2
	List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
	crearLista(lista, tabla);

	// paso 3
	HuffmanTreeInfo *raiz = crearArbol(lista);

	// Recorro el arbol para obtener los codigos y los cargo en el array de contadores, en el campo code
	cargarCodigosEnTabla(raiz, tabla);

	// Grabo el archivo comprimido
	grabarArchivoComprimido(fName, tabla);
}

string toBinary(int n)
{
	string r;
	while (n != 0)
	{
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

void descomprimir(string fName)
{
	FILE *f = fopen("prueba.txt.huf", "r+b");
	// BitReader br = bitReader(f);
	char c = read<char>(f);
	cout << "El arbol tiene " << charToInt(c) << " hojas" << endl;
	int x = read<int>(f);
	cout << "La longitud del archivo original es de " << x << " bytes" << endl;
	c = read<char>(f);
	while (!feof(f))
	{
		// cout<<"Leo un "<<toBinary(int(c))<<endl;
		// bitReaderRead(br);
		cout << charToInt(c) << endl;
		c = read<char>(f);
	}

	fclose(f);
}

int main()
{
	// recibo el nombre del archivo
	// string fName = argv[1];

	string fName = "prueba.txt";

	// si no termina con ".huf" comprimo
	if (!endsWith(fName, ".huf"))
	{
		comprimir(fName);
	}
	/*else //descomprimo
	{
		descomprimir(fName);
	}
	*/

	// descomprimir("prueba.txt.huf");
	return 0;
}

#endif
