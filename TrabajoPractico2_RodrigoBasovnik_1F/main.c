#include <stdio.h>
#include <stdlib.h>
#include "arrayemployees.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define EMPLEN 10

int main(){

    Employee empleado[EMPLEN];
    Sector sectores[5] = {{1, "Recursos Humanos"},
                          {2, "Ventas"},
                          {3, "Administracion"},
                          {4, "Soporte Tecnico"},
                          {5, "Proveedores"}};

    char seguir = 's';
    int flagCase1 = 0, legajo = 0, modificarLegajo, confirmModif, opcionInform, buscarLeg, salirInform = 0;

    initEmployee(empleado, EMPLEN);

    do{

        switch(showMainManu()){

        case 1:
            printf("\nOpcion Alta Empleado");
            flagCase1 = addEmployee(empleado, sectores, EMPLEN, legajo);
            legajo++;
            break;
        case 2:
            printf("\nOpcion Modificar Empleado");
            printf("\nIngrese el legajo del empleado que desea modificar");
            scanf("%d", &modificarLegajo);
            if(findEmployeeById(empleado, EMPLEN, modificarLegajo)){
                printf("\nSe encontro el legajo: ");
                printEmployee(empleado, sectores, modificarLegajo);
                printf("\nDesea modificarlo? S / N");
                confirmModif = getche();
                confirmModif = tolower(confirmModif);
                if (confirmModif == 's'){
                    modifyEmployee(empleado, sectores, EMPLEN, modificarLegajo);
                }
            }
            break;
        case 3:
            printf("\nOpcion Baja Empleado");

        case 4:
            if(flagCase1 == 1){
                printf("\nOpcion Informes");
                printf("\n1-Mostrar todos los legajos");
                printf("\n2-Mostrar un legajo");
                printf("\n3-Volver al menu principal");
                scanf("%d", &opcionInform);
                do{
                    switch(opcionInform){
                    case 1:
/*                        printEmployees(empleado, sectores, EMPLEN);
                        system("pause");*/
                        break;
                    case 2:
                        fflush(stdin);
                        printf("\nIngrese Legajo a buscar: ");
                        scanf("%d", &buscarLeg);
                        printEmployee(empleado, sectores, buscarLeg);
                        salirInform = 1;
                        break;
                    case 3:
                        printf("\nOpcion volver al menu principal");
                        salirInform = 1;
                        break;
                    default:
                        printf("\nOpcion Incorrecta");
                        break;
                    }
                }while(salirInform == 0);
            }
            if(flagCase1 == 0){
                printf("\nNo se ha dado de alta ningun empleado.");
            }
            break;
        case 5:
            printf("\nOpcion Salir");
            seguir = 'n';
            break;

        default:
            printf("\nOpcion invalida");
            break;

        }

    system("pause");

    }while(seguir == 's');
        return 0;
}
