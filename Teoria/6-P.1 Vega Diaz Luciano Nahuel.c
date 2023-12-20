#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en la pila
struct Node {
    int data;
    struct Node* next;
};

// Definición de la estructura de la pila
struct Stack {
    struct Node* top;
};

// Función para inicializar una pila vacía
void initializeStack(struct Stack* s) {
    s->top = NULL;
}

// Función para verificar si la pila está vacía
int isEmpty(struct Stack* s) {
    return (s->top == NULL);
}

// Función para insertar un elemento en la pila
void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Función para eliminar y obtener el elemento superior de la pila
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("La pila está vacía.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);

    return value;
}

// Función para ordenar una pila por tamaño de forma descendente
void sortStack(struct Stack* original, struct Stack* temp1, struct Stack* temp2) {
    while (!isEmpty(original)) {
        int current = pop(original);

        while (!isEmpty(temp1) && temp1->top->data < current) {
            push(original, pop(temp1));
        }

        push(temp1, current);
    }
}

// Función para mostrar los libros ordenados de forma inversa
void printSortedBooks(struct Stack* sortedStack) {
    printf("Libros ordenados de menor a mayor tamaño:\n");

    while (!isEmpty(sortedStack)) {
        printf("%d ", pop(sortedStack));
    }

    printf("\n");
}

// Función principal
int main() {
    struct Stack bookStack, tempStack1, tempStack2;
    initializeStack(&bookStack);
    initializeStack(&tempStack1);
    initializeStack(&tempStack2);

    // Insertar libros en la pila de ejemplo
    push(&bookStack, 30);
    push(&bookStack, 20);
    push(&bookStack, 40);
    push(&bookStack, 10);

    // Ordenar la pila de libros
    sortStack(&bookStack, &tempStack1, &tempStack2);

    // Mostrar los libros ordenados de forma inversa
    printSortedBooks(&tempStack1);

    return 0;
}
