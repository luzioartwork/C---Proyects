#include <stdio.h>
#include <math.h>

void calcularRaices(float a, float b, float c) {
    // Calcular el discriminante
    float discriminante = b * b - 4 * a * c;

    // Verificar el valor del discriminante
    if (discriminante > 0) {
        // Dos raíces reales distintas
        float raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        float raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Las raíces son %.2f y %.2f\n", raiz1, raiz2);
    } else if (discriminante == 0) {
        // Dos raíces reales iguales
        float raiz = -b / (2 * a);
        printf("La raíz doble es %.2f\n", raiz);
    } else {
        // Raíces complejas conjugadas
        float parteReal = -b / (2 * a);
        float parteImaginaria = sqrt(-discriminante) / (2 * a);
        printf("Las raíces son %.2f + %.2fi y %.2f - %.2fi\n", parteReal, parteImaginaria, parteReal, parteImaginaria);
    }
}

int main() {
    float a, b, c;

    // Solicitar los coeficientes a, b y c al usuario
    printf("Ingrese el coeficiente a: ");
    scanf("%f", &a);
    printf("Ingrese el coeficiente b: ");
    scanf("%f", &b);
    printf("Ingrese el coeficiente c: ");
    scanf("%f", &c);

    // Calcular y mostrar las raíces
    calcularRaices(a, b, c);

    return 0;
}
