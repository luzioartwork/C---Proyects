#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Producto {
    char descripcion[50];
    int codigo;
    int cantidad;
    float precio;
};

void insertarProducto(struct Producto stock[], int *numProductos) {
    if (*numProductos >= 100) {
        printf("Error: La capacidad del stock esta llena.\n");
        return;
    }

    struct Producto nuevoProducto;
    printf("Ingrese la descripción del producto: ");
    scanf("%s", nuevoProducto.descripcion);
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &nuevoProducto.codigo);
    printf("Ingrese la cantidad en stock: ");
    scanf("%d", &nuevoProducto.cantidad);
    printf("Ingrese el precio por unidad: ");
    scanf("%f", &nuevoProducto.precio);

    stock[*numProductos] = nuevoProducto;
    (*numProductos)++;
    printf("Producto agregado al stock.\n");
}


void registrarCompra(struct Producto stock[], int numProductos, int codigo, int cantidad) {
    for (int i = 0; i < numProductos; i++) {
        if (stock[i].codigo == codigo) {
            stock[i].cantidad += cantidad;
            printf("Compra registrada con exito.\n");
            return;
        }
    }

    printf("Error: Producto con codigo %d no encontrado.\n", codigo);
}


void registrarVenta(struct Producto stock[], int numProductos, int codigo, int cantidad) {
    for (int i = 0; i < numProductos; i++) {
        if (stock[i].codigo == codigo) {
            if (stock[i].cantidad >= cantidad) {
                stock[i].cantidad -= cantidad;
                printf("Venta registrada con exito.\n");
            } else {
                printf("Error: Stock insuficiente para realizar la venta.\n");
            }
            return;
        }
    }

    printf("Error: Producto con codigo %d no encontrado.\n", codigo);
}

int productosSinStock(struct Producto stock[], int numProductos) {
    int sinStock = 0;
    for (int i = 0; i < numProductos; i++) {
        if (stock[i].cantidad == 0) {
            sinStock++;
        }
    }
    return sinStock;
}

void modificarPrecio(struct Producto stock[], int numProductos, int codigo, float nuevoPrecio) {
    for (int i = 0; i < numProductos; i++) {
        if (stock[i].codigo == codigo) {
            stock[i].precio = nuevoPrecio;
            printf("Precio modificado con exito.\n");
            return;
        }
    }

    printf("Error: Producto con codigo %d no encontrado.\n", codigo);
}


void eliminarProducto(struct Producto stock[], int *numProductos, int codigo) {
    for (int i = 0; i < *numProductos; i++) {
        if (stock[i].codigo == codigo) {

            for (int j = i; j < *numProductos - 1; j++) {
                stock[j] = stock[j + 1];
            }

            (*numProductos)--;
            printf("Producto eliminado con exito.\n");
            return;
        }
    }

    printf("Error: Producto con codigo %d no encontrado.\n", codigo);
}

int main() {
    struct Producto stock[100];
    int numProductos = 0;
    int opcion, codigo, cantidad;
    float nuevoPrecio;

    do {

        printf("\nMenu:\n");
        printf("1. Insercion de producto en stock\n");
        printf("2. Registrar compra de materiales\n");
        printf("3. Registrar venta de materiales\n");
        printf("4. Cantidad de productos sin stock\n");
        printf("5. Modificar precio de un producto\n");
        printf("6. Eliminar producto\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                insertarProducto(stock, &numProductos);
                break;
            case 2:
                printf("Ingrese el codigo del producto: ");
                scanf("%d", &codigo);
                printf("Ingrese la cantidad a comprar: ");
                scanf("%d", &cantidad);
                registrarCompra(stock, numProductos, codigo, cantidad);
                break;
            case 3:
                printf("Ingrese el codigo del producto: ");
                scanf("%d", &codigo);
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                registrarVenta(stock, numProductos, codigo, cantidad);
                break;
            case 4:
                printf("La cantidad de productos sin stock es: %d\n", productosSinStock(stock, numProductos));
                break;
            case 5:
                printf("Ingrese el codigo del producto: ");
                scanf("%d", &codigo);
                printf("Ingrese el nuevo precio: ");
                scanf("%f", &nuevoPrecio);
                modificarPrecio(stock, numProductos, codigo, nuevoPrecio);
                break;
            case 6:
                printf("Ingrese el codigo del producto a eliminar: ");
                scanf("%d", &codigo);
                eliminarProducto(stock, &numProductos, codigo);
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 7);

    return 0;
}
