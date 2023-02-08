#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/files.hpp"


using namespace std;

string arrayToString(unsigned char bits[],int cantidad)
{
	string num="";
	int i = 0;
	while(i<cantidad)
	{
		num = insertAt(num,i,bits[i]);
		i++;
	}
	return num;
}

struct BitWriter
{
	unsigned char bits[8];          //cambi� de int a char
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
		int codigo = stringToInt(arrayToString(bw.bits,8),2);
		//cout<<arrayToString(bw.bits,bw.cont)<<endl;
		char ch = static_cast<char>(codigo);
		write<unsigned char>(bw.f,ch);  
		bw.cont = 0;
		int i =0;
		while(i < 8)
		{
			bw.bits[i]=0;
			i++;
		}
	}
	char bitc = intToChar(bit);
	bw.bits[bw.cont] = bitc;
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
