#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d;
    printf("Ingrese los coeficientes de la ecuacion cubica (a, b, c, d): ");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    //formulas sacadas del libro porque no me las acordaba
    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
    double discriminante = p * p * p / 27 + q * q / 4;
    double raiz_discriminante = sqrt(fabs(discriminante));
    double angulo = acos(-q / (2 * raiz_discriminante));
    double raiz_cubica_discriminante = cbrt(raiz_discriminante);
    double x1 = -2 * raiz_cubica_discriminante * cos(angulo / 3) - b / (3 * a);
    double x2 = -2 * raiz_cubica_discriminante * cos((angulo + 2 * M_PI) / 3) - b / (3 * a);
    double x3 = -2 * raiz_cubica_discriminante * cos((angulo - 2 * M_PI) / 3) - b / (3 * a);

    printf("Las soluciones de la ecuacion cubica son:\n");
    printf("x1 = %.4f\n", x1);
    printf("x2 = %.4f\n", x2);
    printf("x3 = %.4f\n", x3);

    return 0;
}
