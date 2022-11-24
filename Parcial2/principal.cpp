#include <iostream>
#include "../API/biblioteca/tads/Map.hpp"
#include "../API/biblioteca/funciones/files.hpp"
#include "../API/biblioteca/tads/List.hpp"
#include "principal.hpp"
using namespace std;

Array<Consumo> decodeConsumo(unsigned char acumulado[])
{
    return {};
}
unsigned char *encodeConsumo(Array<Consumo> arr)
{
    return NULL;
}
int calcularConsumoAnual(Array<Consumo> arr, int actual)
{
    return 0;
}

Map<string, RCategoria> subirCategorias()
{
    return {};
}
int buscarCliente(FILE *fCli, int idCli)
{
    return 0;
}
string buscarCategoria(int consAnual, Map<string, RCategoria> &mCat)
{
    return "";
}
int fechaGetMMAAAA()
{
    return 0;
}
void procesarMedicion(Medicion m, FILE *fCli, Map<string, RCategoria> &mCat)
{
    // busco al cliente
    int pos = buscarCliente(fCli, m.idCli);
    seek<Cliente>(fCli, pos);
    Cliente cli = read<Cliente>(fCli);

    Array<Consumo> aCons = decodeConsumo(cli.consumos);
    int consActual = m.lecturaActual - cli.lecturaAnterior;
    int consAcum = calcularConsumoAnual(aCons, consActual);

    string cat = buscarCategoria(consActual, mCat);
    string CatAnt = cli.idCatAnt;
    if (cat != CatAnt)
    {
        RCategoria *rc = mapGet<string, RCategoria>(mCat, cat);
        listAdd<int>(rc->lst, pos);
    }

    // actualizo archivo

    cli.lecturaAnterior = m.lecturaActual;
    strcpy(cli.idCatAnt, cat.c_str());
    arrayRemove<Consumo>(aCons, 0);
    arrayAdd<Consumo>(aCons, consumo(fechaGetMMAAAA(), consActual));
    strcpy(cli.consumos, encodeConsumo(aCons));

    seek<Cliente>(fCli, pos);
    write<Cliente>(fCli, cli);
}
void mostrarClientesRecategorizados(Map<string, RCategoria> &mCat, FILE *fCli)
{
    mapReset<string, RCategoria>(mCat);

    while (mapHasNext<string, RCategoria>(mCat))
    {
        RCategoria *rc = mapNextValue<string, RCategoria>(mCat);
        cout << rc->c.escrip << endl;

        listReset<int>(rc->lst);
        while (!listHasNext<int>(rc->lst))
        {
            int *pos = listNext<int>(rc->lst);
            seek<Cliente>(fCli, *pos);
            Cliente cli = read<Cliente>(fCli);

            cout << cli.idCli << endl;
        }
    }
}

int main()
{
    Map<string, RCategoria> mCat = subirCategorias();

    FILE *fCli = fopen("CLIENTES.dat", "r+b");
    FILE *fMed = fopen("MEDICIONES.dat", "r+b");

    Medicion m = read<Medicion>(fMed);
    while (!feof(fMed))
    {

        procesarMedicion(m, fCli, mCat);
        m = read<Medicion>(fMed);
    }
    mostrarClientesRecategorizados(mCat, fCli);

    fclose(fCli);
    fclose(fMed);

    return 0;
}