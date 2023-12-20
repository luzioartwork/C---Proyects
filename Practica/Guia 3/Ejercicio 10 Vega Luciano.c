#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trabajo {
    char nombreArchivo[50];
    int usuario;
    struct Trabajo* siguiente;
};

void insertarTrabajo(struct Trabajo** lista, char nombreArchivo[], int usuario) {
    struct Trabajo* nuevoTrabajo = (struct Trabajo*)malloc(sizeof(struct Trabajo));
    strcpy(nuevoTrabajo->nombreArchivo, nombreArchivo);
    nuevoTrabajo->usuario = usuario;
    nuevoTrabajo->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoTrabajo;
    } else {
        struct Trabajo* actual = *lista;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoTrabajo;
    }
}

int trabajosPendientesUsuario(struct Trabajo* lista, int usuario) {
    int trabajosPendientes = 0;
    while (lista != NULL) {
        if (lista->usuario == usuario) {
            trabajosPendientes++;
        }
        lista = lista->siguiente;
    }
    return trabajosPendientes;
}

void obtenerYEliminarTrabajo(struct Trabajo** lista, char nombreArchivo[], int* usuario) {
    if (*lista != NULL) {
        struct Trabajo* temp = *lista;
        strcpy(nombreArchivo, temp->nombreArchivo);
        *usuario = temp->usuario;
        *lista = temp->siguiente;
        free(temp);
    } else {

        nombreArchivo[0] = '\0';
        *usuario = -1;
    }
}

int cantidadTrabajosEsperando(struct Trabajo* lista) {
    int cantidad = 0;
    while (lista != NULL) {
        cantidad++;
        lista = lista->siguiente;
    }
    return cantidad;
}

int main() {
    struct Trabajo* listaTrabajos = NULL;


    insertarTrabajo(&listaTrabajos, "Archivo1.txt", 1);
    insertarTrabajo(&listaTrabajos, "Archivo2.txt", 2);
    insertarTrabajo(&listaTrabajos, "Archivo3.txt", 1);

    printf("Trabajos pendientes para el usuario 1: %d\n", trabajosPendientesUsuario(listaTrabajos, 1));

    char archivo[50];
    int usuario;
    obtenerYEliminarTrabajo(&listaTrabajos, archivo, &usuario);
    printf("Trabajo obtenido: %s, Usuario: %d\n", archivo, usuario);

    printf("Cantidad de trabajos esperando: %d\n", cantidadTrabajosEsperando(listaTrabajos));

    return 0;
}
