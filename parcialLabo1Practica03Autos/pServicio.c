#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "pTrabajo.h"
#include "pServicio.h"
#include "pAuto.h"
#include "pMarca.h"
#include "pColor.h"
#include "fecha.h"
#include "utn.h"
#include "pardo.h"

int cargarDescripcionServicios(eServicio servicios[], int tamServicio, int idServicio, char descripcion[])
{
    int exito = 0;  // 0 si hubo algun problema. 1 si cargo todo bien. -1 si cargo todo bien pero no encontro coincidencia de ID
    int flag = 1;

    if(servicios != NULL && tamServicio > 0 && descripcion != NULL)
    {
        exito = 1;
        for(int i=0; i<tamServicio; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
                flag = 0;
            }
        }

        if(flag)
        {
            exito = -1;
        }
    }
    return exito;
}


int cargarPrecioServicio(eServicio servicios[], int tamServicio, int idServicio, float* pPrecioServicio)
{
    int exito = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(servicios != NULL && tamServicio > 0 && pPrecioServicio >= 0){
        exito = 1;
        for(int i=0; i<tamServicio; i++){
            if(servicios[i].id == idServicio){
                (*pPrecioServicio) = servicios[i].precio;

                flag = 0;
                break;
            }
        }
        if(flag){
            exito = -1;
        }
    }
    return exito;
}


// G- Listar Servicios
int mostrarServicios(eServicio servicios[], int tamServicio)
{
    int exito = 0;

    system("cls");
    printf(" --------------------------------------------\n");
    printf("             Lista de Servicios              \n");
    printf("    id Serv.     Servicios       Precio \n");
    printf(" --------------------------------------------\n");

    if(servicios != NULL && tamServicio > 0){
        for(int i=0; i<tamServicio; i++){
            printf("    %d         %-10s   $%8.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");

        exito = 1;
    }
    return exito;
}


int validarServicio(eServicio servicios[], int tamServicio, int id)
{
    int esValido = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.

    if(servicios != NULL && tamServicio > 0){

        for(int i=0; i<tamServicio; i++){
            if(servicios[i].id == id){
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


// Busqueda por Id
int buscarServicioId(eServicio servicios[], int tamServicio, int id, int* pIndex)
{
    int exito = 0;

    if(servicios != NULL && tamServicio > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tamServicio; i++)
        {
            if( servicios[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        exito = 1;
    }
    return exito;
}

// Bonus Track  -   Harcodear algunos Trabajos

// 9
int autosPorServicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int indice;
    int id;
    int flag = 1;

    if(trabajos != NULL && tamTrabajo > 0 && servicios != NULL && tamServicio > 0 && autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        mostrarServicios(servicios, tamServicio);

        utn_getNumero(&id, "Ingrese Id del Servicio: ", "Error. Reingrese Id del servicio: ", 20000,20003, 0);

        if( buscarServicioId(servicios, tamServicio, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra un Servicio con ese Id en el sistema.\n");
            }
            else{
                system("cls");
                printf("---------------------------------------------------------------------------------------------------\n");
                printf("                       *** Lista de Autos por Servicio realizado ***                               \n");
                printf("  Id        Marca Auto       Color         Servicio          Precio        Fecha Trabajo           \n");
                printf("---------------------------------------------------------------------------------------------------\n");

                for(int i=0; i<tamTrabajo; i++)
                {
                    if( !trabajos[i].isEmpty && trabajos[i].idServicio == servicios[indice].id)
                    {
                        mostrarTrabajoFila(trabajos[i], autos, tamAuto, marcas, tamMarca, colores, tamColor, servicios, tamServicio);
                        flag = 0;
                    }
                }
                if( flag )
                {
                    printf("No hay trabajos para mostrar \n");
                }


            }
            exito = 1;
        }
    }
    return exito;
}
