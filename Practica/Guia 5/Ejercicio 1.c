#include <stdio.h>

int main() {
    float a1, b1, c1, a2, b2, c2;
    printf("Ingrese los coeficientes de la primera ecuacion (a1, b1, c1): ");
    scanf("%f %f %f", &a1, &b1, &c1);
    printf("Ingrese los coeficientes de la segunda ecuacion (a2, b2, c2): ");
    scanf("%f %f %f", &a2, &b2, &c2);
    float determinante = a1 * b2 - a2 * b1;
    if (determinante == 0) {
        printf("El sistema no tiene una unica solucion.\n");
    } else {
        float x = (c1 * b2 - c2 * b1) / determinante;
        float y = (a1 * c2 - a2 * c1) / determinante;
        printf("La solucion del sistema es:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
    }

    return 0;
}

