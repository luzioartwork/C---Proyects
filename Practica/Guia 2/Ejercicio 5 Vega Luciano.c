#include <stdio.h>
#include <math.h>
struct Hora {
    int hh;
    int mm;
    int ss;
};

int obtenerSegundos(struct Hora *hora) {
    return hora->hh * 3600 + hora->mm * 60 + hora->ss;
}

void mostrarHora(struct Hora *hora) {
    printf("%02d:%02d:%02d\n", hora->hh, hora->mm, hora->ss);
}

int main() {
    int v[3];
    printf(" Ingrese la Hora : \n");
    scanf("%d",&v[0]);
    printf(" Ingrese los minutos:\n");
    scanf("%d",&v[1]);
    printf(" Ingrese los segundos:\n");
    scanf("%d",&v[2]);
    struct Hora a = {v[0], v[1], v[2]};

    printf(" Ingrese la Hora : \n");
    scanf("%d",&v[0]);
    printf(" Ingrese los minutos:\n");
    scanf("%d",&v[1]);
    printf(" Ingrese los segundos:\n");
    scanf("%d",&v[2]);
    struct Hora segunda = {v[0], v[1], v[2]};
    struct Hora *b = &segunda;

    printf("Hora a: ");
    mostrarHora(&a);
    printf("Hora b: ");
    mostrarHora(b);

    int diferenciaSegundos = sqrt( pow((obtenerSegundos(&a) - obtenerSegundos(b)),2));
    printf("Diferencia en segundos entre a y b: %d\n", diferenciaSegundos);

    struct Hora *c = &a;

    int diferenciaSegundosAC = sqrt( pow((obtenerSegundos(&a) - obtenerSegundos(c)),2));
    printf("Diferencia en segundos entre a y c: %d\n", diferenciaSegundosAC);

    return 0;
}

