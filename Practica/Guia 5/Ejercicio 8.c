#include <stdio.h>
#include <math.h>

struct Punto {
    double x;
    double y;
};

struct Recta {
    double A;
    double B;
    double C;
};

double distancia(struct Punto p1, struct Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double distanciaPuntoRecta(struct Punto punto, struct Recta recta) {
    return fabs(recta.A * punto.x + recta.B * punto.y + recta.C) / sqrt(recta.A * recta.A + recta.B * recta.B);
}

struct Punto puntoMasCercano(struct Punto punto, struct Recta recta) {
    struct Punto puntoCercano;
    double factor = -(recta.A * punto.x + recta.B * punto.y + recta.C) / (recta.A * recta.A + recta.B * recta.B);
    puntoCercano.x = punto.x + factor * recta.A;
    puntoCercano.y = punto.y + factor * recta.B;
    return puntoCercano;
}

int main() {
    struct Punto punto;
    printf("Ingrese las coordenadas del punto (x y): ");
    scanf("%lf %lf", &punto.x, &punto.y);
    struct Recta recta;
    printf("Ingrese los coeficientes de la recta (A B C): ");
    scanf("%lf %lf %lf", &recta.A, &recta.B, &recta.C);
    double DistanciaPuntoRecta = distanciaPuntoRecta(punto, recta);
    printf("Distancia del punto a la recta: %.2lf unidades\n", DistanciaPuntoRecta);
    struct Punto puntoCercano = puntoMasCercano(punto, recta);
    printf("Punto de la recta más cercano al punto dado: (%.2lf, %.2lf)\n", puntoCercano.x, puntoCercano.y);

    return 0;
}

