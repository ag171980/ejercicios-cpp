#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T>
void write(FILE *f, T t)
{
   fseek(f, 0, SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
}

template <typename T>
T read(FILE *f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   T t;
   fseek(f, 0, SEEK_CUR);
   fread(&t, sizeof(T), 1, f);
   return t;
}

template <typename T>
void seek(FILE *f, int n)
{
   fseek(f, 0, SEEK_SET);
   T t;
   for (int i = 0; i < n; i++)
   {
      t = read<T>(f);
   }
}

template <typename T>
int fileSize(FILE *f)
{
   fseek(f, 0, SEEK_SET);
   int cont = 0;
   T t = read<T>(f);
   while (!feof(f))
   {
      t = read<T>(f);
      cont++;
   }
   return cont;
}

template <typename T>
int filePos(FILE *f)
{
   T t;
   int cont = 0;
   // cout << read<T>(f) << endl;
   // fseek(f, 0, SEEK_SET);
   // seek<T>(f,fileSize<T>(f));
   // while(!feof(f)){

   // }
   // cout << "seek_cur: " << fseek(f, 0, SEEK_CUR) << endl;

   return 0;
}

#endif
