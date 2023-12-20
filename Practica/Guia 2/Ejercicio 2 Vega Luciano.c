#include <stdio.h>
#include <string.h>

struct Producto {
    int codigo;
    char descripcion[50];
    int cantidad;
    float precio_unitario;
};

int main() {
    struct Producto producto1;
    char string[50];

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &producto1.codigo);

    printf("Ingrese la descripcion del producto: ");
    scanf("%s", string);
    strcpy(producto1.descripcion, string);

    printf("Ingrese el stock del producto: ");
    scanf("%d", &producto1.cantidad);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto1.precio_unitario);

    float precio_venta = producto1.cantidad * producto1.precio_unitario;

    printf("Descripcion: %s\n", producto1.descripcion);
    printf("Precio de Venta: %.2f\n", precio_venta);

    return 0;
}
