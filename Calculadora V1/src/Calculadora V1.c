/*
 ============================================================================
 Name        : Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main(void) {
	setbuf(stdout,NULL);
	char respuesta;
	int opcion;
	float numero1 = 0;
	float numero2 = 0;
	float sumaRetorno;
	float restaRetorno;
	float multiplicacionRetorno;
	float divisionRetorno;
	float factorial1Retorno;
	float factorial2Retorno;

	do
	{
		system("CLS");

		printf("1. Ingresar 1er operando (A= %.2f)\n", numero1);
		printf("2. Ingresar 2do operando (B= %.2f)\n", numero2);
		printf("3. Calcular operaciones\n");
		printf("	1) Calcular la suma (A+B)\n");
		printf("	2) Calcular la resta (A-B)\n");
		printf("	3) Calcular la division (A/B)\n");
		printf("	4) Calcular la multiplicacion (A*B)\n");
		printf("	5) Calcular el factorial (A! y B!)\n");
		printf("	6) Calcular todas las opciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Que desea hacer?\n");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				printf("Ingrese el primer numero: \n");
				scanf("%f",&numero1);
				break;
			case 2:
				printf("Ingrese el segundo numero: \n");
				scanf("%f",&numero2);
				break;
			case 3:
				sumaRetorno = suma(numero1, numero2);
				restaRetorno = resta(numero1, numero2);
				multiplicacionRetorno = multiplicacion(numero1,numero2);
				divisionRetorno = division(numero1,numero2);
				factorial1Retorno = factorial(numero1);
				factorial2Retorno = factorial(numero2);
				printf("Calculos hechos!\n");
				break;
			case 4:
				printf("El resultado de la suma de %.1f y %.1f es de: %.1f\n", numero1, numero2, sumaRetorno);
				printf("El resultado de la resta de %.1f y %.1f es de: %.1f\n", numero1, numero2, restaRetorno);
				printf("El resultado de la multiplicacion de %.1f y %.1f es de: %.1f\n", numero1, numero2, multiplicacionRetorno);
				printf("El resultado de la division de %.1f y %.1f es de: %.1f\n", numero1, numero2, divisionRetorno);
				printf("El resultado del factorial de %.1f es de: %.1f\n", numero1, factorial1Retorno);
				printf("El resultado del factorial de %.1f es de: %.1f\n", numero2, factorial2Retorno);
				break;
			case 5:
				break;
			default:
				printf("ERROR: opcion no valida!\n");
		}
		fflush(stdin);
		printf("Deseas realizar otra operacion?(s/n)\n");
		scanf("%c", &respuesta);
	}while(respuesta == 's');
	return EXIT_SUCCESS;
}
