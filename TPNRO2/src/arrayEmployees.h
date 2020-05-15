/*
 * arrayEmployees.h
 *
 *  Created on: 14 may. 2020
 *      Author: Agus
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[],int len);


/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length);


/**\brief print one employee
 * \param list Employee[] pointer to employee
 * \return void
 */
void printEmployee(Employee list);


/**
 * \brief load an employee's data into variables and then pass them to addEmployee
 * \param array[] Employee array pointer to array of employees
 * \param len int Array length
 * \param idCont int* Pointer to an id
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int registerEmployee(Employee array[],int len, int* idCont);


/**
 * \brief Find a free space to load an employee
 * \param array[] Employee pointer to array of Employee
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
 */
int findFreeEmployee(Employee array[], int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[],int len, int id);


/**
 * \brief Modify the selected employee by id
 * \param list[] Employee array pointer to array of employees
 * \param len int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 */
int modifyEmployee(Employee list[], int len);


/**
 * \brief Verify that there is at least 1 loaded employee
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \return Return 0 if everything  its ok or -1 if not
 */
int loadedEmployee(Employee list[],int len);


/**
 * \brief Remove an employee selected by id
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \param int id Id selected for remove
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int removeEmployee(Employee list[], int len, int id);


/**
 * \brief Sort the array of employees
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \param int option Option to sort the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int sortEmployees(Employee list[],int len,int option);


/**
 * \brief Print the Total and Average Wages, and how many employees exceed the Average Wage.
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int salaryReports(Employee list[],int len);
#endif /* ARRAYEMPLOYEES_H_ */
