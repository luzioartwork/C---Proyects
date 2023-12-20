#include <stdio.h>

struct Persona {
    int dni;
    double altura;
    int edad;
    char nombre[50];
};

int main() {
    struct Persona persona1;


    persona1.dni = 2102121;
    persona1.altura = 1.80;
    persona1.edad = 25;
    strcpy(persona1.nombre, "Nombre Apellido");


    printf("DNI: %d\n", persona1.dni);
    printf("Altura: %.2f\n", persona1.altura);
    printf("Edad: %d\n", persona1.edad);
    printf("Nombre: %s\n", persona1.nombre);

    return 0;
}

