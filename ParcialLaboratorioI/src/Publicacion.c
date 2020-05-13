/*
 * Publicacion.c
 *
 *  Created on: 8 may. 2020
 *      Author: maculina
 */
#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "utn.h"
#include "Publicacion.h"


static const char TXT_ESTADO[2][8]={"ACTIVO","PAUSADO"};

/**
 * \brief Imprime los datos de un publicacion
 * \param pElemento Puntero a la publicacion que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Texto: %s - Rubro: %d - IdCliente: %d - Estado: %d",pElemento->idPublicacion,pElemento->textoPublicacion,pElemento->rubro,pElemento->idCliente,TXT_ESTADO[pElemento->estado]);
	}
	return retorno;
}

/**
 * \brief Imprime el array de publicaciones
 * \param array Array de publicaciones a ser impreso
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de publicaciones a ser inicializado
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un publicacion en una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferAux;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	!utn_getNumero(&bufferAux.rubro,"\n Rubro? ", "\nError",0,1000,2) &&
			!utn_getDescripcion(bufferAux.textoPublicacion,TEXTO_LEN,"\nTexto de la publicación?\n ", "\nError",2))
		{
			respuesta = 0;
			bufferAux.idCliente = idCliente;
			bufferAux.idPublicacion = *idPublicacion;
			bufferAux.isEmpty = 0;
			array[indice] = bufferAux;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}


/**
 * \brief Buscar primer posicion vacia
 * \param array Array de publicaciones
 * \param limite Limite del array de publicaciones
 * \return Retorna el indice de la posicion vacia o -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

