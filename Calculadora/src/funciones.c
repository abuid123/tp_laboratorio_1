/*
 * funciones.c
 *
 *  Created on: 6 abr. 2020
 *      Author: Agus
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * \brief Dibuja el menu entero, y pregunta que quiere hacer el usuario
 * \param numero1 es el primer numero ingresado por el usuario, el cual va a ser operado luego
 * \param numero2 es el segundo numero ingresado por el usuario, al igual que el numero1 sera operado luego
 * \return 0 en caso de que todoo salga bien
 */
int opcionesMenuDibujo(float numero1, float numero2) {
	setbuf(stdout, NULL);
	printf("\n\t\t\t\tQue operacion desea realizar?\n");
	printf(
			"\t\t°----------------------------------------------------------------°\n");
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t|                           OPERACIONES:                         |\n");
	printf(
			"\t\t|   Suma (%.1f + %.1f)                  Resta    (%.1f - %.1f)   |\n",
			numero1, numero2, numero1, numero2);
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t|   Multiplicacion (%.1f * %.1f)        Division (%.1f / %.1f)   |\n",
			numero1, numero2, numero1, numero2);
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t|   Factorial (%.1f!) o (%.1f!)         Salir                    |\n",
			numero1, numero2);
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t°----------------------------------------------------------------°\n");
	printf(
			"\t\t|                        ¿Que desea hacer?                       |\n");
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t| 1) Calcular resultados              2)Salir                    |\n");
	printf(
			"\t\t|                                                                |\n");
	printf(
			"\t\t°----------------------------------------------------------------°\n");
	return 0;
}

/*
 * \brief Realiza una suma
 * \param numero1 primer numero ingresado
 * \param numero2 segundo numero ingresado
 * \return 0 si salio todo bien
 */
float suma(float numero1, float numero2) {
	float resultado = numero1 + numero2;
	printf("El resultado de la suma de %.2f y %.2f es de: %.2f\n", numero1,numero2, resultado);
	return 0;
}
/*
 * \brief Realiza una resta
 * \param numero1 primer numero ingresado
 * \param numero2 segundo numero ingresado
 * \return 0 si salio todo bien
 */

float resta(float numero1, float numero2) {
	float resultado = numero1 - numero2;
	printf("El resultado de la resta de %.2f y %.2f es de: %.2f\n", numero1,numero2, resultado);
	return 0;
}
/*
 * \brief Realiza una multiplicacion
 * \param numero1 primer numero ingresado
 * \param numero2 segundo numero ingresado
 * \return 0 si salio todo bien
 */
float multiplicacion(float numero1, float numero2) {
	float resultado = numero1 * numero2;
	printf("El resultado de la multiplicacion de %.2f y %.2f es de: %.2f\n",
			numero1, numero2, resultado);
	return 0;
}
/*
 * \brief Realiza una division
 * \param numero1 primer numero ingresado
 * \param numero2 segundo numero ingresado
 * \return 0 si salio todo bien
 */
float division(float numero1, float numero2) {
	float resultado;
	if (numero2 != 0) {
		resultado = (float) numero1 / numero2;
		printf("El resultado de la division de %.2f y %.2f es de: %.2f\n",
				numero1, numero2, resultado);
	} else {
		resultado = printf("No se puede dividir por 0\n");
	}
	return 0;
}
/*
 * \brief imprime el factorial del numero ingresado
 * \param numero1 primer numero ingresado
 * \return 0 si salio toddo bien
 */
float factorialPrimerNumero(float numero1) {
	int contador;
	float resultado;
	resultado = 1;

	for (contador = 1; contador <= numero1; contador++) {
		resultado *= contador;
	}
	printf("El factorial de %.2f es de: %.2f\n", numero1, resultado);
	return 0;
}
/*
 * \brief imprime el factorial del numero ingresado
 * \param numero2 segundo numero ingresado
 * \return 0 en caso de que salga todoo bien
 */
float factorialSegundoNumero(float numero2) {
	int contador;
	float resultado;
	resultado = 1;

	for (contador = 1; contador <= numero2; contador++) {
		resultado *= contador;
	}
	printf("El factorial de %.2f es de: %.2f\n", numero2, resultado);
	return 0;
}

/*
 * \brief Segun la opcion elegida realiza las operaciones matematicas o sale del programa
 * \param opcion Es la opcion elegida por el usuario con anterioridad
 * \param numero1 Es el primer numero ingresado por el usuario
 * \param numero2 Es el segundo numero ingresado por el usuario
 * \return retorna 0 si sale todo bien*/
int opcionMenu(int opcion, float numero1, float numero2) {
		switch (opcion) {
		case 1:
			suma(numero1, numero2);
			resta(numero1, numero2);
			multiplicacion(numero1, numero2);
			division(numero1, numero2);
			factorialPrimerNumero(numero1);
			factorialSegundoNumero(numero2);
			system("pause");
			break;
		case 2:
			break;
		default:
			printf("Opcion incorrecta!\n");
			system("pause");
		}
	return 0;
}

