/*
 * informes.c
 *
 *  Created on: 4 may. 2020
 *      Author: Agus
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"
#include "carreras.h"
#include "informes.h"


void listaAlumnosCarrera(eAlumno alumno[], int tam, eCarrera carreras[], int tamC)
{
	char vCarrera[20];
	int idCarrera;


	mostrarCarreras(carreras, tamC);
	fflush(stdin);
	printf("Eliga la descripcion de la carrera:\n");
	gets(vCarrera);

	//pregunto si encuentra la carrera y me copia el id en mi variable
	cargarIdCarrera(vCarrera, carreras, tam, &idCarrera);

	//Buscar los alumnos para esa carrera
	cargarAlumnosPorCarrera(alumno,tam,carreras,tamC,idCarrera);
	system("pause");
}

void cargarAlumnosPorCarrera(eAlumno vec[],int tam, eCarrera carreras[], int tamC, int idCarrera)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		if(vec[i].idCarrera == idCarrera && vec[i].isEmpty == 0)
		{
			mostrarAlumno(vec[i],carreras,tam);
		}
	}
}
