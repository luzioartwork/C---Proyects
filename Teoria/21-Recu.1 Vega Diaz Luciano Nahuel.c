#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }

    intercambiar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void ordenar_rapido(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int indicePivote = particion(arr, bajo, alto);

        ordenar_rapido(arr, bajo, indicePivote - 1);
        ordenar_rapido(arr, indicePivote + 1, alto);
    }
}

void imprimirVector(int arr[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int vector[10] = {5, 2, 8, 1, 9, 3, 7, 6, 10, 4};
    int longitud = sizeof(vector) / sizeof(vector[0]);

    printf("Vector original: ");
    imprimirVector(vector, longitud);

    ordenar_rapido(vector, 0, longitud - 1);

    printf("Vector ordenado: ");
    imprimirVector(vector, longitud);

    return 0;
}
