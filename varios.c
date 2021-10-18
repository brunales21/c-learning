#include <time.h>
#include "varios.h"
#define FALSE 0
#define TRUE 1
#define MAX_AUX 257
#define SALTO_DE_LINEA printf("\n");

int seguirJugando() {
    printf("\nOtra partidita? (s/n) ");
    char respuesta = getche();
    while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n') {
        printf("\nNo he entendido... Si o no? (s/n) ");
        respuesta = getche();
    }

    SALTO_DE_LINEA;
    SALTO_DE_LINEA;


    if (respuesta == 's' || respuesta == 'S') {
        return TRUE;
    }

    printf("\nCHAU!!!");

    return FALSE;
}

int cuentaVocales(char texto[]) {
    int contador = 0;
    for (int i = 0; texto[i] != 0; i++) {
        char letra = texto[i];
        char letraMinuscula = tolower(letra);
        switch(letraMinuscula) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'á':
        case 'é':
        case 'í':
        case 'ó':
        case 'ú':
        case 'ü':
            contador++;
        }
    }
    return contador;
}

int cuentaVocales2(char * texto) {

    int contador = 0;
    while (*texto != 0) {
        if (*texto == 'a') {
            contador++;
        }
        texto++;
    }
    return contador;
}

int posicionLetra(char texto[], char letra) {
    for (int i = 0; texto[i] != 0; i++) {
        if (letra == texto[i]) {
            return i;
        }
    }
    return -1;
}

int length(char texto[]) {
    int i;
    for (i=0; texto[i] != 0; i++);
    return i;
}

void reverse(char texto[]) {
    for (int i = length(texto) - 1; i >= 0; i--) {
        printf("%c\n", texto[i]);
    }
    printf("\n");
}

int contadorPalabras(char texto[]) {
    int palabras = 0;
    int detectaEspacio = 1;
    for (int i = 0; texto[i] != 0; i++) {
        char c = texto[i];
        int esLetra = (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
        if (!esLetra) {
            //Es un espacio
            detectaEspacio = 1;
        } else {
            //Es una letra
            if (detectaEspacio == 1) {
                palabras++;
                detectaEspacio = 0;
            }
        }
    }
    return palabras;
}

void left(char texto[], int len, char target[]) {
    for (int i = 0; i<len; i++) {
        target[i] = texto[i];
    }
    target[len] = 0;
}

void right(char texto[], int len, char target[]) {
    int end = length(texto);
    for (int i = end-len; texto[i] != 0; i++) {
        target[i-(end-len)] = texto[i];

    }
    target[len] = 0;
}

void subString(char texto[], int ini, int fin, char target[]) {
    int len = fin - ini;
    for(int i = ini; i < fin; i++) {
        //*(target + i-ini) = *(texto + i)
        target[i-ini] = texto [i];
    }
     target[len] = 0;
}

void subString2(char * texto, int  ini, int  fin, char * target) {
    char * end = texto + fin;
    texto = texto + ini;//texto+=ini;
    //for (; texto < end;) {
    while (texto < end) {
        //*target = *texto; target++; texto++;
        *target++ = *texto++;
    }
    *target = 0;
}

void append(char s[], char t[]) {
    int len = length(s);
    for (int i = 0; t[i]!= 0; i++) {
        s[len+i]=t[i];
    }
}

void append2(char * s, char * t) {
    //s = s + length(s);
    s += length(s);
    for (; *t != 0; t++,s++) {
        *s=*t;
    }
}

void copiarInverso(char s[], char t[]) {
    int len = length(s);
    for (int i = len - 1; i >= 0; i--) {
        t[len - 1 - i] = s[i];
    }

}

void copiarInverso2(char * s, char * t) {
    for (char * p = s + length(s) - 1; p >= s; p--, t++) {
        *t = *p;
    }
}

void copiar(char s[], char t[], int maxLength) {
    int i;
    for (i = 0; s[i] != 0 && i < maxLength; i++) {
        t[i] = s[i];
    }
    t[i] = 0;
}

void copiar2(char * s, char * t) {
    for (; *s != 0; s++, t++) {
        *t = *s;
    }
    *t = 0;
}

void copiar3(char * s, char * t) {
    while (*s != 0) {
        *t++ = *s++;
    }
    *t = 0;
}

/*
void imprimir_datos(Jugador * j) {
   printf("El jugador %s %s nacido en %s, juega en el %s de %s.\n",
        j->nombre, j->apellido, j->paisNacimiento, j->club, j->posicion);
}
*/
int getRandom(int from, int to) {
    int range = to - from + 1;
    int random = rand() % range;
    return from + random;
}


int cuentaLetrasDistintas(char texto[]) {
    int j = 0;
    char aux[MAX_AUX];
    for(int i = 0; texto[i] != 0; i++) {
        char letra = texto[i];
        if (letra != ' ' && posicionLetra(aux, letra) == -1){
            aux[j] = letra;
            j++;
            aux[j] = 0;
        }
    }
    return j;
}

void ordenaLetras(char texto[], int asc) {

    if (asc) {
        ordenaLetrasAsc(texto);
    } else {
        ordenaLetrasDes(texto);
    }

}

void ordenaLetrasAsc(char texto[]) {
    int len = length(texto);
    int flag;
    do {
        flag = 0;
        for(int i = 0; i < len - 1; i++) {
            if (texto[i] > texto[i+1]) {
                char aux = texto[i];
                texto[i] = texto[i+1];
                texto[i+1] = aux;
                flag = 1;
            }
        }

    } while (flag);
}

void ordenaLetrasDes(char texto[]) {
    int len = length(texto);
    int flag;
    do {
        flag = 0;
        for(int i = 0; i < len - 1; i++) {
            if (texto[i] < texto[i+1]) {
                char aux = texto[i];
                texto[i] = texto[i+1];
                texto[i+1] = aux;
                flag = 1;
            }
        }

    } while (flag);
}

/*
int mainPlayAhorcado() {
    srand(time(NULL));
    playAhorcado();
    play();
    printf("%d", cuentaLetrasDistintas("1112333"));
    char palabra[50] = "onurb";
    ordenaLetras(palabra, 0);
    printf("%s\n", palabra);
    ordenaLetras(palabra, 1);
    printf("%s", palabra);
    int intentosFallidos = 6;
    char letra;
    char letras[100];
    int i = 0;
    char texto[] = "macaco";
    int len = length(texto);
    while (intentosFallidos > 0) {
        printf("\nElige una letra: ");
        letra = getch();
        letras[i] = letra;
        i++;
        letras[i] = 0;
        printf("%c\n", letra);

        if (posicionLetra(texto, letra) == -1) {
            intentosFallidos--;
            printf("La letra no está....te quedan %d intentos...", intentosFallidos);
        } else {
            if (encuentraLetra(texto, letras) == len) {
                printf("\nGanaste!\n");
                break;
            }
        }
        if (intentosFallidos == 0) {
            printf("\nPerdiste, te has quedado sin intentos.");
        }
    }
    printf("\nFIN del juego.\n");
    return 0;
}

void playAhorcado() {

    char * palabras[] = { "cabeza", "casa", "mesa", "esternocleidomastoideo", "esqueleto", "pelota" };
    int cantidad = sizeof(palabras)/sizeof(char*);

    for (int i=0; i<sizeof(palabras)/sizeof(char*); i++) {
        printf("%s\n", palabras[i]);
    }
}

int encuentraLetra(char texto[], char letras[]) {
    int contador = 0;
    for (int i = 0; texto [i] != 0; i++) {
        char letraOculta = texto[i];
        int encontro = 0;
        for (int j = 0; letras[j] != 0; j++) {
            char letra = letras[j];
            if (letra == letraOculta) {
                printf("%c", letra);
                encontro = 1;
                contador++;
                break;
            }
        }
            if (!encontro) {
                printf("_");
            }
    }
    printf("\n");
    return contador;
}
/*
int carlos () {
   FILE * fp;

   fp = fopen("c:\\temp\\equipos-ar.csv", "w+");

    if (fp == NULL) {
        printf("Error %d \n", errno);
        return 1;
    }

   fprintf(fp, "%d,%s\n", 1, "Boca");
   fprintf(fp, "%d,%s\n", 1, "River");

   fclose(fp);

   return(0);
}

int ejWrite () {
   FILE * fp;

   fp = fopen("c:\\temp\\equipos-ar.csv", "w+");

    if (fp == NULL) {
        printf("Error %d \n", errno);
        return 1;
    }

   fprintf(fp, "%d,%s\n", 1, "Boca");
   fprintf(fp, "%d,%s\n", 1, "River");

   fclose(fp);

   return(0);
}
*/

