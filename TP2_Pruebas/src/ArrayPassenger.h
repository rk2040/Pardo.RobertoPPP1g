/*
 * ArrayPassenger.h
 *
 *  Created on: 8 may. 2022
 *      Author: Roberto i3
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "vuelo.h"

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int idVuelo;		// económica o turística. económica superior. Business o Ejecutiva. Primera clase.
//	int typePasseger;	// Activo o Inactivo
	int statusFlight;
	int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */




int menu();


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);


/**
 * @brief
 *
 * @param vec
 * @param tam
 * @param pIndex
 * @return
 */
int buscarLibre(Passenger vec[], int tam);


int cargaDatosPasajero(char* nombre, char* apellido, float* precio, char* flycode, int* tipoPasaje, int* estadoPasaje, int tamNombre, int tamApellido, int tamFlycode, eVuelo* vuelos, int tamVuelos);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int estadoPasaje);
//int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], eVuelo* vuelo, int tamVuelo);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len, int id);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id, eVuelo* vuelo, int tamVuelo);




/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);


int menuInformar();


int subMenuInformar();


int ordenamiento(Passenger* vec, int tam, int criterio);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length, eVuelo* vuelo, int tamVuelo);


/**
 * @brief
 *
 * @param vec
 */
void mostrarPasajero(Passenger vec, eVuelo* vuelo, int tamVuelo);


void mostrarPasajeroFila(Passenger vec, eVuelo* vuelo, int tamVuelo);


int cargarEstadoPasaje(Passenger vec, char desc[]);



/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersStatus(Passenger* list, int len, int order);

int mostrarPromedioYTotal(Passenger* list, int len);

int ordenarPorId(Passenger* list, int len, int order);

int modificarPasajero(Passenger* vec, int tam, eVuelo* vuelo, int tamVuelo);

int menuModificar();

int harcodearPasajeros(Passenger vec[], int tam, int cant, int* pNextId);
