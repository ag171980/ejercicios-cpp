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

void vaciarTabla(HuffmaneTable tabla[]) {
	int i = 0;
	while (i < 256) {
		tabla[i].n = 0;
		i++;
	}
}

void contarOcurrencias(string fName, HuffmaneTable tabla[]) {
	FILE *f = fopen("prueba.txt", "r+b");
	int pos;
	char c = read<char>(f);
	while (!feof(f)) {
		pos = int(c);
		tabla[pos].n++;
		c = read<char>(f);
	}
	fclose(f);
}

int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b) {
	return (a.n < 256 && b.n < 256)? a.n - b.n : a.c - b.c;
}

void crearLista(List<HuffmanTreeInfo> &lista, HuffmaneTable tabla[]) {
	int indice = 0;
	int contador;
	HuffmanTreeInfo nodo;

	while (indice <= 255) {
		contador = tabla[indice].n;
		if (contador > 0) {
			nodo.c = indice;
			nodo.n = contador;
			nodo.left = NULL;
			nodo.right = NULL;
			listOrderedInsert<HuffmanTreeInfo>(lista, nodo, cmpHuff);
		}
		indice++;
	}
}

void mostrarLista(List<HuffmanTreeInfo> lista) {
	while (listHasNext(lista)) {
		HuffmanTreeInfo *p = listNext<HuffmanTreeInfo>(lista);
		cout << "[" << p->c << "],{" << p->n << "}" << endl;
	}
}

bool tieneHijos(HuffmanTreeInfo nodo) {
	if (nodo.left == NULL && nodo.right == NULL)
		return false;
	else
		return true;
}

HuffmanTreeInfo *crearNodo(HuffmanTreeInfo *nododer, HuffmanTreeInfo *nodoizq, int i) {
	// Creo un nuevo nodo.
	HuffmanTreeInfo *newnodo = new HuffmanTreeInfo();
	newnodo->c = 255 + i;
	newnodo->n = nodoizq->n + nododer->n;
	newnodo->right = nododer;
	newnodo->left = nodoizq;

	return newnodo;
}

HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> &lista) {
	int i = 1;
	while (listSize(lista) > 1) { // mientras que la lista tenga mas de un elemento
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

void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmaneTable tabla[]) {
	HuffmanTree ht = huffmanTree(raiz);
	string code;

	while (huffmanTreeHasNext(ht)) {
		HuffmanTreeInfo *x = huffmanTreeNext(ht, code);
		tabla[x->c].code = code;
	}
}

void grabarArchivoComprimido(string fName, HuffmaneTable tabla[]) {
	FILE *f = fopen("prueba.txt.huf", "w+r");
	int pos;
	char c = read<char>(f);
	while (!feof(f))
	{
		string code = tabla[pos].code;
		write(code,f);

		c = read(f);
		pos++;
	}
	fclose(f);
}

void recorrerArbol(List<HuffmanTreeInfo> &lista) {
	// obtengo el arbol
	HuffmanTreeInfo *raiz = crearArbol(lista);

	// recorro el arbol usando TAD HuffmanTree
	HuffmanTree ht = huffmanTree(raiz);

	string cod;
	while (huffmanTreeHasNext(ht)) {
		HuffmanTreeInfo *x = huffmanTreeNext(ht, cod);
		cout << char(x->c) << ", (" << x->n << "), "
		     << "[" << cod << "]" << endl;
	}
}

void comprimir(string fName) {
	// paso 1
	HuffmaneTable tabla[256];
	vaciarTabla(tabla);
	contarOcurrencias(fName, tabla);

	// paso 2
	List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
	crearLista(lista, tabla);
	// mostrarLista(lista);

	// paso 3
	HuffmanTreeInfo* raiz = crearArbol (lista);
	// mostrarLista(lista);
	// recorrerArbol(lista);

	// Recorro el arbol para obtener los codigos y los cargo en el array de contadores, en el campo code
	cargarCodigosEnTabla(raiz,tabla);
	// recorrerArbol(raiz);

	// Grabo el archivo comprimido
	grabarArchivoComprimido(fName, tabla);
}

void descomprimir(string fName) {
}

int main() {
	// recibo el nombre del archivo
	// string fName = argv[1];

	string fName = "prueba.txt";

	// si no termina con ".huf" comprimo
	if (!endsWith(fName, ".huf")) {
		comprimir(fName);
	} else { // descomprimo
		descomprimir(fName);
	}


	return 0;
}

#endif
