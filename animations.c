#include<stdio.h>
#include "consola.h"
#include "shapes.h"
#include "animations.h"


int paintCarta() {

    setSymbol('O');
    setPause(10000);

    hideCursor();

    disableTrace();
    moveToPosition(0, 20);
    enableTrace();
    moveToPosition(40, 20);
    moveToPosition(40, 10);
    moveToPosition(0, 10);
    moveToPosition(20, 3);
    moveToPosition(40, 10);
    moveToPosition(0, 20);
    moveToPosition(0, 10);
    moveToPosition(40, 20);

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
    int height = getHeight();
    int width = getWidth()-1;
    Position points[width];
    int colors[width];
    char symbols[width];
    //int fibo[] = { 1, 1, 2, 3, 5, 8, 13};

    do {
        //Inicializamos puntos, colores y simbolos
        for(int i = 0; i<width && isNotKeyboardTouched(); i++) {
            points[i].x = i;
            points[i].y = getRandom(0, height);
            symbols[i] = availableSymbols[ getRandom(0, strlen(availableSymbols) - 1) ];
            do {
                colors[i] = getRandom(0,2);
            } while (colors[i] == 1);
        }

        //Efecto de bajada de puntos
        int flag = 1;

        while(flag && isNotKeyboardTouched()) {
            flag = 0;
            for(int i = 0; i<width && isNotKeyboardTouched(); i++) {
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

    } while(isNotKeyboardTouched());

}

