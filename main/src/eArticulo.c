/*
 * eArticulo.c
 *
 *  Created on: 25 jun. 2020
 *      Author: Agus
 */
#include "eArticulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int esNumerica(char *cadena);

/*
 * \brief Inicializa un nuevo articulo cargando todos sos datos a 0
 * \return retorna un articulo inicializado
 *
 */
eArticulo* articulo_new()
{
	eArticulo* this;
	this = (eArticulo*)malloc(sizeof(eArticulo));
	if(this != NULL)
	{
		articulo_setId(this,0);
		articulo_setMedida(this,"");
		articulo_setNombre(this,"");
		articulo_setPrecio(this,0);
		articulo_setRubroId(this,0);
	}
	return this;
}
/*
 * \brief crea un articulo con los parametros pasados como argumentos
 * \param char* idStr puntero al id del articulo
 * \param char* nombreStr puntero al nombre del articulo
 * \param char* precioStr puntero al precio del articulo
 * \param char* sueldoStr puntero al sueldo del articulo
 * \param char* medida puntero a la medida del articulo
 * \return retorna un articulo tipo eArticulo*
 */
eArticulo* articulo_newParametros(char* idStr,char* nombreStr,char* precioStr,char* idRubroStr, char* medida)
{
	eArticulo* this;
	this = articulo_new();
	if(this != NULL)
	{
		articulo_setId(this,atoi(idStr));
		articulo_setMedida(this,medida);
		articulo_setNombre(this,nombreStr);
		articulo_setPrecio(this,atof(precioStr));
		articulo_setRubroId(this,atoi(idRubroStr));
	}
	return this;
}
/*
 * \brief lista todos los articulos
 * \param LinkedList* pArrayListArticulos puntero a la linkedList
 * \return ret int [-1] si sale mal, 0 si sale todo bien
 */
int articulo_listarArticulos(LinkedList* pArrayListArticulos)
{
	int ret = -1;
	int len;
	eArticulo* auxArt;
	if(pArrayListArticulos != NULL)
	{
		system("cls");
		printf(" ID\tNombre\t\t\tmedida\tprecio\trubro descripcion\n");

		len = ll_len(pArrayListArticulos);
		for(int i = 0; i < len; i++)
		{
			auxArt = (eArticulo*)ll_get(pArrayListArticulos,i);
			articulo_mostrarUnArticulo(auxArt);
			ret = 0;
		}
		system("pause");
	}else
	{
		printf("No se pudo cargar la lista\n");
		system("pause");
	}
	return ret;
}
/*
 * \brief muestra un articulo solo
 * \param eArticulo* auxArticulo puntero a un articulo a mostrar
 * \return int ret [-1] si sale mal, 0 si sale todo bien
*/
int articulo_mostrarUnArticulo(eArticulo* auxArticulo)
{
    int ret = -1;
    if(auxArticulo!=NULL)
    {
    	int id;
    	char medida[128];
    	char nombre[128];
    	float precio;
    	int idRubro;
    	char rubroTexto[128];
    	articulo_getId(auxArticulo,&id);
    	articulo_getMedida(auxArticulo,medida);
    	articulo_getNombre(auxArticulo,nombre);
    	articulo_getPrecio(auxArticulo,&precio);
    	articulo_getRubroId(auxArticulo,&idRubro);
    	switch(idRubro)
    	{
    	case 1:
    		strcpy(rubroTexto,"Cuidado de ropa");
    		break;
    	case 2:
    		strcpy(rubroTexto, "Limpieza y desinfeccion");
    		break;
    	case 3:
    		strcpy(rubroTexto,"Cuidado personal e higiene");
    		break;
    	case 4:
    		strcpy(rubroTexto,"Cuidado del automotor");
    		break;
    	}
        printf("|%d\t|%-30.30s\t|%-6.5s\t|%-10.2f\t\t|%-30.30s\n",id,nombre,medida,precio,rubroTexto);
        ret = 0;
    }
    return ret;
}

/*
 * \brief obtiene el id y lo devuelve a una variable
 * \param eArticulo* this puntero a un articulo
 * \param int* id puntero a una variable donde almacenar el id obtenido
 * \return retorno int [-1] si sale mal, 0 si sale todo bien
 */
int articulo_getId(eArticulo* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/**
 * \brief setea el id del articulo
 * \param eArticulo* this puntero a un articulo
 * \param int id, id del articulo a ser seteado
 * \return int ret [-1] si sale mal, 0 si sale todo bien
 */
int articulo_setId(eArticulo* this, int id)
{
    int ret = -1;
    static int IdMaximo = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            IdMaximo++;
            this->id = IdMaximo;
        }
        else
        {
            if(id>IdMaximo)
            {
                this->id = id;
                IdMaximo = id;
            }
        }
        ret = 0;
    }
    return ret;
}

int articulo_setNombre(eArticulo* this,char* nombre)
{
	int retorno = -1;
		if(this != NULL && nombre != NULL)
		{
			if(isValidTexto(nombre))
			{
				retorno = 0;
				strcpy(this->articulo,nombre);
			}
		}
		return retorno;
}

int articulo_getNombre(eArticulo* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->articulo);
	}
	return retorno;
}

int articulo_setPrecio(eArticulo* this,float precio)
{
	int retorno = -1;
	char precioTexto[128];
	if(this != NULL && precio >= 0)
	{
		sprintf(precioTexto,"%f",precio);
		if(isValidFloatNumber(precioTexto))
		{
			retorno = 0;
			this->precio = precio;
		}
	}
	return retorno;
}

int articulo_getPrecio(eArticulo* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int articulo_setMedida(eArticulo* this,char* medida)
{
	int ret = -1;
	if(this != NULL && medida != NULL)
	{
		ret = 0;
		strcpy(this->medida,medida);
	}
	return ret;
}

int articulo_getMedida(eArticulo* this,char* medida)
{
	int ret = -1;
	if(this != NULL && medida != NULL)
	{
		ret = 0;
		strcpy(medida,this->medida);
	}
	return ret;
}

int articulo_setRubroId(eArticulo* this,int rubroId)
{
	int ret = -1;
	char rubroIdTexto[128];
	if(this != NULL && rubroId >= 0 && rubroId <= 4)
	{
		if(esNumerica(itoa(rubroId,rubroIdTexto,10)))
		{
			ret = 0;
			this->rubroId = rubroId;
		}
	}
	return ret;
}

int articulo_getRubroId(eArticulo* this,int* rubroId)
{
	int ret = -1;
	if(this != NULL && rubroId != NULL)
	{
		ret = 0;
		*rubroId = this->rubroId;
	}
	return ret;
}

int articulo_ordenarPorArticulo(void* pElement1, void* pElement2)
{
	int ret = 0;

	eArticulo* articulo1 = (eArticulo*)pElement1;
	eArticulo* articulo2 = (eArticulo*)pElement2;

	if(strcmp(articulo1->articulo, articulo2->articulo)> 0)
	{
		ret = 1;
	}
	else if(strcmp(articulo1->articulo, articulo2->articulo)< 0)
	{
		ret = -1;
	}

	return ret;
}

void articulo_calcularDescuento(void* pElemento)
{
	float precio;
	float precioDescuento;
	int auxIdRubro;
	eArticulo* articulo = (eArticulo*)pElemento;

	articulo_getPrecio(articulo,&precio);
	articulo_getRubroId(articulo,&auxIdRubro);
	if(auxIdRubro == 1 && precio >= 120)
	{
		precioDescuento = precio*20/100;
		precio = (precio-precioDescuento);
		articulo_setPrecio(articulo,precio);
	}
	else if(auxIdRubro == 2 && precio <= 200)
	{
		precioDescuento = precio*10/100;
		precio = (precio-precioDescuento);
		articulo_setPrecio(articulo,precio);
	}
}

static int esNumerica(char *cadena)
{
	int ret = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				ret = 0;
				break;
			}
			i++;
		}
	}

	return ret;
}

int articulo_cantidadArticulosMayorACien(void* pElement)
{
	int ret = 0;

	eArticulo* auxArt = (eArticulo*)pElement;
	float precio;

	articulo_getPrecio(auxArt,&precio);
	if(precio > 100)
		ret = 1;

	return ret;
}

int articulo_cantidadArticulosRubroUno(void* pElement)
{
	int ret = 0;

	eArticulo* auxArt = (eArticulo*)pElement;
	int idRubro;

	articulo_getRubroId(auxArt,&idRubro);
	if(idRubro == 1)
		ret = 1;

	return ret;
}
