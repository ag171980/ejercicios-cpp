#include <iostream>
#include "../../API/biblioteca/funciones/strings.hpp"
#include "../../API/biblioteca/funciones/tokens.hpp"
#include "../../API/biblioteca/funciones/files.hpp"
#include "../../API/biblioteca/tads/Coll.hpp"
#include "streaming.hpp"
using namespace std;

// no indexacion ni busqueda binaria
// para ordenamiento con el collSort funca

Coll<IdxArtista> indexarArtistas(FILE *fAr)
{
    return {};
}
Coll<IdxAlbum> indexarAlbumes(FILE *fAl)
{
    return {};
}
int cmpIdxAlbumId(IdxAlbum a, int id)
{
    return a.idAlbum - id;
}
int cmpAlbumId(Album a, int id)
{
    return a.idAlbum - id;
}
Album buscarIdxAlbum(FILE *fAl, Coll<IdxAlbum> &idxAl, int id)
{
    Album a;
    int posIdx = collFind<IdxAlbum, int>(idxAl, id, cmpIdxAlbumId, idxAlbumFromString);
    IdxAlbum idxAlbum = collGetAt<IdxAlbum>(idxAl, posIdx, idxAlbumFromString);

    return a;
}

Artista buscarIdxArtista(FILE *fAr, Coll<IdxArtista> &idxAr, int id)
{
}

void procesar(Reproduccion r, Coll<IdxAlbum> &idxAl, FILE *fAl, Coll<IdxArtista> &idxAr, FILE *fAr)
{
    // punto1
    // 1. Determinar porcentaje de la reproduccion
    // 2. Buscar en el idxAl e incrementar el contador que corresponde

    Album a = buscarIdxAlbum(fAl, idxAl, r.idAlbum);
    Artista art = buscarIdxArtista(fAr, idxAr, r.idAlbum);
    
    int pos = collFind<IdxAlbum, int>(idxAl, r.idAlbum, cmpIdxAlbumId, idxAlbumFromString);
    IdxAlbum idxAlbum = collGetAt<IdxAlbum>(idxAl, pos, idxAlbumFromString);
    double pct = (double)(r.minutos * 100) / a.duracion;
    if (pct == 0)
    {
        idxAlbum.c0++;
    }
    if (pct < 100 && pct > 75)
    {
        idxAlbum.c100++;
    }
    if (pct < 75 && pct > 50)
    {
        idxAlbum.c75++;
    }
    if (pct < 50 && pct > 25)
    {
        idxAlbum.c50++;
    }
    if (pct < 25)
    {
        idxAlbum.c25++;
    }

    int pos = collFind<IdxAlbum, int>(idxAl, r.idAlbum, cmpIdxAlbumId, idxAlbumFromString);
    IdxAlbum s = collGetAt<IdxAlbum>(idxAl, pos, idxAlbumFromString);

    // punto2
    // 1. Si la reproduccion > 75%
    // 2. Buscar el artista en idxAr e incrementar el contador
}
void mostrarPto1(Coll<IdxAlbum> idxAl, FILE *fAl)
{
}
void mostrarPto2(Coll<IdxArtista> idxAr, FILE *fAr)
{
}
int main()
{
    FILE *fAr = fopen("ARTISTAS.dat", "r+b");
    FILE *fAl = fopen("ALBUMES.dat", "r+b");

    // indexo archivos de consulta
    Coll<IdxArtista> idxAr = indexarArtistas(fAr);
    Coll<IdxAlbum> idxAl = indexarAlbumes(fAl);

    // recorro novedades;=
    FILE *f = fopen("REPRODUCCIONES.dat", "r+b");

    Reproduccion r = read<Reproduccion>(f);
    while (!feof(f))
    {

        procesar(r, idxAl, fAl, idxAr, fAr);

        r = read<Reproduccion>(f);
    }

    // punto1
    mostrarPto1(idxAl, fAl);

    // punto2
    mostrarPto2(idxAr, fAr);

    fclose(f);
    fclose(fAl);
    fclose(fAr);
    return 0;
}