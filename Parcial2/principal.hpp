#include <iostream>

struct Categoria
{
    char idCat[3];
    char escrip[50];
    int m3Desde;
    int m3Hasta;
    double valorM3;
};
struct RCategoria
{
    Categoria c;
    List<int> lst;
};
struct Cliente
{
    int idCli;
    char nombre[100];
    char direccion[200];
    char idCatAnt[3];
    int lecturaAnterior;
    unsigned char consumos[36];
};

struct Medicion
{
    int idCli;
    int lecturaActual;
    Fecha fecha;
};

struct Consumo
{
    int mmaaaa;
    int m3Consumidos;
};