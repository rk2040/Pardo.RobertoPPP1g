#ifndef PSERVICIO_H_INCLUDED
#define PSERVICIO_H_INCLUDED

#include "pTrabajo.h"
#include "pServicio.h"
#include "pAuto.h"
#include "pMarca.h"
#include "pColor.h"
#include "fecha.h"
#include "utn.h"
#include "pardo.h"

typedef struct
{
    int id; // Comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;


int cargarDescripcionServicios(eServicio servicios[], int tamServicio, int idServicio, char descripcion[]);

int cargarPrecioServicio(eServicio servicios[], int tamServicio, int idServicio, float* pPrecioServicio);

int mostrarServicios(eServicio servicios[], int tamServicio);

int validarServicio(eServicio servicios[], int tamServicio, int id);

int buscarServicioId(eServicio servicios[], int tamServicio, int id, int* pIndex);

//int autosPorServicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

#endif // PSERVICIO_H_INCLUDED

