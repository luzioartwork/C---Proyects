#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define n 30
/*
Se desea almacenar una cadena de caracteres en un vector de n=30
elementos. La cadena será ingresada carácter a carácter, finalizando la carga con un *. Una vez
cargada determinar:
a) Cantidad de letras de la segunda palabra.
b) Promedio de vocales de la frase.
c) Cantidad de palabras de más de 5 caracteres.
*/
int ingreso();

void cant_letras_segunda(int tam_cadena);

void promedio_vocales(int tam_cadena);

void cant_palabras(int tam_cadena);


char cadena[n];

int main()
{
int tam_cadena;
tam_cadena = ingreso();

printf("Cadena: %s  tam: %d\n",cadena,tam_cadena);

cant_letras_segunda(tam_cadena);

promedio_vocales(tam_cadena);

cant_palabras(tam_cadena);

return 0;
}

int ingreso()
{
int i = 0, tam_cadena = 0, flag = 0;

while(flag != 1)
{
    printf("\nIngrese un caracter: ");
    gets(&cadena[i]);
    if(cadena[i] == '*')
    {
        flag = 1;
    }
    tam_cadena++;
    i++;
}
return tam_cadena;
}

void cant_letras_segunda(int tam_cadena)
{
int i, cont_letras = 0, flag = 0,espacio;

i=0;
while(flag != 1)
{
    if(cadena[i] == ' ')
    {
        espacio = i;
        flag = 1;
    }
    i++;
}
flag = 0;
i=espacio+1;

printf("\nLa segunda palabra es ");
while(flag != 1)
{
    if(cadena[i] == ' ' || cadena[i] == '*')
    {
        flag = 1;
    }
    else
    {
        printf("%c",cadena[i]);
        cont_letras++;
    }
    i++;
}
printf(" y tiene %d letras",cont_letras);
printf("\n");
return;
}

void promedio_vocales(int tam_cadena)
{
int j, cont_vocal = 0;
float prom_vocal, acum_vocal = 0;

for(j=0; j<tam_cadena ;j++)
{
    switch(cadena[j])
    {
        case 'a': acum_vocal = acum_vocal + cadena[j];
                  cont_vocal++;
        break;

        case 'e': acum_vocal = acum_vocal + cadena[j];
                  cont_vocal++;
        break;

        case 'i': acum_vocal = acum_vocal + cadena[j];
                  cont_vocal++;
        break;

        case 'o': acum_vocal = acum_vocal + cadena[j];
                  cont_vocal++;
        break;

        case 'u': acum_vocal = acum_vocal + cadena[j];
                  cont_vocal++;
        break;
    }
}
prom_vocal = acum_vocal / cont_vocal;
printf("\nEl promedio de las vocales de la cadena es %.3f",prom_vocal);
printf("\n");
}

void cant_palabras(int tam_cadena)
{
int i, cont_palabra = 0, cont_letras = 0;

for(i=0; i<tam_cadena ;i++)
{
    if(cadena[i] == ' ' || cadena[i] == '*')
    {
        cont_letras = 0;
    }
    else
    {
        cont_letras++;
        if(cont_letras == 6)
        {
            cont_palabra++;
        }
    }

}
printf("\nCantidad de palabras de mas de 5 letras = %d",cont_palabra);
printf("\n");
return;
}
