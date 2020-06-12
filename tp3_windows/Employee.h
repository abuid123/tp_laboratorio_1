#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
	int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#include "LinkedList.h"
#include "Controller.h"
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


int employee_mostrarUnEmpleado(Employee* auxEmployee);
int employee_delete(Employee* this);

int employee_getId(Employee* this,int* id);
int employee_setId(Employee* this, int id);

int employee_listEmployees(LinkedList* pArrayListEmployee);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printEmployee(Employee* auxEmployee);
int employee_ListEmployees(LinkedList* pArrayListEmployee);

int employee_ordenarPorId(void* pElement1, void* pElement2);
int employee_ordenarPorNombre(void* pElement1, void* pElement2);
int employee_ordenarPorSueldo(void* pElement1, void* pElement2);
int employee_ordenarPorHoras(void* pElement1, void* pElement2);
#endif // employee_H_INCLUDED
