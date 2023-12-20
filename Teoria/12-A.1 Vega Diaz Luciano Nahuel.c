#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALABRAS 100

typedef struct {
    int num_linea;
    int cant_palabras;
    int cant_signos;
} Registro;

int contarPalabras(char *linea) {
    int contador = 0;
    char *token = strtok(linea, " ");
    while (token != NULL) {
        contador++;
        token = strtok(NULL, " ");
    }
    return contador;
}

int contarSignos(char *linea) {
    int contador = 0;
    for (int i = 0; linea[i] != '\0'; i++) {
        if (ispunct(linea[i])) {
            contador++;
        }
    }
    return contador;
}

void procesarArchivo(const char *nombreArchivo) {
    FILE *archivoEntrada = fopen(nombreArchivo, "r");
    FILE *archivoSalida = fopen("contador.dat", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        perror("Error al abrir los archivos");
        exit(EXIT_FAILURE);
    }

    char linea[256];
    int num_linea = 1;

    while (fgets(linea, sizeof(linea), archivoEntrada) != NULL) {
        Registro registro;
        registro.num_linea = num_linea;
        registro.cant_palabras = contarPalabras(linea);
        registro.cant_signos = contarSignos(linea);

        fwrite(&registro, sizeof(Registro), 1, archivoSalida);
        num_linea++;
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

int main() {
    procesarArchivo("palabras.txt");
    printf("Conteo finalizado. Resultados guardados en contador.dat.\n");
    return 0;
}


