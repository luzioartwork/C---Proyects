#include <stdio.h>
#include <math.h>

int main() {
    double angulo_en_radianes;

    printf("Ingrese el angulo en radianes: ");
    scanf("%lf", &angulo_en_radianes);

    double angulo_en_grados = angulo_en_radianes * 180.0 / M_PI;

    int grados = (int)angulo_en_grados;
    double minutos_temporales = (angulo_en_grados - grados) * 60;
    int minutos = (int)minutos_temporales;
    double segundos = (minutos_temporales - minutos) * 60;

    printf("El angulo %.4lf radianes es equivalente a: %d grados %d minutos %.4lf segundos\n", angulo_en_radianes, grados, minutos, segundos);

    return 0;
}
