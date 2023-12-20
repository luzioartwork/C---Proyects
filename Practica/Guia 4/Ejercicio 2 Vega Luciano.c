#include <stdio.h>

int main() {
    FILE *archivoEntrada, *archivoSalida;
    char caracter;


    archivoEntrada = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos.txt", "r");


    if (archivoEntrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }


    archivoSalida = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos_bk.txt", "w");


    if (archivoSalida == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(archivoEntrada);
        return 1;
    }


    while ((caracter = fgetc(archivoEntrada)) != EOF) {
        fputc(caracter, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
