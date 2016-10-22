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
int menuPrincipal(void)
{
    char auxOpcion[256];
    int opcion;

    system("cls");
    printf("    MENU PRINCIPAL\n\n");
    printf("1- AGREGAR PELICULA\n");
    printf("2- BORRAR PELICULA\n");
    printf("3- MODIFICAR PELICULA\n");
    printf("4- GENERAR PAGINA WEB\n");
    printf("5- SALIR\n");

    fflush(stdin);
    scanf("%s",auxOpcion);
    while(validarNumero(auxOpcion,1,7))
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
int validarNumero(char* auxStr,int limInf, int limSup)
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

void nuevaPelicula(void)
{

    eMovie* new_Movie;

    /**< Genera lugar en la memoria para una nueva pelicula */
    new_Movie = (eMovie*)malloc(sizeof(eMovie));

    /**< Obtiene y valida el titulo de la nueva pelicula, luego lo guarda en la estructura */
    getString(new_Movie->titulo,"Ingrese Titulo: ","Error. Ingrese valido: ",30);

    /**< Obtiene y valida la descripcion, luego la guarda en la estructura */
    getString(new_Movie->descripcion,"Escriba una Descripcion: ", "La descripcion es invalida, reingrese: ",50);

    /**< Obtiene y valida la duracion, luego la guarda en la estructura */
    new_Movie->duracion = obtenerNumero("Ingrese la duracion en minutos: ","Error, reingrese: ",1,600);

    /**< Obtiene y valida el puntaje, luego lo guarda en la estructura */
    new_Movie->puntaje = obtenerNumero("Ingrese un puntaje de 1 a 10: ","Error, reingrese de 1 a 10: ",1,10);

    new_Movie->id = 0;

    strcpy(new_Movie->genero,"Terror");

    strcpy(new_Movie->linkImagen,"LinkImagen");



    if(agregarPelicula(new_Movie) == 0)
    {
        printf("\n\nLa pelicula no pudo ser cargada\n");
        exit(1);
    }
    else
        printf("\n\nLa pelicula se cargo correctamente!\n");

    free(new_Movie);
    system("pause");

}


/** \brief solicita un string, valida su tamanio y lo carga en string.
 *
 * \param texto recibe lo que va a leer el usario
 * \param recibe el array donde guardar el string
 * \param recibe por parametro el limite del array
 * \return retorna 0 si el texto supera el limite o 1 si se cargo correctamente
 *
 */
void getString(char* str,char* texto,char* textoError,int lim)
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
    strcpy(str,auxStr);

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

/** \brief Solicita un entero y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
int obtenerNumero(char* texto, char* textoError, int limInf, int limSup)
{
    int numero;
    char auxNumero[256];

    printf("\n%s", texto);
    fflush(stdin);
    scanf("%s", auxNumero);
    while(validarNumero(auxNumero,limInf,limSup))
    {
        printf("\n%s", textoError);
        fflush(stdin);
        scanf("%s", auxNumero);
    }

    numero = atoi(auxNumero);

    return numero;
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie* new_Movie)
{
    int respuesta = 0;
    FILE* fmovies;

    if((fmovies = fopen("file_movies.dat","ab+"))==NULL)
    {
        printf("El Archivo no se pudo leer");
        system("pause");
        exit(1);
    }


    if(fwrite(new_Movie,sizeof(eMovie),1,fmovies) == 1)
    {
        respuesta = 1;

    }

    if((fclose(fmovies))==-1)
    {
        printf("\nNo se pudo cerrar el archivo");
    }
    else
    {
        printf("\nEl archivo se cerro exitosamente");
    }

    return respuesta;
}



FILE* openFile(void)
{
    FILE* fmovies;

    if((fmovies = fopen("file_movies.dat","ab+"))==NULL)
    {
        printf("El Archivo no se pudo leer");
        system("pause");
        exit(1);
    }

    return fmovies;
}
/*
void listMovies(void)
{
    FILE* fmovies;
    eMovie* pmovie;

    if((fmovies = fopen("file_movies.dat","rb"))==NULL)
    {
        printf("El Archivo no se pudo leer");
        system("pause");
        exit(1);
    }

    pmovie = (eMovie*)malloc(sizeof(eMovie));

    fread(pmovie,sizeof(eMovie),1,fmovies);
    printf("\n%s, %s, %d, %d",pmovie->titulo,pmovie->descripcion,pmovie->duracion,pmovie->puntaje);

    system("pause");
    free(pmovie);
}
*/
void listMovies(void)
{
    FILE* fmovies;
    eMovie* pmovies = (eMovie*)malloc(sizeof(eMovie*));
    int cant;
    fmovies = fopen("file_movies.dat","rb");

    if(fmovies == NULL)
    {
        printf("Error. No se pudo abrir el archivo");
        system("pause");
        exit(1);
    }
    while(!feof(fmovies))
    {
        cant = fread(pmovies,sizeof(eMovie),1,fmovies);
        if(cant != 1)
        {
            if(feof(fmovies))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
            }
        }
        printf("Id: %d\n",pmovies->id);
        printf("Titulo: %s\n",pmovies->titulo);
        printf("Descripcion: %s\n",pmovies->descripcion);
        printf("Genero: %s\n",pmovies->genero);
        printf("Duracion: %d\n",pmovies->duracion);
        printf("Puntaje: %d\n\n\n",pmovies->puntaje);

    }

    system("pause");
}
