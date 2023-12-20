#include <stdio.h>

int main() {
    double distancia, tiempo_horas, tiempo_minutos, tiempo_segundos;

    printf("Ingrese la distancia en metros: ");
    scanf("%lf", &distancia);


    printf("Ingrese el tiempo en horas minutos segundos  (separados por espacios): ");
    scanf("%lf %lf %lf", &tiempo_horas, &tiempo_minutos, &tiempo_segundos);

    double tiempo_total_segundos = tiempo_horas * 3600 + tiempo_minutos * 60 + tiempo_segundos  / 1000.0;
    double velocidad_promedio_kmh = (distancia / 1000.0) / (tiempo_total_segundos / 3600.0);
    double segundos_por_kilometro = 1 / velocidad_promedio_kmh * 3600;


    printf("Velocidad promedio: %.2lf km/h\n", velocidad_promedio_kmh);
    printf("Tiempo necesario para recorrer un kilómetro: %.2lf segundos\n", segundos_por_kilometro);

    return 0;
}
