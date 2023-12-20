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

void apilar(struct Nodo** pila, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

int desapilar(struct Nodo** pila) {
    if (*pila == NULL) {
        printf("La pila esta vacía.\n");
        exit(EXIT_FAILURE);
    }

    int datoDesapilado = (*pila)->dato;
    struct Nodo* nodoAEliminar = *pila;
    *pila = (*pila)->siguiente;
    free(nodoAEliminar);

    return datoDesapilado;
}

void mostrarPila(struct Nodo* pila) {
    struct Nodo* actual = pila;
    printf("Contenido de la pila:\n");
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

int main() {
    struct Nodo* pila = NULL;
    int numero;

    do {
        printf("Ingrese un numero (ingrese 0 para finalizar): ");
        scanf("%d", &numero);

        if (numero != 0) {
            apilar(&pila, numero);
        }
    } while (numero != 0);

    mostrarPila(pila);

    printf("Eliminando la pila:\n");
    while (pila != NULL) {
        int datoDesapilado = desapilar(&pila);
        printf("Desapilado: %d\n", datoDesapilado);
    }

    return 0;
}
