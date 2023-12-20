#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en la lista
struct Node {
    int data;
    struct Node* next;
};

// Función para insertar un elemento en una lista ordenada
void insertInOrder(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && value > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Función para imprimir los elementos de una lista
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función para combinar dos listas ordenadas en una tercera lista ordenada
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL || list2 != NULL) {
        if (list1 == NULL) {
            insertInOrder(&result, list2->data);
            list2 = list2->next;
        } else if (list2 == NULL) {
            insertInOrder(&result, list1->data);
            list1 = list1->next;
        } else {
            if (list1->data < list2->data) {
                insertInOrder(&result, list1->data);
                list1 = list1->next;
            } else {
                insertInOrder(&result, list2->data);
                list2 = list2->next;
            }
        }
    }

    return result;
}

// Función principal
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Cargar las dos listas ordenadas de mayor a menor
    insertInOrder(&list1, 10);
    insertInOrder(&list1, 8);
    insertInOrder(&list1, 5);

    insertInOrder(&list2, 9);
    insertInOrder(&list2, 7);
    insertInOrder(&list2, 3);

    // Imprimir las dos listas originales
    printf("Lista 1: ");
    printList(list1);

    printf("Lista 2: ");
    printList(list2);

    // Obtener la tercera lista con la unión de las dos anteriores
    struct Node* mergedList = mergeLists(list1, list2);

    // Imprimir la tercera lista ordenada de menor a mayor
    printf("Lista fusionada: ");
    printList(mergedList);

    // Liberar memoria al finalizar el programa
    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }

    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
