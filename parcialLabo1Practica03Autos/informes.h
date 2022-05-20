#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <stdio.h>

#include "pAuto.h"
#include "pMarca.h"
#include "pColor.h"
#include "pTrabajo.h"
#include "pServicio.h"

#include "utn.h"
#include "pardo.h"

#endif // INFORMES_H_INCLUDED

int menuInformes();

int informes(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);


