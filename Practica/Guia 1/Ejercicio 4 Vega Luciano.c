/*
Realizar un programa que solicite el ingreso de la fecha en formato
DD/MM/AAAA y expresar la fecha en formato “texto” , es decir DD de “dia”, MM de “Mes” y AAAA
de “Año” , utilizar funciones y la sentencia “case” y sentencias strcat().
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 12

typedef struct{

char dia[n];
char mes[n];
char anio[n];

}cadena_s;

cadena_s cadena;

void ingreso_cadena();
void cadenas_switch();
int main()
{

ingreso_cadena();
cadenas_switch();

return 0;
}
void ingreso_cadena()
{
int  flag = 0;
int aux_dia, aux_mes;

do{
        printf("\nIngrese el dia: ");
        scanf("%s",cadena.dia);
        cadena.dia[2] = '/';

       aux_dia = atoi(cadena.dia);

        if(aux_dia > 0 && aux_dia <= 31)
        {
            flag = 1;
        }
        else
        {
            printf("\n-----EL DIA INGRESADO NO EXISTE-----");
        }


}while(flag != 1);
flag = 0;

do{
        printf("\nIngrese el mes: ");
        scanf("%s",cadena.mes);
        cadena.mes[2] = '/';

       aux_mes = atoi(cadena.mes);

        if(aux_mes > 0 && aux_mes <= 12)
        {
            flag = 1;
        }
        else
        {
            printf("\n-----EL MES INGRESADO NO EXISTE-----");
        }
}while(flag != 1);

        printf("\nIngrese el anio: ");
        scanf("%s",cadena.anio);

        printf("\nCadena Ingresada: %s%s%s",cadena.dia,cadena.mes,cadena.anio);
}
void cadenas_switch()
{
int aux_mes;
char cadena_final[]="";

aux_mes = atoi(cadena.mes);

switch(aux_mes)
{
    case 1:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Enero del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 2:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Febrero del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 3:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Marzo del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 4:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Abril del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 5:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Mayo del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 6:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Junio del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 7:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Julio del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 8:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Agosto del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 9:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Septiembre del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 10:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Octubre del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 11:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Noviembre del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
    case 12:
        cadena.dia[2] = ' ';
        strcat(cadena_final,cadena.dia);
        strcat(cadena_final,"de Diciembre del ");
        strcat(cadena_final,cadena.anio);

        printf("\nCadena final: %s",cadena_final);

    break;
}
}