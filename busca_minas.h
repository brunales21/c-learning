#ifndef BUSCA_MINAS_H_INCLUDED
#define BUSCA_MINAS_H_INCLUDED

int jugarBM();

int getTotalNearBombs(char *pboard, int rows, int cols, int x, int y);
int lose(char *b1, char *b2, int width, int height);
void uncover(int x, int y, char* b1, char* b2, int width, int height);
void showBoard(char *pboard, int rows, int cols);

#endif // BUSCA_MINAS_H_INCLUDED
