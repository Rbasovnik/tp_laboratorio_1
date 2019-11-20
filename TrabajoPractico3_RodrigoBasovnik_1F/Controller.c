#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int response = 0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"r");
        if(pFile!=NULL){
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            response = 1;
        }else{
            response = 1;
        }
    }

    if(response == 1){
        printf("\nDatos cargados correctamente. ");
    } else {
        printf("\nNo se han cargado los datos correctamente. ");
    }
    return response;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int response = 0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        if(pFile!=NULL){
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            fclose(pFile);
            response = 1;
        }else{
            response = 1;
        }
    }

    return response;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int auxId, auxSalary, auxHorasTrabajadas, success = 0;
    char auxName[30];
    Employee* newEmp;

    printf("\nOpcion Alta.\n");
    if(pArrayListEmployee != NULL){
        auxId = employee_addValidId();
        employee_addValidName(auxName, 30);
        auxHorasTrabajadas = employee_addValidInt("\nIngrese Horas Trabajadas\n", 0);
        auxSalary = employee_addValidInt("\nIngrese sueldo\n", 0);

        newEmp = employee_new();
            if(newEmp != NULL){
                if(employee_setId(newEmp, auxId) == 1 &&
                   employee_setNombre(newEmp, auxName) == 1 &&
                   employee_setHorasTrabajadas(newEmp, auxHorasTrabajadas) == 1 &&
                   employee_setSueldo(newEmp, auxSalary) == 1){
                    ll_add(pArrayListEmployee, newEmp);
                    success = 1;
                    printf("\nEl empleado ha sido dado de alta con exito");
                   }
            }
    }

    if(success == 0){
        printf("\nNo se ha dado de alta correctamente\n");
    }

    return success;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i, id, auxHoras, auxSueldo, resultado = -1, index, len;
    char auxName[30];
    char option;
    Employee* auxEmp = employee_new();

    id = employee_addValidId();
        if(auxEmp != NULL){
            if(ll_len(pArrayListEmployee) != 0){
                len = ll_len(pArrayListEmployee);
                    for(i = 0; i < len; i++){
                        auxEmp = ((Employee*) ll_get(pArrayListEmployee, i));
                            if(auxEmp->id == id){
                                printf("\nEmpleado encontrado!");
                                employee_printEmployee(auxEmp);
                                index = i;
                                printf("\nDesea modificar el ingreso? (S/N)\n");
                                option = getche();
                                while(tolower(option) != 's' && tolower(option) != 'n'){
                                    printf("\nOpcion Incorrecta ingrese 'S' o 'N'\n");
                                    option = getche();
                                }
                                    if(option == 's'){
                                            employee_addValidName(auxName, 30);
                                            auxHoras = employee_addValidInt("Ingrese horas trabajadas modificadas\n", 0);
                                            auxSueldo = employee_addValidInt("Ingrese salario modificado\n", 0);

                                            strcpy(auxEmp->nombre, auxName);
                                            auxEmp->horasTrabajadas = auxHoras;
                                            auxEmp->sueldo = auxSueldo;
                                            ll_remove(pArrayListEmployee, index);
                                            ll_push(pArrayListEmployee, index, auxEmp);
                                            resultado = 1;
                                    }
                                break;
                            }
                    }
            }
        }
    return resultado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int i, id, index, success = -1;
    char option;
    Employee* auxEmployee = employee_new();
        if(auxEmployee != NULL){
            id = employee_addValidId();
                for(i = 0; i < ll_len(pArrayListEmployee); i++){
                    auxEmployee = ((Employee*) ll_get(pArrayListEmployee, i));
                    if (auxEmployee->id == id){
                        printf("\nEmpleado encontrado");
                        employee_printEmployee(auxEmployee);
                        printf("\nDesea eliminar el ingreso? (S/N)");
                        option = getche();
                            while(tolower(option) != 's' && tolower(option) != 'n'){
                                printf("\nOpcion incorrecta ingrese 'S' o 'N'\n");
                                option = getche();
                            }
                            if(tolower(option) == 's'){
                                index = i;
                                ll_remove(pArrayListEmployee, index);
                                success = 1;
                                break;
                            } else{
                                break;
                            }
                    }
                }
        }
    return success;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int response = -1;

    if (pArrayListEmployee != NULL){
        employee_printEmployees(pArrayListEmployee);
        response = 1;
    }

    return response;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int orden, sortType = 1, succeed = 0;
        do{
            switch(employee_sortMenu()){
            case 1:
                printf("\nOpcion ordenar por ID");
                printf("\nIngrese el orden: Ascendente (1) / Descendente (0) ");
                scanf("%d", &orden);
                    while(orden != 0 && orden !=  1){
                        printf("\nOrden incorrecto. Reingrese orden");
                    }
                    if(orden == 0){
                        ll_sort(pArrayListEmployee, employee_sortById,orden);
                        printf("\nOrdenamiento exitoso");
                        succeed = 1;
                    }
                    else if(orden == 1){
                        ll_sort(pArrayListEmployee, employee_sortById,orden);
                        printf("\nOrdenamiento exitoso");
                        succeed = 1;
                    }
                break;
            case 2:
                printf("\nOpcion ordenar por Salario");
                printf("\nIngrese el orden: Ascendente (1) / Descendente (0) ");
                scanf("%d", &orden);
                    while(orden != 0 && orden !=  1){
                        printf("\nOrden incorrecto. Reingrese orden");
                    }
                    if(orden == 0){
                        ll_sort(pArrayListEmployee, employee_sortBySalary,orden);
                        printf("\nOrdenamiento exitoso");
                        succeed = 1;
                    }
                    else if(orden == 1){
                        ll_sort(pArrayListEmployee, employee_sortBySalary,orden);
                        printf("\nOrdenamiento exitoso");
                        succeed = 1;
                    }
                break;
            case 3:
                printf("\nOpcion regresar al menu principal");
                sortType = 0;
                break;
            }
        }while(sortType == 1);

    return succeed;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

