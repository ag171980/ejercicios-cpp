#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct BitReader
{
    unsigned char bits[8];
    int pos;
    int cont;
    FILE *f;
};

BitReader bitReader(FILE *f)
{
    BitReader b;
    for (int i = 0; i < 8; i++)
    {
        b.bits[i] = 0;
    }
    b.pos = 0;
    b.cont = 0;
    b.f = f;

    return b;
}

int bitReaderRead(BitReader &br)
{
    int bit;
    unsigned char c;
    if (br.cont == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            br.bits[i] = read<unsigned char>(br.f);
        }
        br.cont = 8;
        br.pos = 0;
    }
    bit = br.bits[br.pos];
    br.pos++;
    br.cont--;
    //cout << "Bit leido: " << char(bit) << endl;
    return bit;
}

#endif
