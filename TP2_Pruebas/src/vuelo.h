/*
 * vuelo.h
 *
 *  Created on: 9 may. 2022
 *      Author: Roberto i3
 */

#ifndef VUELO_H_
#define VUELO_H_

typedef struct
{
	int id;
	char tipoPasaje[20];
	int isEmpty;
}eVuelo;

#endif /* VUELO_H_ */


int cargarTipoPasaje(eVuelo vuelos[], int tam, int id, char desc[]);


//int cargarEstadoPasaje(eVuelo vuelos[], int tam, int id, char desc[]);


int validarIdVuelo(eVuelo vec[], int tam, int id);


int listarVuelos(eVuelo vuelos[], int tam);


int buscarVuelo(eVuelo vec[], int tam, int id, int* pIndex);



