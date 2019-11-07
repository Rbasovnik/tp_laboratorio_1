#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
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
    char salir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        fflush(stdin);
        switch(printMenu())
        {
            case 1:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo Binario)\n");
                //controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
                break;
            case 3:
                printf("Opcion Alta Empleado.\n");
                //controller_addEmployee(LinkedList* pArrayListEmployee);
                break;
            case 4:
                printf("Opcion Modificar Empleado.\n");
                //controller_editEmployee(LinkedList* pArrayListEmployee);
                break;
            case 5:
                printf("Opcion Baja Empleado.\n");
                //controller_removeEmployee(LinkedList* pArrayListEmployee);
                break;
            case 6:
                printf("Opcion Listar Empleados.\n");
                //controller_ListEmployee(LinkedList* pArrayListEmployee);
                break;
            case 7:
                printf("Opcion Ordenar Empleados.\n");
                //controller_sortEmployee(LinkedList* pArrayListEmployee);
                break;
            case 8:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
                //controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
                break;
            case 9:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
                //controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
                break;
            case 10:
                printf("Opcion Salir.\n");
                printf("Desea salir del programa? ( S / N )\n");
                salir = tolower(getche());
                printf("\n");
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        system("pause");
    }while(salir != 's');
    return 0;
}
