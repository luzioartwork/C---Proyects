#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int numeroFila;
    float promedio;
    struct Nodo* siguiente;
};

struct Nodo* inicializarLista() {
    return NULL;
}

void insertarAlFinal(struct Nodo** lista, int numeroFila, float promedio) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->numeroFila = numeroFila;
    nuevoNodo->promedio = promedio;
    nuevoNodo->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        struct Nodo* actual = *lista;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarLista(struct Nodo* lista) {
    struct Nodo* actual = lista;
    while (actual != NULL) {
        printf("Numero de fila: %d, Promedio: %.2f\n", actual->numeroFila, actual->promedio);
        actual = actual->siguiente;
    }
}

int main() {
    int n;

    printf("Ingrese el tamaño de la matriz cuadrada (n x n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Ingrese un valor de n mayor a 0.\n");
        return EXIT_FAILURE;
    }

    int matriz[n][n];

    // Ingresar valores en la matriz
    for (int i = 0; i < n; i++) {
        printf("Ingrese los valores de la fila %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcular el promedio de cada fila e insertar en la lista
    struct Nodo* lista = inicializarLista();
    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < n; j++) {
            suma += matriz[i][j];
        }
        float promedio = suma / n;
        insertarAlFinal(&lista, i + 1, promedio);
    }

    // Mostrar la lista con el número de fila y el promedio
    mostrarLista(lista);

    return 0;
}

