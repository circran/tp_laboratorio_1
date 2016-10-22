#ifndef _LIB_H_DECLARED
#define _LIB_H_DECLARED


int validateInt(char*,int,int);
//char validarEntero(char*);
int getInt(char*,char*,int,int);
void getString(char*,char*,char*,int);
void formatoNombre(char*);
int soloLetras(char*);
int menu(void);
int menuModificar(void);
long int obtenerTelefono(char*,char*,int,int);
void getLink(char* string,char* texto,char* textoError,int lim);

#endif // _LIB_H_DECLARED
