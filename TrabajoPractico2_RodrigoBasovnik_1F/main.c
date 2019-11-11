/*****************
 * Trabajo Practico Nº2 Laboratorio 1 Comision 1F
 * Rodrigo Javier Basovnik
 *****************/

#include <stdio.h>
#include <stdlib.h>
#include "arrayemployees.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define EMPLEN 10
#define UP 1
#define DOWN 0

int main(){

    Employee empleado[EMPLEN];
    Sector sectores[5] = {{1, "Recursos Humanos"},
                          {2, "Ventas"},
                          {3, "Administracion"},
                          {4, "Soporte Tecnico"},
                          {5, "Proveedores"}};

    char seguir = 's';
    int flagCase1 = 0, legajo = 0, checkFlagCase1, opcionInform, buscarLeg, salirInform = 0, i;

    initEmployee(empleado, EMPLEN);

    do{

        switch(showMainManu()){

        case 1:
            printf("\nOpcion Alta Empleado\n");
            flagCase1 = addEmployee(empleado, sectores, EMPLEN, legajo);
            legajo++;
            break;
        case 2:
            if(flagCase1 == 0){
                printf("\nNo se ha dado de alta ningun empleado\n");
                break;
            }
            else{
                printf("\nOpcion Modificar Empleado\n");
                modifyEmployee(empleado, sectores, EMPLEN);
            }
            break;
        case 3:
            if(flagCase1 == 0){
                printf("\nNo se ha dado de alta ningun empleado.");
                break;
            }
            else{
                printf("\nOpcion Baja Empleado\n");
                removeEmployee(empleado, EMPLEN);
            }
            for(i = 0; i < EMPLEN; i++){
                if(empleado[i].isEmpty == 1){
                    checkFlagCase1 = 0;
                    break;
                }
                else{
                    checkFlagCase1 = 1;
                }
            }
            if(checkFlagCase1 == 1){
                flagCase1 = 0;
            }
            break;
        case 4:
            if(flagCase1 == 1){
                printf("\nOpcion Informes");
                printf("\n1-Mostrar todos los legajos");
                printf("\n2-Mostrar un legajo");
                printf("\n3-Volver al menu principal\n");
                scanf("%d", &opcionInform);
                do{
                    switch(opcionInform){
                    case 1:
                        sortEmployees(empleado, EMPLEN, UP);
                        printf("Legajo\tApellido\tNombre\tSalario\tSector\n");
                        printEmployees(empleado, EMPLEN);
                        salirInform = 1;
                        break;
                    case 2:
                        fflush(stdin);
                        printf("\nIngrese Legajo a buscar: ");
                        scanf("%d", &buscarLeg);
                        printEmployee(empleado[buscarLeg]);
                        salirInform = 1;
                        break;
                    case 3:
                        printf("\nOpcion volver al menu principal\n");
                        salirInform = 1;
                        break;
                    default:
                        printf("\nOpcion Incorrecta\n");
                        break;
                    }
                }while(salirInform == 0);
            }
            if(flagCase1 == 0){
                printf("\nNo se ha dado de alta ningun empleado.");
            }
            break;
        case 5:
            printf("\nOpcion Salir\n");
            seguir = 'n';
            break;

        default:
            printf("\nOpcion invalida\n");
            break;

        }

    system("pause");

    }while(seguir == 's');
        return 0;
}
