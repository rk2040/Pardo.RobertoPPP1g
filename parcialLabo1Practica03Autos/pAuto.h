#ifndef PAUTO_H_INCLUDED
#define PAUTO_H_INCLUDED

#include "pMarca.h"
#include "pColor.h"

typedef struct
{
    int id;
    int idMarca;    //validar
    int idColor;
    char caja;
    int isEmpty;
}eAuto;

#endif // PAUTO_H_INCLUDED


char menu();

int inicializarAutos(eAuto autos[], int tam);

int buscarLibre(eAuto autos[], int tam);

int altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int* pNextId);

int cargarDescripcionAuto(eAuto autos[], int tamAuto, int idAuto, char descripcion[], eMarca marcas[], int tamMarca);

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

void mostrarAutoFila(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int buscarAutoId(eAuto autos[], int tamAuto, int id, int* pIndex);

int menuModificar();

int validarAuto(eAuto autos[], int tamAuto, int id);

int modificarAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int ordenarPorMarcaYCaja(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);


int harcodearAutos(eAuto autos[], int tamAuto, int cant, int* pId);


//=====================================================================
int mostrarAutosPorMarcaSeleccionada(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int mostrarAutosPorColorSeleccionado(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int promedioAutosNegrosPorMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int listadoAutosPorMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int marcasConMasAutosCajaM(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int marcasConMenosAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

