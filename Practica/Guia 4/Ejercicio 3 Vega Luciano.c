#include <stdio.h>

int main() {
    FILE *archivoEntrada, *archivoSalida;
    int numero;

    archivoEntrada = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos.txt", "r");

    if (archivoEntrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    archivoSalida = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos_t1.txt", "w");

    if (archivoSalida == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(archivoEntrada);
        return 1;
    }

    while (fscanf(archivoEntrada, "%d", &numero) == 1) {
        fprintf(archivoSalida, "%d %d\n", numero, numero * numero);
    }


    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
