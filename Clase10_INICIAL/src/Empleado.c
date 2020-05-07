/*
 * Empleado.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "utn.h"

/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimir(Empleado* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d- %s - %s - su valor es %.2f",pElemento->id, pElemento->nombre,pElemento->dni,pElemento->precio);
	}
	return retorno;
}

/**
 * \brief Imprime el array de pantallas
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimirArray(Empleado* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty != 1)
			{
				printf("\nID: %d - %s - %s - su altura es %.2f",array[i].id,array[i].nombre,array[i].dni,array[i].precio);

			}
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_inicializarArray(Empleado* array,int limite)
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
 * \brief Da de alta un Empleado en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al Empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_altaArray(Empleado* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Empleado auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDni(auxiliar.dni, DNI_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&auxiliar.precio,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un Empleado en una posicion del array modo TEST
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id ID a ser asignado al Empleado
 *  *
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_altaTestArray(Empleado* array,int limite, int indice, int* id, Empleado auxiliar)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice] = auxiliar;
		array[indice].isEmpty = 0;
		array[indice].id = *id;
		*id = *id + 1;
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un Empleado en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Empleado* array,int limite, int indice)
{
	int respuesta = -1;
	Empleado auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDni(auxiliar.dni, DNI_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&auxiliar.precio,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_bajaArray(Empleado* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice].isEmpty = 1;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Empleado Array de Empleado
* \param limite int Tamaño del array
* \param posicion int Posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int emp_buscarId(Empleado array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].id==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de pantallas
 * \param limite Limite del array de pantallas
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Empleado* array,int limite)
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

/**
 * \brief Ordenar el array de pantallas por nombre
 * \param array Array de pantallas
 * \param limite Limite del array de pantallas
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_ordenarPorNombre(Empleado* array,int limite)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Empleado auxiliar;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					auxiliar = array[i];
					array[i]= array[i+1];
					array[i+1] = auxiliar;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
