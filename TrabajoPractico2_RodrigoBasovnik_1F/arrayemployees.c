#include <arrayemployees.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

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

int initEmployee (Employee eList, int eLen){

    int i;

    for (i = 0; i < eLen; i++){
        eList[i].isEmpty == 1;
    }

}

int showSectorsMenu(Sector sList){
    int secMenOption, j;
    for(j = 0; j < 5; j++){
        printf("\nSector Nro %d %s", sList[j].sectorid, sList[j].sectordesc);
    }
    printf("\nIngrese sector: ");
    scanf("%d", &secMenOption);
    return secMenOption;
}

int addEmployee (Employee aList, int aLen, int aId, char name[]){}

int findEmployeeById(Employee fList, int fLen, int fId){}

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

void modifyEmployee (Employee mList[], Sector msList, int indexM){
    int modifCont = 0, sectCont;
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
            do{
                switch(showSectorsMenu(msList)){
                case 1:
                    mList[indexM].sector == 1;
                    sectCont = 1;
                    break;
                case 2:
                    mList[indexM].sector == 2;
                    sectCont = 1;
                    break;
                case 3:
                    mList[indexM].sector == 3;
                    sectCont = 1;
                    break;
                case 4:
                    mList[indexM].sector == 4;
                    sectCont = 1;
                    break;
                case 5:
                    mList[indexM].sector == 5;
                    sectCont = 1;
                    break;
                default:
                    printf("\nSector Incorrecto. Reingrese el sector");
                    break;
                }while(sectCont = 0);
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

int removeEmployee(Employee rList, int rLen, int rId){}

int sortEmployees(Employee sList, int sLen, int order){}

int printEmployees(Employee pList, int pLen){}
