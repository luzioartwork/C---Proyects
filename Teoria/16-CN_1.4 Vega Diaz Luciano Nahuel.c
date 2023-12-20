#include <stdio.h>

int esPrimo(int numero) {
    if (numero <= 1) {
        return 0;  // No es primo
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  // No es primo
        }
    }

    return 1;  // Es primo
}

void imprimirPrimos(int limite) {
    printf("Números primos entre 2 y %d:\n", limite);

    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {
    int limite;

    printf("Ingrese el valor límite: ");
    scanf("%d", &limite);

    imprimirPrimos(limite);

    return 0;
}
