#include <stdio.h>
#include <stdlib.h>

struct Registro {
    int ubicacion;
    int valor;
};

void ordenarArreglo(struct Registro *arreglo, int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = 0; j < longitud - 1; j++) {
            if (arreglo[j].valor > arreglo[j + 1].valor) {
                struct Registro temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *archivoEntrada, *archivoTextoSalida, *archivoBinarioSalida;

    archivoEntrada = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos1.txt", "r");
    if (archivoEntrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    int numLineas = 0;
    while (!feof(archivoEntrada)) {
        int ubicacion, valor;
        fscanf(archivoEntrada, "%d %d\n", &ubicacion, &valor);
        numLineas++;
    }
    rewind(archivoEntrada);

    struct Registro *arreglo = (struct Registro *)malloc(numLineas * sizeof(struct Registro));

    for (int i = 0; i < numLineas; i++) {
        fscanf(archivoEntrada, "%d %d\n", &arreglo[i].ubicacion, &arreglo[i].valor);
    }

    fclose(archivoEntrada);

    ordenarArreglo(arreglo, numLineas);

    archivoTextoSalida = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos2.txt", "w");
    if (archivoTextoSalida == NULL) {
        perror("Error al abrir el archivo de texto de salida");
        free(arreglo);
        return 1;
    }

    for (int i = 0; i < numLineas; i++) {
        fprintf(archivoTextoSalida, "%d %d\n", arreglo[i].ubicacion, arreglo[i].valor);
    }

    fclose(archivoTextoSalida);

    archivoBinarioSalida = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos3.bin", "wb");
    if (archivoBinarioSalida == NULL) {
        perror("Error al abrir el archivo binario de salida");
        free(arreglo);
        return 1;
    }

    fwrite(arreglo, sizeof(struct Registro), numLineas, archivoBinarioSalida);
    fclose(archivoBinarioSalida);
    free(arreglo);

    printf("Proceso completado con Exito.\n");

    return 0;
}
