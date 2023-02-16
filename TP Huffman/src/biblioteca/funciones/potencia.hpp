

#include <iostream>

#include <stdio.h>
#include <math.h>

int potencia(int numero, int potencia)
{
    if(potencia==0)
    	return 1;
    else
    {
		int resultado = numero;
    	while (potencia > 1)
    	{
        	resultado = resultado * numero;
        	potencia--;
    	}
    return resultado;
	}
}
