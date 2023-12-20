#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición de la estructura para los datos
struct ElectricalData {
    float resistance;
    float current;
    float voltage;
    float power;
    struct ElectricalData* next;
};

// Función para insertar un nuevo dato en la lista
void insertData(struct ElectricalData** head, float resistance, float current) {
    struct ElectricalData* newData = (struct ElectricalData*)malloc(sizeof(struct ElectricalData));
    newData->resistance = resistance;
    newData->current = current;
    newData->voltage = current * resistance;
    newData->power = pow(current, 2) * resistance;
    newData->next = *head;

    *head = newData;
}

// Función para imprimir la tabla y encontrar la potencia máxima y mínima
void printTable(struct ElectricalData* head) {
    float maxPower = -1.0; // Inicializar con un valor muy bajo
    float minPower = INFINITY; // Inicializar con un valor infinitamente alto

    printf("%-15s%-15s%-15s%-15s\n", "Resistencia", "Corriente", "Voltaje", "Potencia");

    while (head != NULL) {
        printf("%-15.2f%-15.2f%-15.2f%-15.2f\n", head->resistance, head->current, head->voltage, head->power);

        // Actualizar potencia máxima y mínima
        if (head->power > maxPower) {
            maxPower = head->power;
        }
        if (head->power < minPower) {
            minPower = head->power;
        }

        head = head->next;
    }

    printf("\nPotencia máxima: %.2f\n", maxPower);
    printf("Potencia mínima: %.2f\n", minPower);
}

// Función principal
int main() {
    struct ElectricalData* dataList = NULL;

    // Insertar datos de ejemplo
    insertData(&dataList, 10.0, 2.0);
    insertData(&dataList, 20.0, 1.5);
    insertData(&dataList, 15.0, 3.0);
    // Puedes seguir insertando más datos según sea necesario

    // Imprimir la tabla y mostrar potencia máxima y mínima
    printTable(dataList);

    // Liberar memoria al finalizar el programa
    while (dataList != NULL) {
        struct ElectricalData* temp = dataList;
        dataList = dataList->next;
        free(temp);
    }

    return 0;
}

