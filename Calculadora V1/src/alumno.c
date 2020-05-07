/*
 * alumno.c
 *
 *  Created on: 29 abr. 2020
 *      Author: Agus
 */

#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "carreras.h"

void inicializarAlumnos(eAlumno alumnos[], int tam) {
	for (int i = 0; i < tam; i++) {
		alumnos[i].isEmpty = 1;
	}
}

void mostrarAlumno(eAlumno alumno, eCarrera carreras[], int tam) {
	char descCarrera[20];
	if(cargarDesCarrera(alumno.idCarrera, carreras, tam, descCarrera))
	{
		printf(
			"%d          %10s          %2d          %c          %2d               %2d               %4.2f              %02d/02%d/%d              %d              %d              %s\n",
			alumno.legajo, alumno.nombre, alumno.edad, alumno.sexo,
			alumno.nota1, alumno.nota2, alumno.promedio,
			alumno.fechaIngreso.dia, alumno.fechaIngreso.mes,
			alumno.fechaIngreso.anio, alumno.idCarrera, alumno.isEmpty, descCarrera);
	}

}

void mostrarAlumnos(eAlumno alumno[], int limite, eCarrera carreras[], int tamC)
{
	int flag = 0;
	system("cls");
	printf("*****Listado de alumnos*****");

	printf("\n\nLegajo          Nombre          Edad          Sexo          Nota1          Nota2          Promedio          Fecha Ingreso          ID Carrera          isEmpty          Descripcion\n");
	for(int i = 0; i<limite;i++)
	{
		if(alumno[i].isEmpty == 0)
		{
			mostrarAlumno(alumno[i], carreras, tamC);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		system("cls");
		printf("\n---No hay alumnos que mostrar---\n");
	}

	printf("\n\n");
}



int harcodearAlumnos(eAlumno alumnos[], int limite, int cantidad)
{
	int cont = 0;

	eAlumno listaAuxiliar[] =
	{
			{20000, "Juan", 20, 'm', 10, 9, 9.5, {12, 05, 2018}, 1000, 0},
			{20001, "Agustin", 20, 'm', 5, 5, 5, {24, 03, 2016}, 1001, 0},
			{20002, "Yanina", 45, 'f', 10, 10, 10, {30, 01, 2000}, 1002, 0},
			{20003, "Geronimo", 17, 'm', 1, 1, 1, {18, 4, 2003}, 1002, 0},
			{20004, "Carla", 33, 'f', 5, 10, 7.5, {03, 11, 1999}, 1001, 0},
			{20005, "Roberto", 51, 'm', 10, 8, 9, {23, 12, 2010}, 1000, 0}
	};

	if(cantidad <= limite && cantidad < 7)
	{
		for(int i = 0; i< cantidad; i++)
		{
			alumnos[i] = listaAuxiliar[i];
			cont++;
		}
	}

	return cont;
}

int altaAlumnoAuto(eAlumno alumno[], int tam, int legajo, eCarrera carreras[], int tamC)
{
	int todoOk = 0;
	int indice;
	int edad;
	int nota1;
	int nota2;
	int idCarrera;
	char sexo;
	char nombre[20];
	eFecha fecha;

	system("cls");
	printf("***Alta Alumno****\n\n");

	indice = buscarLibre(alumno, tam);

	if(indice == -1)
	{
		printf("Sistema Completo. No se pueden agregar mas alumnos.\n");
		system("pause");
	}
	else
	{
		fflush(stdin);
		utn_getName("Ingrese el nombre: \n", "ERROR: NOMBRE INCORRECTO\n", 0,20,2, nombre);
		fflush(stdin);
		utn_getNumero(&edad, "Ingrese la edad: ", "ERROR: EDAD INCORRECTA",18,100,2);
		fflush(stdin);
		utn_getCaracter(&sexo,"\nIngrese el sexo(m o f): ","ERROR Caracter invalido", 'f', 'm',2);
		fflush(stdin);
		utn_getNumero(&nota1, "Ingrese la nota1: ", "ERROR: NOTA INCORRECTA",1,10,2);
		fflush(stdin);
		utn_getNumero(&nota2, "Ingrese la nota2: ", "ERROR: NOTA INCORRECTA",1,10,2);
		fflush(stdin);

		printf("Ingrese la fecha: dd/mm/aaaa");
		scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

		mostrarCarreras(carreras, tamC);
		fflush(stdin);
		utn_getNumero(&idCarrera,"Ingrese el id de la carrera", "Error: id incorrecto", 1000, 1002,2);

		alumno[indice] = newAlumno(legajo, nombre, sexo, edad,nota1,nota2, fecha,idCarrera);
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(eAlumno alumno[], int tam)
{
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(alumno[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int nota1, int nota2, eFecha fecha, int carrera)
{
	eAlumno nuevoAlumno;
	nuevoAlumno.legajo = legajo;
	strcpy(nuevoAlumno.nombre,nombre);
	nuevoAlumno.sexo = sexo;
	nuevoAlumno.edad = edad;
	nuevoAlumno.nota1 = nota1;
	nuevoAlumno.nota2 = nota2;
	nuevoAlumno.promedio = (float) (nota1 + nota2)/2;
	nuevoAlumno.fechaIngreso = fecha;
	nuevoAlumno.idCarrera = carrera;
	nuevoAlumno.isEmpty = 0;

	return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
	int todoOk = -1;
	int indice;
	int legajo;
	char confirma;

	system("cls");
	printf("***Baja Alumno***");

	fflush(stdin);
	utn_getNumero(&legajo, "\nIngrese el legajo: ", "Error, legajo incorrecto",20000,50000,2);

	printf("\n\nLegajo          Nombre          Edad          Sexo          Nota1          Nota2          Promedio          Fecha Ingreso          ID Carrera         isEmpty         Descripcion\n\n");
	indice = buscarAlumno(legajo, alumnos, tam);

	if(indice == -1){
		printf("No tenemos registrado ese legajo.\n\n");
		system("pause");
	}else
	{
		mostrarAlumno(alumnos[indice],carreras,tamC);
		utn_getCaracter(&confirma, "\n\nConfirma eliminacion? (s o n)\n", "Error caracter invalido", 'n', 's' ,2);
		if(confirma == 's')
		{
			alumnos[indice].isEmpty = 1;
			printf("\n\nSe ha eliminado el alumno.\n");
			todoOk = 1;
		}
		else
		{
			printf("\n\nSe ha cancelado la baja.\n");
		}
		system("pause");
	}

	return todoOk;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{
	int indice = -1;

	for(int i = 0; i<tam; i++)
	{
		if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int modificarAlumno(eAlumno alumnos[], int tam , eCarrera carreras[], int tamC)
{
	int todoOk = 0;
	int indice;
	int legajo;
	int opcion;
	int nota;

	system("cls");
	printf("*** Modificar Alumno***\n\n");

	fflush(stdin);
	utn_getNumero(&legajo, "Que legajo desea modificar?\n", "Error: Legajo erroneo", 20000,50000,2);

	indice = buscarAlumno(legajo,alumnos, tam);

	if(indice == -1)
	{
		printf("\nNo se encontro el alumno\n");
		system("pause");
	}
	else
	{
		printf("\n\nLegajo          Nombre          Edad          Sexo          Nota1          Nota2          Promedio          Fecha Ingreso          ID Carrera          isEmpty          Descripcion\n");
		mostrarAlumno(alumnos[indice], carreras,tamC);
		printf("Modificar\n\n");
		printf("Nota parcial 1\n");
		printf("Nota parcial 2\n");

		utn_getNumero(&opcion, "Que nota desea modificar?\n", "Error: opcion erronea", 1,2,2);

		if(opcion == 1)
		{
			utn_getNumero(&nota, "Ingrese la nota 1: \n", "Error: nota erronea", 1,10,2);
			alumnos[indice].nota1 = nota;
			alumnos[indice].promedio = (float)(alumnos[indice].nota1 + alumnos[indice].nota2)/2;
			printf("\nSe actualizo la nota y el promedio.\n");
			todoOk = 1;
		}
		else if(opcion == 2)
		{
			utn_getNumero(&nota, "Ingrese la nota 2: \n", "Error: nota erronea", 1,10,2);
			alumnos[indice].nota2 = nota;
			alumnos[indice].promedio = (float)(alumnos[indice].nota1 + alumnos[indice].nota2)/2;
			printf("\nSe actualizo la nota y el promedio.\n");
			todoOk = 1;
		}
		else{
			printf("\nNo es una opcion valida.\n");
		}
		system("pause");
	}

	return todoOk;
}
void ordenarAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
	eAlumno auxAlumno;

	for(int i = 0; i < tam; i++)
	{
		if(alumnos[i].promedio < alumnos[i+1].promedio && alumnos[i].isEmpty == 0 && alumnos[i+1].isEmpty == 0)
		{
			auxAlumno = alumnos[i];
			alumnos[i] = alumnos[i+1];
			alumnos[i+1] = auxAlumno;
		}
	}
	printf("***Alumnos ordenados por promedio****\n\n");
}
