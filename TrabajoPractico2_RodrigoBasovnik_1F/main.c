#include <stdio.h>
#include <stdlib.h>
#include <arrayemployees.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main(){

    Employee empleado;
    Sector sectores[5] = {{1, "Recursos Humanos"},
                          {2, "Ventas"},
                          {3, "Administracion"},
                          {4, "Soporte Tecnico"},
                          {5, "Proveedores"}};

    char seguir = 's';

    do{

        switch(showMainManu()){

        case 1:
            printf("\nOpcion Alta Empleado");

        case 2:
            printf("\nOpcion Modificar Empleado");

        case 3:
            printf("\nOpcion Baja Empleado");

        case 4:
            printf("\nOpcion Informes");

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
