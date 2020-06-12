#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
static int esNumerica(char *cadena);

/*
 * \brief Inicializa un nuevo empleado cargando todos sos datos a 0
 * \return retorna un empleado inicializado
 *
 */
Employee* employee_new()
{
	Employee* this;
	this = (Employee*)malloc(sizeof(Employee));
	if(this != NULL)
	{
		employee_setNombre(this, "");
		employee_setHorasTrabajadas(this,0);
		employee_setId(this,0);
		employee_setSueldo(this,0);
	}
	return this;
}

/*
 * \brief crea un empleado con los parametros pasados como argumentos
 * \param char* idStr puntero al id del empleado
 * \param char* nombreStr puntero al nombre del empleado
 * \param char* horasTrabajadasStr puntero a las horas del empleado
 * \param char* sueldoStr puntero al sueldo del empleado
 * \return retorna un empleado tipo Employee*
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* this;
	this = employee_new();
	if(this != NULL)
	{
		employee_setNombre(this, nombreStr);
		employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
		employee_setId(this,atoi(idStr));
		employee_setSueldo(this,atoi(sueldoStr));
	}
	return this;
}

/*
 * \brief Borra un empleado de la memoria dinamica
 * \param Employee* this puntero a un empleado
 * \return int [-1] si sale mal, 0 si sale todo bien
 */
int employee_delete(Employee* this)
{
	int ret = -1;
	if(this != NULL)
	{
		ret = 0;
		free(this);
	}
	return ret;
}

/*
 * \brief lista todos los empleados
 * \param LinkedList* pArrayListEmployees puntero a la linkedList
 * \return ret int [-1] si sale mal, 0 si sale todo bien
 */
int employee_listEmployees(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int len;
	Employee* auxEmp;
	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("  ID\tNombre\tHoras\tSueldo\n");

		len = ll_len(pArrayListEmployee);
		for(int i = 0; i < len; i++)
		{
			auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
			employee_mostrarUnEmpleado(auxEmp);
			ret = 0;
		}
		system("pause");
	}else
	{
		printf("No se pudo cargar la lista\n");
		system("pause");
	}
	return ret;
}

/*
 * \brief muestra un empleado solo
 * \param Employee* auxEmployee puntero a un empleado a mostrar
 * \return int ret [-1] si sale mal, 0 si sale todo bien
*/
int employee_mostrarUnEmpleado(Employee* auxEmployee)
{
    int ret = -1;
    if(auxEmployee!=NULL)
    {
    	int id;
    	int horasTrabajadas;
    	char nombre[128];
    	int sueldo;
    	employee_getId(auxEmployee,&id);
    	employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
    	employee_getNombre(auxEmployee,nombre);
    	employee_getSueldo(auxEmployee,&sueldo);
        printf("  %d      %s    %d   %d \n",id,nombre,horasTrabajadas,sueldo);
        ret = 0;
    }
    return ret;
}

/*
 * \brief obtiene el id y lo devuelve a una variable
 * \param Employee* this puntero a un empleado
 * \param int* id puntero a una variable donde almacenar el id obtenido
 * \return retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/**
 * \brief setea el nombre del empleado
 * \param Employee* this puntero a un empleado
 * \param char* nombre puntero al nombre a set seteado
 * \return ret retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
		if(this != NULL && nombre != NULL)
		{
			if(isValidName(nombre))
			{
				retorno = 0;
				strcpy(this->nombre,nombre);
			}
		}
		return retorno;
}

/**
 * \brief obtiene el nombre y lo devuelve a una variable
 * \param Employee* this puntero a un empleado
 * \param int* nombre puntero a una variable donde almacenar el nombre obtenido
 * \return retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}

/**
 * \brief setea las horas trabajas del empleado
 * \param Employee* this puntero a un empleado
 * \param int horasTrabajadas horas a ser seteadas
 * \return ret retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	char horasTrabajadasStr[36];
	itoa(horasTrabajadas,horasTrabajadasStr,10);
	if(this != NULL && horasTrabajadas >= 0)
	{
		if(esNumerica(horasTrabajadasStr))
		{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
		}
	}
	return retorno;
}

/**
 * \brief obtiene las horas trabajadas y lo devuelve a una variable
 * \param Employee* this puntero a un empleado
 * \param int* horasTrabajadas puntero a una variable donde almacenar las horas obtenidas
 * \return retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas !=NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/**
 * \brief setea el sueldo del empleado
 * \param Employee* this puntero a un empleado
 * \param int sueldo sueldo a ser seteadas
 * \return ret retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	char sueldoStr[36];
	itoa(sueldo,sueldoStr,10);
	if(this != NULL && sueldo >= 0)
	{
		if(esNumerica(sueldoStr))
		{
		retorno = 0;
		this->sueldo = sueldo;
		}
	}
	return retorno;
}

/**
 * \brief obtiene el sueldo de un empleado y lo devuelve a una variable
 * \param Employee* this puntero a un empleado
 * \param int* sueldo puntero a una variable donde almacenar el sueldo obtenido
 * \return retorno int [-1] si sale mal, 0 si sale todo bien
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo !=NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

/**
 * \brief imprime en pantalla un solo empleado
 * \param Employee* auxEmployee puntero a un empleado
 * \return int ret [-1] si sale mal, 0 si sale todo bien
 */
int employee_printEmployee(Employee* auxEmployee)
{
    int ret = -1;
    if(auxEmployee!=NULL)
    {
        printf(" | %5d | %15s | %10d | %10d |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        ret = 0;
    }
    return ret;
}

/**
 * \brief imprime toda la lista de empleados
 * \param LinkedList* puntero a la linkedlist
 * \return int ret [-1] si sale mal, 0 si sale todo bien
 */
int employee_ListEmployees(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("|   ID  |     NOMBRE      |   HORAS  |   SUELDO   |\n");

        for(int i=0;i<len;i++)
        {
        	employee_printEmployee((Employee*)ll_get(pArrayListEmployee,i));//ll_get al devolver un void* lo casteo a Employee*.
            ret = 0;
        }
    }
    if(ret == -1)
    {
        printf("Error: No se pudo cargar la lista.\n");
    }

    return ret;
}

/**
 * \brief setea el id del empleado
 * \param Employee* this puntero a un empleado
 * \param int id, id del empelado a ser seteado
 * \return int ret [-1] si sale mal, 0 si sale todo bien
 */
int employee_setId(Employee* this, int id)
{
    int ret = -1;
    static int IdMaximo = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            IdMaximo++;
            this->id = IdMaximo;
        }
        else
        {
            if(id>IdMaximo)
            {
                this->id = id;
                IdMaximo = id;
            }
        }
        ret = 0;
    }
    return ret;
}

/**
 * \brief criterio para ordenar por id
 * \param void* pElement1 puntero a void
 * \param void* pEleemnt2 puntero a void
 * \return int ret retorna 0 si son iguales, 1 si el de la izquierda es mayor al de la derecha y -1 si el de la derecha es mayor al de la izquierda
 */
int employee_ordenarPorId(void* pElement1, void* pElement2)
{
	int ret = 0;

	Employee* employee1 = (Employee*)pElement1;
	Employee* employee2 = (Employee*)pElement2;

	if(employee1->id > employee2->id)
	{
		ret = 1;
	}
	else if(employee1->id < employee2->id)
	{
		ret = -1;
	}

	return ret;
}

/**
 * \brief criterio para ordenar por nombre
 * \param void* pElement1 puntero a void
 * \param void* pEleemnt2 puntero a void
 * \return int ret retorna 0 si son iguales, 1 si el de la izquierda es mayor al de la derecha y -1 si el de la derecha es mayor al de la izquierda
 */
int employee_ordenarPorNombre(void* pElement1, void* pElement2)
{
	int ret = 0;

	Employee* employee1 = (Employee*)pElement1;
	Employee* employee2 = (Employee*)pElement2;

	if(strcmp(employee1->nombre, employee2->nombre)> 0)
	{
		ret = 1;
	}
	else if(strcmp(employee1->nombre, employee2->nombre)< 0)
	{
		ret = -1;
	}

	return ret;
}

/**
 * \brief criterio para ordenar por sueldo
 * \param void* pElement1 puntero a void
 * \param void* pEleemnt2 puntero a void
 * \return int ret retorna 0 si son iguales, 1 si el de la izquierda es mayor al de la derecha y -1 si el de la derecha es mayor al de la izquierda
 */
int employee_ordenarPorSueldo(void* pElement1, void* pElement2)
{
	int ret = 0;

	Employee* employee1 = (Employee*)pElement1;
	Employee* employee2 = (Employee*)pElement2;

	if(employee1->sueldo > employee2->sueldo)
	{
		ret = 1;
	}
	else if(employee1->sueldo < employee2->sueldo)
	{
		ret = -1;
	}

	return ret;
}

/**
 * \brief criterio para ordenar por horas
 * \param void* pElement1 puntero a void
 * \param void* pEleemnt2 puntero a void
 * \return int ret retorna 0 si son iguales, 1 si el de la izquierda es mayor al de la derecha y -1 si el de la derecha es mayor al de la izquierda
 */
int employee_ordenarPorHoras(void* pElement1, void* pElement2)
{
	int ret = 0;

	Employee* employee1 = (Employee*)pElement1;
	Employee* employee2 = (Employee*)pElement2;

	if(employee1->horasTrabajadas > employee2->horasTrabajadas)
	{
		ret = 1;
	}
	else if(employee1->horasTrabajadas < employee2->horasTrabajadas)
	{
		ret = -1;
	}

	return ret;
}

/**
 * \brief valida que la cadena ingresante sea numerica
 * \param char* cadena puntero a char
 * \return int ret retorna 1 si sale mal y 0 si no
 */
static int esNumerica(char *cadena)
{
	int ret = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				ret = 0;
				break;
			}
			i++;
		}
	}

	return ret;
}

