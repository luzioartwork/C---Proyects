#include <stdio.h>

int main() {
    FILE *archivo;
    char caracter;


    archivo = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        putchar(caracter);
    }

    fclose(archivo);

    return 0;
}
