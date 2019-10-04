
typedef struct{
    int sectorid;
    char sectordesc[51];
}Sector;

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void customfgets (char cad[], int in);

int showMainManu();

int initEmployee (Employee eList, int eLen);

int showSectorsMenu(Sector sList);

int addEmployee (Employee aList, int aLen, int aId, char name[])

int findEmployeeById(Employee fList, int fLen, int fId);

int showModificationMenu (void);

int removeEmployee(Employee rList, int rLen, int rId);

int sortEmployees(Employee sList, int sLen, int order);

int printEmployees(Employee pList, int pLen);
