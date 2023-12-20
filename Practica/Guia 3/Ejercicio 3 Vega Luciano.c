#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo* siguiente;
};


struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}


struct Nodo* insertarPrimero(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = cabeza;
    return nuevoNodo;
}


struct Nodo* insertarUltimo(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if (cabeza == NULL) {
        return nuevoNodo;
    }

    struct Nodo* actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    return cabeza;
}


void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    printf("Contenido de la lista:\n");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


struct Nodo* eliminarPrimero(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return NULL;
    }

    struct Nodo* nuevoCabeza = cabeza->siguiente;
    free(cabeza);
    return nuevoCabeza;
}


struct Nodo* eliminarUltimo(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return NULL;
    }

    if (cabeza->siguiente == NULL) {
        free(cabeza);
        return NULL;
    }

    struct Nodo* actual = cabeza;
    while (actual->siguiente->siguiente != NULL) {
        actual = actual->siguiente;
    }

    free(actual->siguiente);
    actual->siguiente = NULL;
    return cabeza;
}


int main() {
    struct Nodo* cabeza = NULL;
    int opcion, dato;

    do {

        printf("\nMenu:\n");
        printf("1. Insertar primero\n");
        printf("2. Insertar ultimo\n");
        printf("3. Mostrar lista\n");
        printf("4. Eliminar primero\n");
        printf("5. Eliminar ultimo\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero para insertar al principio: ");
                scanf("%d", &dato);
                cabeza = insertarPrimero(cabeza, dato);
                break;
            case 2:
                printf("Ingrese un numero para insertar al final: ");
                scanf("%d", &dato);
                cabeza = insertarUltimo(cabeza, dato);
                break;
            case 3:
                mostrarLista(cabeza);
                break;
            case 4:
                cabeza = eliminarPrimero(cabeza);
                break;
            case 5:
                cabeza = eliminarUltimo(cabeza);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 6);


    while (cabeza != NULL) {
        cabeza = eliminarPrimero(cabeza);
    }

    return 0;
}
