#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitWriter
{
	unsigned char bits[8]; // cambi� de int a char
	string bitsAux;
	FILE *f;
	int cont;
	int acum;
};

BitWriter bitWriter(FILE *f)
{
	BitWriter bw;
	bw.f = f;
	bw.cont = 0;
	bw.acum = 0;

	return bw;
}

string arrayToString(unsigned char bits[], int cantidad)
{
	// `
	string numAux = "";
	int i = 0;
	while (i < cantidad)
	{
		numAux += bits[i];
		// num = insertAt(num, i, bits[i]);
		i++;
	}
	return numAux;
}

void bitWriterWrite(BitWriter &bw, int bit)
{
	if (bw.cont == 8)
	{
		string codigo = arrayToString(bw.bits, 8);
		cout<<codigo<<endl;
		for (int i = 0; i < length(codigo); i++)
		{
			//cout << "Bit escrito: " << codigo[i] << endl;
			write<unsigned char>(bw.f, codigo[i]);
		}
		bw.cont = 0;
		int i = 0;
		while (i < 8)
		{
			bw.bits[i] = 0;
			i++;
		}
	}
	unsigned char bitc = intToChar(bit);
	bw.bits[bw.cont] = bitc;
	bw.cont++;
	bw.acum++;
}

void bitWriterWrite(BitWriter &bw, string bits) // funcion agregada
{
	int i = 0;
	while (i < length(bits))
	{
		bitWriterWrite(bw, stringToInt(substring(bits, i, i + 1)));
		i++;
	}
}

void bitWriterFlush(BitWriter &bw)
{
	int cont = bw.cont;
	string aux;
	for (int i = 0; i <= cont; i++)
	{
		aux += bw.bits[i];
	}
	int cantCeros = 8 - length(aux);
	//cout<<"aux es "<<aux<<endl;
	//cout<<"longitud de aux es "<<length(aux)<<endl;
	for (int i = 1; length(aux)<8; i++)
	{
		aux = insertAt(aux,length(aux),'0');
		//cout<<"aux es "<<aux<<endl;
	}
	//cout<<"aux quedo en "<<aux<<endl;
	//cout<<length(aux)<<endl;
	for (int i = 0; i < length(aux); i++)
	{
		//cout << "flush: " << aux[i] << endl;
		write<unsigned char>(bw.f, aux[i]);
	}
	bw.cont++;
	bw.acum++;
	// if (bw.cont == 8)
	// {
	// 	write<int>(bw.f, *bw.bits);
	// 	bw.cont = 0;
	// 	bw.acum = 0;
	// }
}

#endif
