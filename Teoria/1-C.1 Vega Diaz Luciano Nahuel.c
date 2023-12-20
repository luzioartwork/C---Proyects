#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char cadena[100];
    int vocales[5] = {0}; // Inicializar a cero
    int i, longitud;

    printf("Ingresa una cadena: ");
    fgets(cadena, 100, stdin);
    longitud = strlen(cadena);

    // Contar las repeticiones de cada vocal
    for (i = 0; i < longitud; i++) {
        char letra = tolower(cadena[i]);
        if (letra == 'a') {
            vocales[0]++;
        } else if (letra == 'e') {
            vocales[1]++;
        } else if (letra == 'i') {
            vocales[2]++;
        } else if (letra == 'o') {
            vocales[3]++;
        } else if (letra == 'u') {
            vocales[4]++;
        }
    }

    // Imprimir el número de veces que se ha introducido cada vocal
    printf("Número de veces que se ha introducido cada vocal:\n");
    printf("A: %d\n", vocales[0]);
    printf("E: %d\n", vocales[1]);
    printf("I: %d\n", vocales[2]);
    printf("O: %d\n", vocales[3]);
    printf("U: %d\n", vocales[4]);

    // Convertir la cadena a mayúscula
    for (i = 0; i < longitud; i++) {
        cadena[i] = toupper(cadena[i]);
    }
    printf("Cadena en mayúscula: %s", cadena);

    // Eliminar los espacios en blanco
    char cadena_sin_espacios[100];
    int j = 0;
    for (i = 0; i < longitud; i++) {
        if (cadena[i] != ' ') {
            cadena_sin_espacios[j] = cadena[i];
            j++;
        }
    }
    cadena_sin_espacios[j] = '\0';
    printf("Cadena sin espacios: %s", cadena_sin_espacios);

    return 0;
}


