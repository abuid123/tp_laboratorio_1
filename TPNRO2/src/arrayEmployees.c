/*
 * arrayEmployees.c
 *
 *  Created on: 14 may. 2020
 *      Author: Agus
 */

#include "arrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int loadedEmployee(Employee list[],int len)
{
	int ret = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}


int initEmployees(Employee list[],int len)
{
	int ret = -1;
	if(list != NULL && len > 0)
	{
		ret = 0;
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return ret;
}

int printEmployees(Employee list[], int length)
{
	int flag = 0;
	system("cls");
	printf("***Employee list***\n");

	printf("Name       Last Name       Salary       Sector       ID      isEmpty\n");
	for(int i = 0; i<length;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printEmployee(list[i]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			system("cls");
			printf("\n---No employees to show---\n");
			system("pause");
		}
	printf("\n\n");
	return 0;
}

void printEmployee(Employee list)
{
	printf("%s     %s      %.2f          %d        %d         %d\n", list.name,list.lastName,list.salary, list.sector, list.id, list.isEmpty);
}


int registerEmployee(Employee array[],int len, int* idCont)
{
	int ret = -1;
	int index;
	int auxId;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	if(array != NULL && len > 0)
	{
		system("cls");
		printf("***Register Employee****\n\n");

		index = findFreeEmployee(array,len);

		if(index == -1)
		{
			printf("Complete system. No more employees can be added");
			system("pause");
		}
		else
		{
			(*idCont)++;
			auxId = *idCont;
			fflush(stdin);
			utn_getName("Enter the name: \n", "ERROR: INCORRECT NAME\n", 0,51,2, name);
			fflush(stdin);
			utn_getName("Enter the last name: \n", "ERROR: LAST NAME INCORREC\n", 0,51,2, lastName);
			fflush(stdin);
			utn_getFloat("Enter the salary: \n", "ERROR.\n", 1,150000, 1, 120000, 2, &salary);
			fflush(stdin);
			utn_getNumero(&sector, "Enter the sector: \n", "ERROR.\n",1,100,2);

			addEmployee(array,len,auxId,name,lastName,salary,sector);
			ret = 1;
		}
	}
	return ret;
}

int findFreeEmployee(Employee array[], int len) {
	int index = -1;

	for (int i = 0; i < len; i++) {
		if (array[i].isEmpty == 1) {
			index = i;
			break;
		}
	}
	return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int ret = -1;
	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{
		list[id].id = id;
		strcpy(list[id].lastName,lastName);
		strcpy(list[id].name,name);
		list[id].salary = salary;
		list[id].sector = sector;
		list[id].isEmpty = 0;

		ret = 0;
	}
	return ret;
}

int modifyEmployee(Employee list[], int len)
{
	int ret = -1;
	int index;
	int idSearch;
	int option;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	if(list != NULL && len > 0)
	{
		system("cls");
		printf("***Modify Employee***\n");

		printEmployees(list,len);

		utn_getNumero(&idSearch,"enter the id of the employee to modify: \n","ERROR: WE DON'T HAVE THAT ID.\n",1,1000,2);

		index = findEmployeeById(list, len, idSearch);

		if(index == -1)
		{
			printf("We don't have a client with that id.\n");
		}else
		{
			utn_getNumero(&option, "What do you want to modify?\n"
					"1) Name.\n"
					"2) Last Name.\n"
					"3) Salary.\n"
					"4) Sector.\n","Error: invalid option",1,4,2);

			switch(option)
			{
			case 1:
				utn_getName("Enter the name: \n", "ERROR: INVALID NAME\n",0, 51, 2, name);
				strcpy(list[index].name, name);
				printf("\nThe name was successfully updated\n");
				ret = 1;
				break;
			case 2:
				utn_getName("Enter the last name: \n", "ERROR: INVALID LAST NAME\n",0, 51, 2, lastName);
				strcpy(list[index].lastName, lastName);
				printf("\nThe last name was successfully updated\n");
				ret = 1;
				break;
			case 3:
				utn_getFloat("Enter the salary: \n", "ERROR.\n", 1,150000, 1, 120000, 2, &salary);
				list[index].salary = salary;
				printf("The salary was successfully updated\n");
				ret = 1;
				break;
			case 4:
				utn_getNumero(&sector, "Enter the sector: \n", "ERROR.\n",1,100,2);
				list[index].sector = sector;
				printf("The sector was successfully updated\n");
				ret = 1;
				break;
			}
			system("pause");
		}
	}
	return ret;
}

int findEmployeeById(Employee list[],int len, int id)
{
	int index = -1;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		for(i = 0; i< len ; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee list[], int len, int id)
{
	int ret = -1;
	int index;

	if(list != NULL && len > 0 && id > 0)
	{
		system("cls");
		printf("***Remove employee***\n");

		index = findEmployeeById(list,len,id);

		if(index == -1)
		{
			printf("We don't have a client with that id.\n");

		}else
		{
			list[index].salary = 0;
			list[index].id = 0;
			list[index].sector = 0;
			strcpy(list[index].name,"");
			strcpy(list[index].lastName,"");
			list[index].isEmpty = 1;
			printf("Employee has been removed.\n");
			ret = 0;
		}
	}
	return ret;
}

int sortEmployees(Employee list[],int len,int option)
{
	int ret = -1;
	Employee auxList;
	int i;
	int j;

	if(list != NULL && len > 0 && option > 0)
	{
		switch(option)
		{
		case 1:
			for(i = 0; i < len - 1; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if(strcmp(list[j].lastName,list[i].lastName)<0)
					{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
					{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
					}
				}
			}
			ret = 0;
			break;
		case 2:
			for(i = 0; i < len - 1; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if(strcmp(list[j].lastName,list[i].lastName)>0)
					{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
					{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
					}
				}
			}
			ret = 0;
			break;
		}
	}
	return ret;
}

int salaryReports(Employee list[],int len)
{
	int ret = -1;
	int i;
	int count = 0;
	float accumulator = 0;
	float total = 0;
	int salaryMoreAverage = 0;
	if(list != NULL  && len > 0)
	{
		printf("***Salary reports***\n\n");

		for(i = 0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				count++;
				accumulator+= list[i].salary;
			}
		}

		total = accumulator / count;

		for(i = 0; i< len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > total)
			{
				salaryMoreAverage++;
			}
		}
		printf("-----------------------------------------\n");
		printf("Total wages: %.2f\n", accumulator);
		printf("Average wages: %.2f\n", total);
		printf("Employees who exceed the average salary: %d\n",salaryMoreAverage);
		printf("-----------------------------------------\n");
		ret = 0;
	}
	return ret;
}
