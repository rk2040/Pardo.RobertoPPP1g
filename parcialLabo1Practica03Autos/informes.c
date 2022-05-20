#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "informes.h"
#include "pAuto.h"
#include "pMarca.h"
#include "pColor.h"
#include "pTrabajo.h"
#include "pServicio.h"

#include "utn.h"
#include "pardo.h"


//===================================================================================================================
//                      Informes complementarios
//===================================================================================================================
int menuInformes()
{
    int opcion;

    printf("-------------------------------------\n");
    printf("  *** Informes Complementarios ***   \n");
    printf("-------------------------------------\n");
    printf(" 1- Mostrar Autos por Marca \n");
    printf(" 2- Mostrar Autos por Color \n");
    printf(" 3- Informar Promedio de Autos Negros sobre el total de Autos de una Empresa \n");
    printf(" 4- Mostrar un listado de Autos separados por Marca \n");
    printf(" 5- Informar la o las Marcas con mas autos con caja Manual \n");
    printf(" 6- Mostrar la Marca con menos Autos \n");
// Bonus Track  -   Harcodear algunos Trabajos
    printf(" 7- Pedir un Auto y mostrar todos los Trabajos que se le realizaron \n");
    printf(" 8- Pedir un Auto e informar la suma de los precios (costo) de todos los Trabajos que se le realizaron \n");
    printf(" 9- Pedir un Servicio y mostrar los autos que recibieron ese servicio y en que fecha \n");
    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma \n");
    printf(" 0- Volver al menu anterior. \n");
    printf("Ingrese una opcion: \n");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int informes(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
    int exito = 0;
    char salir = 'n';

        do{
            system("cls");

            switch(menuInformes())
            {
            case 1:
                mostrarAutosPorMarcaSeleccionada(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 2:
                mostrarAutosPorColorSeleccionado(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 3:
                promedioAutosNegrosPorMarca(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 4:
                listadoAutosPorMarca(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 5:
                marcasConMasAutosCajaM(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 6:
                marcasConMenosAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
// Bonus Track  -   Harcodear algunos Trabajos
            case 7:
                trabajosPorAuto(trabajos, tamTrabajo, servicios, tamServicio, autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 8:
                precioPorTrabajosPorAuto(trabajos, tamTrabajo, servicios, tamServicio, autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 9:
                autosPorServicios(trabajos, tamTrabajo, servicios, tamServicio, autos, tamAuto, marcas, tamMarca, colores, tamColor);
                break;
            case 10:
                printf("3.\n");
                break;
            case 0:
                salir = opcionConfirmar("Seguro que quiere volver al menu anterior? s/n ", "Error, vuelva a intentarlo. Volver al menu anterior? s/n ");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
        system("pause");

    }while(salir != 's');

    return exito;
}
