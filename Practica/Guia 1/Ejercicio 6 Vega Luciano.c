#include <stdio.h>
#include <string.h>
#include <ctype.h>
void borrarDespuesDeEspacio(char *str) {
    char *espacio = strchr(str, ' ');
    if (espacio != NULL) {
        *espacio = '\0';
}
}

int main() {
    char nomyape[41];
    char nombre[21], apellido[21];
    char usuario[22];
    char var_binario[10], var_decimal[10];

    do {
        printf("Ingrese nombre y apellido (max 40 caracteres): ");
        gets(nomyape);
    } while (strlen(nomyape) > 40 || !isalnum(nomyape[0]));


    int longitud = strlen(nomyape);
    printf("a) Longitud del string: %d\n", longitud);


    itoa(longitud, var_binario, 2);
    printf("b) Longitud en base 2: %s\n", var_binario);


    itoa(longitud, var_decimal, 10);
    printf("c) Longitud en base 10: %s\n", var_decimal);


    for (int i = 0; nomyape[i] != '\0'; i++) {
        nomyape[i] = toupper(nomyape[i]);
    }
    printf("d) Cadena en mayúsculas: %s\n", nomyape);

    int flag=0;
    strcpy(nombre, nomyape);
    borrarDespuesDeEspacio(nombre);
    printf("e) Nombre: %s\n", nombre);


    strcpy(apellido, strchr(nomyape, ' ') + 1);
    printf("f) Apellido: %s\n", apellido);


    strncpy(usuario, nombre, 1);
    usuario[1] = '\0';
    strcat(usuario, apellido);
    printf("g) Usuario: %s\n", usuario);


    if (strcmp(nombre, apellido) == 0) {
        printf("h) El nombre es igual al apellido.\n");
    } else {
        printf("h) El nombre no es igual al apellido.\n");
    }


    int var_entera = atoi(var_decimal);
    printf("i) Valor convertido a entero: %d\n", var_entera);

    return 0;
}
