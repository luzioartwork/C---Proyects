#include <stdio.h>

struct Medicion {
    char nombre[31];
    int numeroMedicion;
    float valor;
};

int main() {
    FILE *archivo;
    struct Medicion medicion;

    archivo = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\mediciones.dat", "rb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while (fread(&medicion, sizeof(struct Medicion), 1, archivo) == 1) {
        printf("Nombre de la prueba: %s\n", medicion.nombre);
        printf("Número de medicion: %d\n", medicion.numeroMedicion);
        printf("Valor de la medicion: %.2f\n", medicion.valor);
        printf("\n");
    }

    fclose(archivo);

    return 0;
}
