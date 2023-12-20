#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 20

/*
Se desea almacenar una cadena de caracteres en un vector de n=30
elementos. La cadena será ingresada carácter a carácter, finalizando la carga con un punto. Una
vez cargada determinar:

a) Cantidad de letras ingresadas (sin espacios).
b) Cantidad de letras “a”.
c) Cantidad de veces que se repite la sílaba “la”
d) Cantidad de palabras.
e) Determinar cuántas palabras empiezan con “s” o “m”.
f) Pasar la primera palabra a un vector auxiliar.
g) Mostrar la última palabra.
h) Mostrar la segunda palabra.
*/
char cadena[n];

int ingreso();

void cant_letras_a(int cont_tam);

void cant_silaba_la(int cont_tam);

void cant_palabras(int cont_tam);

void cant_pal_sm(int cont_tam);

void primera_palabra(int cont_tam);

void segunda_palabra();

void ultima_palabra(int cont_tam);

int main()
{
int cont_tam;

cont_tam = ingreso();

cant_letras_a(cont_tam);

cant_silaba_la(cont_tam);

cant_palabras(cont_tam);

cant_pal_sm(cont_tam);

primera_palabra(cont_tam);

segunda_palabra();

ultima_palabra(cont_tam);

return 0;
}

int ingreso()
{
int i = 0, flag = 0, cont_tam = 0;
char salida = '.';

    while(flag != 1)
    {

        printf("Ingrese un caracter: \n");
        gets(&cadena[i]);

        if(cadena[i] == salida)
        {
            cont_tam++;
            flag = 1;
        }
        cont_tam++;
        i++;
    }
return cont_tam;
}

void cant_letras_a(int cont_tam)
{
int i, cont_a = 0;

for(i=0; i<cont_tam ; i++)
{
    if(cadena[i] == 'a')
    {
        cont_a++;
    }
}
printf("\nCantidad de letras a en la palabra = %d\n",cont_a);
}

void cant_silaba_la(int cont_tam)
{
int i,cont_la = 0;
for(i=0; i<cont_tam-1 ; i++)
{
    if(cadena[i] == 'l' && cadena[i+1] == 'a')
    {
        cont_la++;
    }
}
printf("\nCantidad de silabas (la) en la palabra = %d\n",cont_la);
}
void cant_palabras(int cont_tam)
{
int i, cont_pal = 0;
    for(i=0; i<cont_tam-1 ; i++)
    {
        if(cadena[i] == ' ' || cadena[i] == '.')
        {
            cont_pal++;
        }
    }
printf("\nCantidad de palabras = %d\n",cont_pal);
}
void cant_pal_sm(int cont_tam)
{
int i, cont_letras = 0;
    for(i=0; i<cont_tam-1 ; i++)
    {
        if(cadena[0] == 's' || cadena[0] == 'm')
        {
            cont_letras++;
        }
        if(cadena[i] == ' ')
        {
            if(cadena[i+1] == 's' || cadena[i+1] == 'm')
            {
                cont_letras++;
            }
        }
    }
printf("\nCantidad de letras 's' o 'm' = %d\n",cont_letras);

}
void primera_palabra(int cont_tam)
{
int i;
char aux_primera[n];

for(i=0; i<cont_tam ;i++)
{
    if(cadena[i]== ' ')
    {
        aux_primera[i]=0;
    }
    else
    {
        aux_primera[i]=cadena[i];
    }
}


printf("\nPrimera palabra es %s",aux_primera);
printf("\n");
}
void segunda_palabra()
{
int i, j, espacio1, flag = 0;
char aux_segunda[n];

i=0;
while(flag != 1)
{
    if(cadena[i] == ' ')
    {
        espacio1 = i;
        flag = 1;
    }
    i++;
}

i=espacio1+1;

j = 0;

flag = 0;
while(flag != 1)
{
    if(cadena[i] == ' ' || cadena[i] == '.')
    {
        aux_segunda[j]=0;
        flag = 1;
    }
    else
    {
        aux_segunda[j] = cadena[i];
    }
    j++;
    i++;
}
printf("\nSegunada palabra es %s",aux_segunda);
printf("\n");
}
void ultima_palabra(int cont_tam)
{
int i, espacio, flag=0;

for(i=cont_tam; i>=0 ;i--)
{
    if(cadena[i] == ' ')
    {
        espacio = i;
        i=0;
    }
}

i = espacio;
printf("\nLa ultima palabra es ");
while(flag != 1)
{
    if(cadena[i] == '.')
    {
        cadena[i]=0;
        flag = 1;
    }
    else
    {
        printf("%c",cadena[i]);
    }
    i++;
}
printf("\n");
return;
}
