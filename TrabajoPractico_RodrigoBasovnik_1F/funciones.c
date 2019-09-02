#include <stdio.h>
#include <stdlib.h>


int mostrarMenu(int operA, int operB, int flagA, int flagB){

    int opcion;

    system("cls");
    printf("*** Menu de Opciones ***\n\n");
    if(flagA == 0){
        printf("1- Ingresar Operando A = x\n");
    }else {
        printf("1- Operando A = %d \n", operA);}
    if(flagB == 0){
        printf("2- Ingresar Operando B = y\n");
    }else {
        printf("2- Ingresar Operando B = %d \n", operB);}
    printf("3- Calcular Operaciones\n");
    printf("4- Mostrar resultados\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion:  ");
    scanf("%d", &opcion);

    return opcion;
}




int sumaOperandos(int operA, int operB){
    int suma;
    suma = operA + operB;
    return suma;
}



int restaOperandos(int operA, int operB){
    int resta;
    resta = operA - operB;
    return resta;
}



float divisionOperandos(int operA, int operB){
    float division;
    division = (float) operA / operB;
    return division;
}




int multiplicacionOperandos(int operA, int operB){
    int multiplicacion;
    multiplicacion = operA * operB;
    return multiplicacion;
}



long factorialOperandoA(int operA){
    long factorial = 0;
    if (operA <= 1){
        factorial = 1;
    }
    else {
        factorial = operA * factorialOperandoA(operA-1);
    }
    return factorial;
}



long factorialOperandoB(int operB){
    long factorial = 0;
    if (operB <= 1){
        factorial = 1;
    }
    else {
        factorial = operB * factorialOperandoB(operB - 1);
    }
    return factorial;
}

