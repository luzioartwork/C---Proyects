#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX_CARACTERES 100

void mostrarFrase(char *frase, int x) {

    COORD coord;
    coord.X = x;
    coord.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


    printf("%s", frase);
}

void deslizarFrase(char *frase, int repeticiones, int velocidad) {
    int longitud = strlen(frase);
    int limite = 40 - longitud;

    for (int r = 0; r < repeticiones; r++) {
        for (int x = 40; x >= limite; x--) {
            mostrarFrase(frase, x);
            Sleep(velocidad);
            system("cls");
        }
    }
}

int main() {
    char frase[MAX_CARACTERES];
    int sonido = 1;
    int repeticiones = 1;
    int velocidad = 100;

    int opcion;

    do {
        system("cls");
        printf("1) Ingresar la frase\n");
        printf("2) Activar/Desactivar sonido\n");
        printf("3) Ingresar la cantidad de Repeticiones (1-3)\n");
        printf("4) Velocidad (Lento - Rápido)\n");
        printf("5) Ejecutar programa\n");
        printf("6) Salir\n");

        printf("Ingrese la opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la frase (max %d caracteres): ", MAX_CARACTERES);
                scanf(" %[^\n]s", frase);
                break;
            case 2:
                sonido = 1 - sonido;
                printf("Sonido %s\n", sonido ? "Activado" : "Desactivado");
                break;
            case 3:
                printf("Ingrese la cantidad de repeticiones (1-3): ");
                scanf("%d", &repeticiones);
                repeticiones = (repeticiones < 1) ? 1 : ((repeticiones > 3) ? 3 : repeticiones);
                break;
            case 4:
                printf("Velocidad (Lento - 1 a Rápido - 5): ");
                scanf("%d", &velocidad);
                velocidad = (velocidad < 1) ? 1 : ((velocidad > 5) ? 5 : velocidad);
                velocidad *= 100;
                break;
            case 5:
                deslizarFrase(frase, repeticiones, velocidad);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

        if (opcion != 6) {
            printf("Presione una tecla para continuar...");
            getch();
        }

    } while (opcion != 6);

    return 0;
}
