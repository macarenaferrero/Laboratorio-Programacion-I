/*
 * Pantalla.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Macarena
 */
#include "Pantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Imprime un Pantallas
 * \param pProducto Puntero al Pantallas que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimir(Pantalla* pPantallas)
{
	int retorno=-1;
	char cadenaTipo[5];
	if(pPantallas != NULL && pPantallas->isEmpty == 0)
	{
		retorno = 0;

		switch(pPantallas->tipoPantalla)
		{
		case 1:
			strncpy(cadenaTipo,"LCD",5);
			break;
		case 2:
			strncpy(cadenaTipo,"LED",5);
			break;
		}
		printf("ID: %8d  -%6s -    %8s -  %s  Precio: %.2f\n",pPantallas->id, pPantallas->nombre,pPantallas->direccion,cadenaTipo,pPantallas->precio);

	}
	return retorno;
}

/**
 * \brief Imprime el array de Pantallas
 * \param arrayPantallas Array de Pantallas a ser impreso
 * \param limite Limite del array de Pantallas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimirArray(Pantalla* arrayPantallas,int limite)
{
	int retorno = -1;
	int i;
	if(arrayPantallas != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			pan_imprimir(&arrayPantallas[i]);
		}
	}
	return retorno;
}

/**
 * \brief Inicializa el array de pacientes
 * \param arrayPantallas Array de pacientes a ser actualizado
 * \param limite Limite del array de pacientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_initArray(Pantalla* arrayPantallas,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayPantallas != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arrayPantallas[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Carga el array
 * \param arrayPantallas Array de pacientes a ser actualizado
 * \param limite Limite del array de pacientes
 * \param indice Posicion a ser actualizada
 * \param id PunteroId direccion de memoria del valor del ID
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_updateArray(Pantalla* arrayPantallas,int limite, int indice, int* id)
{
	int respuesta = -1;
	Pantalla auxPantalla;
	if(arrayPantallas != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	(!utn_getNombre(auxPantalla.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2)) &&
			(!utn_getDescripcion(auxPantalla.direccion, DESCRIPCION_LEN, "\nDireccion?", "\nDireccion invalida",2)) &&
			(!utn_getNumeroFlotante(&auxPantalla.precio,"\nPrecio por día?","\nPrecio es invalido",0.01,1000000,2)) &&
			(!utn_getNumero(&auxPantalla.tipoPantalla, "Ingrese tipo [1-LED - 2 LCD]\n", "Valor incorrecto\n", 1, 2, 2)))
		{
			respuesta = 0;
			auxPantalla.id = *id;
			auxPantalla.isEmpty = 0;
			arrayPantallas[indice]= auxPantalla;
			*id = *id + 1;
		}
	}
	return respuesta;
}

/*
* \brief Modifica el array
* \param arrayPantallas Array de pacientes a ser modificado
* \param limite Limite del array de pacientes
* \param indice Posicion a ser modificada
* \return Retorna 0 (EXITO) y -1 (ERROR)
*
*/
int pan_modificarArray(Pantalla* arrayPantallas,int limite, int indice)
{
	int respuesta = -1;
	Pantalla auxPantalla;
	if(arrayPantallas != NULL && limite > 0 && indice < limite && indice >= 0 && arrayPantallas[indice].isEmpty==0)
	{
		if(	(!utn_getNombre(auxPantalla.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2)) &&
			(!utn_getDescripcion(auxPantalla.direccion, DESCRIPCION_LEN, "\nDireccion?", "\nDireccion invalida",2)) &&
			(!utn_getNumeroFlotante(&auxPantalla.precio,"Precio por día?\n","\nPrecio es invalido",0,10000,2)) &&
			(!utn_getNumero(&auxPantalla.tipoPantalla, "Ingrese tipo [1-LED - 2 LCD]\n", "Valor incorrecto\n", 1, 2, 2)))
		{
			respuesta = 0;
			auxPantalla.id = arrayPantallas[indice].id;
			auxPantalla.isEmpty = 0;
			arrayPantallas[indice]= auxPantalla;
		}
	}
	return respuesta;
}


/*
* \brief Modifica el array
* \param arrayPantallas Array de pacientes a ser modificado
* \param limite Limite del array de pacientes
* \param indice Posicion a ser modificada
* \return Retorna 0 (EXITO) y -1 (ERROR)
*
*/
int pan_bajarArray(Pantalla* arrayPantallas,int limite, int indice)
{
	int respuesta = -1;
	if(arrayPantallas != NULL && limite > 0 && indice < limite && indice >= 0 && arrayPantallas[indice].isEmpty==0)
	{
		arrayPantallas[indice].isEmpty = 1;
		respuesta =0;

	}
	return respuesta;
}



/**
 * \brief Indica posiciones libres
 * \param lista[] Array de la lista a evaluar
 * \param len Limite del array de la lista
 * \param pIndice Puntero donde se guardará el valor del indice vacío
 * \return Retorna 0 si hay casillero vacio y -1 (ERROR)
 *
 */

int pan_getEmptyIndex(Pantalla lista[], int len)
{
	int retorno=-1;
	int i;

	if(lista != NULL && len > 0)
	{

		for(i=0; i<len;i++)
		{
			if(lista[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}



/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de Pantalla
* \param limite int Tamaño del array
* \param posicion int Posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado, sino retorna el índice del valor buscado
*
*/
int pan_buscarId(Pantalla array[], int limite, int valorBuscado)
{

    int retorno=-1;
    int i;
	if(array != NULL && limite >= 0)
	{
		for(i=0; i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].id == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
    return retorno;
}



/**
 * \brief Ordenar el array de Pantalla por nombre
 * \param array Array de Pantalla
 * \param limite Limite del array de Pantalla
 * \return Retorna -1 (ERROR) o 0 So salió todo bien
 *
 */
int pan_ordenarPorNombre(Pantalla* array,int limite)
{
	int respuesta = -1;
	int i;
	int FlagSwap;
	Pantalla aux;
	if(array != NULL && limite >= 0)
	{
		respuesta = 0;
		do
		{
		FlagSwap = 0;
			for(i=0; i<limite-1;i++)
			{
				if(array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN)> 0)
				{
					aux = array[i];
					array[i] = array[i+1];
					array[i+1] = aux;
					FlagSwap = 1;
				}
			}
			limite--;
		}while(FlagSwap);
	}
	return respuesta;
}
