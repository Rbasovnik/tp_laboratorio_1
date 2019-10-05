
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

void initEmployee (Employee eList[], int eLen);

int showSectorsMenu(Sector sList[]);

int isFreeEmployee(Employee ifList[], int ifLen);

int addEmployee (Employee aList[], Sector asList[], int aLen, int aId);

int findEmployeeById(Employee fList[], int fLen, int fId);

int showModificationMenu (void);

void modifyEmployee (Employee mList[], Sector msList[], int mLen);

void removeEmployee(Employee rList[], int rLen);

int sortEmployees(Employee sList[], int sLen, int order);

void printEmployee(Employee pOList);

void printEmployees(Employee pAList[], int pLen);
