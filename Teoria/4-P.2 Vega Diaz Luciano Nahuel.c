#include <stdio.h>
#include <stdlib.h>
#define n 5
void copiarArray(int vector1[],int vector2[],int longitud);
int main()
{//Declaramos los vectores
    int i;
 int vector1[n]= {1,2,3,4,5};
 int vector2[n] ={7,7,7,7,7};
 //Mostramos los vectores
printf("El primer vector es: ");
for(i=0;i<n;i++){
          printf(" | %d | ",vector1[i]);
    }
printf("\n El segundo vector es: ");
for(i=0;i<n;i++){
          printf(" | %d | ",vector2[i]);
    }
    //Hacemos uso de la funcion
copiarArray(vector1,vector2,n);
printf("\n------------------------------------------------------------");
printf("\n------------|   SE COPIA VECTOR 1 EN EL 2  |----------------");
printf("\n------------------------------------------------------------");

//Mostramos de nuevo los vectores
printf("\n Ahora el primer vector es: ");
for(i=0;i<n;i++){
          printf(" | %d | ",vector1[i]);
    }
printf("\n y el segundo vector es: ");
for(i=0;i<n;i++){
          printf(" | %d | ",vector2[i]);
    }
return 0;
}
// definimos la funcion
void copiarArray(int vector1[],int  vector2[],int tamanio){
int *vectoraux[n];int i;
for(i=0;i<tamanio;i++){
        vectoraux[i]=*(vector1+i);
    vector2[i]=vectoraux[i];
}
vector2=vectoraux;

}