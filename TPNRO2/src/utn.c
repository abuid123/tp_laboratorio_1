/*
 * main.c
 *
 *  Created on: 2 abr. 2020
 *      Author: agus_
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

static int esNumerica(char *cadena);
static int utn_getInt(int *pResultado);
static int myGets(char *cadena, int longitud);
/*
 * \brief Solicita un número y lo retorna.
 * \return Número ingresado por el usuario.
 *
 */
float pedirNumero() {
	float auxiliar;
	printf("Ingrese el numero: ");
	scanf("%f", &auxiliar);
	return auxiliar;
}
/*
 * \brief Esta funcion sirve para calcular el area de un circulo
 * \param Radio correspondiente al radio del circulo
 * \return El area del circulo
 *
 */
float calcularAreaCirculo(float radio) {
	float resultado;
	resultado = 3.14 * radio * radio;
	return resultado;
}

/*
 * \brief Comprueba que todos los elementos del conjunto sean numericos
 * \param Es la cadena ingresada anteriormente por el usuario
 * \return retorna 1 si todos salio biene y -1 si no
 *
 */

static int esNumerica(char *cadena) {
	int ret = 1;
	int i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				ret = 0;
				break;
			}
			i++;
		}
	}

	return ret;
}

/*
 * \brief Solicita al usuario un numero o un grupo de numeros de hasta 64 espacios
 * \param Recibe como parametro el numero ingresado por el usuario
 * \return retorna 1 si salio todoo bien
 *
 */
static int utn_getInt(int *pResultado) {
	int ret = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			ret = 0;
		}
	}

	return ret;
}

/*
 * \brief Obtiene un numero, y valida si cumple los parametros, si no, descuenta 1 intento hasta llegar a los intentos
 * establecidos, tambien comprueba si los numeros son enteros mediante la funcion utn_getInt
 *
 * \param pResultado puntero a variable donde se escribira el valor ingresado en el caso de ser correcto.
 * \param mensaje puntero a cadena de caracteres con mensaje a imprimir antes de pedir los datos por consola.
 * \param mensajeError puntero a cadena de caracteres  con mensaje de error en el caso de que el dato ingresado no sea valido.
 * \param minimo valor minimo aceptado(inclusive)
 * \param maximo valor maximo aceptado(inclusive)
 * \param reintentos Cantidad de veces que se le volvera a pedir al usuario que ingrese un dato en caso de error.
 * \return retorna -1 si se queda sin reintentos y retorna 0 si salio todoo bien
 *
 */

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int num;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (utn_getInt(&num) == 0) {
			if (num <= maximo && num >= minimo) {
				*pResultado = num;
				retorno = 0;
				break;
			}
		}

		printf("%s", mensajeError);
	}
	return retorno;
}

static int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo) {
				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
	int retorno=-1;
	char bufferStr[max+10];

	if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
	{
		do
		{
			printf("%s",msg);
			fgets(bufferStr,sizeof(bufferStr),stdin);
			bufferStr[strlen(bufferStr)-1]='\0';

			if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
			{
				strncpy(resultado,bufferStr,max);
				retorno=0;
				break;
			}
			printf("%s 1",msgError);
			(*reintentos)--;
		}
		while((*reintentos)>=0);
	}
	return retorno;
};

int utn_getTelefono(char *msj, char *mensajeError, int minSize, int maxSize,
		int min, int max, int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msj != NULL && mensajeError != NULL
			&& min
					< max&& minSize < maxSize && reintentos >= 0 && input != NULL) {
		do {
			if (!getString(msj, mensajeError, minSize, maxSize, &reintentos,
					bufferStr)) {
				if (telefonoValido(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", mensajeError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int telefonoValido(char *string) {
	int retorno = 1;
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		if ((string[i] < '\0' || string[i] > '9')
				&& (string[i] != '-' || string[i] != ' ')) {
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int utn_getDni(char *mensaje, char *mensajeError, int min, int max,
		int reintentos, char *input) {
	int retorno = -1;
	min = 8; //sin puntos
	max = 11; //con puntos
	char bufferStr[max];

	if (mensaje != NULL && mensajeError != NULL
			&& min < max&& reintentos >= 0 && input != NULL) {
		do {
			if (!getString(mensaje, mensajeError, min, max, &reintentos,
					bufferStr)) {
				if (dniValido(bufferStr) == 1) {
					strncpy(input, bufferStr, max);
					retorno = 0;
					break;
				} else {
					printf("%s 2", mensajeError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}

	return retorno;
}

int dniValido(char *string) {
	int retorno = 1;
	int i;

	for (i = 0; string[i] != '\0'; i++) {
		if ((string[i] < '0' || string[i] > '9') && (string[i] != '.')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getEmail(char *mensaje, char *mensajeError, int min, int max,
		int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[max + 10];

	if (mensaje != NULL && mensajeError != NULL
			&& min < max&& reintentos >= 0 && input != NULL) {
		do {
			if (!getString(mensaje, mensajeError, min, max, &reintentos,
					bufferStr)) {
				if (validarEmail(bufferStr) == 1) {
					strncpy(input, bufferStr, max);
					retorno = 0;
					break;
				} else {
					printf("%s 2", mensajeError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}

	return retorno;
}

int validarEmail(char *string) {
	int retorno = 1;
	int i;

	for (i = 0; string[i] != '\0'; i++) {
		if ((string[i] < '-' && string[i] != '+')
				|| (string[i] > '9' && string[i] < '@')
				|| (string[i] > 'Z' && string[i] != '_' && string[i] < 'a')
				|| string[i] > 'z') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        //printf("%d",i);
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTexto(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr); // atof array to float
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
