#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
using namespace std;

struct Reproduccion
{
   int idUsuario;
   int idAlbum;
   int fecha;
   int minutos;
};

struct Album
{
   int idAlbum;
   int idArtista;
   char titulo[50];
   int duracion;
};

struct Artista
{
   int idArtista;
   char nombre[50];
};

struct IdxAlbum
{
   int idAlbum;
   int pos;
   int c100;
   int c75;
   int c50;
   int c25;
   int c0;
};

struct IdxArtista
{
   int idArtista;
   int pos;
   int cont;
};

string reproduccionToString(Reproduccion x)
{
   char sep = 1;
   string sIdUsuario=to_string(x.idUsuario);
   string sIdAlbum=to_string(x.idAlbum);
   string sFecha=to_string(x.fecha);
   string sMinutos=to_string(x.minutos);
   return sIdUsuario+sep+sIdAlbum+sep+sFecha+sep+sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
   char sep = 1;
   Reproduccion x;
   string t0 = getTokenAt(s,sep,0);
   x.idUsuario=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idAlbum=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.fecha=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.minutos=stoi(t3);
   return x;
}

string reproduccionToDebug(Reproduccion x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idUsuario;
   sout << ",";
   sout << x.idAlbum;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.minutos;
   sout<< "]";
   return sout.str();
}

string reproduccionToDebug(string mssg,Reproduccion x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idUsuario;
   sout << ",";
   sout << x.idAlbum;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.minutos;
   sout<< "]";
   return sout.str();
}

Reproduccion reproduccion(int idUsuario,int idAlbum,int fecha,int minutos)
{
   Reproduccion a;
   a.idUsuario = idUsuario;
   a.idAlbum = idAlbum;
   a.fecha = fecha;
   a.minutos = minutos;
   return a;
}

bool reproduccionEquals(Reproduccion a,Reproduccion b)
{
   if(a.idUsuario!=b.idUsuario) return false;
   if(a.idAlbum!=b.idAlbum) return false;
   if(a.fecha!=b.fecha) return false;
   if(a.minutos!=b.minutos) return false;
   return true;
}

string albumToString(Album x)
{
   char sep = 2;
   string sIdAlbum=to_string(x.idAlbum);
   string sIdArtista=to_string(x.idArtista);
   string sTitulo=x.titulo;
   string sDuracion=to_string(x.duracion);
   return sIdAlbum+sep+sIdArtista+sep+sTitulo+sep+sDuracion;
}

Album albumFromString(string s)
{
   char sep = 2;
   Album x;
   string t0 = getTokenAt(s,sep,0);
   x.idAlbum=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idArtista=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   strcpy(x.titulo,t2.c_str());
   string t3 = getTokenAt(s,sep,3);
   x.duracion=stoi(t3);
   return x;
}

string albumToDebug(Album x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idAlbum;
   sout << ",";
   sout << x.idArtista;
   sout << ",";
   sout << x.titulo;
   sout << ",";
   sout << x.duracion;
   sout<< "]";
   return sout.str();
}

string albumToDebug(string mssg,Album x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idAlbum;
   sout << ",";
   sout << x.idArtista;
   sout << ",";
   sout << x.titulo;
   sout << ",";
   sout << x.duracion;
   sout<< "]";
   return sout.str();
}

Album album(int idAlbum,int idArtista,string titulo,int duracion)
{
   Album a;
   a.idAlbum = idAlbum;
   a.idArtista = idArtista;
   strcpy(a.titulo,titulo.c_str());
   a.duracion = duracion;
   return a;
}

bool albumEquals(Album a,Album b)
{
   if(a.idAlbum!=b.idAlbum) return false;
   if(a.idArtista!=b.idArtista) return false;
   if(a.duracion!=b.duracion) return false;
   return true;
}

string artistaToString(Artista x)
{
   char sep = 3;
   string sIdArtista=to_string(x.idArtista);
   string sNombre=x.nombre;
   return sIdArtista+sep+sNombre;
}

Artista artistaFromString(string s)
{
   char sep = 3;
   Artista x;
   string t0 = getTokenAt(s,sep,0);
   x.idArtista=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.nombre,t1.c_str());
   return x;
}

string artistaToDebug(Artista x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idArtista;
   sout << ",";
   sout << x.nombre;
   sout<< "]";
   return sout.str();
}

string artistaToDebug(string mssg,Artista x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idArtista;
   sout << ",";
   sout << x.nombre;
   sout<< "]";
   return sout.str();
}

Artista artista(int idArtista,string nombre)
{
   Artista a;
   a.idArtista = idArtista;
   strcpy(a.nombre,nombre.c_str());
   return a;
}

bool artistaEquals(Artista a,Artista b)
{
   if(a.idArtista!=b.idArtista) return false;
   return true;
}

string idxAlbumToString(IdxAlbum x)
{
   char sep = 4;
   string sIdAlbum=to_string(x.idAlbum);
   string sPos=to_string(x.pos);
   string sC100=to_string(x.c100);
   string sC75=to_string(x.c75);
   string sC50=to_string(x.c50);
   string sC25=to_string(x.c25);
   string sC0=to_string(x.c0);
   return sIdAlbum+sep+sPos+sep+sC100+sep+sC75+sep+sC50+sep+sC25+sep+sC0;
}

IdxAlbum idxAlbumFromString(string s)
{
   char sep = 4;
   IdxAlbum x;
   string t0 = getTokenAt(s,sep,0);
   x.idAlbum=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.pos=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.c100=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.c75=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.c50=stoi(t4);
   string t5 = getTokenAt(s,sep,5);
   x.c25=stoi(t5);
   string t6 = getTokenAt(s,sep,6);
   x.c0=stoi(t6);
   return x;
}

string idxAlbumToDebug(IdxAlbum x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idAlbum;
   sout << ",";
   sout << x.pos;
   sout << ",";
   sout << x.c100;
   sout << ",";
   sout << x.c75;
   sout << ",";
   sout << x.c50;
   sout << ",";
   sout << x.c25;
   sout << ",";
   sout << x.c0;
   sout<< "]";
   return sout.str();
}

string idxAlbumToDebug(string mssg,IdxAlbum x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idAlbum;
   sout << ",";
   sout << x.pos;
   sout << ",";
   sout << x.c100;
   sout << ",";
   sout << x.c75;
   sout << ",";
   sout << x.c50;
   sout << ",";
   sout << x.c25;
   sout << ",";
   sout << x.c0;
   sout<< "]";
   return sout.str();
}

IdxAlbum idxAlbum(int idAlbum,int pos,int c100,int c75,int c50,int c25,int c0)
{
   IdxAlbum a;
   a.idAlbum = idAlbum;
   a.pos = pos;
   a.c100 = c100;
   a.c75 = c75;
   a.c50 = c50;
   a.c25 = c25;
   a.c0 = c0;
   return a;
}

bool idxAlbumEquals(IdxAlbum a,IdxAlbum b)
{
   if(a.idAlbum!=b.idAlbum) return false;
   if(a.pos!=b.pos) return false;
   if(a.c100!=b.c100) return false;
   if(a.c75!=b.c75) return false;
   if(a.c50!=b.c50) return false;
   if(a.c25!=b.c25) return false;
   if(a.c0!=b.c0) return false;
   return true;
}

string idxArtistaToString(IdxArtista x)
{
   char sep = 5;
   string sIdArtista=to_string(x.idArtista);
   string sPos=to_string(x.pos);
   string sCont=to_string(x.cont);
   return sIdArtista+sep+sPos+sep+sCont;
}

IdxArtista idxArtistaFromString(string s)
{
   char sep = 5;
   IdxArtista x;
   string t0 = getTokenAt(s,sep,0);
   x.idArtista=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.pos=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.cont=stoi(t2);
   return x;
}

string idxArtistaToDebug(IdxArtista x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idArtista;
   sout << ",";
   sout << x.pos;
   sout << ",";
   sout << x.cont;
   sout<< "]";
   return sout.str();
}

string idxArtistaToDebug(string mssg,IdxArtista x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idArtista;
   sout << ",";
   sout << x.pos;
   sout << ",";
   sout << x.cont;
   sout<< "]";
   return sout.str();
}

IdxArtista idxArtista(int idArtista,int pos,int cont)
{
   IdxArtista a;
   a.idArtista = idArtista;
   a.pos = pos;
   a.cont = cont;
   return a;
}

bool idxArtistaEquals(IdxArtista a,IdxArtista b)
{
   if(a.idArtista!=b.idArtista) return false;
   if(a.pos!=b.pos) return false;
   if(a.cont!=b.cont) return false;
   return true;
}

#endif