#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));


    int numeroAleatorio = rand() % 100 + 1;

    int intentosRestantes = 6;
    int intentoUsuario;

    printf("Adivina el numero entre 1 y 100. Tienes 6 oportunidades.\n");

    while (intentosRestantes > 0) {
        printf("Intento %d: ", 7 - intentosRestantes);
        scanf("%d", &intentoUsuario);


        if (intentoUsuario == numeroAleatorio) {
            printf("Adivinaste el número %d en %d intentos.\n", numeroAleatorio, 6 - intentosRestantes + 1);
            break;
        } else {
            // Decrementar el contador de intentos y proporcionar pistas
            intentosRestantes--;

            if (intentoUsuario < numeroAleatorio) {
                printf("El numero es mayor. ");
            } else {
                printf("El numero es menor. ");
            }

            printf("Intentos restantes: %d\n", intentosRestantes);

            if (intentosRestantes == 0) {
                printf("Te quedaste sin oportunidades. El número correcto era %d.\n", numeroAleatorio);
            }
        }
    }

    return 0;
}
