/*
 * carreras.c
 *
 *  Created on: 29 abr. 2020
 *      Author: Agus
 */

#include "carreras.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void mostrarCarreras(eCarrera carreras[], int tam)
{
	printf("ID           Descripcion\n\n");
	for(int i = 0; i < tam; i++){
		mostrarCarrera(carreras[i]);
	}
	printf("\n");
}

void mostrarCarrera(eCarrera carrera)
{
	printf("%d     %s\n", carrera.id, carrera.descripcion);
}

int cargarDesCarrera(int idCarrera, eCarrera carreras[], int tam, char descripcion[])
{
	int todoOk = 0;

	for(int i = 0; i<tam; i++)
	{
		if(carreras[i].id == idCarrera)
		{
			strcpy(descripcion,carreras[i].descripcion);
			todoOk = 1;
			break;
		}
	}

	return todoOk;
}

int cargarIdCarrera(char descripcion[], eCarrera carreras[], int tam, int* idCarrera)
{
	int todoOk = 0;

	for(int i = 0; i < tam; i++)
	{
		if(strcmp(carreras[i].descripcion, descripcion) == 0)
		{
			*idCarrera = carreras[i].id;
			todoOk = 1;
			break;
		}
	}

	return todoOk;
}
