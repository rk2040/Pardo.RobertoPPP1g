#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int invertirCadena(char cadena[]);

int ordenarCaracteres(char cadena[]);

int main()
{

//--- Ejercicio 2 ---
    char cadena2[20] = {"UTN-FRA"};


    printf("%s\n", cadena2);

    invertirCadena(cadena2);

    printf("%s\n", cadena2);

    printf("%s\n\n\n");

//--- Ejercicio 3 ---
    char cadena3[20] = {"algoritmo"};


    printf("%s\n", cadena3);

    ordenarCaracteres(cadena3);

    printf("%s\n", cadena3);


    return 0;
}


/*
1. Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres), infectados(int), recuperados(int) y muertos(int).
Desarrollar una función llamada actualizarRecuperados que reciba el país y los recuperados del dia y que acumule estos a los que ya tiene el país.
La función no devuelve nada. *
*/
//--- Ejercicio 1 ---



/*
2. Crear una función que se llame invertirCadena que reciba una cadena de caracteres como parámetro y su responsabilidad es invertir
los caracteres de la misma. Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU *
*/
//--- Ejercicio 2 ---

int invertirCadena(char cadena[]){
    int todoOk = 0;
    char aux;
    int tam = strlen(cadena);

    if(cadena != NULL){



      for (int i = 0, j = tam - 1; i < (tam / 2); i++, j--) {
        aux = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = aux;
        }



    return todoOk;
    }
}

/*
3. Crear una función que se llame ordenarCaracteres que reciba una cadena de caracteres como parámetro y su responsabilidad es
ordenarlos caracteres de manera ascendente dentro de la cadena. Ejemplo si le pasamos "algoritmo" la deja como "agilmoort" *
*/
//--- Ejercicio 3 ---
int ordenarCaracteres(char cadena[]){
    int todoOk = 0;
    char aux;

    if(cadena != NULL){
        for(int i=0; i< strlen(cadena)-1; i++){
            for(int j=i+1; j<strlen(cadena); j++){

                if(cadena[i]>cadena[j]){
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;

                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
