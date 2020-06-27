#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArticulo.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero a la direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArticle)
{
	FILE* pArch;
	int ret = -1;
	int controlCarga;

	if(path != NULL && pArrayListArticle != NULL)
	{
		pArch = fopen(path,"r");
		if(pArch != NULL)
		{
			controlCarga = parser_articuloFromText(pArch,pArrayListArticle);
			if(controlCarga == 0)
			{
				fclose(pArch);
				ret = 0;
			}else
			{
				printf("No se pudo abrir el archivo.\n");
			}
		}
	}
    return ret;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_ListArticle(LinkedList* pArrayListArticle)
{
	int ret = -1;
	if(pArrayListArticle != NULL)
	{
		if(articulo_listarArticulos(pArrayListArticle))
		{
			ret = 0;
		}
	}
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_sortArticle(LinkedList* pArrayListArticle)
{
	int ret = -1;
	if(pArrayListArticle != NULL)
	{
		ll_sort(pArrayListArticle,articulo_ordenarPorArticulo,1);
		ret = 0;

	}
    return ret;
}

/*
 * \brief calcula el descuento de los articulos
 * \param LinkedList* puntero a la ll
 * \return ret -1 si sale mal y 0 si sale bien
 *
 */
int controller_calcularDescuento(LinkedList* pArrayListArticle)
{
	int ret =-1;
	if(pArrayListArticle != NULL)
	{
		ll_map(pArrayListArticle,articulo_calcularDescuento);
		ret = 0;
	}
	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* puntero a la direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero a la linkedlist
 * \return int [-1] si sale mal, 0 si sale todo bien
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArticle)
{
	int ret = -1;
	FILE* pFile;
	eArticulo* auxArt;
	int auxId;
	char medida[128];
	float precio;
	char auxNombre[128];
	int rubroId;
	int len = ll_len(pArrayListArticle);
	if(path != NULL && pArrayListArticle != NULL && len > 0)
	{
		pFile = fopen(path,"w");
		if(pFile !=NULL)
		{
			fprintf(pFile,"id,articulo,medida,precio,rubroId\n");

			for(int i = 0; i < len; i ++)
			{
				auxArt = (eArticulo*)ll_get(pArrayListArticle,i);
				if(auxArt != NULL)
				{
					articulo_getId(auxArt,&auxId);
					articulo_getMedida(auxArt,medida);
					articulo_getNombre(auxArt,auxNombre);
					articulo_getPrecio(auxArt,&precio);
					articulo_getRubroId(auxArt,&rubroId);

					fprintf(pFile,"%d,%s,%s,%f,%d\n",auxId,auxNombre,medida,precio,rubroId);

				}
			}
			fclose(pFile);
			ret = 0;
		}
	}
    return ret;
}

int controller_cantidadArticulosMayorACien(LinkedList* pListaProductos)
{
	int ret = -1;
	int contador = 0;
	if(pListaProductos != NULL)
	{
		ret = 0;
		contador = ll_count(pListaProductos,articulo_cantidadArticulosMayorACien);
		printf("La cantidad de productos mayores a 100 pesos es de %d", contador);
	}
	return ret;
}

int controller_cantidadArticulosRubro1(LinkedList* pListaProductos)
{
	int ret = -1;
	int contador = 0;
	if(pListaProductos != NULL)
	{
		ret = 0;
		contador = ll_count(pListaProductos,articulo_cantidadArticulosRubroUno);
		printf("La cantidad de productos con el rubro 1 es de %d", contador);
	}
	return ret;
}
