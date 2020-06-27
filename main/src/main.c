/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"

#define arch "C:/Users/agus_/eclipse-workspace/main/src/data.csv"

int main(void) {
	setbuf(stdout,NULL);
	int opcion2;
	int control=0;
	int opcion;
	char nombreArchivo[128];
	LinkedList* pListaProductos = ll_newLinkedList();
	system("color 02");
	do
	{
		system("cls");
		utn_getNumero(&opcion,"Ingrese una opcion: \n"
				"1) Leer el archivo y guardarlos en la LinkedList\n"
				"2) Ordenar por articulo de manera ascendente\n"
				"3) Imprimir todos los Articulos de la Distribuidora\n"
				"4) Calcular descuentos\n"
				"5) Generar archivo con los descuentos\n"
				"6) Salir\n"
				"7) Informes", "Error, opcion invalida\n",1,7,3);

		switch(opcion)
		{
		case 1:
			printf("Ingrese el nombre del archivo a abrir\n");
			gets(nombreArchivo);
			if(!controller_loadFromText(arch,pListaProductos))
			{
				printf("Archivo leido con exito\n");
				system("pause");
			}
			break;
		case 2:
			if(!controller_sortArticle(pListaProductos))
			{
				printf("Ordenado por articulos de manera ascendente, completado\n");
				system("pause");
			}
			break;
		case 3:
			controller_ListArticle(pListaProductos);
			break;
		case 4:
			if(!controller_calcularDescuento(pListaProductos))
			{
				control = 1;
				printf("Descuentos hechos exitosamente\n");
			}
			break;
		case 5:
			if(control == 1)
			{
				if(!controller_saveAsText("mapeado.csv",pListaProductos))
						printf("Archivo guardado con exito\n");
				system("pause");
			}else
			{
				printf("Primero tiene que cargar un archivo y hacer los descuentos\n");
				system("pause");
			}
			break;
		case 7:
			utn_getNumero(&opcion2,"1) Cantidad de Artículos cuyo precio sea mayor a $100\n"
					"2) Cantidad de Artículos del Rubro 1 – CUIDADO DE ROPA\n","Error, opcion invalida\n",1,2,3);
			switch(opcion2)
			{
			case 1:
				controller_cantidadArticulosMayorACien(pListaProductos);
				break;
			case 2:
				controller_cantidadArticulosRubro1(pListaProductos);
				break;
			}
			break;
		}
	}while(opcion != 6);
	return EXIT_SUCCESS;
}
