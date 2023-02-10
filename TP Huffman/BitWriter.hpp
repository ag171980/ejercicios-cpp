#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/files.hpp"

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
	string num = "";
	string numAux ="";
	int i = 0;
	while (i < cantidad)
	{
//		cout<<bits[i]<<endl;
		numAux +=bits[i];
		cout<<numAux<<endl;
//		cout<<"insertAt: ("<<num<<", "<<i<<", "<<bits[i]<<")"<<endl;
		num = insertAt(num, i, bits[i]);
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
		for(int i = 0; i < length(codigo);i++){
			char ch = static_cast<char>(codigo);
			cout<<ch<<endl;
		}
		//		write<unsigned char>(bw.f, char(codigo));
		bw.cont = 0;
		int i = 0;
		while (i < 8)
		{
			bw.bits[i] = 0;
			i++;
		}
		cout<<"------------------"<<endl;
	}

	char bitc = intToChar(bit);
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
	while ((bw.acum % 8) != 0)
	{
		bitWriterWrite(bw, 0);
	}
	if (bw.cont == 8)
	{
		write<int>(bw.f, *bw.bits);
		bw.cont = 0;
		bw.acum = 0;
	}
}

#endif
