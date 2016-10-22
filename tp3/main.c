#include <stdio.h>
#include <stdlib.h>
#include "Movies.h"
#include "lib.h"
#define MOVIES 150
int main()
{
    //FILE* fMovies;
    eMovie aMovies[MOVIES];
    int option;

    movies_Inicialize(aMovies,MOVIES);
    movie_loadMovies(aMovies,MOVIES);
   do
    {
        option = menu();

        switch(option)
        {
        case 1: //AGREGAR PELICULA
            movie_new(aMovies,MOVIES);
            break;
        case 2://BORRAR PELICULA
            movies_delete(aMovies,MOVIES);
            break;
        case 3://MODIFICAR PELICULA
            movie_modify(aMovies,MOVIES);
            break;
        case 4://GENERAR PAGINA WEB
            movie_generateHTML(aMovies,MOVIES);
            break;
        }
    }while(option != 5);

    movie_saveMovies(aMovies,MOVIES);

    return 0;
}
