/*
 * Contrataciones.c
 *
 *  Created on: 30 abr. 2020
 *      Author: maculina
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Contrataciones.h"

/**
 * \brief Imprime los datos de una contratacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimir(Contrataciones* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nId Contratación: %d - Id Pantalla: %d - %s - %s  - %d",pElemento->id,pElemento->idPantalla,pElemento->archivo,pElemento->cuit, pElemento->dia);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimirArray(Contrataciones* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			con_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_inicializarArray(Contrataciones* array,int limite)
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
 * \brief Da de alta una contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_updateArray(Contrataciones* array,int limite, int indice, int* idContratacion)
{
	int respuesta = -1;
	Contrataciones auxContratacion;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idContratacion != NULL)
	{
		if(	(!utn_getNombre(auxContratacion.archivo, ARCHIVO_LEN, "\nNombre archivo?", "\nNombre invalido",2)) &&
			(!utn_getDni(auxContratacion.cuit, CUIT_LEN, "\nIngrese CUIT sin guiones:", "\nCUIT invalido",2)) &&
			(!utn_getNumero(&auxContratacion.dia,"\nCantidad de días?","\nCantidad días inválido",0,1000,2)))
		{
			respuesta = 0;
			auxContratacion.id = *idContratacion;
			auxContratacion.isEmpty = 0;
			array[indice]= auxContratacion;
			*idContratacion = *idContratacion + 1;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de una contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_modificarArray(Contrataciones* array,int limite, int indice)
{
	int respuesta = -1;
	Contrataciones bufferIngreso;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	(!utn_getNombre(bufferIngreso.archivo,ARCHIVO_LEN,"\nNombre archivo?\n","\nERROR\n",2)) &&
			(!utn_getDni(bufferIngreso.cuit,CUIT_LEN,"\nCUIT?\n","\nERROR\n",2)) &&
			(!utn_getNumero(&bufferIngreso.dia, "Ingrese cantidad de días\n", "Días incorrectos\n", 0, 1000, 2)))

		{
			respuesta = 0;
			bufferIngreso.id = array[indice].id;
			bufferIngreso.isEmpty = 0;
			array[indice] = bufferIngreso;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_bajarArray(Contrataciones* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array  Array de contrataciones
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int con_buscarId(Contrataciones array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/** \brief Busca un cuit en un array y devuelve la posicion en que se encuentra
* \param array  Array de contrataciones
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int con_buscarCuit(Contrataciones array[], int limite, char valorBuscado[])
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado != NULL)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].cuit == valorBuscado)
			{
				con_imprimirArray(array, limite);
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int con_getEmptyIndex(Contrataciones* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
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

/**
 * \brief Ordenar el array de contrataciones por archivo
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int con_ordenarPorNombre(Contrataciones* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Contrataciones buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].archivo,array[i+1].archivo,ARCHIVO_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de contrataciones por archivo y altura
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int con_ordenarPorNombreAltura(Contrataciones* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Contrataciones buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].archivo,array[i+1].archivo,ARCHIVO_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].cuit < array[i+1].cuit) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
