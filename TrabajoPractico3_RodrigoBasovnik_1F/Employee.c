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

void employee_printEmployee(Employee* this){
    if (this != NULL){
        printf("\n%5d %20s %20d %20d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    } else{
        printf("\nPointer incorrecto");
    }
}

void employee_printEmployees(LinkedList* lList){
    int i;
        if(lList != NULL){
            printf("\n%5s %20s %20s %20s", "Id", "Nombre", "Horas", "Sueldo");
            for(i = 0; i < ll_len(lList); i++){
                employee_printEmployee((Employee*) ll_get(lList,i));
            }
        }
}


int employee_sortById( void* employee, void* otherEmployee){
    int result = 0;
    Employee* ptr1;
    Employee* ptr2;

    if(employee != NULL && otherEmployee != NULL ){
        ptr1 = (Employee*) employee;
        ptr2 = (Employee*) otherEmployee;

        if(ptr1->id > ptr2->id){
            result = 1;
        } else if(ptr1->id < ptr2->id){
            result = -1;
        } else {
            result = 0;
        }
    }
    return result;
}


int employee_sortBySalary( void* employee, void* otherEmployee){
    int result = 0;
    Employee* ptr1;
    Employee* ptr2;

    if(employee != NULL && otherEmployee != NULL ){
        ptr1 = (Employee*) employee;
        ptr2 = (Employee*) otherEmployee;

        if(ptr1->sueldo > ptr2->sueldo){
            result = 1;
        } else if(ptr1->sueldo < ptr2->sueldo){
            result = -1;
        } else {
            result = 0;
        }
    }
    return result;
}

int employee_addValidId(){
    int input;
        printf("\nIngrese ID");
        scanf("%d", &input);
        while(input == 0){
            printf("\nId Incorrecto. Ingrese un ID distinto de 0");
        }
    return input;
}

void employee_addValidName(char name[], int len){
    char aux[len];
        printf("\nIngrese nombre\n");
        fflush(stdin);
        fgets(aux, len, stdin);
        while (aux == '\0'){
            ("\nError. Ingrese un nombre valido. ");
            fflush(stdin);
            fgets(aux, len, stdin);
        }
        strcpy(name, aux);
}

int employee_addValidInt(char message[], int minRange){
    int input;
        printf("\n%s", message);
        scanf("%d", &input);
        while(input < minRange){
            printf("\nIngreso incorrecto. Debe ser mayor a 0");
        }
    return input;
}
