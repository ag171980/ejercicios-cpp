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
	int bits[8];
	FILE* f;
	int cont;
	int acum;
};

BitWriter bitWriter(FILE* f)
{
	BitWriter bw;
	bw.f = f;
	bw.cont = 0;
	bw.acum = 0;

   return bw;
}

void bitWriterWrite(BitWriter& bw,int bit)
{
	if(bw.cont == 8)        
	{
		int x = 0;
		while(x<8)
		{
			write<int>(bw.f,bw.bits[x]);
			x++;
		}        
		bw.cont = 0;
	}
	bw.bits[bw.cont] = bit;
	bw.cont++;
	bw.acum++;
}

void bitWriterWrite(BitWriter& bw, string bits)      //funcion agregada
{
	int i = 0;
	while(i<length(bits))
	{
		bitWriterWrite(bw,stringToInt(substring(bits,i,i+1)));
		i++;
	}
}

void bitWriterFlush(BitWriter& bw)
{
	while((bw.acum % 8) != 0)
	{
		bitWriterWrite(bw, 0);
	}
	if(bw.cont == 8)
	{
		write<int>(bw.f, *bw.bits);
		bw.cont = 0;
		bw.acum = 0;
	}
}

#endif
