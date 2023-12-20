#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 10

typedef struct {
    char nombre[50];
    int edad;
    char numeroDocumento[15];
} Registro;

void agregarRegistro(FILE *archivo) {
    Registro nuevoRegistro;

    printf("Ingrese el nombre: ");
    scanf("%s", nuevoRegistro.nombre);

    printf("Ingrese la edad: ");
    scanf("%d", &nuevoRegistro.edad);

    printf("Ingrese el numero de documento: ");
    scanf("%s", nuevoRegistro.numeroDocumento);

    fwrite(&nuevoRegistro, sizeof(Registro), 1, archivo);

    printf("Registro agregado correctamente.\n");
}

void visualizarRegistros(FILE *archivo) {
    Registro registroLeido;


    fseek(archivo, 0, SEEK_SET);

    printf("Registros almacenados:\n");

    while (fread(&registroLeido, sizeof(Registro), 1, archivo) == 1) {
        printf("Nombre: %s, Edad: %d, Documento: %s\n", registroLeido.nombre, registroLeido.edad, registroLeido.numeroDocumento);
    }
}

void buscarYModificarRegistro(FILE *archivo) {
    char numeroDocumentoBusqueda[15];
    Registro registroLeido;

    printf("Ingrese el numero de documento a buscar: ");
    scanf("%s", numeroDocumentoBusqueda);

    fseek(archivo, 0, SEEK_SET);
    int encontrado = 0;
    while (fread(&registroLeido, sizeof(Registro), 1, archivo) == 1) {
        if (strcmp(registroLeido.numeroDocumento, numeroDocumentoBusqueda) == 0) {
            printf("Registro encontrado:\n");
            printf("Nombre: %s, Edad: %d, Documento: %s\n", registroLeido.nombre, registroLeido.edad, registroLeido.numeroDocumento);


            printf("Ingrese el nuevo nombre: ");
            scanf("%s", registroLeido.nombre);


            fseek(archivo, -sizeof(Registro), SEEK_CUR);
            fwrite(&registroLeido, sizeof(Registro), 1, archivo);

            encontrado = 1;
            printf("Registro modificado correctamente.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Registro no encontrado.\n");
    }
}

void pasarDiezPrimerosALista(FILE *archivo) {

    Registro lista[MAX_REGISTROS];
    int i = 0;


    fseek(archivo, 0, SEEK_SET);


    while (i < MAX_REGISTROS && fread(&lista[i], sizeof(Registro), 1, archivo) == 1) {
        i++;
    }

    printf("Diez primeros registros almacenados en la lista.\n");

    for (int j = 0; j < i; j++) {
        printf("Nombre: %s, Edad: %d, Documento: %s\n", lista[j].nombre, lista[j].edad, lista[j].numeroDocumento);
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
        printf("3. Buscar y Modificar Registro\n");
        printf("4. Pasar Diez Primeros a Lista\n");
        printf("5. Salir\n");
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
                buscarYModificarRegistro(archivo);
                break;
            case 4:
                pasarDiezPrimerosALista(archivo);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 5);

    fclose(archivo);

    return 0;
}
