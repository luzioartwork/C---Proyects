#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    int repeticiones[26] = {0}; // Inicializar a cero
    int repeticiones_dobles[26]={0};
    int letras_dobles = 0, vocales = 0;
    int i, longitud, palindromo = 1; // 1 = Verdadero, 0 = Falso

    printf("Ingresa una palabra: ");
    scanf("%s", palabra);

    longitud = strlen(palabra);

    // Contar las repeticiones de cada letra
    for (i = 0; i < longitud; i++) {
        int letra_index = palabra[i] - 'a';
        repeticiones[letra_index]++;
    }

    // Revisar si todas las letras son diferentes
    int diferentes = 1;
    for (i = 0; i < 26; i++) {
        if (repeticiones[i] > 1) {
            diferentes = 0;
            break;
        }
    }
    if (diferentes) {
        printf("Todas las letras son diferentes\n");
    }

    // Revisar si todas las letras se repiten dos veces
    int dobles = 1;
    for (i = 0; i < 26; i++) {
        if (repeticiones[i] != 2 && repeticiones[i] != 0) {
            dobles = 0;
            break;
        }
    }
    if (dobles) {
        printf("Todas las letras se repiten dos veces\n");
    }

    // Revisar si tiene dos letras dobles
    for (i = 0; i < longitud - 1; i++) {
        if (palabra[i] == palabra[i+1]) {
            repeticiones_dobles[i] = 1;
            i++; // Saltar la letra repetida
        }
    }
    
    
    
    for (i = 0; i < 26; i++) {
        if (repeticiones_dobles[i] == 1) {
            letras_dobles++;
        }
    }
    if (letras_dobles == 2) {
        printf("La palabra tiene dos letras dobles\n");
    }

    // Revisar si la palabra posee las 5 vocales
    for (i = 0; i < longitud; i++) {
        char letra = palabra[i];
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            vocales++;
        }
    }
    if (vocales == 5) {
        printf("La palabra tiene las 5 vocales\n");
    }

    // Revisar si la palabra es un palíndromo
    for (i = 0; i < longitud/2; i++) {
        if (palabra[i] != palabra[longitud-i-1]) {
            palindromo = 0;
            break;
        }
    }
    if (palindromo) {
        printf("La palabra es un palíndromo\n");
    }

    // Imprimir la cantidad de repeticiones de cada letra
    printf("Cantidad de repeticiones de cada letra:\n");
    for (i = 0; i < 26; i++) {
        if (repeticiones[i] > 0) {
            printf("%c: %d\n", 'a' + i, repeticiones[i]);
        }
    }

    return 0;
}

