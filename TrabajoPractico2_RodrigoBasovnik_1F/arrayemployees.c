#include <stdio.h>
#include <stdlib.h>
#include "arrayemployees.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define EMPLEN 10

void customfgets (char cad[], int in){
    int i;
    fflush(stdin);
    fgets(cad, in-2, stdin);

    cad[in-2] = '\0';
    for (i = 0; i < in; i++){
        if (cad[i] == '\n'){
                cad[i] = '\0';
                break;
        }
    }

}

int showMainManu(){
    int mmOption;
    system("cls");
    printf("******** ABM ********");
    printf("\n1- Alta empleado");
    printf("\n2- Modificar empleado");
    printf("\n3- Baja empleado");
    printf("\n4- Informes");
    printf("\n5- Salir");
    printf("\nSeleccione opcion: ");
    scanf("%d", &mmOption);

    return mmOption;
}

void initEmployee (Employee eList[], int eLen){

    int i;

    for (i = 0; i < eLen; i++){
        eList[i].isEmpty = 1;
    }
}

int showSectorsMenu(Sector sList[]){
    int secMenOption, j;
    for(j = 0; j < 5; j++){
        printf("\nSector Nro %d %s", sList[j].sectorid, sList[j].sectordesc);
    }
    printf("\nIngrese sector: ");
    scanf("%d", &secMenOption);
    while(secMenOption < 1 || secMenOption > 5){
        printf("\nSector incorrecto. Reingrese sector");
        scanf("%d", &secMenOption);
    }
    return secMenOption;
}

int isFreeEmployee(Employee ifList[], int ifLen){

    int isFree = -1 , i;

        for(i = 0; i < ifLen; i++){
            if(ifList[i].isEmpty == 1){
                isFree = i;
                break;
            }
        }
    return isFree;
}

int addEmployee (Employee aList[], Sector asList[], int aLen, int aId){

    int isEmptyIndex, flagAdd;

    isEmptyIndex = isFreeEmployee(aList, aLen);

    if(isEmptyIndex == -1){
        printf("\nImposible cargar nuevo empleado. Espacio completo");
    }
    else{

        aList[isEmptyIndex].id = aId;

        printf("\nIngrese Apellido:\n");
        fflush(stdin);
        customfgets(aList[isEmptyIndex].lastName, 51);
        printf("\nIngrese Nombre:\n");
        fflush(stdin);
        customfgets(aList[isEmptyIndex].name, 51);
        printf("\nIngrese salario:\n");
        fflush(stdin);
        scanf("%f", &aList[isEmptyIndex].salary);
        printf("\nSeleccionar Sector");
        fflush(stdin);
        aList[isEmptyIndex].sector = showSectorsMenu(asList);

        aList[isEmptyIndex].isEmpty = 0;
        flagAdd = 1;
        printf("\nAlta exitosa. Empleado registrado en el legajo Nro %d\n", aId);
    }
    return flagAdd;
}

int findEmployeeById(Employee fList[], int fLen, int fId){
    int k, flagFound = 0;

    for(k = 0; k < fLen; k++){
        if(fList[k].id ==  fId && fList[k].isEmpty == 0){
            flagFound = 1;
            break;
        }
        else{
            flagFound = 0;
        }
    }

    return flagFound;
}

int showModificationMenu (void){
    int modMenOption;
    printf("\n**MENU DE MODIFICACION**");
    printf("\n1-Modificar Nombre");
    printf("\n2-Modificar Apellido");
    printf("\n3-Modificar Salario");
    printf("\n4-Modificar Sector");
    printf("\n5-Volver a Menu Principal");
    printf("\nIngrese opcion: ");
    scanf("%d", &modMenOption);

    return modMenOption;
}

void modifyEmployee (Employee mList[], Sector msList[], int mLen){
    int modifCont = 0, sectCont, i, modificarLegajo;
    char  confirmModif;

    printf("\nIngrese el legajo del empleado que desea modificar\n");
    scanf("%d", &modificarLegajo);
        if(findEmployeeById(mList, EMPLEN, modificarLegajo) == 1){
            printf("\nSe encontro el legajo: \n");
            printEmployee(mList[modificarLegajo]);
            printf("\nDesea modificarlo? S / N\n");
            fflush(stdin);
            confirmModif = getche();
            confirmModif = tolower(confirmModif);
            if (confirmModif == 's'){
                for(i = 0; i < mLen; i++){
                    if(mList[i].id == modificarLegajo){
                        modificarLegajo = i;
                    }
                }
                do{
                    switch(showModificationMenu()){
                    case 1:
                        fflush(stdin);
                        printf("\nIngrese el nombre: ");
                        customfgets(mList[modificarLegajo].name, 51);
                        break;
                    case 2:
                        fflush(stdin);
                        printf("\nIngresar Apellido: ");
                        customfgets(mList[modificarLegajo].lastName, 51);
                        break;
                    case 3:
                        fflush(stdin);
                        printf("\nIngresar Salario: ");
                        scanf("%f", &mList[modificarLegajo].salary);
                        break;
                    case 4:
                        fflush(stdin);
                        sectCont = showSectorsMenu(msList);
                        mList[modificarLegajo].sector = sectCont;
                        break;
                    case 5:
                        printf("\nOpcion Salir\n");
                        modifCont = 1;
                        break;
                    default:
                        printf("\nOpcion incorrecta\n");
                        break;
                    }
                }while(modifCont == 0);
            }
            else{
                printf("\nLegajo no encontrado en el sistema\n");
            }
        }
}

void removeEmployee(Employee rList[], int rLen){
    int i, flagRemoval = 0, bajaLegajo;
    char confirmBaja;

    printf("\nIngrese el legajo del empleado que desea dar de baja: ");
    scanf("%d", &bajaLegajo);
        if(findEmployeeById(rList, EMPLEN, bajaLegajo) == 1){
            printf("\nSe encontro el legajo: ");
            printEmployee(rList[bajaLegajo]);
            printf("\nDesea continuar con la baja? S / N\n");
            fflush(stdin);
            confirmBaja = getche();
            confirmBaja = tolower(confirmBaja);
            if (confirmBaja == 's'){
                for(i = 0; i < rLen; i++){
                    if(rList[i].id == bajaLegajo){
                        bajaLegajo = i;
                    }
                }
                rList[bajaLegajo].isEmpty = 1;
                flagRemoval = 1;
            }
        }
        else{
            printf("\nLegajo no encontrado en el sistema\n");
        }
        if(flagRemoval == 1){
            printf("\nBaja dada con exito!\n");
        }

}

//int sortEmployees(Employee sList[], int sLen, int order){}

void printEmployee(Employee pOList){

    printf("\n%d\t%s\t%s\t%.2f\t%d\n", pOList.id, pOList.lastName, pOList.name, pOList.salary, pOList.sector);

}

void printEmployees(Employee pAList[], int pLen){
    int i, contador = 0;

    for(i = 0; i < pLen; i++){
        if(pAList[i].isEmpty == 0){
            printEmployee(pAList[i]);
            contador++;
        }
    }

    if(contador == 0){
        printf("\nNo hay empleados por mostrar");
    }
}
