#include <stdio.h>
#include <math.h>

struct Punto {
    double x;
    double y;
};

double distancia(struct Punto p1, struct Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double calcularAngulo(struct Punto p1, struct Punto p2, struct Punto p3) {
    double a = distancia(p2, p3);
    double b = distancia(p1, p3);
    double c = distancia(p1, p2);

    return acos((a * a + b * b - c * c) / (2 * a * b)) * (180.0 / M_PI);
}

int main() {

    struct Punto v1, v2, v3;
    printf("Ingrese las coordenadas del primer vértice (x y): ");
    scanf("%lf %lf", &v1.x, &v1.y);
    printf("Ingrese las coordenadas del segundo vértice (x y): ");
    scanf("%lf %lf", &v2.x, &v2.y);
    printf("Ingrese las coordenadas del tercer vértice (x y): ");
    scanf("%lf %lf", &v3.x, &v3.y);


    double angulo1 = calcularAngulo(v1, v2, v3);
    double angulo2 = calcularAngulo(v2, v1, v3);
    double angulo3 = calcularAngulo(v3, v1, v2);


    double s = (distancia(v1, v2) + distancia(v2, v3) + distancia(v3, v1)) / 2.0;
    double area = sqrt(s * (s - distancia(v1, v2)) * (s - distancia(v2, v3)) * (s - distancia(v3, v1)));


    struct Punto centroCirculoInscrito;
    centroCirculoInscrito.x = (v1.x + v2.x + v3.x) / 3.0;
    centroCirculoInscrito.y = (v1.y + v2.y + v3.y) / 3.0;


    double D = 2.0 * (v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y));
    struct Punto centroCirculoCircunscrito;
    centroCirculoCircunscrito.x = ((v1.x * v1.x + v1.y * v1.y) * (v2.y - v3.y) + (v2.x * v2.x + v2.y * v2.y) * (v3.y - v1.y) + (v3.x * v3.x + v3.y * v3.y) * (v1.y - v2.y)) / D;
    centroCirculoCircunscrito.y = ((v1.x * v1.x + v1.y * v1.y) * (v3.x - v2.x) + (v2.x * v2.x + v2.y * v2.y) * (v1.x - v3.x) + (v3.x * v3.x + v3.y * v3.y) * (v2.x - v1.x)) / D;

    // CORREGIR EL RESULTADO DA MAL
    struct Punto ortocentro;
    ortocentro.x = (sqrt(v1.x) * (v2.y - v3.y) + sqrt(v2.x) * (v3.y - v1.y) + sqrt(v3.x) * (v1.y - v2.y) +
                    (v1.x * (v2.x - v3.x) + v2.x * (v3.x - v1.x) + v3.x * (v1.x - v2.x)) *
                        (v1.y * (v2.x + v3.x) + v2.y * (v3.x - v1.x) + v3.y * (v1.x - v2.x))) /
                   D;
    ortocentro.y = (sqrt(v1.y) * (v2.x - v3.x) + sqrt(v2.y) * (v3.x - v1.x) + sqrt(v3.y) * (v1.x - v2.x) +
                    (v1.x * (v2.x - v3.x) + v2.x * (v3.x - v1.x) + v3.x * (v1.x - v2.x)) *
                        (v1.y * (v2.x + v3.x) + v2.y * (v3.x - v1.x) + v3.y * (v1.x - v2.x))) /
                   D;

    struct Punto baricentro;
    baricentro.x = (v1.x + v2.x + v3.x) / 3.0;
    baricentro.y = (v1.y + v2.y + v3.y) / 3.0;


    printf("Ángulo 1: %.2lf grados\n", angulo1);
    printf("Ángulo 2: %.2lf grados\n", angulo2);
    printf("Ángulo 3: %.2lf grados\n", angulo3);
    printf("Área del triángulo: %.2lf unidades cuadradas\n", area);
    printf("Centro del círculo inscrito: (%.2lf, %.2lf)\n", centroCirculoInscrito.x, centroCirculoInscrito.y);
    printf("Centro del círculo circunscrito: (%.2lf, %.2lf)\n", centroCirculoCircunscrito.x, centroCirculoCircunscrito.y);
    printf("Ortocentro: (%.2lf, %.2lf)\n", ortocentro.x, ortocentro.y);
    printf("Baricentro: (%.2lf, %.2lf)\n", baricentro.x, baricentro.y);

    return 0;
}
