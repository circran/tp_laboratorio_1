typedef struct
{
    int id;
    char titulo[30];
    char descripcion[50];
    char genero[20];
    int duracion;
    int puntaje;
    char linkImagen[100];

}eMovie;


FILE* openFile(void);

int menuPrincipal(void);
int validarNumero(char*,int,int);
int soloLetras(char*);
void getString(char*,char*,char*,int);
int obtenerNumero(char*,char*,int,int);


void nuevaPelicula(void);


int agregarPelicula(eMovie*);
//void leePelicula(void);
void listMovies(void);
