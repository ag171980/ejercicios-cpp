#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Predio
{
   int idPredio;
   char nombre[15];
   char direccion[25];
   int cantCanchas;
   int idBarrio;
};

struct Cancha
{
   int idPredio;
   int canchaNro;
   double precio;
   int flgCubierta;
   char obervaciones[100];
};

struct Reserva
{
   int idReserva;
   int idCliente;
   int idPredio;
   int diaMes;
   char turno;
   char celContacto[20];
};

struct Rechazo
{
   Reserva reserva;
   int motivoRechazo;
};

struct Capacidad
{
   int idPredio;
   int dia;
   int cancha;
   int ctm;
   int ctt;
   int ctn;
};

struct Barrio
{
   int idBarrio;
   int catm;
   int crtm;
   int catt;
   int crtt;
   int catn;
   int crtn;
};

string predioToString(Predio x)
{
   char sep = 1;
   string sIdPredio=to_string(x.idPredio);
   string sNombre=x.nombre;
   string sDireccion=x.direccion;
   string sCantCanchas=to_string(x.cantCanchas);
   string sIdBarrio=to_string(x.idBarrio);
   return sIdPredio+sep+sNombre+sep+sDireccion+sep+sCantCanchas+sep+sIdBarrio;
}

Predio predioFromString(string s)
{
   char sep = 1;
   Predio x;
   string t0 = getTokenAt(s,sep,0);
   x.idPredio=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.nombre,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   strcpy(x.direccion,t2.c_str());
   string t3 = getTokenAt(s,sep,3);
   x.cantCanchas=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.idBarrio=stoi(t4);
   return x;
}

string predioToDebug(Predio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idPredio;
   sout << ",";
   sout << x.nombre;
   sout << ",";
   sout << x.direccion;
   sout << ",";
   sout << x.cantCanchas;
   sout << ",";
   sout << x.idBarrio;
   sout<< "]";
   return sout.str();
}

string predioToDebug(string mssg,Predio x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idPredio;
   sout << ",";
   sout << x.nombre;
   sout << ",";
   sout << x.direccion;
   sout << ",";
   sout << x.cantCanchas;
   sout << ",";
   sout << x.idBarrio;
   sout<< "]";
   return sout.str();
}

Predio predio(int idPredio,string nombre,string direccion,int cantCanchas,int idBarrio)
{
   Predio a;
   a.idPredio = idPredio;
   strcpy(a.nombre,nombre.c_str());
   strcpy(a.direccion,direccion.c_str());
   a.cantCanchas = cantCanchas;
   a.idBarrio = idBarrio;
   return a;
}

bool predioEquals(Predio a,Predio b)
{
   if(a.idPredio!=b.idPredio) return false;
   if(a.cantCanchas!=b.cantCanchas) return false;
   if(a.idBarrio!=b.idBarrio) return false;
   return true;
}

string canchaToString(Cancha x)
{
   char sep = 2;
   string sIdPredio=to_string(x.idPredio);
   string sCanchaNro=to_string(x.canchaNro);
   string sPrecio=to_string(x.precio);
   string sFlgCubierta=to_string(x.flgCubierta);
   string sObervaciones=x.obervaciones;
   return sIdPredio+sep+sCanchaNro+sep+sPrecio+sep+sFlgCubierta+sep+sObervaciones;
}

Cancha canchaFromString(string s)
{
   char sep = 2;
   Cancha x;
   string t0 = getTokenAt(s,sep,0);
   x.idPredio=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.canchaNro=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.precio=stod(t2);
   string t3 = getTokenAt(s,sep,3);
   x.flgCubierta=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   strcpy(x.obervaciones,t4.c_str());
   return x;
}

string canchaToDebug(Cancha x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idPredio;
   sout << ",";
   sout << x.canchaNro;
   sout << ",";
   sout << x.precio;
   sout << ",";
   sout << x.flgCubierta;
   sout << ",";
   sout << x.obervaciones;
   sout<< "]";
   return sout.str();
}

string canchaToDebug(string mssg,Cancha x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idPredio;
   sout << ",";
   sout << x.canchaNro;
   sout << ",";
   sout << x.precio;
   sout << ",";
   sout << x.flgCubierta;
   sout << ",";
   sout << x.obervaciones;
   sout<< "]";
   return sout.str();
}

Cancha cancha(int idPredio,int canchaNro,double precio,int flgCubierta,string obervaciones)
{
   Cancha a;
   a.idPredio = idPredio;
   a.canchaNro = canchaNro;
   a.precio = precio;
   a.flgCubierta = flgCubierta;
   strcpy(a.obervaciones,obervaciones.c_str());
   return a;
}

bool canchaEquals(Cancha a,Cancha b)
{
   if(a.idPredio!=b.idPredio) return false;
   if(a.canchaNro!=b.canchaNro) return false;
   if(a.precio!=b.precio) return false;
   if(a.flgCubierta!=b.flgCubierta) return false;
   return true;
}

string reservaToString(Reserva x)
{
   char sep = 3;
   string sIdReserva=to_string(x.idReserva);
   string sIdCliente=to_string(x.idCliente);
   string sIdPredio=to_string(x.idPredio);
   string sDiaMes=to_string(x.diaMes);
   string sTurno=string(1,x.turno);
   string sCelContacto=x.celContacto;
   return sIdReserva+sep+sIdCliente+sep+sIdPredio+sep+sDiaMes+sep+sTurno+sep+sCelContacto;
}

Reserva reservaFromString(string s)
{
   char sep = 3;
   Reserva x;
   string t0 = getTokenAt(s,sep,0);
   x.idReserva=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idCliente=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.idPredio=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.diaMes=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.turno=(char)t4[0];
   string t5 = getTokenAt(s,sep,5);
   strcpy(x.celContacto,t5.c_str());
   return x;
}

string reservaToDebug(Reserva x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idReserva;
   sout << ",";
   sout << x.idCliente;
   sout << ",";
   sout << x.idPredio;
   sout << ",";
   sout << x.diaMes;
   sout << ",";
   sout << x.turno;
   sout << ",";
   sout << x.celContacto;
   sout<< "]";
   return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idReserva;
   sout << ",";
   sout << x.idCliente;
   sout << ",";
   sout << x.idPredio;
   sout << ",";
   sout << x.diaMes;
   sout << ",";
   sout << x.turno;
   sout << ",";
   sout << x.celContacto;
   sout<< "]";
   return sout.str();
}

Reserva reserva(int idReserva,int idCliente,int idPredio,int diaMes,char turno,string celContacto)
{
   Reserva a;
   a.idReserva = idReserva;
   a.idCliente = idCliente;
   a.idPredio = idPredio;
   a.diaMes = diaMes;
   a.turno = turno;
   strcpy(a.celContacto,celContacto.c_str());
   return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
   if(a.idReserva!=b.idReserva) return false;
   if(a.idCliente!=b.idCliente) return false;
   if(a.idPredio!=b.idPredio) return false;
   if(a.diaMes!=b.diaMes) return false;
   if(a.turno!=b.turno) return false;
   return true;
}

string rechazoToString(Rechazo x)
{
   char sep = 4;
   string sReserva=reservaToString(x.reserva);
   string sMotivoRechazo=to_string(x.motivoRechazo);
   return sReserva+sep+sMotivoRechazo;
}

Rechazo rechazoFromString(string s)
{
   char sep = 4;
   Rechazo x;
   string t0 = getTokenAt(s,sep,0);
   x.reserva=reservaFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.motivoRechazo=stoi(t1);
   return x;
}

string rechazoToDebug(Rechazo x)
{
   stringstream sout;
   sout<< "[";
   sout << reservaToDebug(x.reserva);
   sout << ",";
   sout << x.motivoRechazo;
   sout<< "]";
   return sout.str();
}

string rechazoToDebug(string mssg,Rechazo x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << reservaToDebug(x.reserva);
   sout << ",";
   sout << x.motivoRechazo;
   sout<< "]";
   return sout.str();
}

Rechazo rechazo(Reserva reserva,int motivoRechazo)
{
   Rechazo a;
   a.reserva = reserva;
   a.motivoRechazo = motivoRechazo;
   return a;
}

bool rechazoEquals(Rechazo a,Rechazo b)
{
   if(!reservaEquals(a.reserva,b.reserva)) return false;
   if(a.motivoRechazo!=b.motivoRechazo) return false;
   return true;
}

string capacidadToString(Capacidad x)
{
   char sep = 5;
   string sIdPredio=to_string(x.idPredio);
   string sDia=to_string(x.dia);
   string sCancha=to_string(x.cancha);
   string sCtm=to_string(x.ctm);
   string sCtt=to_string(x.ctt);
   string sCtn=to_string(x.ctn);
   return sIdPredio+sep+sDia+sep+sCancha+sep+sCtm+sep+sCtt+sep+sCtn;
}

Capacidad capacidadFromString(string s)
{
   char sep = 5;
   Capacidad x;
   string t0 = getTokenAt(s,sep,0);
   x.idPredio=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.dia=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.cancha=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.ctm=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.ctt=stoi(t4);
   string t5 = getTokenAt(s,sep,5);
   x.ctn=stoi(t5);
   return x;
}

string capacidadToDebug(Capacidad x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idPredio;
   sout << ",";
   sout << x.dia;
   sout << ",";
   sout << x.cancha;
   sout << ",";
   sout << x.ctm;
   sout << ",";
   sout << x.ctt;
   sout << ",";
   sout << x.ctn;
   sout<< "]";
   return sout.str();
}

string capacidadToDebug(string mssg,Capacidad x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idPredio;
   sout << ",";
   sout << x.dia;
   sout << ",";
   sout << x.cancha;
   sout << ",";
   sout << x.ctm;
   sout << ",";
   sout << x.ctt;
   sout << ",";
   sout << x.ctn;
   sout<< "]";
   return sout.str();
}

Capacidad capacidad(int idPredio,int dia,int cancha,int ctm,int ctt,int ctn)
{
   Capacidad a;
   a.idPredio = idPredio;
   a.dia = dia;
   a.cancha = cancha;
   a.ctm = ctm;
   a.ctt = ctt;
   a.ctn = ctn;
   return a;
}

bool capacidadEquals(Capacidad a,Capacidad b)
{
   if(a.idPredio!=b.idPredio) return false;
   if(a.dia!=b.dia) return false;
   if(a.cancha!=b.cancha) return false;
   if(a.ctm!=b.ctm) return false;
   if(a.ctt!=b.ctt) return false;
   if(a.ctn!=b.ctn) return false;
   return true;
}

string barrioToString(Barrio x)
{
   char sep = 6;
   string sIdBarrio=to_string(x.idBarrio);
   string sCatm=to_string(x.catm);
   string sCrtm=to_string(x.crtm);
   string sCatt=to_string(x.catt);
   string sCrtt=to_string(x.crtt);
   string sCatn=to_string(x.catn);
   string sCrtn=to_string(x.crtn);
   return sIdBarrio+sep+sCatm+sep+sCrtm+sep+sCatt+sep+sCrtt+sep+sCatn+sep+sCrtn;
}

Barrio barrioFromString(string s)
{
   char sep = 6;
   Barrio x;
   string t0 = getTokenAt(s,sep,0);
   x.idBarrio=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.catm=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.crtm=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.catt=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.crtt=stoi(t4);
   string t5 = getTokenAt(s,sep,5);
   x.catn=stoi(t5);
   string t6 = getTokenAt(s,sep,6);
   x.crtn=stoi(t6);
   return x;
}

string barrioToDebug(Barrio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idBarrio;
   sout << ",";
   sout << x.catm;
   sout << ",";
   sout << x.crtm;
   sout << ",";
   sout << x.catt;
   sout << ",";
   sout << x.crtt;
   sout << ",";
   sout << x.catn;
   sout << ",";
   sout << x.crtn;
   sout<< "]";
   return sout.str();
}

string barrioToDebug(string mssg,Barrio x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idBarrio;
   sout << ",";
   sout << x.catm;
   sout << ",";
   sout << x.crtm;
   sout << ",";
   sout << x.catt;
   sout << ",";
   sout << x.crtt;
   sout << ",";
   sout << x.catn;
   sout << ",";
   sout << x.crtn;
   sout<< "]";
   return sout.str();
}

Barrio barrio(int idBarrio,int catm,int crtm,int catt,int crtt,int catn,int crtn)
{
   Barrio a;
   a.idBarrio = idBarrio;
   a.catm = catm;
   a.crtm = crtm;
   a.catt = catt;
   a.crtt = crtt;
   a.catn = catn;
   a.crtn = crtn;
   return a;
}

bool barrioEquals(Barrio a,Barrio b)
{
   if(a.idBarrio!=b.idBarrio) return false;
   if(a.catm!=b.catm) return false;
   if(a.crtm!=b.crtm) return false;
   if(a.catt!=b.catt) return false;
   if(a.crtt!=b.crtt) return false;
   if(a.catn!=b.catn) return false;
   if(a.crtn!=b.crtn) return false;
   return true;
}

#endif
