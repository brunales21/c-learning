void play() {

    int from = 1;
    int to = 100;

    char jugar = 's';

    while (jugar == 's' || jugar == 'S') {
        int x = getRandom(from, to);
        printf("Ya elegí un número entre %d y %d, a ver si lo adivinas pronto...\n\n", from, to);

        int jugando = 1;
        int intentos = 0;

        while (jugando) {
            intentos++;
            printf("\nElige un número: ");
            int seleccion;
            scanf("%d", &seleccion);

            if (seleccion == -1) {
                return;
            }

            if (seleccion > x) {
                printf("Uuuuyyy... te pasaste!\n");
            } else if (seleccion < x) {
                printf("Uuuuyyy... te quedaste corto!\n");
            } else {
                printf("Biiieeeenn! Acertaste en %d intentos!!!\n", intentos);
                if (intentos<3) {
                    printf("Bastante rápido! Genial!\n");
                } else if (intentos >= 3 && intentos < 8) {
                    printf("No estuvo mal pero podrías hacerlo mejor!\n");
                } else {
                    printf("Peor no puede ser, ya era hora de que adivinaras!\n");
                }
                jugando = 0;
            }
        }

        printf("Fin de la partida.\n\n");

    }

}

/*void ordenaLetras(char texto[], char aux) {
    int len = length(texto);
    int flag;
    do {
        flag = 0;
        for(int i = 0; i < len-1; i++) {
            if (texto[i] > texto[i+1]) {
                char aux = texto[i];
                texto[i] = texto [i+1];
                texto[i+1] = aux;
                flag = 1;
            }
        }
    } while (flag);
}
*/
