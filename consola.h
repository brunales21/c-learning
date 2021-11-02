#ifndef CONSOLA_H_INCLUDED
#define CONSOLA_H_INCLUDED

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75

static int _pause = 0;

int isKbUntouched();
void hideCursor();
int getScreenWidth();
int getScreenHeight();
void setColor(int color);
void gotoxy(int x,int y);
void gotoxyChar(int x, int y, char c);
void gotoxyText(int x, int y, char * text);

void setPause(int pause);
int getPause();
void pause();

#endif // CONSOLA_H_INCLUDED
