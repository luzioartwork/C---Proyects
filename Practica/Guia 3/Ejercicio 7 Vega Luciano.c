#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

struct Nodo* inicializarPila() {
    return NULL;
}

void push(struct Nodo** pila, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

int pop(struct Nodo** pila) {
    if (*pila == NULL) {
        printf("Error: la pila esta vacia.\n");
        exit(EXIT_FAILURE);
    }

    struct Nodo* temp = *pila;
    *pila = (*pila)->siguiente;
    int dato = temp->dato;
    free(temp);
    return dato;
}

void convertirABinario(int numero) {
    struct Nodo* pila = inicializarPila();

    while (numero > 0) {
        int residuo = numero % 2;
        push(&pila, residuo);
        numero = numero / 2;
    }

    printf("Representacion binaria: ");
    while (pila != NULL) {
        printf("%d", pop(&pila));
    }
    printf("\n");
}

int main() {
    int numero;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Error: Ingrese un numero entero no negativo.\n");
        return EXIT_FAILURE;
    }

    convertirABinario(numero);

    return 0;
}
