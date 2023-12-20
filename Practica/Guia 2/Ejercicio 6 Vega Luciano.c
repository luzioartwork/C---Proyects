#include <stdio.h>
#include <stdlib.h>

struct Medicion {
    int numero;
    int *v1;
    int *v2;
    int *v3;
};

void cargarMedicion(struct Medicion *medicion) {
    printf("Ingrese el numero de medicion: ");
    scanf("%d", &medicion->numero);

    medicion->v1 = (int *)malloc(sizeof(int));
    medicion->v2 = (int *)malloc(sizeof(int));
    medicion->v3 = (int *)malloc(sizeof(int));

    printf("Ingrese el primer valor: ");
    scanf("%d", medicion->v1);
    printf("Ingrese el segundo valor: ");
    scanf("%d", medicion->v2);
    printf("Ingrese el tercer valor: ");
    scanf("%d", medicion->v3);
}

void mostrarMedicion(struct Medicion *medicion) {
    printf("Numero de medicion: %d\n", medicion->numero);
    printf("V1: %d, V2: %d, V3: %d\n", *(medicion->v1), *(medicion->v2), *(medicion->v3));
}

int main() {

    struct Medicion x;
    cargarMedicion(&x);
    mostrarMedicion(&x);

    struct Medicion z;
    cargarMedicion(&z);
    mostrarMedicion(&z);

    x.v1 = z.v1;
    x.v2 = z.v2;
    x.v3 = z.v3;

    printf("Valores vinculados a travez de punteros:\n");
    mostrarMedicion(&x);

    struct Medicion *z_dinamico = (struct Medicion *)malloc(sizeof(struct Medicion));
    cargarMedicion(z_dinamico);
    mostrarMedicion(z_dinamico);

    x.v1 = z_dinamico->v1;
    x.v2 = z_dinamico->v2;
    x.v3 = z_dinamico->v3;


    printf("Valores vinculados a través de punteros (z_dinamico):\n");
    mostrarMedicion(&x);

    free(z_dinamico->v1);
    free(z_dinamico->v2);
    free(z_dinamico->v3);
    free(z_dinamico);

    return 0;
}
