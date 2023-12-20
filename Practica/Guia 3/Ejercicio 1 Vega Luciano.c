#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

struct Nodo* insertarAlFrente(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabeza;
    return nuevoNodo;
}

void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    struct Nodo* cabeza = NULL;

    for (int i = 0; i < 4; i++) {
        int valor;
        printf("Ingrese un valor para el nodo %d: ", i + 1);
        scanf("%d", &valor);
        cabeza = insertarAlFrente(cabeza, valor);
    }

    printf("Lista antes de eliminar:\n");
    mostrarLista(cabeza);

    liberarLista(cabeza);

    return 0;
}

