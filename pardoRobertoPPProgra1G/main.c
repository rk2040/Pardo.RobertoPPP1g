#include <stdio.h>
#include <stdlib.h>



/*
1. Crear una función llamada aplicarAumento que reciba como parámetro el
precio de un producto y devuelva el valor del producto con un aumento del 5%.
Realizar la llamada desde el main.


2. Crear una función que se llame reemplazarCaracteres que reciba una cadena
de caracteres como primer parámetro, un carácter como segundo y otro carácter
como tercero, la misma deberá reemplazar cada ocurrencia del segundo parámetro
por el tercero y devolver la cantidad de veces que se reemplazo ese carácter en la cadena


3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha
estructura por tipo. Ante igualdad de tipo deberá ordenarse por efectividad creciente.
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

