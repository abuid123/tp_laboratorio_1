/*
 * alumno.h
 *
 *  Created on: 29 abr. 2020
 *      Author: Agus
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#include "carreras.h"
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int legajo;
	char nombre[20];
	int edad;
	char sexo;
	int nota1;
	int nota2;
	float promedio;
	eFecha fechaIngreso;
	int idCarrera;
	int isEmpty;
}eAlumno;


#endif /* ALUMNO_H_ */

void inicializarAlumnos(eAlumno alumnos[], int tam);
int modificarAlumno(eAlumno alumnos[], int tam , eCarrera carreras[], int tamC);
void mostrarAlumno(eAlumno alumno, eCarrera carreras[], int tam);
void mostrarAlumnos(eAlumno alumno[], int limite, eCarrera carreras[], int tamC);
int harcodearAlumnos(eAlumno alumnos[], int limite, int cantidad);
int buscarLibre(eAlumno alumno[], int tam);
int altaAlumnoAuto(eAlumno alumno[], int tam, int legajo, eCarrera carreras[], int tamC);
eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int nota1, int nota2, eFecha fecha, int carrera);
int bajaAlumno(eAlumno alumno[], int tam, eCarrera carreras[], int tamC);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
void ordenarAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
