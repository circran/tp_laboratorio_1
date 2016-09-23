#include <stdio.h>
#include <stdlib.h>


/** \brief Solicita al usuario que ingrese un numero y devuelve el numero.
 *
 * \param void
 * \return El numero ingresado.
 *
 */

float pedirOperando (void)
{
    float x;
    printf("Ingrese el numero..\n");
    fflush(stdin);
    scanf("%f", &x);
    return x;
}


/** \brief Recibe los numero de la primera y la ultima opcion de un menu. Valida que la opcion sea valida y
 *          devuelve la opcion elegida por el usuario.
 * \param La variable "desde" recibe el numero de la primera opcion.
 * \param La variable "hasta" recibe el numero de la ultima opcion.
 * \return La variable "opcion" devuelve la eleccion del usuario.
 *
 */

int elegirOpcion (int desde, int hasta)
{
  int opcion;

  do
  {
  printf("Ingrese una opcion..\n");
  fflush(stdin);
  scanf("%d", &opcion);

  }while(opcion < desde || opcion > hasta);
  return opcion;
}

/** \brief Realiza la suma de dos float recibidos y retorna el resultado
 *
 * \param La variable x recibe el primer operando.
 * \param La variable y recibe el segundo operando.
 * \return Retorna el resultado de la suma.
 *
 */

float calcularSuma(float x, float y)
{
    return x + y;
}

/** \brief Realiza la resta de dos float recibidos y retorna el resultado
 *
 * \param La variable x recibe el primer operando.
 * \param La variable y recibe el segundo operando.
 * \return Retorna el resultado de la resta.
 *
 */
float calcularResta(float x,float y)
{
    return x - y;
}


/** \brief Realiza la division de dos float recibidos y retorna el resultado.
 *
 * \param la varible x recibe el primer operando
 * \param la variable y recibe el segundo operando
 * \return retorna el resultado de la division
 *
 */

float calcularDivision(float x,float y)
{
    return x / y;
}



/** \brief Realiza la multiplicacion de dos float y devuelve el resultado
 *
 * \param la varible x recibe el primer operando
 * \param la variable y recibe el segundo operando
 * \return retorna el resultado de la multiplicacion
 *
 */

float calcularMultiplicacion(float x,float y)
{
    return x * y;
}


/** \brief Recibe un float, realiza el factorial y devuelve el resultado.
 *
 * \param la variable x recibe el numero
 * \param
 * \return la variable "acu" retorna el resultado
 *
 */
float calcularFactorial(float x)
{
    float acu = 1;
    int i;


    for(i=1;i<=x;i++)
    {
        acu = acu * i;
    }

    return acu;
}
