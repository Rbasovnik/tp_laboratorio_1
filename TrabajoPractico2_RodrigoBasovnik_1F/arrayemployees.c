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
        if(fList[k].id ==  fId){
            flagFound = 1;
            break;
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

void modifyEmployee (Employee mList[], Sector msList[], int mLen, int indexM){
    int modifCont = 0, sectCont, i;

    for(i = 0; i < mLen; i++){
        if(mList[i].id == indexM){
            indexM = i;
        }
    }

    do{
        switch(showModificationMenu()){
        case 1:
            fflush(stdin);
            printf("\nIngrese el nombre: ");
            customfgets(mList[indexM].name, 51);
            break;
        case 2:
            fflush(stdin);
            printf("\nIngresar Apellido: ");
            customfgets(mList[indexM].lastName, 51);
            break;
        case 3:
            fflush(stdin);
            printf("\nIngresar Salario: ");
            scanf("%f", &mList[indexM].salary);
            break;
        case 4:
            fflush(stdin);
            sectCont = showSectorsMenu(msList);
            mList[indexM].sector = sectCont;
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

//int removeEmployee(Employee rLis[]t, int rLen, int rId){}

//int sortEmployees(Employee sList[], int sLen, int order){}

void printEmployee(Employee pOList[], Sector pOsList[], int pId){

    printf("\n%d\t%s\t%s\t%.2f\t%d\t%s", pOList[pId].id, pOList[pId].lastName, pOList[pId].name, pOList[pId].salary, pOList[pId].sector, pOsList[pOList[pId].sector-1].sectordesc);

}

/*void printEmployees(Employee pAList[], Sector pAsList[], int pLen){
    int l;

    for(l = 0; l < pLen; l++){
        printEmployee(pAList[l], pAsList[pAList[l].sector - 1], EMPLEN);
    }

}

*/
