#include <stdio.h>
#include <stdlib.h>
#include <arrayemployees.h>
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
    int flagCase1 = 0, legajo = 0, modificarLegajo, confirmModif, opcionInform;

    initEmployee(empleado, EMPLEN);

    do{

        switch(showMainManu()){

        case 1:
            printf("\nOpcion Alta Empleado");
            flagCase1 = addEmployee(empleado, sectores, EMPLEN, legajo);
            legajo++
            break;
        case 2:
            printf("\nOpcion Modificar Empleado");
            printf("\nIngrese el legajo del empleado que desea modificar");
            scanf("%d", &modificarLegajo)
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
            printf("\nOpcion Informes");
            printf("\n1-Mostrar todos los legajos");
            printf("\n2-Mostrar un legajo");
            scanf("%d", opcionInform);
            do{
                switch(opcionInform){
                case 1:
                    printEmployees(empleado, sectores, EMPLEN);
                    break;
                case 2:
                    printEmployee(empleado, sectores, EMPLEN);
                }

        case 5:
            printf("\nOpcion Salir");
            seguir == 'n';
            break;

        default:
            printf("\nOpcion invalida");
            break;

        }

    system("pause");

    }while(seguir == 's');
        return 0;
}
