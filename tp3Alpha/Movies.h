#ifndef _MOVIES_H_DECLARED
#define _MOVIES_H_DECLARED

typedef struct
{
    int id;
    char title[100];
    char description[150];
    char genre[50];
    int duration;
    int score;
    char linkImagen[200];
    int status;
}eMovie;

int movies_generateId(eMovie*,int,int);
void movies_Inicialize(eMovie*,int);
void movie_new(eMovie*,int);
int movie_getFreeSpace(eMovie*,int);
int movies_searchForId(eMovie* aMovies,int length,int id);
void movies_delete(eMovie* aMovies,int length);
int movie_menuMod(void);
void movie_modify(eMovie* aMovies,int length);
void movie_viewMovie(eMovie* aMovie,int length,int index);
void movie_viewMovies(eMovie* aMovie,int length);

//FUNCIONES PARA LOS ARCHIVOS
void movie_saveMovies(eMovie* aMovie,int length);
void movie_loadMovies(eMovie* aMovie, int length);
void movie_generateHTML(eMovie* aMovie,int length);

#endif // _MOVIES_H_DECLARED








