#include <stdio.h>
#include <stdlib.h>



/*
1. Crear una funci�n llamada aplicarAumento que reciba como par�metro el
precio de un producto y devuelva el valor del producto con un aumento del 5%.
Realizar la llamada desde el main.


2. Crear una funci�n que se llame reemplazarCaracteres que reciba una cadena
de caracteres como primer par�metro, un car�cter como segundo y otro car�cter
como tercero, la misma deber� reemplazar cada ocurrencia del segundo par�metro
por el tercero y devolver la cantidad de veces que se reemplazo ese car�cter en la cadena


3. Dada la siguiente estructura generar una funci�n que permita ordenar un array de dicha
estructura por tipo. Ante igualdad de tipo deber� ordenarse por efectividad creciente.
Hardcodear datos y mostrarlos desde el main.
*/

typedef struct{
    int id;
    char nombre[20];
    char tipo[20];
    float efectividad;
}eVacuna;


float aplicarAumento(float precio);

int cambiarCaracter(char cadena[], char caracter1, char caracter2);

int main()
{



//  Ejercicio 1

    float precioProducto = 100;

    float precioAumentado;

    precioAumentado = aplicarAumento(precioProducto);
    printf(" Ejercicio 1: Aplicar Aumento: %.2f\n \n",precioAumentado);


//  Ejercicio 2

    char cadena[20] = "pepeelgrillo";

    char primerCaracter = 'o';

    char segundoCaracter = 'i';

    printf("%s\n", cadena);

    strcpy(cadena, cambiarCaracter(cadena, primerCaracter, segundoCaracter));

    printf("%s\n", cadena);



    return 0;
}

//  Ejercicio 1
float aplicarAumento(float precio){
    float aumento;
    float precioFinal;
    aumento = precio *5/100;
    precioFinal = precio + aumento;
    return precioFinal;
}


int cambiarCaracter(char cadena[], char caracter1, char caracter2){
    int todoOk =0;

    if(cadena != NULL){
        for(int i=0; i>strlen(cadena); i++){
            if(cadena[i] == caracter1){
                cadena[i]=caracter2;
            }
        }
    todoOk =1;
    }
}

