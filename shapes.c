#include <stdio.h>
#include "consola.h"
#include "shapes.h"
#include "math.h"


void drawSymbolXY(int x, int y) {
    gotoxy(x, y);
    printf("%c", symbol);
}

void clearSymbolXY(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

void drawSymbol(Position * point) {
    gotoxy(point->x, point->y);
    printf("%c", symbol);
}

void clearSymbol(Position * point) {
    gotoxy(point->x, point->y);
    printf(" ");
}

void setPosition(Position * p, int x, int y) {
    p->x=x;
    p->y=y;
}

void setSymbol(char s) {
    symbol = s;
}

char getSymbol() {
    return symbol;
}

float getSlope(Position *source, Position *target) {
    return ((float)(target->y - source->y))/(target->x - source->x);
}

void enableTrace() {
    trace = 1;
}

void disableTrace() {
    trace = 0;
}

int isTraceEnabled() {
    return trace == 1;
}

int isTraceDisabled() {
    return !isTraceEnabled();
}

void moveToPosition(int x2, int y2) {
    static int x1 = 0;
    static int y1 = 0;

    // Esto lo puse porque si no estaba habilitado el trace, se dejaba sin borrar una posicion anterior...
    if (isTraceDisabled()) {
        clearSymbolXY(x1, y1);
    }

    if (x1 != x2 || y1 != y2) { // Este "if" lo puse por un bug que ví....luego te lo cuento, Bruno...
        if (abs(x1-x2) >= abs(y1-y2)) {
            moveToPositionByX(x1, y1, x2, y2);
        } else {
            moveToPositionByY(x1, y1, x2, y2);
        }
    }

    drawSymbolXY(x2, y2); // Esto lo puse porque si no estaba habilitado el trace, no mostraba nada...

    x1 = x2;
    y1 = y2;
}

void moveToPositionByX(int x1, int y1, int x2, int y2) {
    float slope = ((float)(y2 - y1)) / (x2 - x1);
    int sign = (x1 > x2) ? -1 : 1;
    for(int x = x1; x * sign <= x2 * sign; x+=sign) {
        int y = slope * (x - x1) + y1;
        drawSymbolXY(x, y);

        pause();
        if (isTraceDisabled()) {
            clearSymbolXY(x, y);
        }
    }
}

void moveToPositionByY(int x1, int y1, int x2, int y2) {
    float slope = ((float)(x2 - x1)) / (y2 - y1);
    int sign = (y1 > y2) ? -1 : 1;
    for(int y = y1; y * sign <= y2 * sign; y+=sign) {
        int x = slope * (y - y1) + x1;
        drawSymbolXY(x, y);
        pause();
        if (isTraceDisabled()) {
            clearSymbolXY(x, y);
        }
    }
}






