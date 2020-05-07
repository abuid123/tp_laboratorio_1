/*
 * informes.h
 *
 *  Created on: 4 may. 2020
 *      Author: Agus
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"
#include "carreras.h"

#endif /* INFORMES_H_ */

void listaAlumnosCarrera(eAlumno alumno[], int tam, eCarrera carreras[], int tamC);
void cargarAlumnosPorCarrera(eAlumno vec[],int tam, eCarrera carreras[], int tamC, int idCarrera);
