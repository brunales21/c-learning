
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "varios.h"
#include <conio.h>

int variableGlobal=1;

typedef struct {
    int id;
    int division;//4 bytes
    char nombre[50];//50 bytes
    int anioFundacion;// 4 bytes
    char estadio[50];//50 bytes
} Equipo;

enum Resultado { LOCAL, EMPATE, VISITANTE };

typedef struct {
    int jornada;
    Equipo equipoLocal;
    Equipo equipoVisitante;
    enum Resultado resultado1;
    enum Resultado resultado2;
} Partido;

typedef struct {
    Partido partidos[15];
} Quiniela;

int mainParaEstudiar() {
    int filasMax, columnasMax;

    Equipo equipos[40];

    Quiniela quinielaDeBruno;

    quinielaDeBruno.partidos[0].jornada = 1;

    Equipo * equipo = &equipos[4];

    equipo->division = 1;
    strcpy(equipo->nombre, "Barcelona");
    strcpy(equipo->estadio, "Camp Nou");
    equipo->anioFundacion = 1900;

    showEquipo(equipo);

    printf("\nElige un numero de filas: ");
    scanf("%d", &filasMax);
    printf("\nElige un numero de columnas: ");
    scanf("%d", &columnasMax);
    muestraMatriz(filasMax, columnasMax);
    printf("\n");

    return 0;
}

void showEquipo(Equipo * equipo) {
    printf("Nombre: %s; %Estadio: %s, Fundacion: %d, Division: %d\n", equipo->nombre, equipo->estadio, equipo->anioFundacion, equipo->division);
}

void muestraMatriz(int filas, int columnas) {

    for(int fila = 0; fila<filas; fila++) {
        for(int columna = 0; columna<columnas; columna++) {
            printf("(%d,%d)", fila, columna);
        }
        printf("\n");
    }

}

int foo() {
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            for (int k = 0; k<10; k++) {
                printf("(%d,%d,%d)\n", i, j, k);
            }
        }
    }
}
