#ifndef VARIOS_H_INCLUDED
#define VARIOS_H_INCLUDED

int seguirJugando();
int cuentaVocales(char texto[]);
int cuentaVocales2(char * texto);
int posicionLetra(char texto[], char letra);
int length(char texto[]);
void reverse(char texto[]);
int contadorPalabras(char texto[]);
void left(char texto[], int len, char target[]);
void right(char texto[], int len, char target[]);
void subString(char texto[], int ini, int fin, char target[]);
void subString2(char * texto, int  ini, int  fin, char * target);
void append(char s[], char t[]);
void append2(char * s, char * t);
void copiarInverso(char s[], char t[]);
void copiarInverso2(char * s, char * t);
void copiar(char s[], char t[], int maxLength);
void copiar2(char * s, char * t);
void copiar3(char * s, char * t);
int getRandom(int from, int to);
int cuentaLetrasDistintas(char texto[]);
void ordenaLetras(char texto[], int asc);
void ordenaLetrasAsc(char texto[]);
void ordenaLetrasDes(char texto[]);
int mainPlayAhorcado();
void playAhorcado();
int encuentraLetra(char texto[], char letras[]);
long getTimestamp();
int getInteger(char * texto, int min, int max);
char getDniLetter(int dniNum);
int getHighestInc(int * nums, int len);


#endif // VARIOS_H_INCLUDED

