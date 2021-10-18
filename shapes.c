#include <stdio.h>
#include "consola.h"
#include "shapes.h"

void drawPoint(Point point) {
    gotoxy(point.x, point.y);
    printf("%c", point.symbol);
}

void clearPoint(Point point) {
    gotoxy(point.x, point.y);
    printf(" ");
}
