#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD
#include "./biblioteca/funciones/strings.hpp"
=======
#include "biblioteca/funciones/strings.hpp"
>>>>>>> 9b804d1a2b7a938fb59e393c69064f5cb1065f2b

using namespace std;

struct BitReader
{
	int bits[8];
	int cont;
	FILE* f;
};

BitReader bitReader(FILE* f)
{
	BitReader b;
	for(int i = 0; i<8; i++)
	{
		b.bits[i] = read<int>(f);
	}
	b.cont = 0;
	b.f = f;

   return b;
}

int bitReaderRead(BitReader& br)
{
	int bit;
	if(br.cont == 8)
	{
		bitReader(br.f);
	}
	bit = br.bits[br.cont];
	br.cont++;

   return bit;
}

#endif
