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

    if(response == 1){
        printf("\nDatos cargados correctamente.");
    } else {
        printf("\No se han cargado los datos correctamente.");
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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

