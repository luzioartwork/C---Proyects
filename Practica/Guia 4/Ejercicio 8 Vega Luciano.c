#include <stdio.h>

void encriptar(FILE *fuente, FILE *destino) {
    int caracter;


    while ((caracter = fgetc(fuente)) != EOF) {
        // Al encriptar cambiamos por su valor ASCII
        fprintf(destino, "%d ", caracter);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s archivo_fuente archivo_destino\n", argv[0]);
        return 1;
    }

    FILE *fuente = fopen(argv[1], "r");
    if (fuente == NULL) {
        perror("Error al abrir el archivo fuente");
        return 1;
    }

    FILE *destino = fopen(argv[2], "w");
    if (destino == NULL) {
        perror("Error al abrir el archivo destino");
        fclose(fuente);
        return 1;
    }


    encriptar(fuente, destino);
    fclose(fuente);
    fclose(destino);

    printf("Encriptacion completada.\n");

    return 0;
}
