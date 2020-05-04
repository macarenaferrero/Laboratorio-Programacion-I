#include "Fantasma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

/**
 * \brief Imprime los datos de un fantasma
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_imprimir(Fantasma* pElemento)
{
	int retorno=-1;


	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno = 0;
		printf("\nId: %d - %s - %s - %s - %s - %s - %.2f - %.2f",pElemento->id,
																pElemento->nombre,
																pElemento->dni,
																pElemento->mail,
																pElemento->telefono,
																pElemento->direccion,
																pElemento->altura,
																pElemento->peso);
	}

	return retorno;
}

/**
 * \brief Imprime el array de fantasmas
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_imprimirArray(Fantasma* array,int limite)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			fan_imprimir(&array[i]);
		}
	}

	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_inicializarArray(Fantasma* array,int limite)
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
 * \brief Da de alta un fantasma en una posicion del array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al fantasma
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_altaArray(Fantasma* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Fantasma auxiliar;

	if(array != NULL && indice < limite && limite > 0 && indice >= 0 && id != NULL)
	{
		if((!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Ingrese nombre\n", "Valor inválido\n", 2)) &&
		(!utn_getDni(auxiliar.dni, DNI_LEN, "Ingrese DNI\n", "Valor inválido\n", 2)) &&
		(!utn_getDescripcion(auxiliar.direccion, DIR_LEN, "Ingrese Dirección\n", "Valor inválido\n", 2)) &&
		(!utn_getDescripcion(auxiliar.mail, MAIL_LEN,"Ingrese mail\n", "Valor inválido\n", 2)) &&
		(!utn_getDni(auxiliar.telefono, TEL_LEN, "Ingrese teléfono\n", "Valor inválido\n", 2)) &&
		(!utn_getNumeroFlotante(&auxiliar.altura, "Ingrese altura\n", "Valor inválido\n", 0, 4, 2)) &&
		(!utn_getNumeroFlotante(&auxiliar.peso,"Ingrese peso\n", "Valor inválido\n", 0, 300, 2)))
		{
			respuesta =0;
			auxiliar.isEmpty = 0;
			auxiliar.id = *id;
			array[indice] = auxiliar;
			*id = *id + 1;
		}
	}

	return respuesta;
}

/**
 * \brief Actualiza los datos de un fantasma en una posicion del array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_modificarArray(Fantasma* array,int limite, int indice)
{
	int respuesta = -1;
	Fantasma auxiliar;

		if(array != NULL && indice < limite && limite > 0  && indice >= 0 && array[indice].isEmpty == 0)
		{
			if(!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Ingrese nombre\n", "Valor inválido\n", 2) &&
				(!utn_getDni(auxiliar.dni, DNI_LEN, "Ingrese DNI\n", "Valor inválido\n", 2)) &&
					(!utn_getDescripcion(auxiliar.direccion, DIR_LEN, "Ingrese Dirección\n", "Valor inválido\n", 2)) &&
					(!utn_getDescripcion(auxiliar.mail, MAIL_LEN,"Ingrese mail\n", "Valor inválido\n", 2)) &&
					(!utn_getDni(auxiliar.telefono, TEL_LEN, "Ingrese teléfono\n", "Valor inválido\n", 2)) &&
					(!utn_getNumeroFlotante(&auxiliar.altura, "Ingrese altura\n", "Valor inválido\n", 0, 4, 2)) &&
					(!utn_getNumeroFlotante(&auxiliar.peso,"Ingrese peso\n", "Valor inválido\n", 0, 300, 2)))
			{
				respuesta =0;
				auxiliar.isEmpty = 0;
				auxiliar.id = array[indice].id;
				array[indice] = auxiliar;
			}
		}
	return respuesta;
}
/**
 * \brief Elimina una posicion del array
 * \param array Array de fantasmas a ser eliminado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser eliminada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_bajaArray(Fantasma* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && indice < limite && limite > 0  && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}


	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de fantasma
* \param limite int Tamaño del array
* \param posicion int Posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado, sino retorna el índice del valor buscado
*
*/
int fan_buscarId(Fantasma array[], int limite, int valorBuscado)
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
 * \brief Buscar primer posicion vacia
 * \param array Array de fantasmas
 * \param limite Limite del array de fantasmas
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int fan_getEmptyIndex(Fantasma* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite >= 0)
	{
		for(i=0; i<limite;i++)
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
 * \brief Ordenar el array de fantasmas por nombre
 * \param array Array de fantasmas
 * \param limite Limite del array de fantasmas
 * \return Retorna -1 (ERROR) o 0 So salió todo bien
 *
 */
int fan_ordenarPorNombre(Fantasma* array,int limite)
{
	int respuesta = -1;
	int i;
	int FlagSwap;
	Fantasma aux;
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
