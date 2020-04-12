/*
 * main.c
 *
 *  Created on: 2 abr. 2020
 *      Author: agus_
 */


#include <stdio.h>
#include <stdlib.h>
/*
 * \brief Solicita un número y lo retorna.
 * \return Número ingresado por el usuario.
 *
 */
int utn_getSoloNumeros(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

float pedirNumero()
{
	float auxiliar;
	printf("Ingrese el numero: ");
	scanf("%f", &auxiliar);
	return auxiliar;
}
/*
 * \brief Comprueba que todos los elementos del conjunto sean numericos
 * \param Es la cadena ingresada anteriormente por el usuario
 * \return retorna 1 si todos salio biene y -1 si no
 *
 */

int esNumerica(char* cadena){
	int ret = -1;
	int i = 0;

	if(cadena != NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			break;
			i++;
		}
		if(cadena[i]=='\0')
		ret=1;
	}

	return ret;
}

/*
 * \brief Solicita al usuario un numero o un grupo de numeros de hasta 64 espacios
 * \param Recibe como parametro el numero ingresado por el usuario
 * \return retorna 1 si salio todoo bien
 *
 */
static int utn_getInt(int* pResultado)
{
	char buffer[64];
	scanf("%s", buffer);
	//funcion para validar
	if(esNumerica(buffer)==1){

	}
	*pResultado = atoi(buffer);

	return 1;
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

int utn_getNumero(float* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int ret;
	int num;
	while(reintentos>0)
	  {
	   printf(mensaje);
	   if(utn_getInt(&num)==1)
	   {
			   break;
	   }
	   fflush(stdin);

	   reintentos--;
	   printf(mensajeError);
	  }
	if(reintentos==0)
	 {
	  ret=-1;
	 }
	 else
	 {
	  ret=0;
	  *pResultado = num;
	 }
	 return ret;
}

float suma(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}

float resta(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}

float multiplicacion(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 * numero2;
	return resultado;
}

float division(float numero1, float numero2)
{
	float resultado;
	if(numero2 != 0){
		resultado = numero1 / numero2;
	}else{
		printf("No es posible dividir por cero\n");
	}
	return resultado;
}

float factorial(float numero)
{
	float resultado = 1;

	while(numero > 1)
	{
		resultado *= numero;
		numero--;
	}
	return resultado;
}

