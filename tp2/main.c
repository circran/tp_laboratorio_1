#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20

int main()
{

    int opcion;
    int indice; //Guarda el indice libre
    long int dni;
    char baja;
    ePersona arrayPersonas[TAM];

    inicializarArrayPersonas(arrayPersonas,TAM);
    do
    {
        opcion = mostrarMenu();
        switch(opcion)
        {
            case 1: //AGREGAR PERSONA

                indice = obtenerIndiceLibre(arrayPersonas,TAM);/**< Busca un indice en estado 0 */

                /**< Obtiene el nombre, lo valida y lo guarda */
                getString(arrayPersonas[indice].nombre,"Ingrese nombre: ","Error.. Reingrese: ",50);
                /**< Pasa el nombre a miniscula y luego la primer letra a mayuscula */
                formatoNombre(arrayPersonas,indice);

                /**< obtiene y carga la edad luego de validarla*/
                arrayPersonas[indice].edad = obtenerNumero("Ingrese la edad: ","Error, reingrese: ",0,100);

                /**< Obtiene y carga el dni luego de validarlo */
                arrayPersonas[indice].dni = obtenerDni("Ingrese Dni: ","Error, reingrese valido: ",1000000,99999999);

                arrayPersonas[indice].estado = 1;
                break;

            case 2: //DAR BAJA LOGICA A UNA PERSONA
                system("cls");
                dni = obtenerDni("Ingrese el dni de la persona: ","Error.. reingrese valido: ",1000000,99999999);
                indice = buscarPorDni(arrayPersonas,TAM,dni);
                while(indice == -1)
                      {
                          printf("\nError.. No existe una persona con ese DNI");
                          system("pause");
                          printf("\nIngrese el dni de la persona: ");
                          scanf("%ld", &dni);
                      }

                      mostrarPersona(arrayPersonas,indice);

                      printf("\nEsta seguro que desea dar de baja a esta persona?s/n :");
                      fflush(stdin);
                      baja = tolower(getchar());
                      if(baja == 's')
                      {

                          arrayPersonas[indice].estado = 2;
                          printf("\n\nPersona dada de baja\n\n");
                      }
                      else
                      {
                          printf("\n\nBaja cancelada por el usuario..\n\n");
                      }
                system("pause");

                break;

            case 3: //IMPRIMIR LISTA ORDENANA POR NOMBRE

                ordenarPersonas(arrayPersonas,TAM);
                mostrarPersonas(arrayPersonas,TAM);
                break;
            case 4: //MOSTRAR GRAFICO DE BARRAS
                    graficarEdades(arrayPersonas,TAM);

                break;

        }

    }while(opcion != 5);

    return 0;
}

