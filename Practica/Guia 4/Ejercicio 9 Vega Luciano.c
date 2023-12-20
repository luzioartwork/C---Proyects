#include <stdio.h>

void desencriptar(FILE *fuente, FILE *destino) {
    int valor_ascii;

    while (fscanf(fuente, "%d", &valor_ascii) != EOF) {
        // Desencriptar el valor ASCII
        fprintf(destino, "%c", valor_ascii);
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

    desencriptar(fuente, destino);
    fclose(fuente);
    fclose(destino);

    printf("Desencriptacion completada.\n");

    return 0;
}
