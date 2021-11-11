#include <stdio.h>

static void _showNumber(int number, int base) {
    if (number >= base) {
        _showNumber(number / base, base);
        number = number % base;
    }
    printf("%c", (number < 10 ? 48 : 55) + number);
}

void showNumber(int number, int base) {
    _showNumber(number, base);
    printf("\n");
}

int mainShowNumber() {
    showNumber(360, 10);
    showNumber(360, 2);
    showNumber(360, 16);
    showNumber(360, 8);
    
    return 0;
}
