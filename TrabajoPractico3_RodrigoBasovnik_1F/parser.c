#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char input[4][30];
        int cant,response = 0;
        Employee* empleado;
        if(pFile != NULL && pArrayListEmployee != NULL){
            while(!feof(pFile)){
                cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n", input[0], input[1], input[2], input[3]);
                empleado = employee_newParametros(input[0],input[1],input[2],input[3]);
                if(empleado != NULL && employee_isValid(empleado)){
                    ll_add(pArrayListEmployee,empleado );
                    response = 1;
                }
                if(cant < 4){
                    if(feof(pFile)){
                        break;
                    }else{
                        response = 0;
                        break;
                    }
                }
            }
        }

    return response;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int respons = 0;
    int cant = 0;
    Employee* empleado;
    if(pFile != NULL && pArrayListEmployee != NULL){
        while(!feof(pFile)){
            empleado = employee_new();
            cant = fread(empleado,sizeof(Employee),1,pFile);
            if(empleado != NULL){
                if(employee_isValid(empleado) == 1){
                    ll_add(pArrayListEmployee,empleado);
                    response = 1;
                }else{
                    employee_delete(empleado);
                }
            }
            if(cant < 1){
                if(feof(pFile)){
                break;
                }else{
                    respons = 0;
                    break;
                }
            }
        }
    }

    return response;
}
