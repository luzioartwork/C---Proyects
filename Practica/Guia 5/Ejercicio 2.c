#include <stdio.h>

int main() {
    float a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    printf("Ingrese los coeficientes de la primera ecuacion (a1, b1, c1, d1): ");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    printf("Ingrese los coeficientes de la segunda ecuacion (a2, b2, c2, d2): ");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    printf("Ingrese los coeficientes de la tercera ecuacion (a3, b3, c3, d3): ");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);
    float det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);

    if (det == 0) {
        printf("El sistema no tiene una unica solucion.\n");
    } else {
        float x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
        float y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
        float z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;

        printf("La solucion del sistema es:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
        printf("z = %.2f\n", z);
    }

    return 0;
}
