#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en la cola
struct Node {
    int data;
    struct Node* next;
};

// Definición de la estructura de la cola
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Función para inicializar una cola vacía
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Función para insertar un elemento en la cola
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Función para verificar si la cola está vacía
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Función para calcular la suma de dos colas y devolver una nueva cola
struct Queue* sumQueues(struct Queue* q1, struct Queue* q2) {
    struct Queue* resultQueue = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(resultQueue);

    while (!isEmpty(q1) && !isEmpty(q2)) {
        int sum = q1->front->data + q2->front->data;
        enqueue(resultQueue, sum);

        // Eliminar elementos de las colas originales
        struct Node* temp1 = q1->front;
        struct Node* temp2 = q2->front;
        q1->front = q1->front->next;
        q2->front = q2->front->next;
        free(temp1);
        free(temp2);
    }

    return resultQueue;
}

// Función para imprimir los elementos de una cola
void printQueue(struct Queue* q) {
    struct Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Función principal
int main() {
    struct Queue queue1, queue2;
    initializeQueue(&queue1);
    initializeQueue(&queue2);

    // Insertar elementos en las colas de ejemplo
    enqueue(&queue1, 1);
    enqueue(&queue1, 2);
    enqueue(&queue1, 3);

    enqueue(&queue2, 4);
    enqueue(&queue2, 5);
    enqueue(&queue2, 6);

    // Calcular la suma de las colas
    struct Queue* resultQueue = sumQueues(&queue1, &queue2);

    // Imprimir las colas originales y la cola resultante
    printf("Queue 1: ");
    printQueue(&queue1);

    printf("Queue 2: ");
    printQueue(&queue2);

    printf("Sum Queue: ");
    printQueue(resultQueue);

    return 0;
}
