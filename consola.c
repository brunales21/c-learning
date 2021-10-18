#include<windows.h>

void hideCursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int getWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x,int y) {
	COORD p;// Definir la variable de estructura p
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);// Obtener el identificador de función actual
	p.X=x;p.Y=y;// Transfiere la posición de movimiento objetivo del cursor a la estructura
	SetConsoleCursorPosition(handle,p);// Mueve el cursor
}

void gotoxyChar(int x, int y, char c) {
    gotoxy(x, y);
    printf("%c", c);
}

void gotoxyText(int x, int y, char * text) {
    gotoxy(x, y);
    printf("%s", text);
}

