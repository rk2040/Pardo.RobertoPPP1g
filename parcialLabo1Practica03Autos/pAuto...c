#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pAuto.h"
#include "pMarca.h"
#include "pColor.h"

#include "utn.h"
#include "pardo.h"




char menu()
{
    char opcion;

    printf("-------------------------------------\n");
    printf("    *** Lavadero de Autos ***        \n");
    printf("-------------------------------------\n");
    printf("A- Altas Auto \n");
    printf("B- Modificar Auto \n");
    printf("C- Baja Auto \n");
    printf("D- Listar Autos \n");
    printf("E- Listar Marcas \n");
    printf("F- Listar Colores \n");
    printf("G- Listar Servicios \n");
    printf("H- Altas Trabajo \n");
    printf("I- Listar Trabajos \n");
    printf("J- Informes complementarios \n");
    printf("X- Salir \n");
    printf("Ingrese una opcion: \n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}


// Inicializa todos los autos con valos isEmpty 1 (vacio)
int inicializarAutos(eAuto autos[], int tam)
{
    int exito = 0;

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            autos[i].isEmpty = 1;
        }
        exito = 1;
    }
    return exito;
}


// Buscar la primer posicion libre dentro del array
int buscarLibre(eAuto autos[], int tam)
{
    int indice = -1;

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if( autos[i].isEmpty )
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


// A- Alta
int altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int* pNextId)
{
    int exito = 0;
    int indice;
    eAuto auxAuto;

    if(autos != NULL && tamAuto >0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor > 0)
    {
        system("cls");

        printf("-------------------------------------\n");
        printf("       *** Alta de Autos ***        \n");
        printf("-------------------------------------\n");

        indice = buscarLibre(autos, tamAuto);

        if(indice == -1)
        {
            printf("No hay Autos cargados en el sistema.\n");
        }
        else{
            auxAuto.id = *pNextId;

            (*pNextId)++;   // le sumo 1 para el id del siguiente que se de de alta


            printf("Ingrese tipo de caja: m (manual) / a (automatica)\n");
            fflush(stdin);
            scanf("%c", &auxAuto.caja);
            auxAuto.caja = toupper(auxAuto.caja);
            while( !(auxAuto.caja == 'M' || auxAuto.caja == 'A') )
            {
                printf("Ingrese tipo de caja: m (manual) / a (automatica)\n");
                fflush(stdin);
                scanf("%c", &auxAuto.caja);
                auxAuto.caja = toupper(auxAuto.caja);
            }

            mostrarMarcas(marcas, tamMarca);
            //utn_getNumero(&auxAuto.idMarca, "Ingrese Id de la Marca: ", "Error. \nReingrese Id de la Marca: ", 1, 1000, 1);
            printf("Ingrese Id de la Marca: ");
            fflush(stdin);
            scanf("%d", &auxAuto.idMarca);
        // Valido Id
            while( !validarMarca(marcas, tamMarca, auxAuto.idMarca) )
            {
                printf("Error. \nReingrese Id de la Marca: ");
                fflush(stdin);
                scanf("%d", &auxAuto.idMarca);
            }


            mostrarColores(colores, tamColor);
            printf("Ingrese Id del Color: ");
            fflush(stdin);
            scanf("%d", &auxAuto.idColor);
        //Valido Id
            while( !validarColor(colores, tamColor, auxAuto.idColor) )
            {
                printf("Error. Reingrese Id del Color: ");
                fflush(stdin);
                scanf("%d", &auxAuto.idColor);
            }

            auxAuto.isEmpty = 0;

            autos[indice] = auxAuto;

            exito = 1;
        }
    }
    return exito;
}


int cargarDescripcionAuto(eAuto autos[], int tamAuto, int idAuto, char descripcion[], eMarca marcas[], int tamMarca)
{
    int exito = 0;  // 0 si hubo algun problema. 1 si cargo todo bien. -1 si cargo todo bien pero no encontro coincidencia de ID
    int flag = 1;
    int indiceMarca;

    if(autos != NULL && tamAuto > 0 && descripcion != NULL && marcas != NULL && tamMarca > 0)
    {
        exito = 1;
        for(int i=0; i<tamAuto; i++)
        {
            if(autos[i].id == idAuto)
            {
                indiceMarca = autos[i].idMarca;
                strcpy(descripcion, marcas[indiceMarca].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            exito = -1;
        }
    }
    return exito;
}


void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    char descMarca[20];
    char descColor[20];

    if( cargarDescripcionMarca(marcas, tamMarca, unAuto.idMarca, descMarca) &&
        cargarDescripcionColor(colores, tamColor, unAuto.idColor, descColor) )
    {
        printf(" Id     : %d\n", unAuto.id);
        printf(" Marca  : %s\n", descMarca);
        printf(" Color  : %s\n", descColor);
        printf(" Caja   : %c\n", unAuto.caja);
    }
}


void mostrarAutoFila(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    char descMarca[20];
    char descColor[20];

    if( cargarDescripcionMarca(marcas, tamMarca, unAuto.idMarca, descMarca) &&
        cargarDescripcionColor(colores, tamColor, unAuto.idColor, descColor) )
        {
            printf("%4d     %-10s      %-10s   %c\n", unAuto.id, descMarca, descColor, unAuto.caja);
        }

}


//----
int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int flag = 1;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        system("cls");
        printf("------------------------------------------------\n");
        printf("         *** Listado de Autos ***               \n");
        printf("  Id     Marca           Color       Caja       \n");
        printf("------------------------------------------------\n");

        for(int i=0; i<tamAuto; i++)
        {
            if( !autos[i].isEmpty )
            {
                mostrarAutoFila(autos[i], marcas, tamMarca, colores, tamColor);
                flag = 0;
            }
        }
        if( flag )
        {
            printf("No hay Autos cargados en el sistema.\n");
        }
        exito = 1;
    }
    return exito;
}


// Busqueda por Id
int buscarAutoId(eAuto autos[], int tamAuto, int id, int* pIndex)
{
    int exito = 0;

    if(autos != NULL && tamAuto > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tamAuto; i++)
        {
            if( !autos[i].isEmpty && autos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        exito = 1;
    }
    return exito;
}


// B- Modificar
int menuModificar()
{
    int opcion;

    printf("-------------------------------------\n");
    printf("      *** Modificar Auto ***        \n");
    printf("-------------------------------------\n");
    printf("1- Color \n");
    printf("2- Caja \n");
    printf("0- Volver al menu anterior. \n");
    printf("Ingrese una opcion: \n");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}


int validarAuto(eAuto autos[], int tamAuto, int id)
{
    int esValido = 0;

    if(autos != NULL && tamAuto > 0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(autos[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


int modificarAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int indice;
    int id;
    eAuto auxAuto;
    char confirmaSalir = 'n';
    char confirma;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        system("cls");
        printf("-------------------------------------\n");
        printf("      *** Modificar Auto ***        \n");
        mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor);

        utn_getNumero(&id, "Ingrese Id del Auto: ", "Error. Reingrese Id del Auto: ", 1,1000, 0);

        if( buscarAutoId(autos, tamAuto, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra un Auto con ese Id en el sistema.\n");
            }
            else{
                mostrarAuto(autos[indice], marcas, tamMarca, colores, tamColor);
                confirma = opcionConfirmar("Quiere Modificar este Auto?: s/n ", "Error. Quiere Modificar este Auto?: s/n ");

                if(confirma == 's')
                {
                    auxAuto = autos[indice];

                    do{
                        system("cls");
                        mostrarAuto(autos[indice], marcas, tamMarca, colores, tamColor);
                        switch(menuModificar())
                        {
                        case 1:
                            mostrarColores(colores, tamColor);
                            utn_getNumero(&auxAuto.idColor, "Ingrese Id del Color: ", "Error. Reingrese Id del Color: ", 5000, 5004, 5);
                        //Valido Id
                            while( !validarColor(colores, tamColor, auxAuto.idColor) )
                            {
                                utn_getNumero(&auxAuto.idColor, "Error. Reingrese Id del Color: ", "Error. Reingrese Id del Color: ", 5000, 5004, 5);
                            }
                            autos[indice] = auxAuto;
                            break;
                        case 2:
                                printf("Ingrese tipo de caja: m (manual) / a (automatica)\n");
                                fflush(stdin);
                                scanf("%c", &auxAuto.caja);
                                auxAuto.caja = toupper(auxAuto.caja);
                                while( !(auxAuto.caja == 'M' || auxAuto.caja == 'A') )
                                {
                                    printf("Error. Reingrese tipo de caja: m (manual) / a (automatica)\n");
                                    fflush(stdin);
                                    scanf("%c", &auxAuto.caja);
                                    auxAuto.caja = toupper(auxAuto.caja);
                                }
                                autos[indice] = auxAuto;
                            break;
                        case 0:
                            confirmaSalir = opcionConfirmar("Seguro que quiere salir de la Modificacion? s/n ", "Error, vuelva a intentarlo. salir de la Modificacion? s/n ");
                            break;
                        default:
                            printf("Opcion invalida.\n");
                            break;
                        }

                    }while(confirmaSalir != 's');
                }
                else{
                    printf("Modificacion cancelada por el usuario\n");
                }

            }
            exito = 1;
        }
    }
    return exito;
}



// C- Baja
int bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int indice;
    int id;
    char confirma;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        system("cls");
        printf("-------------------------------------\n");
        printf("      *** Baja de Auto ***        \n");
        mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor);

        utn_getNumero(&id, "Ingrese Id del Auto: ", "Error. Reingrese Id del Auto: ", 1,1000, 0);

        indice = buscarAutoId(autos, tamAuto, id, &indice);

        if( buscarAutoId(autos, tamAuto, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra un Auto con ese Id en el sistema.\n");
            }
            else{
                system("cls");
                mostrarAuto(autos[indice], marcas, tamMarca, colores, tamColor);

                confirma = opcionConfirmar("Quiere Confirmar la baja de este Auto? s/n: ", "Error. Quiere Confirmar la baja de este Auto? s/n: ");

                if( confirma == 's' )
                {
                    autos[indice].isEmpty = 1;
                    printf("Baja exitosa.\n");
                }
                else{
                    printf("Baja cancelada por el usuario.\n");
                }
            }
        }
        exito = 1;
    }
    return exito;
}



// D- Listar
int ordenarPorMarcaYCaja(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    eAuto auxAuto;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        for(int i=0; i<tamAuto -1; i++)
        {
            for(int j=i+1; j<tamAuto; j++)
            {
                if( (autos[i].idMarca == autos[j].idMarca && autos[i].caja > autos[j].caja) ||
                    (autos[i].idMarca != autos[j].idMarca && autos[i].idMarca > autos[j].idMarca) )
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
            }
        }
        exito = 1;
    }
    return exito;
}

//=========================================================================================================================
//DATOS HARCODEO
//=========================================================================================================================
int idAuto[10] = {1,2,3,4,5,6,7,8,9,10};

int idMarca[10] = {1000,1002,1000,1001,1001,1003,1000,1002,1003,1004};

int idColor[10] = {5000,5002,5000,5001,5004,5003,5002,5002,5000,5001};

char caja[10] = {'A','A','M','M','M','A','M','M','M','A'};


int harcodearAutos(eAuto autos[], int tamAuto, int cant, int* pId)
{
    int contador = -1;

    if(autos != NULL && tamAuto > 0 && cant >= 0 && cant <= tamAuto && pId != NULL){
        contador = 0;
        for(int i=0; i<cant; i++){
            autos[i].id = *pId;
            (*pId)++;
            autos[i].idMarca = idMarca[i];
            autos[i].idColor = idColor[i];
            autos[i].caja = caja[i];
            autos[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}


//===================================================================================================================
//                      Informes complementarios
//===================================================================================================================

// 1
int mostrarAutosPorMarcaSeleccionada(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
int exito = 0;
    int indice;
    int id;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        mostrarMarcas(marcas, tamMarca);
        utn_getNumero(&id, "Ingrese Id de la Marca: ", "Error. Reingrese Id de la Marca: ",1000, 1004, 0);

        system("cls");
        printf("------------------------------------------------\n");
        printf("  *** Listado de Autos de la Marca elegida ***  \n");
        printf("  Id     Marca           Color       Caja       \n");
        printf("------------------------------------------------\n");


        if( buscarMarcaId(marcas, tamMarca, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra una Marca con ese Id en el sistema.\n");
            }
            else{
                for(int i=0; i<tamAuto; i++)
                {
                    if( !autos[i].isEmpty && autos[i].idMarca == id)
                    {
                        mostrarAutoFila(autos[i], marcas, tamMarca, colores, tamColor);
                    }
                }
            }
            exito = 1;
        }
    }
    return exito;
}

// 2
int mostrarAutosPorColorSeleccionado(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int indice;
    int id;

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        mostrarColores(colores, tamColor);
        utn_getNumero(&id, "Ingrese Id del Color: ", "Error. Reingrese Id del Color: ",5000, 5004, 0);

        system("cls");
        printf("------------------------------------------------\n");
        printf("   *** Listado de Autos del Color elegido ***   \n");
        printf("  Id     Marca           Color       Caja       \n");
        printf("------------------------------------------------\n");


        if( buscarColorId(colores, tamColor, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra una Marca con ese Id en el sistema.\n");
            }
            else{
                for(int i=0; i<tamAuto; i++)
                {
                    if( !autos[i].isEmpty && autos[i].idColor == id)
                    {
                        mostrarAutoFila(autos[i], marcas, tamMarca, colores, tamColor);
                    }
                }
            }
            exito = 1;
        }
    }
    return exito;
}

// 3
int promedioAutosNegrosPorMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int indice;
    int id;
    int totalAutos = 0;
    int autosNegros = 0;
    float promedio;
    char descripcion[20];

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {
        mostrarMarcas(marcas, tamMarca);
        utn_getNumero(&id, "Ingrese Id de la Marca: ", "Error. Reingrese Id de la Marca: ",1000, 1004, 0);

        system("cls");
        printf("------------------------------------------------\n");
        printf("   *** Listado de Autos del Color elegido ***   \n");
        printf("  Id     Marca           Color       Caja       \n");
        printf("------------------------------------------------\n");


        if( buscarMarcaId(marcas, tamMarca, id, &indice) )
        {
            if(indice == -1)
            {
                printf("No se encuentra una Marca con ese Id en el sistema.\n");
            }
            else{
                for(int i=0; i<tamAuto; i++)
                {
                    if( !autos[i].isEmpty && autos[i].idMarca == id)
                    {
                        totalAutos ++;
                        if(autos[i].idColor == 5000)
                        {
                            autosNegros ++;
                        }
                    }
                }
                if(autosNegros > 0)
                {
                    promedio = (float) (autosNegros * 100) / totalAutos;
                    cargarDescripcionMarca(marcas, tamMarca, id, descripcion);
                    printf("El promedio de autos negros sobre un total de %d autos de la marca %s es: %% %.2f\n", totalAutos, descripcion, promedio);
                }
                else{
                    printf("No hay autos para promediar.\n");
                }
            }
            exito = 1;
        }
    }
    return exito;
}

// 4
int listadoAutosPorMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    char descripcion[20];

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {

        system("cls");
        printf("------------------------------------------------\n");
        printf("    *** Listado de Autos por Marca     ***      \n");
        printf("  Id     Marca           Color       Caja       \n");
        printf("------------------------------------------------\n");


        for(int i=0; i<tamMarca; i++)
        {
            cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descripcion);
            printf("\n  ------ %s ------ \n\n", descripcion);

            for(int j=0; j<tamAuto; j++)
            {
                if( !autos[j].isEmpty && autos[j].idMarca == marcas[i].id)
                {
                    mostrarAutoFila(autos[j], marcas, tamMarca, colores, tamColor);
                }
            }
        }
        exito = 1;
    }
    return exito;
}


// 5
int marcasConMasAutosCajaM(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int marcaMax;
    int cantidades[tamMarca];
    int flag = 1;
    char descripcion[20];

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {

        for(int i=0; i<tamMarca; i++)
        {
            cantidades[i] = 0;

            for(int j=0; j<tamAuto; j++)
            {
                if( !autos[j].isEmpty && autos[j].idMarca == marcas[i].id && autos[j].caja == 'M')
                {
                    cantidades[i] ++;
                }
            }
        }

        for(int i=0; i<tamMarca; i++)
        {
            if( flag || ( cantidades[i] > marcaMax) )
            {
                marcaMax = cantidades[i];
                cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descripcion);
                flag = 0;
            }
        }

        for(int i=0; i<tamMarca; i++)
        {
            if(cantidades[i] == marcaMax)
            {
                cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descripcion);
                printf("La marca con mas autos con Caja Manual es %s y tiene %d autos\n", descripcion, marcaMax);
            }
        }

        exito = 1;
    }
    return exito;
}


// 6
int marcasConMenosAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int exito = 0;
    int marcaMinimo;
    int cantidades[tamMarca];
    int flag = 1;
    char descripcion[20];

    if(autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0 && colores != NULL && tamColor)
    {

        for(int i=0; i<tamMarca; i++)
        {
            cantidades[i] = 0;

            for(int j=0; j<tamAuto; j++)
            {
                if( !autos[j].isEmpty && autos[j].idMarca == marcas[i].id )
                {
                    cantidades[i] ++;
                }
            }
        }

        for(int i=0; i<tamMarca; i++)
        {
            if( flag || ( cantidades[i] < marcaMinimo) )
            {
                marcaMinimo = cantidades[i];
                cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descripcion);
                flag = 0;
            }
        }

        for(int i=0; i<tamMarca; i++)
        {
            if(cantidades[i] == marcaMinimo)
            {
                cargarDescripcionMarca(marcas, tamMarca, marcas[i].id, descripcion);
                printf("La marca con menos autos es %s y tiene %d autos\n", descripcion, marcaMinimo);
            }
        }

        exito = 1;
    }
    return exito;
}

