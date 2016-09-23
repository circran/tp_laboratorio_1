#include <stdio.h>
#include <stdlib.h>
#include "circran.h"


int main()
{
    int opcion;
    float a = 0;
    float b = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactorizacion;


    do
    {
        system("cls");
        printf("\n1 Ingresar 1er operando (A=%.2f)\n", a);
        printf("2 Ingresar 2do operando (B=%.2f)\n", b);
        printf("3 Calcular la suma (A+B)\n");
        printf("4 Calcular la resta (A-B)\n");
        printf("5 Calcular la division (A/B)\n");
        printf("6 Calcular la multiplicacion (A*B)\n");
        printf("7 Calcular el factorial (A!)\n");
        printf("8 Calcular todas las operaciones\n");
        printf("9 Salir\n");

        opcion = elegirOpcion(1,9);


        switch(opcion)
        {
            case 1://1er operando
                                {
                a = pedirOperando();
                break;
                }
            case 2://2do operando
                {
                b = pedirOperando();
                break;
                }
            case 3://SUMA
                {
                    resultadoSuma = calcularSuma(a,b);
                    printf("\nEl resultado de la suma es: %.2f \n\n", resultadoSuma);
                    system("pause");
                    break;
                }

            case 4://RESTA
                {
                    resultadoResta = calcularResta(a,b);
                    printf("\nEl resultado de la resta es: %.2f\n\n", resultadoResta);
                    system("pause");
                    break;
                }
            case 5://DIVISION
                {
                    if(b == 0)
                    {
                        printf("\nError, no se puede divir por 0\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        resultadoDivision = calcularDivision(a,b);
                        printf("\nEl resultado de la division es %.2f\n\n", resultadoDivision);
                        system("pause");
                    }
                    break;
                }

            case 6://MULTIPLICACION
                {
                    resultadoMultiplicacion = calcularMultiplicacion(a,b);
                    printf("\nEl resultado de la multiplicacion es %.2f \n\n", resultadoMultiplicacion);
                    system("pause");
                    break;
                }
            case 7://FACTORIAL
                {
                    resultadoFactorizacion = calcularFactorial(a);
                    printf("\nEl factorial es %.2f \n\n", resultadoFactorizacion);
                    system("pause");
                    break;
                }

            case 8: //Todas las operaciones
                {
                    resultadoSuma = calcularSuma(a,b);
                    printf("\nEl resultado de la suma es: %.2f \n", resultadoSuma);

                    resultadoResta = calcularResta(a,b);
                    printf("\nEl resultado de la resta es: %.2f\n", resultadoResta);

                    resultadoDivision = calcularDivision(a,b);
                    printf("\nEl resultado de la division es %.2f\n", resultadoDivision);

                    resultadoMultiplicacion = calcularMultiplicacion(a,b);
                    printf("\nEl resultado de la multiplicacion es %.2f \n\n", resultadoMultiplicacion);

                    resultadoFactorizacion = calcularFactorial(a);
                    printf("\nEl factorial es %.2f \n\n", resultadoFactorizacion);

                    system("pause");

                    break;
                }

        }


    } while(opcion != 9);


    return 0;
}




