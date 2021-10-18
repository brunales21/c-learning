#define VARIOS_H_INCLUDED
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
int carlos ();
int ejWrite ();

/*typedef struct {
    char nombre[30];
    char apellido[30];
    char paisNacimiento[30];
    char liga[20];
    char club[30];
    char posicion[10];
    int media;
    int disparo;
    int regate;
    int pase;
    int ritmo;
    int defensa;
    int fisico;
} Jugador;

//void imprimir_datos(struct jugador *j);
void imprimir_datos(Jugador *j);

#endif // VARIOS_H_INCLUDED
*/