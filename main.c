#include <stdio.h>
#include <windows.h>
#include "consola.h"
#include "shapes.h"
#include "animations.h"

int main() {

    enableTrace();
    setSymbol(0xDB);
    bounce();

    return 0;

}

/*
void logDebug(int x, int y) {
    gotoxy(getScreenWidth()/2,getScreenHeight()/2);
    printf("(%d,%d)", x, y);
    FILE *f = fopen("log.txt", "a");
    fprintf(f, "(%d,%d) ", x, y);
    fclose(f);
}
*/

