/*
 * Empleado.c
 *
 *  Created on: May 05, 2020
 *      Author: Macarena
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
		printf("Id: %d- %s - %s - Salario: %.2f Sector: %d\n",	pElemento->id,
																pElemento->name,
																pElemento->lastName,
																pElemento->salary,
																pElemento->sector);
	}
	return retorno;
}

/**
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser impreso
 * \param limite Limite del array de empleados
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
				printf("Id: %d- %s - %s - Salario: %.2f Sector: %d\n",	array[i].id,
																		array[i].name,
																		array[i].lastName,
																		array[i].salary,
																		array[i].sector);
			}
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de empleados a ser inicializado
 * \param limite Limite del array de empleados
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
 * \brief Da de alta a un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_altaArray(Empleado* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Empleado auxiliar;

	if(array != NULL && indice < limite && limite > 0 && indice >= 0 && id != NULL)
	{
		if((!utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre empleado:\n", "Valor inválido\n", 2)) &&
		(!utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Valor inválido\n", 2)) &&
		(!utn_getNumero(&auxiliar.sector, "Ingrese sector:\n", "Valor inválido\n", 0, 10, 2)) &&
		(!utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Valor inválido\n", 0, 100000, 2)))
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
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Empleado* array,int limite, int indice)
{
	int respuesta = -1;
	Empleado auxiliar;
	int opcion;
	if(array != NULL && limite > 0 && indice < limite)
	{
	do
	{
		auxiliar[indice]
		if(!utn_getNumero(&opcion, "Ingrese el valor que desea modificar:\n 1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n", "Opcion incorrecta\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre empleado:\n", "Valor inválido\n", 2);
				break;
			case 2:
				utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Valor inválido\n", 2);
				break;
			case 3:
				utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Valor inválido\n", 0, 100000, 2);
				break;
			case 4:
				utn_getNumero(&auxiliar.sector, "Ingrese sector:\n", "Valor inválido\n", 0, 10, 2);
				break;
			}
			respuesta = 0;
			array[indice].isEmpty = 0;

		}
	}while(opcion !=5);

		}
	}
	return respuesta;
}
/**
 * \brief Elimina una posicion del array
 * \param array Array de empleados a ser modificado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser eliminada
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
* \param array Array de empleados
* \param limite int Tamaño del array
* \param posicion int Posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado sino, retorna el indice donde se encuentra el valor buscado
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
            if(array[i].isEmpty==0 && array[i].id==valorBuscado)
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
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
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
 * \brief Ordenar el array de empleados por nombre
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna = si pudo o -1 (ERROR)
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
					strncmp(array[i].name,array[i+1].name,NAME_LEN) > 0)
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
