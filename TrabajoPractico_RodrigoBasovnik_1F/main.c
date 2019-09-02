/*********************************************************************************************
*Programa: Trabajo Practico N°1
*
*Objetivo:
    Hacer una calculadora. Para ello el programa iniciará y contará con un menu de opciones
    1.Ingresar 1er operando (A=x)
    2.Ingresar 2do operando (B=y)
    3.Calcular todas las operaciones
        a)Calcular la suma (A+B)
        b)Calcular la resta (A-B)
        c)Calcular la division (A/B)
        d)Calcular la multiplicacion (A*B)
        e)Calcular el factorial (A!)
    4.Informar resultados
        a)“El resultado de A+B es: r”
        b)“El resultado de A-B es: r”
        c)“El resultado de A/B es: r” o “No es posible dividir por cero”
        d)“El resultado de A*B es: r”
        e)“El factorial de A es: r1 y El factorial de B es: r2”
    5.Salir

    -Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
    que contenga las funciones para realizar las cinco operaciones.

    -En el menú deberán aparecer los valores actuales cargados en los operandos A y B
    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

    -Deberán contemplarse los casos de error (división por cero, etc)

    -Documentar todas las funciones

*Version 1.0 del 2 de septiembre de 2019.
*Autor: Rodrigo Javier Basovnik.
*Tecnicatura Superior En Programacion - 1° Cuatrimestre - Comision 1°F
*Docente: David Fernandez
*
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    float division;
    int flagOperandoA = 0;
    int flagOperandoB = 0;
    int flagOperations = 0;
    int multiplicacion;
    int operandoA;
    int operandoB;
    int suma;
    int resta;
    long factorialA;
    long factorialB;


    do{
        switch(mostrarMenu(operandoA, operandoB, flagOperandoA, flagOperandoB)){
    case 1:
        printf("Opcion Ingresar Operando A\n");
        scanf("%d", &operandoA);
        flagOperandoA = 1;
        break;
    case 2:
        printf("Opcion Ingresar Operando B\n");
        scanf("%d", &operandoB);
        flagOperandoB = 1;
        break;
    case 3:
        printf("Opcion Calcular Resultados\n");

        if (flagOperandoA == 0 && flagOperandoB == 0){
            printf("Error al realizar los calculos. Por favor ingrese los operandos A y B\n");
        }
        else if (flagOperandoA == 0){
            printf("Error al realizar los calculos. Por favor ingrese el operando A\n");
        }
        else if (flagOperandoB == 0){
            printf("Error al realizar los calculos. Por favor ingrese el operando B\n");
        }
        else {
            suma = sumaOperandos(operandoA, operandoB);
            resta = restaOperandos(operandoA, operandoB);
            division = divisionOperandos(operandoA, operandoB);
            multiplicacion = multiplicacionOperandos(operandoA, operandoB);
            factorialA = factorialOperandoA(operandoA);
            factorialB = factorialOperandoB(operandoB);
            flagOperations = 1;
            printf("Las operaciones fueron realizadas con exito\n");
        }

        break;
    case 4:
        printf("Opcion Mostrar resultados\n");
        if (flagOperations == 0) {
                printf("No se han realizado las operaciones\n");
        }
        else{
                printf("El resultado de A+B es: %d \n", suma);
                printf("El resultado de A-B es: %d \n", resta);
            if (operandoB == 0){
                printf("No es posible dividir por 0\n");
                }
            else{
            printf("El resultado de A/B es: %.2f \n", division);
                }
            printf("El resultado de A*B es: %d \n", multiplicacion);
            printf("El factorial de A! es: %ld  y el factorial de B! es: %ld \n", factorialA, factorialB);
        }
        break;
    case 5:
        printf("Opcion Salir\n");
        seguir = 'n';
        break;
    default:
        printf("Opcion invalida\n");
        break;
        }

    system("pause");

    }while (seguir == 's');

    return 0;
}
