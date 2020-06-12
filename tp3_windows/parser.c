#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Direccion del archivo a leer con los datos
 * \param pArrayListEmployee LinkedList* Puntero a la estructura linkedList
 * \return int retorna -1 si sale mal o 0 si sale bien
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	char bufferName[128];
	char bufferId[128];
	char bufferHoras[128];
	char bufferSueldo[128];
	int cant = 0;
	Employee* auxEmp;
	int i = 0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHoras,bufferSueldo);

		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHoras,bufferSueldo);
			if(cant == 4)
			{
				auxEmp = employee_newParametros(bufferId,bufferName,bufferHoras,bufferSueldo);
				if(auxEmp != NULL)
				{
					ll_add(pArrayListEmployee,auxEmp);
					ret = 0;
					i++;
				}
			}else
			{
				if(feof(pFile))
				{
					printf("Final del archivo, cantidad de bytes leidos: %d.\n",i);
					system("pause");
					break;
				}
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero a la ubicacion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int ret retorna -1 si sale mal y 0 si sale todo bien
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmple = NULL;
    int cant = 0;
    int id;
    while(!feof(pFile))
    {
        auxEmple = employee_new();

        if(auxEmple!=NULL)
        {
        	cant = fread(auxEmple,sizeof(Employee),1,pFile);

			employee_getId(auxEmple,&id);
			employee_setId(auxEmple,id);

			if(cant<1)
			{
				printf("Error al leer los datos\n");
				system("pause");
				break;
			}
			else
			{
				ll_add(pArrayListEmployee,auxEmple);
				retorno = 0;
			}
        }
    }
    return retorno;
}
