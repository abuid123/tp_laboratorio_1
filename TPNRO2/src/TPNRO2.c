/*
 ============================================================================
 Name        : TPNRO2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "utn.h"

#define QTY_EMPLOYEES 1000

int menu ();
int reportsMenu();

int main(void) {
	setbuf(stdout,NULL);

	int r;
	int answer = 0;
	int idEmployee = 0;
	int searchId;
	int answer2 = 0;
	int order;
	Employee arrayEmployees[QTY_EMPLOYEES];

	r = initEmployees(arrayEmployees,QTY_EMPLOYEES);
	if(r == -1)
	{
		printf("Error invalid length or NULL pointer\n");
	}
	else
	{
		do
		{
			switch(menu())
			{
			case 1:
				registerEmployee(arrayEmployees,QTY_EMPLOYEES,&idEmployee);
				printf("Client loaded successfully\n");
				break;
			case 2:

				if(loadedEmployee(arrayEmployees,QTY_EMPLOYEES)==0)
				{
					modifyEmployee(arrayEmployees,QTY_EMPLOYEES);
				}else
					printf("You have to load at least one employee.\n");

				break;
			case 3:

				if(loadedEmployee(arrayEmployees,QTY_EMPLOYEES)==0)
				{
					printEmployees(arrayEmployees,QTY_EMPLOYEES);
					utn_getNumero(&searchId,"Enter the id what do you want to remove.\n","THAT ID DOESNT EXIST.\n",1,QTY_EMPLOYEES,2);
					removeEmployee(arrayEmployees,QTY_EMPLOYEES,searchId);
				}else
					printf("You have to load at least one employee.\n");

				break;
			case 4:
				if(loadedEmployee(arrayEmployees,QTY_EMPLOYEES)==0)
				{
					do
					{
						switch(reportsMenu())
						{
						case 1:
							utn_getNumero(&order,"Sort by:\n"
									"1) upward.\n"
									"2) downwards.\n","ERROR INVALID OPTION.\n",1,2,2);
							sortEmployees(arrayEmployees,QTY_EMPLOYEES,order);
							printEmployees(arrayEmployees,QTY_EMPLOYEES);
							break;
						case 2:
							salaryReports(arrayEmployees,QTY_EMPLOYEES);
							break;
						case 3:
							answer2 = 3;
							break;
						}
					}while(answer2 != 3);
				}else
					printf("You have to load at least one employee.\n");

				break;
			case 5:
				answer = 5;
				printf("Thank you and good bye\n");
				break;
			}
		}while(answer != 5);
	}

	return EXIT_SUCCESS;
}


int menu ()
{
	int option;
	system("cls");
	printf("Option Menu\n\n");
	printf("1) Register an employee\n");
	printf("2) Modify Employee\n");
	printf("3) Remove Employee\n");
	printf("4) List Employees\n");
	printf("5) Exit\n");
	utn_getNumero(&option, "Enter option: \n","Error invalid option\n",
			1, 5, 2);

	return option;
}

int reportsMenu()
{
	int option;
	system("cls");
	printf("REPORTS\n");
	printf("1)List of employees alphabetically sorted by Last Name and Sector.\n");
	printf("2)Total and average wages, and how many employees exceed the average wage.\n");
	printf("3)Exit.\n");
	utn_getNumero(&option, "Enter option: \n","Error invalid option\n",
				1, 3, 2);
	return option;
}
