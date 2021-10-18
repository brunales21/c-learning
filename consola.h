#ifndef CONSOLA_H_INCLUDED
#define CONSOLA_H_INCLUDED

void hideCursor();
int getWidth();
int getHeight();
void setColor(int color);
void gotoxy(int x,int y);
void gotoxyChar(int x, int y, char c);
void gotoxyText(int x, int y, char * text);

#endif // CONSOLA_H_INCLUDED
