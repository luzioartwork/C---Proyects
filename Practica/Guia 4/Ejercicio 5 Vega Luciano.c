#include <stdio.h>

int main() {
    FILE *archivoBinario;
    int numero;


    archivoBinario = fopen("E:\\universidad\\Trabajos\\13- Informatica 2\\TP\\datos_b1.bin", "rb");

    if (archivoBinario == NULL) {
        perror("Error al abrir el archivo binario");
        return 1;
    }

    while (fread(&numero, sizeof(int), 1, archivoBinario) == 1) {
        printf("%d\n", numero);
    }

    fclose(archivoBinario);

    return 0;
}
