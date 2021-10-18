#include<stdio.h>
#include "consola.h"
#include "shapes.h"

int main() {
    while (!kbhit()){
        mostrar();
    }

}
//mostrar puntos
 int mostrar() {
    srand(time(NULL));
    hideCursor();
    int height = getHeight();
    int width = getWidth()-1;
    Point points[width];
    int colors[width];
    for(int i = 0; i<width; i++) {
        points[i].x = i;
        points[i].y = getRandom(0, height);
        points[i].symbol = '*';
        colors[i] = getRandom(1,15);

    }

//mostrar animación
    int flag;

    do {
        flag = 0;
        for (int i = 0; i<width; i++) {
            if (points[i].y<height) {
                clearPoint(points[i]);
                points[i].y++;
                drawPoint(points[i]);
                flag = 1;
            }
            setColor(colors[i]);
            drawPoint(points[i]);
        }
         usleep(1000);
    } while(!kbhit() && flag);
}

/*int main() {

    while(1) {
        showMatrixEffect();
    }

}

int showMatrixEffect() {
    srand(time(NULL));
    hideCursor();
    int height = getHeight();
    int width = getWidth()-1;
    Point points[width];
    int colors[width];

    //Inicializamos puntos y colores
    for(int i = 0; i<width; i++) {
        /*
        Point * point = &points[i];
        point->x = i;
        point->y = getRandom(0, height);
        point->symbol = '*';
        drawPoint(*point);
        */
        /*points[i].x = i;
        points[i].y = getRandom(0, height);
        points[i].symbol = getRandom('0', '1');
        do {
            colors[i] = getRandom(0,2);
        } while (colors[i] == 1);

    }

    //Efecto de bajada de puntos
    int flag;

    do {
        flag = 0;
        for(int i = 0; i<width; i++) {
            if(points[i].y < height) {
                //clearPoint(points[i]);
                points[i].y++;
                //drawPoint(points[i]);
                flag = 1;
            }

            setColor(colors[i]);
            drawPoint(points[i]);
        }
        usleep(1000);
    } while(flag);

    //getch();

}





int main2() {
    srand(time(NULL));
    for(int i = 0; i<100; i++) {
        Point pointA;
        pointA.x = getRandom(0, getWidth());
        pointA.y = getRandom(0, getHeight());
        pointA.symbol = '*';
        setColor(getRandom(0, 15));
        drawPoint(pointA);
    }
}


/*int main () {

    srand(time(NULL));

    do {
        jugarPiedraPapelOTijera();
    } while (seguirJugando());

}*/


/*
int main() {
	//gotoxyText(45,8,"Nice to meet you!");
	//gotoxyChar(0,0,'*');
	int ch;

    while ((ch = _getch()) != 27)
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d", _getch ());
        printf("\n");
    }

    printf("ESC %d\n", ch);
    return;

    //_kbhit();
    hidecursor();
    int width = getWidth();
    int height = getHeight();
    int cx = width/2;
    int cy = height/2;
	for(int x = -cx; x<=cx; x++) {
        textcolor(x);
        int y = x*0.1;
        gotoxyChar(x+cx, cy-y, 'O');
        usleep(10000);
        //gotoxyChar(x+cx, cy-y, ' ');

	}

	return 0;
}
*/


//Primer prototipo: Personaje (caracter) se mueve por la pantalla por cada vez que se toca una flecha
//Con ESC se termina el juego.
