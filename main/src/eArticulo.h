/*
 * eArticulo.h
 *
 *  Created on: 25 jun. 2020
 *      Author: Agus
 */

#ifndef EARTICULO_H_
#define EARTICULO_H_
typedef struct
{
	int id;
	char articulo[128];
	float precio;
	char medida[128];
	int rubroId;
}eArticulo;

#include "LinkedList.h"
#include "Controller.h"

eArticulo* articulo_new();
eArticulo* articulo_newParametros(char* idStr,char* nombreStr,char* precioStr,char* idRubroStr, char* medida);

int articulo_getId(eArticulo* this,int* id);
int articulo_setId(eArticulo* this, int id);

int articulo_setNombre(eArticulo* this,char* nombre);
int articulo_getNombre(eArticulo* this,char* nombre);

int articulo_setPrecio(eArticulo* this,float precio);
int articulo_getPrecio(eArticulo* this,float* precio);

int articulo_setMedida(eArticulo* this,char* medida);
int articulo_getMedida(eArticulo* this,char* medida);

int articulo_setRubroId(eArticulo* this,int rubroId);
int articulo_getRubroId(eArticulo* this,int* rubroId);

int articulo_listarArticulos(LinkedList* pArrayListArticulos);
int articulo_mostrarUnArticulo(eArticulo* auxArticulo);

int articulo_ordenarPorArticulo(void* pElement1, void* pElement2);
void articulo_calcularDescuento(void* pElemento);
int articulo_cantidadArticulosMayorACien(void* pElement);
int articulo_cantidadArticulosRubroUno(void* pElement);
#endif /* EARTICULO_H_ */
