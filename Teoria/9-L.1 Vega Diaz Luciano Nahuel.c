#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definición de la estructura de un estudiante
struct Student {
    char name[50];
    int enrollment;
    float grade;
    float deviation;
    struct Student* next;
};

// Función para insertar un estudiante en la lista ordenada por calificación
void insertStudent(struct Student** head, char name[], int enrollment, float grade) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->enrollment = enrollment;
    newStudent->grade = grade;
    newStudent->next = NULL;

    // Calcular desviación del promedio
    newStudent->deviation = grade - 0.0; // Cambia 0.0 por el promedio real al obtenerlo

    // Insertar en la lista ordenada
    if (*head == NULL || grade >= (*head)->grade) {
        newStudent->next = *head;
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL && grade < current->next->grade) {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }
}

// Función para calcular el promedio de las calificaciones
float calculateAverage(struct Student* head) {
    float sum = 0.0;
    int count = 0;

    while (head != NULL) {
        sum += head->grade;
        count++;
        head = head->next;
    }

    return (count > 0) ? (sum / count) : 0.0;
}
// Función para buscar un estudiante por su legajo
struct Student* findStudentByEnrollment(struct Student* head, int enrollment) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->enrollment == enrollment) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Si el estudiante no se encuentra
}

// Función para modificar los datos de un estudiante
void modifyStudentData(struct Student* student, char name[], float grade) {
    strcpy(student->name, name);
    student->grade = grade;
    // Recalcular desviación con el nuevo promedio
    student->deviation = grade - 0.0; // Cambia 0.0 por el promedio real al obtenerlo
}

// Función para eliminar un estudiante por su legajo
void deleteStudentByEnrollment(struct Student** head, int enrollment) {
    struct Student* current = *head;
    struct Student* prev = NULL;

    while (current != NULL && current->enrollment != enrollment) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Estudiante con legajo %d no encontrado.\n", enrollment);
        return;
    }

    if (prev == NULL) {
        // El estudiante a eliminar es el primer elemento
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Estudiante con legajo %d eliminado.\n", enrollment);
}

// Función principal
int main() {
    struct Student* students = NULL;

    // Introducir datos de estudiantes
    insertStudent(&students, "Juan Perez", 101, 85.5);
    insertStudent(&students, "Maria Rodriguez", 102, 92.0);
    insertStudent(&students, "Carlos Gomez", 103, 78.5);
    // Puedes seguir añadiendo más estudiantes según sea necesario

    // Calcular promedio de calificaciones
    float average = calculateAverage(students);

    // Imprimir información de estudiantes
    printf("Lista de estudiantes ordenada por calificación:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Nombre", "Legajo", "Calificación", "Desviación");

    struct Student* current = students;
    while (current != NULL) {
        printf("%-20s %-10d %-10.2f %-10.2f\n", current->name, current->enrollment, current->grade, current->deviation);
        current = current->next;
    }

    // Imprimir el promedio
    printf("\nPromedio de calificaciones: %.2f\n", average);

    return 0;
}

