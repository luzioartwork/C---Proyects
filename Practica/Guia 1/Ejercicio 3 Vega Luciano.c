#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 50

/*
Crear un arreglo de cadena de caracteres de n=50 elementos,
ingresar la frase y controlar que no sobrepase la capacidad del arreglo, la frase finaliza con un
“punto”.
Al finalizar la frase imprimir la cantidad de caracteres, imprimir la frase en el orden
ingresado y luego en orden invertido.
Realizar la codificación en principio solo en la función
main().
Luego implementar el mismo programa anterior pero ahora empleando funciones
definidas fleer() , fimpr1() e fimpr2(). Utilizar en este las funciones de biblioteca gets(), strlen().
*/

char cadena[n];

void fleer();

void fimpr1();

void fimpr2();

int main()
{
int i=0,flag = 0, len, mitad_cadena;
char salida = '.', aux;

printf("Finalizar con un .(limite de caracteres %d)\n",n);

while(flag != 1){
    printf("\nIngrese la cadena: ");
    gets(&cadena[i]);

        if(cadena[i] == salida)
        {
            flag = 1;
        }
        if(i == n-1)
        {
            printf("\n----- Usted llego al limite de caracteres -----");
            flag = 1;
        }
        i++;

}
len = strlen(cadena);
printf("\nCantidad de caracteres en total: %d",len);
printf("\nCadena original: %s",cadena);

mitad_cadena = len/2;
for(i=0; i<mitad_cadena;i++)
{
    aux = cadena[i];
    cadena[i] = cadena[len - i - 1];
    cadena[len - i - 1] = aux;
}
printf("\nCadena invertida: %s\n",cadena);
printf("\n------------ APLICANDO FUNCIONES ------------");

fleer();
fimpr1();
fimpr2();
return 0;
}
void fleer()
{
   int i=0,flag = 0;

while(flag != 1){
printf("\nIngrese la cadena: ");
gets(&cadena[i]);

    if(cadena[i] == '.')
    {
        flag = 1;
    }
    if(i == n-1)
    {
        printf("\n----- Usted llego al limite de caracteres -----");
        flag = 1;
    }
    i++;

}
}

void fimpr1()
{
    int len;
    len = strlen(cadena);
    printf("\nCantidad de caracteres en total: %d",len);
    printf("\nCadena original: %s",cadena);
}

void fimpr2()
{
int i, len, mitad_cadena;
char aux;

len = strlen(cadena);
mitad_cadena = len/2;
for(i=0; i<mitad_cadena;i++)
{
    aux = cadena[i];
    cadena[i] = cadena[len - i - 1];
    cadena[len - i - 1] = aux;
}
printf("\nCadena invertida: %s",cadena);
}
