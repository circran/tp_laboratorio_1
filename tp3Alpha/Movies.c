#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib.h"
#include "Movies.h"

/** \brief Solicita los datos de una nueva pelicula, los valida y los carga en el array
 *
 * \param aMovie recibe el array de peliculas
 * \param length recibe el tamaño del array
 * \return -
 *
 */

void movie_new(eMovie* aMovie,int length)
{
    int indice;

    if(aMovie != NULL && length > 0)
    {

        indice = movie_getFreeSpace(aMovie,length); //OBTIENE UN LUGAR LIBRE

        aMovie[indice].id = movies_generateId(aMovie,length,1000);//GENERA EL ID

        getString(aMovie[indice].title,"Ingrese Titulo: ","Error. Reingrese valido: ",100);//Obtiene el titulo
        formatoNombre(aMovie[indice].title);

        getString(aMovie[indice].description,"Ingrese Descripcion: ","Error. Reingrese valido: ",150);//Obtiene la descripcion
        formatoNombre(aMovie[indice].description);

        getString(aMovie[indice].genre,"Ingrese Genero: ","Error. Reingrese valido: ",50);//Obtiene el genero
        formatoNombre(aMovie[indice].genre);

        aMovie[indice].duration = getInt("Ingrese la duracion en min: ","Error.. reingrese: ",1,300);//Obtiene la duracion

        aMovie[indice].score = getInt("Ingrese un puntaje, del 1 al 10: ","Error.. reingrese valido: ",1,10);//Obtiene el puntaje

        getLink(aMovie[indice].linkImagen,"Ingrese el link de la imagen: ","Error, es muy largo, reingrese: ",200);

        aMovie[indice].status = 1;//Carga el status con el valor de 1

        system("cls");
        printf("\n\n\n\tPelicula Cargada con exito!\n\n\n");
        system("pause");
    }
    else
    {
        printf("Error. el programa va a cerrarse..");
        system("pause");
        exit(1);
    }
}


/**
 * Obtiene el primer indice libre del array.
 * \param recibe el array como parametro
 * \param recibe el tamanio del array
 * \return el primer indice disponible
 */
int movie_getFreeSpace(eMovie* aMovie,int length)
{
    int i;
    int indice;
    for(i=0;i<length;i++)
    {
        if(aMovie[i].id == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief carga el valor 0 en el id de cada indice.
 *
 * \param abonado recibe el array
 * \param recibe el tamanio del array.
 * \return -
 *
 */
void movies_Inicialize(eMovie* aMovies,int length)
{
    int i;
    if(aMovies == NULL)
    {
       printf("Error. No se pudo inicializar la estructura.");
       system("pause");
       exit(1);
    }

    for(i=0;i<length;i++)
    {
         (aMovies+i)->id = 0;
    }
}

/** \brief Busca el ultimo id y genera el siguiendo, o si es el primer id lo genera a partir de un limite minimo
 *
 * \param recibe el array de abonado y su longitud
 * \param recibe el limite inferior a partir del cual se generan los id
 * \return retorna el id generado o -1 si no se pudo generar el id
 *
 */

int movies_generateId(eMovie* aMovies,int length,int limitLower)
{
    int max,i,id;
    int flag = 0;

    for(i=0;i<length;i++)
    {
        if(aMovies[i].id != 0)
        {
            max = aMovies[i].id;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        id = limitLower + 1;
    }
    if(flag == 1)
    {
        id = max + 1;
    }

    return id;
}

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 * @param abonados el array se pasa como parametro.
 * @param id el id a ser buscado en el array.
 * @return el indice en donde se encuentra el id que coincide
 */
int movies_searchForId(eMovie* aMovies,int length,int id)
{
    int i;
    int index = -1;
    for(i=0;i<length;i++)
    {
        if(aMovies[i].id == id && aMovies[i].status == 1)
        {
            index = i;
        }
    }
    return index;
}

/** \brief solicita el id de una pelicula luego la borra o no, dependiendo que se seleccione
 *
 * \param recibe el array
 * \param recibe la longitud del array
 * \return -
 *
 */

void movies_delete(eMovie* aMovies,int length)
{
    int id, index;
    char baja[256];

    movie_viewMovies(aMovies,length);

    id = getInt("Ingrese el id de la pelicula a borrar: ","Error.. Ingrese un id valido",1000,2000);
    index = movies_searchForId(aMovies,length,id);

    if(index == -1)
    {
        printf("\nNo existe una pelicula con ese id\n\n ");
        system("pause");
    }

    else
    {
        system("cls");
        movie_viewMovie(aMovies,length,index);

        getString(baja,"\nEsta seguro que desea borrar esta pelicula?s/n: ","Ingrese 's' o 'n': ",1);
        baja[0] = tolower(baja[0]);

        if(baja[0] == 's' && soloLetras(baja) == 1)
        {

            aMovies[index].status = 0;
            printf("\n\nPelicula borrada\n\n");
        }
        else
        {
            printf("\n\nLa pelicula no fue borrada\n\n");
        }
        system("pause");
    }
}

/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
int movie_menuMod(void)
{
    char auxOpcion[256];
    int option;

    printf("\n1- Titulo\n");
    printf("2- Descripcion\n");
    printf("3- Genero\n");
    printf("4- Duracion\n");
    printf("5- Puntaje\n");
    printf("6- Link de la imagen\n");

    fflush(stdin);
    scanf("%s", auxOpcion);
    while(validateInt(auxOpcion,1,6))
    {
        printf("\nError.. Reingrese: ");
        fflush(stdin);
        scanf("%s", auxOpcion);
    }
    option = atoi(auxOpcion);

    return option;
}

/** \brief Solicita el id de la pelicula que se quiere modificar y luego de elegir que modificar se realiza el cambio
 *
 * \param abonados recibe el array con la lista de todos las peliculas
 * \param length recibe el tamanio del array
 * \return -
 *
 */

void movie_modify(eMovie* aMovie,int length)
{
    int id, index,option;


    movie_viewMovies(aMovie,length);

    id = getInt("Ingrese el id de la pelicula a borrar: ","Error.. Ingrese un id valido",1000,2000);
    index = movies_searchForId(aMovie,length,id);

    if(index == -1)
    {
        printf("\nNo existe una pelicula con ese id\n\n ");
        system("pause");
    }
    else
    {
        system("cls");
        movie_viewMovie(aMovie,length,index);

        printf("\n\nQue desea modificar de la pelicula? :\n");
        option = movie_menuMod();
        switch(option)
        {
        case 1:
            getString(aMovie[index].title,"Ingrese Titulo: ","Error. Reingrese valido: ",100);//Obtiene el titulo
            formatoNombre(aMovie[index].title);
            break;

        case 2:
            getString(aMovie[index].description,"Ingrese Descripcion: ","Error. Reingrese valido: ",150);//Obtiene la descripcion
            formatoNombre(aMovie[index].description);
            break;

        case 3:
            getString(aMovie[index].genre,"Ingrese Genero: ","Error. Reingrese valido: ",50);//Obtiene el genero
            formatoNombre(aMovie[index].genre);
            break;

        case 4:
            aMovie[index].duration = getInt("Ingrese la duracion en min: ","Error.. reingrese: ",1,300);//Obtiene la duracion
            break;
        case 5:
            aMovie[index].score = getInt("Ingrese un puntaje, del 1 al 10: ","Error.. reingrese valido: ",1,10);
            break;
        case 6:
            getLink(aMovie[index].linkImagen,"Ingrese el link de la imagen: ","Error, es muy largo, reingrese: ",200);
            break;

        }
        system("cls");
        printf("\n\t\tModificacion realizada con exito!\n\n\n");
        system("pause");
    }
}

/** \brief Muestra los datos de la pelicula cargada en el indice que recibe
 *
 * \param recibe el array con todas las peliculas
 * \param recibe el tamanio del array
 * \param recibe el indice de la pelicula que se quieren ver los datos
 *
 */

void movie_viewMovie(eMovie* aMovie,int length,int index)
{
    printf("|ID     |Titulo\t\t     |Genero      |Puntaje|Duracion\n");
    printf("---------------------------------------------------------------\n");
    printf("|%d   |%-19s |%-11s |%-7d|%-7d\n",aMovie[index].id,aMovie[index].title, aMovie[index].genre, aMovie[index].score,aMovie[index].duration);
}

/** \brief Muestra los datos de las peliculas cargadas
  *
  * \param aMovie recibe el array con los datos de las peliculas
  * \param lenght recibe el tamanio del array
  * \return -
  *
  */
void movie_viewMovies(eMovie* aMovie,int length)
{
    int i;

    printf("|ID     |Titulo\t\t     |Genero      |Puntaje|Duracion\n");
    printf("---------------------------------------------------------------\n");
    for(i=0;i<length;i++)
    {
        if(aMovie[i].id != 0 && aMovie[i].status == 1)
        {
            printf("|%d   |%-19s |%-11s |%-7d|%-7d\n",aMovie[i].id,aMovie[i].title, aMovie[i].genre, aMovie[i].score,aMovie[i].duration);
        }
    }
    printf("\n\n");
}

/**
 *  Agrega las peliculas al archivo binario
 *  @param aMovie la estructura a ser agregada al archivo
 *  @return -
 */
void movie_saveMovies(eMovie* aMovie,int length)
{
    int i;
    FILE* fmovies;

    if((fmovies = fopen("file_movies.dat","wb"))==NULL)
    {
        system("cls");
        printf("El Archivo no se pudo leer");
        system("pause");
    }

    for(i=0;i<length;i++)
    {
        if(fwrite(aMovie+i,sizeof(eMovie),1,fmovies) != 1)
        {
            printf("Error al escribir archivo..");
            system("pause");
        }
    }


    if((fclose(fmovies))==-1)
    {
        printf("\nNo se pudo cerrar el archivo");
    }
    else
    {
        printf("\nEl archivo se cerro exitosamente");
    }
}
/** \brief Escribe cada pelicula de la estructura en el archivo binario
 *
 * \param aMovie recibe el array con las peliculas
 * \param length recibe el tamaño del array
 * \return -
 *
 */

void movie_loadMovies(eMovie* aMovie, int length)
{
    FILE* fmovies;
    int i = 0;
    if((fmovies = fopen("file_movies.dat","rb"))==NULL)
    {
        system("pause");
        return;
    }

    while(!feof(fmovies))
    {
        fread(aMovie+i,sizeof(eMovie),1,fmovies);
        i++;
    }
    if((fclose(fmovies))==-1)
    {
        printf("\nNo se pudo cerrar el archivo");
    }
}

/**
 *  Genera una pagina web con las peliculas cargadas
 *  @param aMovie la estructura a ser agregada al archivo
 *  @return -
 */
void movie_generateHTML(eMovie* aMovie,int length)
{
    int i;
    FILE* fmovies;

    if((fmovies = fopen("movies_web.html","w"))==NULL)
    {
        system("cls");
        printf("El Archivo no se pudo leer");
        system("pause");
    }

    for(i=0;i<length;i++)
    {
        if(aMovie[i].status == 1)
        {
            fprintf(fmovies,"<article class='col-md-4 article-intro'>\n <a href='#'> \n<img class='img-responsive img-rounded' src='");
            fprintf(fmovies,"%s",aMovie[i].linkImagen);
            fprintf(fmovies,"'alt=''> \n</a> \n <h3> \n <a href='#'> %s </a>\n",aMovie[i].title);
            fprintf(fmovies,"</h3> \n <ul> \n <li>Género: %s </li> \n",aMovie[i].genre);
            fprintf(fmovies,"<li>Puntaje: %d </li>\n ",aMovie[i].score);
            fprintf(fmovies,"<li>Duración: %d </li> \n",aMovie[i].duration);
            fprintf(fmovies,"</ul> \n <p> %s </p> \n",aMovie[i].description);
            fprintf(fmovies, "</article> \n\n\n");
        }
    }



    if((fclose(fmovies))==-1)
    {
        printf("\nNo se pudo cerrar el archivo");
    }
   printf("\n\n\n \tLa pagina web se genero correctamente!\n\n\n");
   system("pause");
}

