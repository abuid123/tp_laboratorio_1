/*
 * biblioteca.h
 *
 *  Created on: 2 abr. 2020
 *      Author: agus_
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_



#endif /* BIBLIOTECA_H_ */
float pedirNumero();
float calcularAreaCirculo(float radio);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
float calcularAreaCirculo(float radio);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getTelefono(char* msj, char*mensajeError, int minSize, int maxSize, int min, int max, int reintentos, char* input);
int telefonoValido(char* string);
int dniValido(char* string);
int utn_getDni(char *mensaje, char *mensajeError, int min, int max,
		int reintentos, char *input);
int validarEmail(char* string);
int utn_getEmail(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* input);
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido) ;
int isValidTexto(char* stringRecibido);
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);
