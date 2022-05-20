#ifndef PTRABAJO_H_INCLUDED
#define PTRABAJO_H_INCLUDED

#include <stdio.h>

#include "pServicio.h"
#include "fecha.h"
#include "pAuto.h"

typedef struct
{
    int id;        // Autoincremental
    int idAuto;    //validar
    int idServicio;//validar
    eFecha fecha;  //validar dia, mes, año
    int isEmpty;
}eTrabajo;



int inicializarTrabajos(eTrabajo trabajos[], int tamTrabajo);

int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrabajo);

int altaTrabajo(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eServicio servicios[], int tamServicio, int* pNextId);


void mostrarTrabajoFila(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eServicio servicios[], int tamServicio);

int mostrarTrabajos(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eServicio servicios[], int tamServicio);

int harcodearTrabajos(eTrabajo trabajos[], int tamTrabajo, int cant, int* pId);

int trabajosPorAuto(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int precioPorTrabajosPorAuto(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

#endif // PTRABAJO_H_INCLUDED

