#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo* siguiente;
};


struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}


struct Nodo* insertarPrimero(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = cabeza;
    return nuevoNodo;
}


struct Nodo* insertarSegundo(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if (cabeza == NULL) {
        return nuevoNodo;
    }

    struct Nodo* segundoNodo = cabeza->siguiente;
    cabeza->siguiente = nuevoNodo;
    nuevoNodo->siguiente = segundoNodo;
    return cabeza;
}


void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    printf("Contenido de la lista:\n");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


void mostrarPromedio(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía. No se puede calcular el promedio.\n");
        return;
    }

    int suma = 0;
    int contador = 0;
    struct Nodo* actual = cabeza;

    while (actual != NULL) {
        suma += actual->dato;
        contador++;
        actual = actual->siguiente;
    }

    float promedio = (float)suma / contador;
    printf("Promedio de la lista: %.2f\n", promedio);
}


int encontrarPosicion(struct Nodo* cabeza, int numero) {
    int posicion = 1;
    struct Nodo* actual = cabeza;

    while (actual != NULL) {
        if (actual->dato == numero) {
            return posicion;
        }

        actual = actual->siguiente;
        posicion++;
    }

    return -1;
}


struct Nodo* eliminarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    return NULL;
}

int main() {
    struct Nodo* cabeza = NULL;
    int opcion, dato, numero, posicion;

    do {

        printf("\nMenu:\n");
        printf("1. Insertar primero\n");
        printf("2. Insertar segundo\n");
        printf("3. Mostrar lista\n");
        printf("4. Calcular y mostrar el promedio de la lista\n");
        printf("5. Encontrar posicion de un numero\n");
        printf("6. Eliminar toda la lista\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero para insertar al principio: ");
                scanf("%d", &dato);
                cabeza = insertarPrimero(cabeza, dato);
                break;
            case 2:
                printf("Ingrese un numero para insertar en segunda posicion: ");
                scanf("%d", &dato);
                cabeza = insertarSegundo(cabeza, dato);
                break;
            case 3:
                mostrarLista(cabeza);
                break;
            case 4:
                mostrarPromedio(cabeza);
                break;
            case 5:
                printf("Ingrese un numero a buscar: ");
                scanf("%d", &numero);
                posicion = encontrarPosicion(cabeza, numero);
                if (posicion != -1) {
                    printf("El nymero %d se encuentra en la posicion %d de la lista.\n", numero, posicion);
                } else {
                    printf("El numero %d no se encuentra en la lista.\n", numero);
                }
                break;
            case 6:
                cabeza = eliminarLista(cabeza);
                printf("Lista eliminada.\n");
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 7);

    return 0;
}
