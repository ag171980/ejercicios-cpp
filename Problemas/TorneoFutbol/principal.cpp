#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/funciones/files.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
#include "principal.hpp"
// #include "Resultados.hpp"
using namespace std;

int cmpREquipoId(REquipo r, int id)
{
    return r.e.idEq - id;
}

Coll<REquipo> subirEquipos()
{
    FILE *f = fopen("EQUIPOS.dat", "r+b");
    Coll<REquipo> c = coll<REquipo>();
    Equipo e = read<Equipo>(f);
    while (!feof(f))
    {
        REquipo re;
        re.e = e;
        re.acum = 0;
        collAdd<REquipo>(c, re, rEquipoToString);
        e = read<Equipo>(f);
    }
    fclose(f);
    return c;
}
void procesarResultado(int idEq, int ptos, Coll<REquipo> &c)
{
    int pos = collFind<REquipo, int>(c, idEq, cmpREquipoId, rEquipoFromString);

    REquipo re = collGetAt<REquipo>(c, pos, rEquipoFromString);
    re.acum += ptos;
    collSetAt<REquipo>(c, re, pos, rEquipoToString);
    return;
}
int cmpREquipo(REquipo a, REquipo b)
{
    int pa = a.acum + a.e.puntos;
    int pb = b.acum + b.e.puntos;
    return (pb - pa);
}
void mostrarResultados(Coll<REquipo> cEq)
{
    // ordeno de mayor a menor segun el puntaje (ptos + acum)
    collSort<REquipo>(cEq, cmpREquipo, rEquipoFromString, rEquipoToString);
    collReset<REquipo>(cEq);
    while (collHasNext<REquipo>(cEq))
    {
        REquipo x = collNext<REquipo>(cEq, rEquipoFromString);
        int ptosActualizados = x.e.puntos + x.acum;
        cout << x.e.nombre << ", " << ptosActualizados << endl;
    }
}
int main()
{
    // Subo los equipos a memoria
    Coll<REquipo> cEq = subirEquipos();

    FILE *f = fopen("RESULTADOS.dat", "r+b");
    Resultado r = read<Resultado>(f);
    while (!feof(f))
    {
        // proceso
        r = read<Resultado>(f);
    }

    mostrarResultados(cEq);
    fclose(f);

    return 0;
}