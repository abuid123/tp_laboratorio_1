#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero a la direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArch;
	int ret = -1;
	int controlCarga;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArch = fopen(path,"r");
		if(pArch != NULL)
		{
			controlCarga = parser_EmployeeFromText(pArch,pArrayListEmployee);
			if(controlCarga == 0)
			{
				fclose(pArch);
				ret = 0;
			}else
			{
				printf("No se pudo abrir el archivo.\n");
			}
		}
	}
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = -1;
    int controlCarga;
    pFile = fopen(path,"rb");

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        controlCarga = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        if(controlCarga == 0)
            retorno = 0;
    }
    else
    {
    	printf("No se pudo abrir el archivo.\n");
    }

    fclose(pFile);

    return retorno;
}
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	Employee* this;
	int horasTrabajadas;
	int sueldo;
	char nombre[128];
	this = employee_new();
	if(this != NULL)
	{
		system("cls");
		printf("Alta de empleado.\n");

		if(utn_getName("Ingrese el nombre: \n", "Error nombre invalido.\n",1,128,3,nombre) == 0)
		{
			if(utn_getNumero(&sueldo,"Ingrese el sueldo:\n","Error sueldo invalido\n",200,500000,3)== 0)
			{
				if(utn_getNumero(&horasTrabajadas,"Ingrese las horas trabajadas:\n","Error horas erroneas\n",1,10000,3) == 0)
				{
					employee_setHorasTrabajadas(this,horasTrabajadas);
					employee_setId(this,-1);
					employee_setNombre(this,nombre);
					employee_setSueldo(this,sueldo);

					ll_add(pArrayListEmployee,this);

					printf("Alta exitosa\n");
					system("pause");
					ret = 0;

				}
			}
		}
	}
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* this;
	int len = ll_len(pArrayListEmployee);
	int ret = -1;
	int option;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int idAModificar;
	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("MODIFICAR EMPLEADO\n");
		utn_getNumero(&idAModificar,"\nIngrese el id a modificar: \n","Error, id no valido'n",1,1050,3);


		for(int i = 0; i < len; i++)
		{
			this = (Employee*)ll_get(pArrayListEmployee,i);
			if(this->id == idAModificar)
			{
				printf("  ID\tNombre\tHoras\tSueldo\n");

				employee_mostrarUnEmpleado(this);
				printf("-----------------------------\n");

				utn_getNumero(&option, "Que opcion desea modificar?\n"
						"1) Nombre\n"
						"2) Sueldo\n"
						"3) Horas trabajadas\n"
						"4) Salir\n","Error opcion invalida\n",1,4,3);

				switch(option)
				{
				case 1:
					if(utn_getName("Ingrese el nombre:\n","Error nombre invalido.\n",1,128,3,nombre)==0)
					{
						ret = 0;
						employee_setNombre(this,nombre);
						printf("Nombre modificado correctamente\n");
					}
					break;
				case 2:
					if(utn_getNumero(&sueldo,"Ingrese el sueldo\n","Error sueldo invalido\n",200,500000,3)==0)
					{
						ret = 0;
						employee_setSueldo(this,sueldo);
						printf("Sueldo modificado correctamente\n");
					}
					break;
				case 3:
					if(utn_getNumero(&horasTrabajadas,"Ingrese las horas\n","Error horas invalido\n",1,10000,3)==0)
					{
						ret = 0;
						employee_setHorasTrabajadas(this,horasTrabajadas);
						printf("Horas modificadas correctamente\n");
					}
					break;
				case 4:
					printf("Usted cancelo la modificacion de datos.\n");
					break;
				}
			}
		}
		if(ret == -1)
		{
			printf("No se encontro a alguien con ese id\n");
		}
	}
    return ret;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	Employee* this;
	int idAEliminar;
	char confirmacion;
	int auxId;
	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("Eliminar empleado.\n");

		int len = ll_len(pArrayListEmployee);
		employee_ListEmployees(pArrayListEmployee);
		utn_getNumero(&idAEliminar,"Ingrese el id a eliminar:\n","Error, id invalido\n",1,1050,3);

		for(int i = 0; i < len; i++)
		{
			this = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(this,&auxId);
			if(auxId == idAEliminar)
			{
				printf("  ID\tNombre\tHoras\tSueldo\n");
				employee_mostrarUnEmpleado(this);
				printf("---------------------------");

				utn_getCaracter(&confirmacion,"\nEsta seguro que desea eliminar el empleado?\n","Error caracter invalido\n",'n','s',3);

				if(confirmacion == 's')
				{
					ll_remove(pArrayListEmployee,i);
					employee_delete(this);
					printf("Baja exitosa\n");
					ret = 0;
					break;
				}else if(confirmacion == 'n')
				{
					printf("Baja cancelada.\n");
					ret = 0;
				}
				else
				{
					printf("Opcion invalida\n");
					ret = 0;
				}
			}
		}
		if(ret == -1)
		{
			printf("No tenemos a nadie con ese id\n");
		}
	}
    return ret;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	if(pArrayListEmployee != NULL)
	{
		if(employee_listEmployees(pArrayListEmployee))
		{
			ret = 0;
		}
	}
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int option;
	int orden;
	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("Ordenar empleados\n");
		utn_getNumero(&option,"Ingrese el criterio para ordenar:\n"
				"1) ID\n"
				"2) Nombre\n"
				"3) Horas Trabajadas\n"
				"4) Sueldo\n"
				"5) Salir\n","Error, opcion invalida\n",1,5,3);

		utn_getNumero(&orden, "De que manera quiere ordenar?\n"
				"Ascendente(ingrese 1)\n"
				"Descendente(ingrese 0)\n"
				"Cancelar (Ingrese 2)\n","Error ingrese una opcion valida\n",0,2,3);

		if(orden == 2)
		{
			printf("Ah cancelado el ordenamiento y sera devuelto al menu\n");
			system("pause");
		}
		if(orden != 2)
		{
			switch(option)
					{
					case 1:
						ll_sort(pArrayListEmployee,employee_ordenarPorId,orden);
						printf("Ordenado por ID correcto\n");
						ret = 0;
						break;
					case 2:
						ll_sort(pArrayListEmployee,employee_ordenarPorNombre,orden);
						printf("Ordenado por nombre correcto\n");
						ret = 0;
						break;
					case 3:
						ll_sort(pArrayListEmployee,employee_ordenarPorHoras,orden);
						printf("Ordenado por horas correcto\n");
						ret = 0;
						break;
					case 4:
						ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,orden);
						printf("Ordenado por sueldo correcto\n");
						ret = 0;
						break;
					}
		}
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* puntero a la direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	FILE* pFile;
	Employee* auxEmp;
	int auxId;
	int auxSueldo;
	int auxHoras;
	char auxNombre[128];
	int len = ll_len(pArrayListEmployee);
	if(path != NULL && pArrayListEmployee != NULL && len > 0)
	{
		pFile = fopen(path,"w");
		if(pFile !=NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

			for(int i = 0; i < len; i ++)
			{
				auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
				if(auxEmp != NULL)
				{
					employee_getId(auxEmp,&auxId);
					employee_getSueldo(auxEmp,&auxSueldo);
					employee_getHorasTrabajadas(auxEmp,&auxHoras);
					employee_getNombre(auxEmp,auxNombre);

					fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);

				}
			}
			fclose(pFile);
			ret = 0;
		}
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* puntero a la direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int len = ll_len(pArrayListEmployee);
	if(path != NULL && pArrayListEmployee != NULL && len > 0)
	{
		FILE* pFile;

		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,pFile);
			}

			fclose(pFile);
			ret = 0;
		}
	}
    return ret;
}

