/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Macarena
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "utn.h"

/**
 * \brief Imprime un producto
 * \param pProducto Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimir(Producto* pProducto)
{
	int retorno=-1;
	if(pProducto != NULL)
	{
		retorno = 0;
		printf("%s -    %8s -    Precio %.2f\n",pProducto->nombre,pProducto->descripcion,pProducto->precio);
	}
	return retorno;
}

/**
 * \brief Inicializa el array de productos
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_initArray(Producto* arrayProductos,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayProductos != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arrayProductos[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_updateArray(Producto* arrayProductos,int limite, int indice)
{
	int respuesta = -1;
	Producto auxProducto;
	if(arrayProductos != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxProducto.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDescripcion(auxProducto.descripcion, NOMBRE_LEN, "\nDescripcion?", "\nDescripcion invalida",2) == 0 &&
			utn_getNumeroFlotante(&auxProducto.precio,"\nPrecio?","\nPrecio es invalido",0.01,1000000,2) == 0)
		{
			respuesta = 0;
			arrayProductos[indice] = auxProducto;
		}
	}
	return respuesta;
}

/**
 * \briefIndica posiciones libres
 * \param lista[] Array de la lista a evaluar
 * \param len Limite del array de la lista
 * \para *indice Puntero donde se guarda el indice vacio
 * \return Retorna 0 (OK) y -1 (ERROR)
 *
 */

int prod_getEmptyIndex(Producto lista[], int len, int* pIndice)
{
	int retorno=-1;
	int i;

	if(lista != NULL && len > 0)
	{

		for(i=0; i<len;i++)
		{
			if(lista[i].isEmpty == 1)
			{
				retorno =0;
				*indice =i;
				break;
			}
		}
	}

	return retorno;
}
