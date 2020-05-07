/*
 * carreras.h
 *
 *  Created on: 29 abr. 2020
 *      Author: Agus
 */

#ifndef CARRERAS_H_
#define CARRERAS_H_

typedef struct
{
	int id;
	char descripcion[20];
}eCarrera;

#endif /* CARRERAS_H_ */

void mostrarCarrera(eCarrera carrera);
void mostrarCarreras(eCarrera carreras[], int tam);
int cargarDesCarrera(int idCarrera, eCarrera carreras[], int tam, char descripcion[]);
int cargarIdCarrera(char descripcion[], eCarrera carreras[], int tam, int* idCarrera);

