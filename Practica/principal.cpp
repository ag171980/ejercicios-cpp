#include <iostream>
#include "principal.hpp"
#include "../API/biblioteca/funciones/strings.hpp"
#include "../API/biblioteca/funciones/tokens.hpp"
#include "../API/biblioteca/funciones/files.hpp"
#include "../API/biblioteca/tads/Coll.hpp"
using namespace std;

Coll<Nota> subirNota()
{
    Coll<Nota> n = coll<Nota>();
    collAdd<Nota>(n, nota(4, 1), notaToString);
    collAdd<Nota>(n, nota(1, 7), notaToString);
    collAdd<Nota>(n, nota(2, 9), notaToString);
    collAdd<Nota>(n, nota(5, 5), notaToString);
    collAdd<Nota>(n, nota(3, 2), notaToString);
    return n;
}

Coll<Alumno> subirAlumnos()
{
    // EJEMPLO DE PDF
    // abrimos archivo
    // FILE *f = fopen("ALUMNOS.dat", "r+b");

    // creamos coll vacia
    // Coll<Alumno> al = coll<Alumno>();

    // leemos el archivo
    //  Alumno a = read<Alumno>(f);
    //  while(!feof(f)){
    // agregamos el registro a la coleccion
    //     collAdd<Alumno>(al,a, alumnoToString);
    //     a = read<Alumno>(f);
    // }
    // fclose(f);
    // return al;

    // creamos coll vacia

    Coll<Alumno> al = coll<Alumno>();
    collAdd<Alumno>(al, alumno(4, "Carlos"), alumnoToString);
    collAdd<Alumno>(al, alumno(2, "Martin"), alumnoToString);
    collAdd<Alumno>(al, alumno(5, "Francisco"), alumnoToString);
    collAdd<Alumno>(al, alumno(1, "Juan"), alumnoToString);
    collAdd<Alumno>(al, alumno(3, "Leonel"), alumnoToString);
    return al;
}
int cmpAlumnoId(Alumno a, Alumno b)
{
    int alegajo = a.legajo;
    int blegajo = b.legajo;
    return alegajo < blegajo ? -1 : alegajo > blegajo ? 1
                                                      : 0;
}
int cmpNotaId(Nota a, Nota b)
{
    int alegajo = a.legajo;
    int blegajo = b.legajo;
    return alegajo < blegajo ? -1 : alegajo > blegajo ? 1
                                                      : 0;
}
Coll<Alumno> recorrer(Coll<Alumno> als, Coll<Nota> nots)
{
    collSort<Alumno>(als, cmpAlumnoId, alumnoFromString, alumnoToString);
    collSort<Nota>(nots, cmpNotaId, notaFromString, notaToString);
    cout << "Legajo | Nombre | Nota" << endl;
    while (collHasNext<Alumno>(als) && collHasNext<Nota>(nots))
    {
        Alumno a = collNext<Alumno>(als, alumnoFromString);
        Nota n = collNext<Nota>(nots, notaFromString);
        cout << a.legajo << "      | " << a.nombre << "     | " << n.nota << endl;
    }
}


int main()
{
    Coll<Alumno> als = subirAlumnos();
    Coll<Nota> nots = subirNota();
    recorrer(als, nots);
    // subirAlumnos();
    return 0;
}