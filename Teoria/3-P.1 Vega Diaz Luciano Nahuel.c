#include <stdio.h>
#include <stdlib.h>
#define n 10
int main()
{
    int vector[n] = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 } ;int i;
    int* pvector;
      printf("El vector es:\n");
    for(i=0;i<n;i++){
            pvector=*(vector + i);
          printf(" | %d | ",pvector);
    }
      printf("\n Sus posiciones de memoria son: \n");
    for(i=0;i<n;i++){
            pvector=&vector[i];
          printf(" |%d| ",pvector);
    }
return 0;
}

