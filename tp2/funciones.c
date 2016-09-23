#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int mostrarMenu(void)
{
    int opcion;
    system("cls");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");

    scanf("%d",&opcion);
    while(!validarNumero(opcion,1,5))
    {
        printf("\nError.. Reingrese: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

int validarNumero(int x,int limInf, int limSup)
{
    int validacion = 0;

    if(x >= limInf && x <= limSup)
    {
        validacion = 1;
    }

    return validacion;
}

void inicializarArrayPersonas(ePersona persona[],int tamArray)
{
    int i;
    for(i=0;i<tamArray;i++)
    {
        persona[i].estado = 0;
    }
}

int obtenerIndiceLibre(ePersona persona[],int tamArray)
{
    int i;
    int indice;
    for(i=0;i<tamArray;i++)
    {
        if(persona[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void getString(char string[],char texto[],char textoError[],int lim)
{
    char aux[400];
    printf("\n%s",texto);
    fflush(stdin);
    gets(aux);
    while(strlen(aux) > lim)
    {
        printf("\n%s", textoError);
        gets(aux);
    }
    strcpy(string,aux);

}
int obtenerNumero(char texto[], char textoError[], int limInf, int limSup)
{
    int numero;

    printf("\n%s", texto);
    scanf("%d", &numero);
    while(!validarNumero(numero,limInf,limSup))
    {
        printf("\n%s", textoError);
        scanf("%d", &numero);
    }
    return numero;
}

int buscarPorDni(ePersona persona[],int tamArray,long int dni)
{
    int i;
    int indice = -1;
    for(i=0;i<tamArray;i++)
    {
        if(persona[i].dni == dni)
        {
            indice = i;
        }
    }
    return indice;
}

void mostrarPersona(ePersona personas[],int indice)
{
    printf("Nombre\t\tEdad\t\tDni\n\n");
    printf("%s\t\t%d\t\t%d\n",personas[indice].nombre, personas[indice].edad, personas[indice].dni);
}

void ordenarPersonas(ePersona personas[],int tamArray)
{
    int i,j;
    ePersona auxPersonas;

    for(i=0;i-1<tamArray;i++)
    {
        for(j=i+1;j<tamArray;j++)
        {

            if(strcmp(personas[i].nombre,personas[j].nombre)> 0)
            {
                auxPersonas = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersonas;
            }
        }
    }

}
void mostrarPersonas(ePersona personas[],int tamArray)
{
    int i;

    printf("\n\nNombre\t\tEdad\t\tDni\n\n");

    for(i=0;i<tamArray;i++)
    {
        if(personas[i].estado == 1)
        {

            printf("%s\t\t%d\t\t%d\n",personas[i].nombre, personas[i].edad, personas[i].dni);
        }
    }
    printf("\n\n");
    system("pause");
}

void graficarEdades(ePersona personas[],int tamArray)
{
    int i,mayor;
    int bandera = 0;
    int hasta18 = 0;
    int de19a35 = 0;
    int masDe35 = 0;
    system("cls");

    for(i=0;i<tamArray;i++)
    {
        if(personas[i].estado == 1)
        {

            if(personas[i].edad <= 18)
            {
                hasta18 = hasta18 + 1;
            }
            else if(personas[i].edad >= 19 && personas[i].edad <= 35)
            {
                de19a35 = de19a35 + 1;
            }
            else if(personas[i].edad > 35)
            {
                masDe35 = masDe35 + 1;
            }
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= masDe35)
    {
        mayor = hasta18;
    }
    else if(de19a35 >= hasta18 && de19a35 >=masDe35)
    {
        mayor = de19a35;
    }
    else
    {
        mayor = masDe35;
    }

    printf("******GRAFICO******\n");

    for(i=mayor;i>0;i--)
        {
        if(i < 10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }

        if(i <= hasta18)
        {
            printf("*");
        }
        if(i <= de19a35)
        {
            printf("\t*");
            bandera = 1;
        }
        if(i <= masDe35)
        {
            if(bandera == 0)
            {
                printf("\t\t*");
            }
            if(bandera == 1)
            {
                printf("\t*");
            }

        }
        printf("\n");
    }

    printf("____________________");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, masDe35);
    printf("\n\n\n");
    system("pause");
}

void formatoNombre(ePersona personas[],int indice)
{
    strcpy(personas[indice].nombre,strlwr(personas[indice].nombre));
    personas[indice].nombre[0] = toupper(personas[indice].nombre[0]);
}

long int obtenerDni(char texto[],char textoError[],int limInf,int limSup)
{
    long int numero;

    printf("\n%s", texto);
    scanf("%ld", &numero);
    while(!validarNumero(numero,limInf,limSup))
    {
        printf("\n%s", textoError);
        scanf("%ld", &numero);
    }
    return numero;
}
