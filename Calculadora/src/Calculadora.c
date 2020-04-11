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
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	float numero1, numero2;
	int opcion;

	printf("Ingrese el primer numero: (A=x)\n");
	scanf("%f", &numero1);
	printf("Ingrese el segundo numero: (B=y)\n");
	scanf("%f", &numero2);

	system("CLS");
	printf("\t\tNumero 1 (A=%.2f)", numero1);
	printf("\t\t\tNumero 2 (B=%.2f)\n", numero2);

	opcionesMenuDibujo(numero1, numero2);
	scanf("%d", &opcion);

	opcionMenu(opcion, numero1,numero2);

	return EXIT_SUCCESS;
}
