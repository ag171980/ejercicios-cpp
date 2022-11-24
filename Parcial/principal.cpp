//============================================================================
// Name        : cpp.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "principal.hpp"
using namespace std;

Coll<Predio> subirPredios()
{
   return {};
}

Coll<Capacidad> inicializarCapacidades(Coll<Predio> cPre)
{
   return {};
}

void procesarReserva(Reserva r,Coll<Capacidad>& cCap,Coll<Barrio>& cBar,FILE* w)
{

}

void motrarPunto3(Coll<Barrio> cBar)
{

}

int main( )
{
   // inicializo estructuras de datos
   Coll<Predio> cPre = subirPredios();
   Coll<Capacidad> cCap = inicializarCapacidades(cPre);
   Coll<Barrio> cBar = coll<Barrio>();

   // abro archivos
   FILE* f = fopen("RESERVAS.dat","r+b");
   FILE* w = fopen("RECHAZOS.dat","w+b");

   // proceso reservas
   Reserva r = read<Reserva>(f);
   while( !feof(f) )
   {
      procesarReserva(r,cCap,cBar,w);
      r = read<Reserva>(f);
   }

   // muestro punto 3
   motrarPunto3(cBar);

   fclose(w);
   fclose(f);
   return 0;
}



