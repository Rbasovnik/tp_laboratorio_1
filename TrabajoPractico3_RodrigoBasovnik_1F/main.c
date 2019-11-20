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
    int success, flagCarga = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        fflush(stdin);
        switch(employee_printMenu())
        {
            case 1:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
                controller_loadFromText("data.csv",listaEmpleados);
                flagCarga = 1;
                system("pause");
                break;
            case 2:
                printf("Opcion cargar los datos de los empleados desde el archivo data.csv (modo Binario)\n");
                controller_loadFromBinary("data.csv" , listaEmpleados);
                flagCarga = 2;
                system("pause");
                break;
            case 3:
                success = controller_addEmployee(listaEmpleados);
                if(success == 1){
                printf("\nDatos cargados correctamente.\n");
                } else {
                    printf("\nNo se han cargado los datos correctamente.\n");
                }
                system("pause");
                break;
            case 4:
                printf("Opcion Modificar Empleado.\n");
                if(flagCarga != 0){
                    success = controller_editEmployee(listaEmpleados);
                    if(success == 1){
                        printf("\nModificacion exitosa\n");
                    } else{
                        printf("\nModificacion cancelada\n");
                    }
                } else{
                    printf("\nError. No se han cargado datos\n");
                }
                system("pause");
                break;
            case 5:
                printf("Opcion Baja Empleado.\n");
                if(flagCarga != 0){
                    success = controller_removeEmployee(listaEmpleados);
                        if(success == 1){
                            printf("\nBaja exitosa\n");
                        } else{
                            printf("\nBaja cancelada\n");
                        }
                } else{
                    printf("\nError. No se han cargado los datos");
                }
                system("pause");
                break;
            case 6:
                printf("Opcion Listar Empleados.\n");
                success = controller_ListEmployee(listaEmpleados);
                    if(flagCarga == 0){
                        printf("\nNo se han listado los emmpleados. No estan cargados los datos\n");
                    }
                    if(success == -1){
                        printf("\nNo se han listado los empleados. Ocurrio un error\n");
                    }
                system("pause");
                break;
            case 7:
                printf("Opcion Ordenar Empleados.\n");
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
                //controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
                system("pause");
                break;
            case 9:
                printf("Opcion Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
                //controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
                system("pause");
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
