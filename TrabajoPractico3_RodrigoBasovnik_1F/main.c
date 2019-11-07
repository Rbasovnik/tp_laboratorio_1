#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        printMenu();
        scanf("%d", option);
        switch(option)
        {
            case 1:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo Binario)\n");

                break;
            case 3:
                printf("Opcion Alta Empleado.\n");

                break;
            case 4:
                printf("Opcion Modificar Empleado.\n");

                break;
            case 5:
                printf("Opcion Baja Empleado.\n");

                break;
            case 6:
                printf("Opcion Listar Empleados.\n");

                break;
            case 7:
                printf("Opcion Ordenar Empleados.\n");

                break;
            case 8:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");

                break;
            case 9:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");

                break;
            case 10:
                printf("Opcion Salir\n");

                break;
            default:
                printf("Opcion Incorrecta");
                break;
        }
    }while(option != 10);
    return 0;
}
