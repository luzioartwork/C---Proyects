#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

int contarElementos(struct Nodo *lista) {
    int contador = 0;
    struct Nodo *actual = lista;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

void imprimirListaTexto(struct Nodo *lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        perror("Error al abrir el archivo de texto");
        exit(EXIT_FAILURE);
    }

    struct Nodo *actual = lista;

    while (actual != NULL) {
        fprintf(archivo, "%d\n", actual->dato);
        actual = actual->siguiente;
    }

    fclose(archivo);
}

void imprimirListaBinario(struct Nodo *lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo binario");
        exit(EXIT_FAILURE);
    }

    struct Nodo *actual = lista;

    while (actual != NULL) {
        fwrite(&(actual->dato), sizeof(int), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}

void eliminarDesdeArchivo(struct Nodo **lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo de eliminación");
        exit(EXIT_FAILURE);
    }

    int totalElementos = 0;
    int encontrados = 0;

    while (!feof(archivo)) {
        int dato;
        fscanf(archivo, "%d", &dato);
        totalElementos++;

        struct Nodo *actual = *lista;
        struct Nodo *anterior = NULL;

        while (actual != NULL) {
            if (actual->dato == dato) {
                encontrados++;
                if (anterior == NULL) {
                    *lista = actual->siguiente;
                    free(actual);
                    actual = *lista;
                } else {
                    anterior->siguiente = actual->siguiente;
                    free(actual);
                    actual = anterior->siguiente;
                }
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
    }

    fclose(archivo);

    FILE *informe = fopen("informe.txt", "w");

    if (informe == NULL) {
        perror("Error al abrir el archivo de informe");
        exit(EXIT_FAILURE);
    }

    fprintf(informe, "Total de elementos en el archivo de eliminación: %d\n", totalElementos);
    fprintf(informe, "Elementos encontrados y eliminados: %d\n", encontrados);
    fprintf(informe, "Elementos no encontrados en la lista: %d\n", totalElementos - encontrados);

    fclose(informe);
}

int main() {
    struct Nodo *lista = NULL;
    FILE *archivoDatos = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos1.txt", "r");

    if (archivoDatos == NULL) {
        perror("Error al abrir el archivo datos1.txt");
        exit(EXIT_FAILURE);
    }

    while (!feof(archivoDatos)) {
        int dato;
        fscanf(archivoDatos, "%d", &dato);

        struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
        if (nuevoNodo == NULL) {
            perror("Error al asignar memoria para el nodo");
            exit(EXIT_FAILURE);
        }

        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = NULL;

        if (lista == NULL) {
            lista = nuevoNodo;
        } else {
            struct Nodo *actual = lista;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    fclose(archivoDatos);

    int totalElementos = contarElementos(lista);
    printf("Total de elementos en la lista: %d\n", totalElementos);

    FILE *archivoMitad1 = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\mitad1.txt", "w");

    if (archivoMitad1 == NULL) {
        perror("Error al abrir el archivo mitad1.txt");
        exit(EXIT_FAILURE);
    }

    int mitad = totalElementos / 2;
    struct Nodo *actual = lista;

    for (int i = 0; i < mitad; i++) {
        fprintf(archivoMitad1, "%d\n", actual->dato);
        actual = actual->siguiente;
    }

    fclose(archivoMitad1);


    FILE *archivoMitad2 = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\mitad2.txt", "wb");

    if (archivoMitad2 == NULL) {
        perror("Error al abrir el archivo mitad2.txt");
        exit(EXIT_FAILURE);
    }

    for (int i = mitad; i < totalElementos; i++) {
        fwrite(&(actual->dato), sizeof(int), 1, archivoMitad2);
        actual = actual->siguiente;
    }

    fclose(archivoMitad2);

    eliminarDesdeArchivo(&lista, "borrar.txt");

    while (lista != NULL) {
        struct Nodo *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }

    printf("Proceso completado con éxito.\n");

    return 0;
}

