#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArticulo.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Direccion del archivo a leer con los datos
 * \param pArrayListEmployee LinkedList* Puntero a la estructura linkedList
 * \return int retorna -1 si sale mal o 0 si sale bien
 *
 */
int parser_articuloFromText(FILE* pFile , LinkedList* pArrayListArticle)
{
	int ret = -1;
	char buffer[5][128];
	int cant = 0;
	eArticulo* auxArt;
	int i = 0;
	if(pFile != NULL && pArrayListArticle != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			if(cant == 5)
			{
				auxArt = articulo_newParametros(buffer[0],buffer[1],buffer[3],buffer[4],buffer[2]);
				if(auxArt != NULL)
				{
					ll_add(pArrayListArticle,auxArt);
					ret = 0;
					i++;
				}
			}else
			{
				if(feof(pFile))
				{
					printf("Final del archivo, cantidad de bytes leidos: %d.\n",i);
					system("pause");
					break;
				}
			}
		}
	}
    return ret;
}
