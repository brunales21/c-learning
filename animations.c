#include <stdio.h>
#include "consola.h"
#include "shapes.h"
#include "animations.h"

void randomLines() {

    srand(time(NULL));
    hideCursor();
    enableTrace();
    char symbols[] = {0xB0, 0xB1, 0xB2, 0xDB};
    setPause(1000);

    do {
        int width = getScreenWidth()-1;
        int height = getScreenHeight()-1;
        setSymbol(symbols[getRandom(0, sizeof(symbols)-1)]);
        setColor(getRandom(1, 15));
        moveToPosition(getRandom(0, width), getRandom(0, height));
        //drawSymbolXY(getRandom(0, width), getRandom(0, height));
        pause();
    } while(isKbUntouched());
}

int paint() {

    int minX = 0;
    int maxX = getScreenWidth() - 1; // Si width = 100, x va de 0 a 99, por lo que el máximo es 99.
    int minY = 0;
    int maxY = getScreenHeight() - 1; // Si height = 50, y va de 0 a 49, por lo que el máximo es 49.

    int x = 0;
    int y = 0;

    // Step nos permite cambiar la distancia de cada paso que se da.
    int stepX = 2;
    int stepY = 1;

    hideCursor();
    enableTrace();
    setSymbol(0xDB);

    char key;

    do {

        moveToPosition(x, y);

        gotoxy(50,20); printf("%d,%d,%d,%d",x,y,maxX,maxY);

        //setColor(getRandom(1,16));

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
        }

    } while(key != 27);

}


int paintCarta() {

    setSymbol(0xDB);
    setPause(10000);

    hideCursor();

    disableTrace();
    moveToPosition(0, 20);
    moveToPosition(70, 20);
    enableTrace();
    moveToPosition(70, 10);
    moveToPosition(30, 10);
    moveToPosition(50, 3);
    moveToPosition(70, 10);
    moveToPosition(30, 20);
    moveToPosition(30, 10);
    moveToPosition(70, 20);
    moveToPosition(30, 20);

    return 0;
}


int showMatrixEffectDefault() {
    showMatrixEffect(NULL);
}

int showMatrixEffect(char * availableSymbols) {

    if (availableSymbols == NULL) {
        availableSymbols = "01";
    }

    srand(time(NULL));
    hideCursor();
    int height = getScreenHeight();
    int width = getScreenWidth()-1;
    Position points[width];
    int colors[width];
    char symbols[width];
    //int fibo[] = { 1, 1, 2, 3, 5, 8, 13};

    do {
        //Inicializamos puntos, colores y simbolos
        for(int i = 0; i<width && isKbUntouched(); i++) {
            points[i].x = i;
            points[i].y = getRandom(0, height);
            symbols[i] = availableSymbols[ getRandom(0, strlen(availableSymbols) - 1) ];
            do {
                colors[i] = getRandom(0,2);
            } while (colors[i] == 1);
        }

        //Efecto de bajada de puntos
        int flag = 1;

        while(flag && isKbUntouched()) {
            flag = 0;
            for(int i = 0; i<width && isKbUntouched(); i++) {
                if(points[i].y < height) {
                    //clearPoint(points[i]);
                    points[i].y++;
                    //drawPoint(points[i]);
                    flag = 1;
                }

                setColor(colors[i]);
                setSymbol(symbols[i]);
                drawSymbol(&points[i]);
            }
            pause();
        }

    } while(isKbUntouched());

}

void getBounceXY(int x1, int y1, int x2, int y2, int * x3, int * y3, int W, int H) {

    if ((x2 == 0 || x2 == W) && (y2 == 0 || y2 == H)) {
        *x3 = x1;
        *y3 = y1;
        return;
    }

    float Dx = abs(x1 - x2);
    float Dy = abs(y1 - y2);

    char horizontal = x2 >= x1 ? 'R' : 'L';
    char vertical = y2 >= y1 ? 'D' : 'U';

    //Source R, debe dirigirse hacia la izquierda
    if (x2 == W) {
        if (vertical == 'D') {
            //Bajando
            //Target L
            *x3 = 0;
            *y3 = y2 + W * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target B
                *x3 = x2 - (H - y2) * Dx/Dy;
                *y3 = H;
            }
        } else {
            //Subiendo
            //Target L
            *x3 = 0;
            *y3 = y2 - W * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target T
                *x3 = W - y2 * Dx/Dy;
                *y3 = 0;
            }
        }
    }
    //Source L, debe dirigirse a la derecha
    if (x2 == 0) {
        if (vertical == 'D') {
            //Bajando
            //Target R
            *x3 = W;
            *y3 = y2 + W * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target B
                *x3 = (H - y2) * Dx/Dy;
                *y3 = H;
            }
        } else {
            //Subiendo
            //Target R
            *x3 = W;
            *y3 = y2 - W * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target T
                *x3 = y2 * Dx/Dy;//CORREGIR EN DOC
                *y3 = 0;
            }
        }
    }
    //Source B, debe dirigirse hacia arriba
    if (y2 == H) {
        if (horizontal == 'R') {
            //Hacia la derecha
            //Target R
            *x3 = W;
            *y3 = y2 - (W - x2) * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target T
                *x3 = x2 + H * Dx/Dy;
                *y3 = 0;
            }
        } else {
            //Hacia la izquierda
            //Target L
            *x3 = 0;
            *y3 = H - x2 * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target T
                *x3 = x2 - H * Dx/Dy;
                *y3 = 0;
            }
        }
    }
    //Source T, debe dirigirse hacia abajo
    if (y2 == 0) {
        if (horizontal == 'R') {
            //Hacia la derecha
            //Target R
            *x3 = W;
            *y3 = (W - x2) * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target B
                *x3 = x2 + H * Dx/Dy;
                *y3 = H;
            }
        } else {
            //Hacia la izquierda
            //Target L
            *x3 = 0;
            *y3 = x2 * Dy/Dx;
            if (*y3 < 0 || *y3 > H) {
                //Target B
                *x3 = x2 - H * Dx/Dy;
                *y3 = H;
            }
        }
    }
}

void bounce() {
    srand(time(NULL));
    hideCursor();
    setPause(10000);
    int width = getScreenWidth()-1;
    int height = getScreenHeight()-1;

    int x1 = getRandom(0, width);
    int y1 = getRandom(0, height);

    setColor(0);
    moveToPosition(x1, y1);

    int x2;
    int y2;

    int side = getRandom(0, 3);
    switch(side) {
        case 0: y2 = 0; x2 = getRandom(0, width); break; //TOP
        case 1: x2 = width; y2 = getRandom(0, height); break; //RIGHT
        case 2: y2 = height; x2 = getRandom(0, width); break; //BOTTOM
        case 3: x2 = 0; y2 = getRandom(0, height); break; //LEFT
    }

    moveToPosition(x2, y2);

    int count = 0;
    do {
        //setColor(getRandom(1, 15));
        //logDebug(x2, y2);

        int x3, y3;

        getBounceXY(x1, y1, x2, y2, &x3, &y3, width, height);

        if (count % 4 == 0) {
            setColor(getRandom(1, 15));
        }

        moveToPosition(x3, y3);

        //Chequea y controla cambio de tamanho de la pantalla
        int width2 = getScreenWidth()-1;
        int height2 = getScreenHeight()-1;
        if (width2 != width) {
            if (x2 == width) {
                x2 = width2;
            }
            if (x3 == width) {
                x3 = width2;
            }
            width = width2;
        }
        if (height2 != height) {
            if (y2 == height) {
                y2 = height2;
            }
            if (y3 == height) {
                y3 = height2;
            }
            height = height2;
        }

        //Nuevos últimos puntos:
        x1 = x2;
        y1 = y2;

        x2 = x3;
        y2 = y3;

        count++;
    } while(isKbUntouched());
}
