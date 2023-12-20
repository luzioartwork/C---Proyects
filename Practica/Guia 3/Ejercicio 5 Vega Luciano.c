#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int numeroMovil;
    int horas;
    int minutos;
    int segundos;
    struct Nodo* siguiente;
};

struct Nodo* crearNodo(int numeroMovil, int horas, int minutos, int segundos) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->numeroMovil = numeroMovil;
    nuevoNodo->horas = horas;
    nuevoNodo->minutos = minutos;
    nuevoNodo->segundos = segundos;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}


struct Nodo* insertarUltimo(struct Nodo* cabeza, int numeroMovil, int horas, int minutos, int segundos) {
    struct Nodo* nuevoNodo = crearNodo(numeroMovil, horas, minutos, segundos);
    if (cabeza == NULL) {
        return nuevoNodo;
    }

    struct Nodo* actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    return cabeza;
}


int movilMenosDemora(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return -1;
    }

    struct Nodo* actual = cabeza;
    int menorDemora = actual->horas * 3600 + actual->minutos * 60 + actual->segundos;
    int numeroMovilMenorDemora = actual->numeroMovil;

    while (actual != NULL) {
        int demoraActual = actual->horas * 3600 + actual->minutos * 60 + actual->segundos;
        if (demoraActual < menorDemora) {
            menorDemora = demoraActual;
            numeroMovilMenorDemora = actual->numeroMovil;
        }

        actual = actual->siguiente;
    }

    return numeroMovilMenorDemora;
}


struct Nodo* eliminarMovil(struct Nodo* cabeza, int numeroMovil) {
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return NULL;
    }

    if (cabeza->numeroMovil == numeroMovil) {
        struct Nodo* nuevoCabeza = cabeza->siguiente;
        free(cabeza);
        return nuevoCabeza;
    }

    struct Nodo* actual = cabeza;
    while (actual->siguiente != NULL && actual->siguiente->numeroMovil != numeroMovil) {
        actual = actual->siguiente;
    }

    if (actual->siguiente == NULL) {
        printf("No se encontro el movil con el numero %d en la lista.\n", numeroMovil);
        return cabeza;
    }

    struct Nodo* movilAEliminar = actual->siguiente;
    actual->siguiente = movilAEliminar->siguiente;
    free(movilAEliminar);
    printf("Se elimino el móvil con el numero %d de la lista.\n", numeroMovil);
    return cabeza;
}


void mostrarMoviles(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    struct Nodo* actual = cabeza;
    printf("Moviles y sus tiempos:\n");
    while (actual != NULL) {
        printf("Numero Movil: %d, Tiempo: %02d:%02d:%02d\n", actual->numeroMovil, actual->horas, actual->minutos, actual->segundos);
        actual = actual->siguiente;
    }
}


int main() {
    struct Nodo* cabeza = NULL;
    int opcion, numeroMovil, horas, minutos, segundos;

    do {

        printf("\nMenu:\n");
        printf("1. Insercion al ultimo\n");
        printf("2. Retornar el numero de movil que menos se demoro\n");
        printf("3. Eliminar un movil pasado por parametro\n");
        printf("4. Mostrar todos los moviles con sus tiempos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

       switch (opcion) {
            case 1:
                printf("Ingrese el numero del movil: ");
                scanf("%d", &numeroMovil);
                printf("Ingrese las horas: ");
                scanf("%d", &horas);
                printf("Ingrese los minutos: ");
                scanf("%d", &minutos);
                printf("Ingrese los segundos: ");
                scanf("%d", &segundos);
                cabeza = insertarUltimo(cabeza, numeroMovil, horas, minutos, segundos);
                break;
            case 2:
                numeroMovil = movilMenosDemora(cabeza);
                if (numeroMovil != -1) {
                    printf("El numero de movil que menos se demoro es: %d\n", numeroMovil);
                }
                break;
            case 3:
                printf("Ingrese el numero del movil a eliminar: ");
                scanf("%d", &numeroMovil);
                cabeza = eliminarMovil(cabeza, numeroMovil);
                break;
            case 4:
                mostrarMoviles(cabeza);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
