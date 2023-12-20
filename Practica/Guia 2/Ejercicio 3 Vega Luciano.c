#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 5

struct Producto {
    char descripcion[50];
    int cantidad;
    float precio;
};

void cargarProducto(struct Producto productos[], int codigo) {
    printf("Ingrese la descripción del producto %d: ", codigo);
    scanf("%s", productos[codigo].descripcion);

    printf("Ingrese la cantidad del producto %d: ", codigo);
    scanf("%d", &productos[codigo].cantidad);

    printf("Ingrese el precio del producto %d: ", codigo);
    scanf("%f", &productos[codigo].precio);
}

int main() {
    struct Producto productos[MAX_PRODUCTOS];


    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        cargarProducto(productos, i);
    }

    int maxStockCodigo = 0;
    for (int i = 1; i < MAX_PRODUCTOS; i++) {
        if (productos[i].cantidad > productos[maxStockCodigo].cantidad) {
            maxStockCodigo = i;
        }
    }
    printf("a) Código del producto con más stock: %d\n", maxStockCodigo);


    int maxDescCodigo = 0;
    for (int i = 1; i < MAX_PRODUCTOS; i++) {
        if (strlen(productos[i].descripcion) > strlen(productos[maxDescCodigo].descripcion)) {
            maxDescCodigo = i;
        }
    }
    printf("b) Código del producto con descripción más extensa: %d\n", maxDescCodigo);


    int maxPrecioCantidadCodigo = 0;
    float maxPrecioCantidad = productos[0].precio * productos[0].cantidad;
    for (int i = 1; i < MAX_PRODUCTOS; i++) {
        float precioCantidadActual = productos[i].precio * productos[i].cantidad;
        if (precioCantidadActual > maxPrecioCantidad) {
            maxPrecioCantidad = precioCantidadActual;
            maxPrecioCantidadCodigo = i;
        }
    }
    printf("c) Descripción del producto con mayor precio x cantidad: %s\n", productos[maxPrecioCantidadCodigo].descripcion);

    return 0;
}
