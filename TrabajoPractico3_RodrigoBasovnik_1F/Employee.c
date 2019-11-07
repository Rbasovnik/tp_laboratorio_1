#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){

    Employee* this = malloc(sizeof(Employee));

    if (this != NULL){
        this->id = 0;
        strcpy(this->nombre, " ");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
        this = employee_new();
            if(this != NULL){
                if(employee_setId(this, atoi(idStr)) == 0 || employee_setNombre(this, nombreStr) == 0 || employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) == 0 || employee_setSueldo(this, atoi(sueldoStr)) == 0){
                    free(this);
                    this = NULL;
            }
        }
    }
    return this;
}

void employee_delete();

int employee_setId(Employee* this,int id){
    int resultado = 0;
        if(this != NULL && id > 0){
            this->id = id;
            resultado = 1;
        }

    return resultado;
}

int employee_getId(Employee* this,int* id){
    int resul = 0;
    if(this != NULL && id > 0){
        *id = this-> id;
        resul = 1;
    }
    return resul;
}

int employee_setNombre(Employee* this,char* nombre){
    int result = 0;
        if(this != NULL && nombre != '\0'){
        strcpy(this->nombre, nombre);
        result = 1;
        }
    return result;
}
int employee_getNombre(Employee* this,char* nombre){
    int resultado = 0;
        if(this != NULL && nombre != '\0'){
            strcpy(nombre, this->nombre);
            resultado = 1;
        }
    return resultado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int result = 0;
        if(this != NULL && horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        result = 1;
        }
    return result;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
   int resul = 0;
    if(this != NULL && horasTrabajadas > 0){
        *horasTrabajadas = this->horasTrabajadas;
        resul = 1;
    }
    return resul;
}

int employee_setSueldo(Employee* this,int sueldo){
    int res = 0;
        if(this != NULL && sueldo > 999){
            this->sueldo = sueldo;
            res = 1;
        }
    return res;
}
int employee_getSueldo(Employee* this,int* sueldo){
    int resul = 0;
    if(this != NULL && *sueldo > 999){
        *sueldo = this->sueldo;
        resul = 1;
    }
    return resul;
}

int printMenu(){
    int option;
    system("cls");
    printf("********Menu de opciones********\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir.\n");
    printf("Ingrese la opcion deseada\n");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}
