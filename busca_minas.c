#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "consola.h"
#include "shapes.h"
#include "animations.h"
#include "math.h"
#include "varios.h"
#define CLEANCONSOLE system("cls")

int jugarBM() {

    do {


      /*  printf("ELIGA LA DIFICULTAD (F/N/D)");

        char dificultad = getche();
        while (dificultad != 'f' && dificultad != 'F' && dificultad != 'n' && dificultad != 'N' && dificultad != 'd' && dificultad != 'D') {
                printf("\nELIGA LA DIFICULTAD (F/N/D)");
                dificultad = getche();
        }
        */

        int primeraVez = 1;
        gotoxy(0,0);
        srand(time(NULL));
        CLEANCONSOLE;
        long initTime = getTimestamp();

        int width;
        int height;
        int totalBombs;
        int availableFlags = totalBombs;

        printf("ELIGE LA DIFICULTAD: (f/n/d)\n-Facil\n-Normal\n-Dificil\n?");
        char dificultad = getche();

        while (dificultad != 'f' && dificultad != 'F' && dificultad != 'n' && dificultad != 'N' && dificultad != 'd' && dificultad != 'D') {
                printf("\nNO HE ENTENDIDO, ELIGE LA DIFICULTAD: \nFacil\nNormal\nDificil\n?");
                dificultad = getche();
        }

        if (dificultad == 'f' || dificultad == 'F') {
            width = 10;
            height = 10;
            totalBombs = 10;
            availableFlags = totalBombs;
        }
            if (dificultad == 'n' || dificultad == 'N') {
                width = 18;
                height = 18;
                totalBombs = 40;
                availableFlags = totalBombs;
            }
                if (dificultad == 'd' || dificultad == 'D') {
                    width = 24;
                    height = 24;
                    totalBombs = 99;
                    availableFlags = totalBombs;
            }

            CLEANCONSOLE;


        char board[width][height];
        char board2[width][height];

        //inicializamos el tablero de atras y el de adelante
        for(int x = 0; x<width; x++) {
            for(int y = 0; y<height; y++) {
                board[x][y] = ' ';
                board2[x][y] = 'o';
            }
        }

        showBoard(board2, width, height);

        int stepX = 1;
        int stepY = 1;

        int x = 0;
        int y = 0;

        int maxX = width - 1;
        int maxY = height - 1;

        int minX = 0;
        int minY = 0;

        int offsetX = 1;
        int offsetY = 1;

        char key;


        do {

            gotoxy(x+offsetX, y+offsetY);

            key = getch(); // Aquí la ejecución se detiene esperando una tecla del teclado.

            // Cuando se trata de una flecha, hay que hacer 2 getch por cada pulsación,
            // siendo el 2do el que tiene el valor de la dirección de la flecha.

            if (key == -32) {
                key = getch(); // En este caso se devuelve inmediatamente un valor, la ejecución no se detiene aquí.
            }
            switch(key) {
                case ARROW_UP: y = y - stepY >= minY ? y - stepY : y; break;
                case ARROW_RIGHT: x = x + stepX <= maxX ? x + stepX : x; break;
                case ARROW_DOWN: y = y + stepY <= maxY ? y + stepY : y; break;
                case ARROW_LEFT: x = x - stepX >= minX ? x - stepX : x; break;
                case 8:
                    if (board2[y][x] == 'o') {
                        setColor(0xA0);
                        board2[y][x] = 'F';
                        availableFlags--;
                    } else if (board2[y][x] == 'F') {
                        setColor(0x0E);
                        board2[y][x] = '?';
                        availableFlags++;
                    } else if (board2[y][x] == '?') {
                        setColor(0x0F);
                        board2[y][x] = 'o';
                    } else {
                        break;
                    }

                    printf("%c", board2[y][x]);
                    setColor(0x0F);
                    if (availableFlags == 0) {
                        if (win(board2, width, height, offsetY, initTime)) {
                            key = 27;
                        }
                    }

                    //Si acaba de poner F, detectar si ganó...Es cuando en board2 no hay "o" y hay tantas "F" como totalBombs

                    break;
                case ' ':
                    if (board[y][x] == 'B') {
                        lose(board, board2, width, height, offsetX, offsetY);
                        key = 27;
                    } else {
                        if (primeraVez) {
                            initBombs(totalBombs, width, height, board, x, y);
                            primeraVez = 0;
                        }
                        setColor(2);
                        uncover(x, y, board, board2, width, height, offsetX, offsetY);
                        if (availableFlags == 0) {
                            if (win(board2, width, height, offsetY, initTime)) {
                                key = 27;
                            }
                        }
                    }
                    break;
            }


        } while(key != 27);
    } while (seguirJugando());
    return 0;
}

void lose(char *b1, char *b2, int width, int height, int offsetX, int offsetY) {
    setPause(2500);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c1 = *(b1+y*width+x);
            char c2 = *(b2+y*width+x);
            gotoxy(x+offsetX, y+offsetY);
            if (c1 == 'B') {
                if (c2 == 'F') {
                    setColor(2);
                    printf("F");
                } else {
                    setColor(4);
                    printf("B");
                }
            } else {
                printf(" ");
            }
            pause();
        }
        printf("\n");
    }
    setColor(15);
    gotoxy(0, height + offsetY + 1);
    printf("Has pisado una mina!\n");

}

void uncover(int x, int y, char * b1, char * b2, int width, int height, int offsetX, int offsetY) {
    if (x<0 || x>=width || y<0 || y>=height) {
        return;
    }

    char s2 = *(b2 + y*width + x);

    if (s2 != 'o') {
        //Ya está destapado
        return;
    }

    char s1 = *(b1 + y*width + x);

    if (s1 == 'F' || s1 == '?') {
        return;
    }

    *(b2 + y*width + x) = s1;
    gotoxy(x+offsetX,y+offsetY);

    setPause(500);
    pause();
    printf("%c", s1);

    if (s1 >= '1' && s1 <= '8') {
        return;
    }

    //N
    uncover(x, y-1, b1, b2, width, height, offsetX, offsetY);

    //NE
    uncover(x+1, y-1, b1, b2, width, height, offsetX, offsetY);

    //E
    uncover(x+1, y, b1, b2, width, height, offsetX, offsetY);

    //SE
    uncover(x+1, y+1, b1, b2, width, height, offsetX, offsetY);

    //S
    uncover(x, y+1, b1, b2, width, height, offsetX, offsetY);

    //SW
    uncover(x-1, y+1, b1, b2, width, height, offsetX, offsetY);

    //W
    uncover(x-1, y, b1, b2, width, height, offsetX, offsetY);

    //NW
    uncover(x-1, y-1, b1, b2, width, height, offsetX, offsetY);

}

void showBoard(char *pboard2, int width, int height) {
    for(int y = -1; y <= height; y++) {
        for(int x = -1; x <= width; x++) {
            if (y == -1 || y == height || x == -1 || x == width) {
                setColor(2);
                printf("%c", 0xDB);
            } else {
                setColor(15);
                printf("%c", *(pboard2+((width*y)+x)));
            }
        }
        printf("\n");
    }
}

int getTotalNearBombs(char *pboard, int width, int height, int xc, int yc) {
    int count = 0;
    for (int y = yc - 1; y <= yc + 1; y++) {
        if (y < 0 || y >= height) {
            continue;
        }
        for (int x = xc - 1; x <= xc + 1; x++) {
            if (x < 0 || x >= width) {
                continue;
            }
            if (*(pboard+width*y+x) == 'B') {
                count++;
            }
        }
    }
    return count;
}



char getValue(char *b, int width, int x, int y) {
    return *(b+x*width+y);
}

// Si (xc - 1 <= x <= xc + 1) ^ (yc - 1 <= y <= yc + 1) => No puede haber bomba en x,y
// if (xc - 1 <= x && x <= xc + 1 && yc - 1 <= y && y <= yc + 1) { continue; }
// A => B   if (A) { B }


void initBombs(int totalBombs, int width, int height, char *pboard, int xc, int yc) {
//metemos las bombas
    for(int i = 0; i < totalBombs; i++) {
        while(1) {
            int x = getRandom(0, width - 1);
            int y = getRandom(0, height - 1);
            if (xc - 1 <= x && x <= xc + 1 && yc - 1 <= y && y <= yc + 1) {
                continue;
            }
            if (' ' == *(pboard+y*width+x)) {
                *(pboard+y*width+x) = 'B';
                break;
            }
        }

    }

//metemos los numeros
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (*(pboard+y*width+x) != 'B') {
                int bombs = getTotalNearBombs(pboard, width, height, x, y);
                if (bombs > 0) {
                    *(pboard+y*width+x) = '0' + bombs;
                }

            }
        }
    }
}

int win(char *pboard2, int width, int height, int offsetY, long initTime) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = *(pboard2+y*width+x);
            if ( c == 'o' || c == '?') {
                return 0;
            }
        }
    }

    gotoxy(0, height + offsetY + 1);
    printf("Ganaste! Has encontrado todas las minas en %d segundos.", getTimestamp() - initTime);
    return 1;
}

/*int setDifficulty(int width, int height, int totalBombs, int availablaFlags) {

        printf("ELIGE LA DIFICULTAD (F/N/D)");
        char dificultad = getche();

        while (dificultad != 'f' && dificultad != 'F' && dificultad != 'n' && dificultad != 'N' && dificultad != 'd' && dificultad != 'D') {
                printf("\nELIGA LA DIFICULTAD (F/N/D)");
                dificultad = getche();
        }

        if (dificultad == 'f' || dificultad == 'F') {
            width = 10;
            height = 10;
            totalBombs = 10;
            availableFlags = totalBombs;
        }
            if (dificultad == 'n' || dificultad == 'N') {
                width = 18;
                height = 18;
                totalBombs = 40;
                availableFlags = totalBombs;
            }
                if (dificultad == 'd' || dificultad == 'D') {
                    width = 24;
                    height = 24;
                    totalBombs = 99;
                    availableFlags = totalBombs;
            }

            CLEANCONSOLE;


}
*/
