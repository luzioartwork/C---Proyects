#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
} Registro;

void agregarRegistro(FILE *archivo) {
    Registro nuevoRegistro;

    printf("Ingrese el nombre: ");
    scanf("%s", nuevoRegistro.nombre);

    printf("Ingrese la edad: ");
    scanf("%d", &nuevoRegistro.edad);


    fwrite(&nuevoRegistro, sizeof(Registro), 1, archivo);

    printf("Registro agregado correctamente.\n");
}

void visualizarRegistros(FILE *archivo) {
    Registro registroLeido;


    fseek(archivo, 0, SEEK_SET);

    printf("Registros almacenados:\n");


    while (fread(&registroLeido, sizeof(Registro), 1, archivo) == 1) {
        printf("Nombre: %s, Edad: %d\n", registroLeido.nombre, registroLeido.edad);
    }
}

int main() {
    FILE *archivo;
    int opcion;

    archivo = fopen("datos.dat", "ab+");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    do {

        printf("\nMenú:\n");
        printf("1. Agregar Registro\n");
        printf("2. Visualizar Registros\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarRegistro(archivo);
                break;
            case 2:
                visualizarRegistros(archivo);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    fclose(archivo);

    return 0;
}
