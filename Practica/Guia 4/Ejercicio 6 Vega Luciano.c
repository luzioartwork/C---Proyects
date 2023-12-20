#include <stdio.h>

struct Medicion {
    char nombre[31];
    int numeroMedicion;
    float valor;
};

int main() {
    FILE *archivo;
    struct Medicion mediciones[20];

    archivo = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\mediciones.dat", "wb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        printf("Ingrese el nombre de la prueba (hasta 30 caracteres): ");
        scanf("%30s", mediciones[i].nombre);

        printf("Ingrese el número de medición: ");
        scanf("%d", &mediciones[i].numeroMedicion);

        printf("Ingrese el valor de la medición: ");
        scanf("%f", &mediciones[i].valor);

        fwrite(&mediciones[i], sizeof(struct Medicion), 1, archivo);
    }


    fclose(archivo);

    return 0;
}
