#include <stdio.h>
#include <stdlib.h>

void main() {

    char nombre[21] = "BRUNO";

    nombre[0] = 'B';
    nombre[1] = 'R';
    nombre[2] = 'U';
    nombre[3] = 'N';
    nombre[4] = 'O';
    nombre[21] = 0;

    printf("nombre=%s\n", nombre);

    char original[20] = "Bruno Emiliano";
    char copia[5];
    char aux[10]="BOCA JR";

    strcpy2(copia, 4, original);

    printf("copia=%s\n", copia);
    printf("aux=%s\n", aux);


    int a=4;
    int b=6;

    printf("---------------------------\n");

    printf("Direccion de a= %u\n", &a);
    printf("Direccion de b= %u\n", &b);

    printf("a=%d\n", a);
    printf("b=%d\n", b);

    swap(&a,&b);

    printf("a=%d\n", a);
    printf("b=%d\n", b);

}

void swap(int * numero1, int * numero2) {
      printf("Swapeando...\n");
    int numeroAuxiliar = *numero1;
    *numero1 = *numero2;
    *numero2 = numeroAuxiliar;
}

int strcpy2(char* target, int maxLength, char* source) {
    int i;

    for (i = 0; source[i] != 0 && i < maxLength; i++) {
        target[i] = source[i];
    }

    target[i] = 0;

    return 0;

}
