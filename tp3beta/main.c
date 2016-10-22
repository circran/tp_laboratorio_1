#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>
#include <ctype.h>

#define MOVIES 40

int main()
{
    int opcion;


    do
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1://AGREGAR PELICULA
            {
                nuevaPelicula();
                //leerPelicula();
                break;
            }

        case 2://BORRAR PELICULA
            listMovies();
            break;

        case 3://MODIFICAR PELICULA

            break;

        case 4://GENERAR PAGINA WEB

            break;

        }

    }while(opcion != 5);
    return 0;
}
