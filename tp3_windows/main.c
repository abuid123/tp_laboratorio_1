#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#define arch "C:/Users/agus_/Downloads/TP3/eclipse_tp3/tp3_windows/data.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

	setbuf(stdout,NULL);
    int option = 0;
    system("color 02");
    int controlador= 0;
    int controlador2 = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	system("cls");
    	utn_getNumero(&option, "Ingrese una opcion:\n"
    	    		"1)Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    	    		"2)Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    	    		"3)Alta de empleado\n"
    	    		"4)Modificar datos de empleado\n"
    	    		"5)Baja de empleado\n"
    	    		"6)Listar empleados\n"
    	    		"7)Ordenar empleados\n"
    	    		"8)Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    	    		"9)Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    	    		"10)Salir.\n","Error, opcion incorrecta",1,10,3);
        switch(option)
        {
            case 1:
            	if(controlador == 0)
            	{
            		controller_loadFromText(arch,listaEmpleados);
					printf("Archivo de texto cargado exitosamente.\n");
					controlador = 1;
					system("pause");
            	}
            	else
            	{
            		printf("Ya a cargado el archivo de texto!\n");
            		system("pause");
            	}
                break;
            case 2:
            	if(controlador2 == 0)
				{
            		controller_loadFromBinary(arch,listaEmpleados);
					printf("Archivo binario cargado exitosamente.\n");
					controlador2 = 1;
					system("pause");
				}
				else
				{
					printf("Ya a cargado el archivo de texto!\n");
					system("pause");
				}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	controlador = 1;
            	break;
            case 4:
            	if(controlador != 0)
            		controller_editEmployee(listaEmpleados);
            	else
            		printf("Primero debe dar de alta 1 empleado o cargar 1 archivo\n");
            	system("pause");
            	break;
            case 5:
            	if(controlador != 0)
            		controller_removeEmployee(listaEmpleados);
            	else
					printf("Primero debe dar de alta 1 empleado o cargar 1 archivo\n");
            	system("pause");
            	break;
            case 6:
            	if(controlador != 0)
            		controller_ListEmployee(listaEmpleados);
            	else
            		printf("Primero debe dar de alta 1 empleado o cargar 1 archivo\n");
            	system("pause");
            	break;
            case 7:
            	if(controlador != 0)
            		controller_sortEmployee(listaEmpleados);
            	else
					printf("Primero debe dar de alta 1 empleado o cargar 1 archivo\n");
            	system("pause");
            	break;
            case 8:
            	if(!controller_saveAsText("data.csv",listaEmpleados))
            		printf("Se a guardado correctamente como texto.\n");
            	system("pause");
            	break;
            case 9:
            	if(!controller_saveAsBinary("data.csv",listaEmpleados))
            		printf("Se a guardado correctamente como texto.\n");
				system("pause");
            	break;
        }
    }while(option != 10);
    return 0;
}
