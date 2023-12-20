#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición de la estructura de un nodo en la pila
struct Node {
    char data;
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
bool isEmpty(struct Stack* s) {
    return (s->top == NULL);
}

// Función para insertar un elemento en la pila
void push(struct Stack* s, char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Función para eliminar y obtener el elemento superior de la pila
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("La pila está vacía.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = s->top;
    char value = temp->data;
    s->top = temp->next;
    free(temp);

    return value;
}

// Función para invertir un string utilizando una pila
void reverseString(char* str) {
    struct Stack charStack;
    initializeStack(&charStack);

    // Push cada carácter en la pila
    for (int i = 0; str[i] != '\0'; ++i) {
        push(&charStack, str[i]);
    }

    // Pop cada carácter de la pila para invertir el string
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = pop(&charStack);
    }
}

// Función para verificar si una cadena está balanceada
bool isBalanced(char* str) {
    struct Stack charStack;
    initializeStack(&charStack);

    // Verificar el equilibrio de la cadena
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(&charStack, str[i]);
        } else if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
            if (isEmpty(&charStack)) {
                return false;  // No hay abertura correspondiente
            }

            char topChar = pop(&charStack);
            if ((str[i] == '}' && topChar != '{') ||
                (str[i] == ']' && topChar != '[') ||
                (str[i] == ')' && topChar != '(')) {
                return false;  // No hay coincidencia entre abertura y cierre
            }
        }
    }

    return isEmpty(&charStack);  // La pila debe estar vacía al final
}

// Función principal
int main() {
    // Parte A: Invertir un string
    char str1[] = "Hola, mundo!";
    printf("String original: %s\n", str1);
    reverseString(str1);
    printf("String invertido: %s\n\n", str1);
    char str2[] = "{[()()]}";
       printf("String original: %s\n", str2);
    printf("La cadena \"%s\" está balanceada: %s\n", str2, isBalanced(str2) ? "true" : "false");



    return 0;
}

