#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/** \brief carga el valor 0 en el estado de cada indice.
 *
 * \param persona recibe el array
 * \param recibe el tamanio del array.
 * \return -
 *
 */
 void inicializarArrayPersonas(ePersona[],int);


/**
 * Obtiene el primer indice libre del array.
 * \param recibe el array como parametro
 * \param recibe el tamanio del array
 * \return el primer indice disponible
 */
int obtenerIndiceLibre(ePersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param persona el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona[],int,long int);


/** \brief Muestra un menu, solicita opcion y la valida. Retorna la opcion.
 *
 * \param -
 * \param -
 * \return retorna la opcion elegida por el usuario ya validada.
 *
 */
 int mostrarMenu(void);

 /** \brief valida que el numero que recibe este entre los limites.
 *
 * \param recibe el numero a validar.
 * \param recibe el limite inferior
 * \param recibe el limite superior
 * \return retorna 0 si el numero no esta dentro de los limites o 1 si lo esta.
 */
 int validarNumero(int,int,int);


/** \brief solicita un string, valida su tamanaio y lo carga en string.
 *
 * \param texto recibe lo que va a leer el usario
 * \param recibe el array donde guardar el string
 * \param recibe por parametro el limite del array
 * \return retorna 0 si el texto supera el limite o 1 si se cargo correctamente
 *
 */

 void getString(char[],char[],char[],int);

/** \brief Solicita un entero y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
 int obtenerNumero(char[],char[],int,int);

/** \brief Muestra los datos de la persona cargada en ese indice
 *
 * \param personas recibe el array como parametro
 * \param indice recibe el indice en que estaca cargada la persona a mostrar
 * \return -
 *
 */

 void mostrarPersona(ePersona[],int);

 /** \brief Ordena alfabeticamente el array de personas teniendo como base el nombre
  *
  * \param personas recibe el array con los datos de las personas
  * \param tamArray recibe el tamaño del array
  * \return -
  *
  */

 void ordenarPersonas(ePersona[],int);

 /** \brief Muestra los datos de las personas cargadas que esten en alta
  *
  * \param personas recibe el array con los datos de las personas
  * \param tamArray recibe el tamaño del array
  * \return -
  *
  */
 void mostrarPersonas(ePersona[],int);

/** \brief Genera un grafico de barra apartir de la cant de personas que hay de determinadas edades.
 *
 * \param personas recibe el array con las edades de las personas
 * \param int tamArray recibe el tamaño de array de personas
 * \return -
 *
 */

 void graficarEdades(ePersona[],int);

/** \brief Recibe un nombre, lo pasa todo a miniscula y luego su primer letra a mayuscula
 *
 * \param personas recibe el array donde estan guardados los datos de la persona
 * \param indice recibe el indice de la persona a modificar
 * \return -
 *
 */

 void formatoNombre(ePersona[],int);

/** \brief Solicita un long int y valida que este dentro de los limites
 *
 * \param recibe el texto para solicitar al usuario
 * \param recibe el texto para mostrar al usuario en caso de error.
 * \param limInf recibe el limite inferior por parametro
 * \param limSup recibe el limite superior por parametro
 * \return retorna el numero luego de ser validado
 *
 */
long int obtenerDni(char[],char[],int,int);

 #endif // FUNCIONES_H_INCLUDED
