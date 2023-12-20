#include <stdio.h>
#include <math.h>

int main() {
    double grados, minutos, segundos;

    printf("Ingrese el angulo en grados, minutos y segundos (ejemplo: 45 30 0): ");
    scanf("%lf %lf %lf", &grados, &minutos, &segundos);

    double angulo_en_grados = grados + (minutos / 60) + (segundos / 3600);
    double angulo_en_radianes = angulo_en_grados * M_PI / 180.0;
    double coseno_del_angulo = cos(angulo_en_radianes);


    printf("El coseno del angulo %.2lf grados es: %.4lf\n", angulo_en_grados, coseno_del_angulo);

    return 0;
}
