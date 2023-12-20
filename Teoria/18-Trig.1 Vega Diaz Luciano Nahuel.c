#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846


double gradosARadianes(double grados) {
    return grados * (PI / 180.0);
}

int main() {

    double angulos[] = {30.0, 45.0, 60.0, 90.0};

    printf("angulo (grados)\tSeno\n");


    for (int i = 0; i < sizeof(angulos) / sizeof(angulos[0]); i++) {
        double anguloEnRadianes = gradosARadianes(angulos[i]);
        double seno = sin(anguloEnRadianes);

        printf("%.1f\t\t%.4f\n", angulos[i], seno);
    }

    return 0;
}

