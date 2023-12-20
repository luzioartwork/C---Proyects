#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Nodo {
    char caracter;
    struct Nodo* siguiente;
};

void insertarCaracter(char c, struct Nodo** lista) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->caracter = c;
    nuevoNodo->siguiente = NULL;

    if (*lista == NULL || c <= (*lista)->caracter) {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    } else {
        struct Nodo* actual = *lista;
        while (actual->siguiente != NULL && c > actual->siguiente->caracter) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

int contarPalabras(struct Nodo* lista) {
    int palabras = 0;
    while (lista != NULL) {
        if (isalpha(lista->caracter) && (lista->siguiente == NULL || !isalpha(lista->siguiente->caracter))) {
            palabras++;
        }
        lista = lista->siguiente;
    }
    return palabras;
}

int contarCaracteresPalabraMasLarga(struct Nodo* lista) {
    int caracteres = 0;
    int maxCaracteres = 0;
    while (lista != NULL) {
        if (isalpha(lista->caracter)) {
            caracteres++;
        } else {
            if (caracteres > maxCaracteres) {
                maxCaracteres = caracteres;
            }
            caracteres = 0;
        }
        lista = lista->siguiente;
    }
    return maxCaracteres;
}

void pasarPrimeraPalabraAVector(struct Nodo* lista, char vector[]) {
    int i = 0;
    while (lista != NULL && isalpha(lista->caracter)) {
        vector[i] = lista->caracter;
        lista = lista->siguiente;
        i++;
    }
    vector[i] = '\0';
}

void eliminarYMostrarPrimeraPalabra(struct Nodo** lista) {
    while (*lista != NULL && !isalpha((*lista)->caracter)) {
        struct Nodo* temp = *lista;
        *lista = (*lista)->siguiente;
        free(temp);
    }

    if (*lista != NULL) {
        struct Nodo* temp = *lista;
        while (temp != NULL && isalpha(temp->caracter)) {
            printf("%c", temp->caracter);
            struct Nodo* siguiente = temp->siguiente;
            free(temp);
            temp = siguiente;
        }
        *lista = temp;
        printf("\n");
    } else {
        printf("No hay palabras para mostrar.\n");
    }
}

void mostrarLista(struct Nodo* lista) {
    while (lista != NULL) {
        printf("%c ", lista->caracter);
        lista = lista->siguiente;
    }
    printf("\n");
}

int main() {
    struct Nodo* lista = NULL;
    char caracter;

    printf("Ingrese caracteres (terminar con '.'): ");
    while (1) {
        scanf(" %c", &caracter);
        if (caracter == '.') {
            break;
        }
        insertarCaracter(caracter, &lista);
    }

    printf("Cantidad de palabras: %d\n", contarPalabras(lista));
    printf("Cantidad de caracteres de la palabra mas larga: %d\n", contarCaracteresPalabraMasLarga(lista));

    char vector[100];
    pasarPrimeraPalabraAVector(lista, vector);
    printf("Primera palabra en un vector: %s\n", vector);

    printf("Eliminar y mostrar primera palabra:\n");
    eliminarYMostrarPrimeraPalabra(&lista);

    printf("Lista completa:\n");
    mostrarLista(lista);

    return 0;
}
