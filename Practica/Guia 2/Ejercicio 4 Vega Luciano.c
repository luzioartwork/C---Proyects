#include <stdio.h>
#include <math.h>

struct Punto {
    int X;
    int Y;
};

int main() {
    const int MAX_PUNTOS = 5;
    struct Punto puntos[MAX_PUNTOS];


    for (int i = 0; i < MAX_PUNTOS; i++) {
        printf("Ingrese la coordenada X del punto %d: ", i + 1);
        scanf("%d", &puntos[i].X);

        printf("Ingrese la coordenada Y del punto %d: ", i + 1);
        scanf("%d", &puntos[i].Y);
    }


    int puntosEnII = 0;
    for (int i = 0; i < MAX_PUNTOS; i++) {
        if (puntos[i].X < 0 && puntos[i].Y > 0) {
            puntosEnII++;
        }
    }
    printf("a) Puntos en el II cuadrante: %d\n", puntosEnII);


    int puntosEnOrigen = 0;
    for (int i = 0; i < MAX_PUNTOS; i++) {
        if (puntos[i].X == 0 && puntos[i].Y == 0) {
            puntosEnOrigen = 1;
            break;
        }
    }
    printf("b) %s puntos sobre el origen (0,0)\n", puntosEnOrigen ? "Hay" : "No hay");


    int puntoPosicion4 = 3;
    double distanciaAlOrigen = sqrt(pow(puntos[puntoPosicion4].X, 2) + pow(puntos[puntoPosicion4].Y, 2));
    printf("c) Distancia al origen del punto en la posicion 4: %.2f\n", distanciaAlOrigen);

    return 0;
}
