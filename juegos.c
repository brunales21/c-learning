#include "varios.h"
#include "consola.h"
#include "juegos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define CLEANCONSOLE system("cls")



void jugarPiedraPapelOTijera() {

    typedef enum { PIEDRA=0, PAPEL=1, TIJERA=2 } Elemento;

    char * elementos[] = { "PIEDRA", "PAPEL", "TIJERA" };

    Elemento elementoDelCPU;
    Elemento elementoDelHumano;

    elementoDelCPU = getRandom(0, 2);

    char eleccion = -1;

    do {
        if (eleccion != -1) {
            printf("%c", eleccion);
            printf("\nEsa opcion no existe...\n");
        }
        printf("Elija elemento:\n1-PIEDRA\n2-PAPEL\n3-TIJERA\n? ");
        eleccion = getch();
    } while (eleccion != '1' && eleccion != '2' && eleccion != '3');

    if (eleccion == '1') {
        elementoDelHumano = PIEDRA;
    } else if (eleccion == '2') {
        elementoDelHumano = PAPEL;
    } else {
        elementoDelHumano = TIJERA;
    }

    printf("%s", elementos[elementoDelHumano]);

    printf("\nEl CPU habia sacado %s\n", elementos[elementoDelCPU]);

    if (elementoDelHumano == PIEDRA && elementoDelCPU == TIJERA
        ||
        elementoDelHumano == PAPEL && elementoDelCPU == PIEDRA
        ||
        elementoDelHumano == TIJERA && elementoDelCPU == PAPEL
        ) {
        printf("HAS GANADO!!!\n");
    } else if (elementoDelCPU == elementoDelHumano) {
        printf("EMPATAMOS!!!\n");
    } else {
        printf("HAS PERDIDO!!!\n");
    }

}


