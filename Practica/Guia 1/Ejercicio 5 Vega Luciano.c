#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura del nodo de la pila
struct Node {
    char data;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para insertar un nodo en la parte superior de la pila
void push(struct Node** top, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Función para eliminar el nodo en la parte superior de la pila
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("La pila está vacía.\n");
        return '\0';
    }
    struct Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Función para verificar si la pila está vacía
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Función para invertir un string usando una pila
void reverseString(char* str) {
    int len = strlen(str);
    struct Node* stack = NULL;

    // Llenar la pila con los caracteres del string
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // Reemplazar los caracteres del string con los de la pila
    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

// Función para verificar si los corchetes, llaves y paréntesis están balanceados correctamente
int check(const char* str) {
    struct Node* stack = NULL;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch == '{' || ch == '[' || ch == '(') {
            push(&stack, ch);
        } else if (ch == '}' || ch == ']' || ch == ')') {
            if (isEmpty(stack)) {
                return 0; // Cierra un símbolo sin un símbolo correspondiente de apertura previo
            }

            char topChar = pop(&stack);
            if ((ch == '}' && topChar != '{') || (ch == ']' && topChar != '[') || (ch == ')' && topChar != '(')) {
                return 0; // Cierra un símbolo diferente al que está en la parte superior de la pila
            }
        }
    }

    return isEmpty(stack) ? 1 : 0; // Si la pila está vacía, los símbolos están balanceados
}

int main() {
    char input[100];
    printf("Ingrese un string: ");
    fgets(input, sizeof(input), stdin);

    // Eliminar el salto de línea final de fgets
    input[strcspn(input, "\n")] = '\0';

    printf("String original: %s\n", input);

    reverseString(input);

    printf("String invertido: %s\n", input);

    int result = check(input);
    if (result) {
        printf("El string tiene símbolos balanceados.\n");
    } else {
        printf("El string NO tiene símbolos balanceados.\n");
    }

    return 0;
}