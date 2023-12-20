#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int numLineas = 24;
    for (int i = 0; i < numLineas; i++) {
        int numEspacios = rand() % 78 + 1;

        for (int j = 0; j < numEspacios; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}
