#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printMenu();
void employee_printEmployee(Employee* this);
void employee_printEmployees(LinkedList* lList);

int employee_sortById( void* employee, void* auxEmployee);
int employee_sortBySalary( void* employee, void* auxEmployee);

int employee_addValidId();
void employee_customfgets (char cad[], int in);
void employee_addValidName(char name[], int len);
int employee_addValidInt(char message[], int minRange);

#endif // employee_H_INCLUDED
