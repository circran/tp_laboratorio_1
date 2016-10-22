#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
int menu(void)
{
    char auxOpcion[256];
    int opcion;

    system("cls");
    printf("    MENU PRINCIPAL\n\n");
    printf("1- AGREGAR PELICULA\n");
    printf("2- BORRAR PELICULA\n");
    printf("3- MODIFICAR PELICULA\n");
    printf("4- GENERAR PAGINA WEB\n");
    printf("5- Salir\n");

    fflush(stdin);
    scanf("%s",auxOpcion);
    while(validateInt(auxOpcion,1,5))
    {
        printf("\nError.. Reingrese: ");
        fflush(stdin);
        scanf("%s",auxOpcion);
    }

    opcion = atoi(auxOpcion);


    return opcion;
}

/** \brief valida que el numero que recibe este entre los limites.
 *
 * \param recibe el numero a validar.
 * \param recibe el limite inferior
 * \param recibe el limite superior
 * \return retorna 0 si el numero no esta dentro de los limites o 1 si lo esta.
 */
int validateInt(char* auxStr,int limInf, int limSup)
{
    int auxNumero, i, validacion = 0;

    for(i=0;auxStr[i] != '\0';i++)
    {
        if(auxStr[i] < '0' || auxStr[i] > '9')
        {
            validacion = 1;
            break;
        }
    }

    auxNumero = atoi(auxStr);

    if(auxNumero < limInf || auxNumero > limSup)
    {
        validacion = 1;
    }

    return validacion;
}

/** \brief solicita un string, valida su tamanio y lo carga en string.
 *
 * \param texto recibe lo que va a leer el usario
 * \param recibe el array donde guardar el string
 * \param recibe por parametro el limite del array
 * \return retorna 0 si el texto supera el limite o 1 si se cargo correctamente
 *
 */
void getString(char* string,char* texto,char* textoError,int lim)
{
    char auxStr[400];

    printf("\n%s",texto);
    fflush(stdin);
    gets(auxStr);

    while(!soloLetras(auxStr)|| strlen(auxStr) > lim)
    {
        printf("\n%s", textoError);
        fflush(stdin);
        gets(auxStr);
    }
    strcpy(string,auxStr);

}
/** \brief Recibe un puntero con un nombre, lo pasa a miniscula y la primer letra a mayuscula
 *
 * \param str recibe el puntero con el nombre
 * \param
 * \return
 *
 */

void formatoNombre(char* str)
{
    strlwr(str);
    str[0] = toupper(str[0]);
}

/** \brief recibe un texto y verifica que solo contenga letras
 *
 * \param str recibe el puntero con el texto
 * \param
 * \return
 *
 */
int soloLetras(char* str)
{
    int i,validacion = 1;

    for(i=0;str[i]!='\0';i++)
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            validacion = 0;
            break;
        }
    }
    return validacion;
}
/** \brief Solicita un long int y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
long int obtenerTelefono(char* texto,char* textoError,int limInf,int limSup)
{
    long int numero;
    char auxNumero[256];

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%s", auxNumero);

    while(validateInt(auxNumero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%s", auxNumero);
    }

    numero = atoi(auxNumero);
    return numero;
}



/** \brief Solicita un entero y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
int getInt(char* texto, char* textoError, int limInf, int limSup)
{
    int numero;
    char auxNumero[256];

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%s", auxNumero);
    while(validateInt(auxNumero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%s", auxNumero);
    }

    numero = atoi(auxNumero);

    return numero;
}

/** \brief solicita un string, valida su tamanio y lo carga en string.
 *
 * \param texto recibe lo que va a leer el usario
 * \param recibe el array donde guardar el string
 * \param recibe por parametro el limite del array
 * \return retorna 0 si el texto supera el limite o 1 si se cargo correctamente
 *
 */
void getLink(char* string,char* texto,char* textoError,int lim)
{
    char auxStr[800];

    printf("\n%s",texto);
    fflush(stdin);
    gets(auxStr);

    while(strlen(auxStr) > lim)
    {
        printf("\n%s", textoError);
        fflush(stdin);
        gets(auxStr);
    }
    strcpy(string,auxStr);

}


