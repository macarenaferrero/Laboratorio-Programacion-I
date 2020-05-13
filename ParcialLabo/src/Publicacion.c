#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"


static const char TXT_ESTADO[2][8]={"PAUSADO","ACTIVO"};

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
		printf("\nID: %d - Texto: %8s - Rubro: %8d - IdCliente: %8d - Estado: %8s"	,pElemento->idPublicacion
																				,pElemento->textoPublicacion
																				,pElemento->rubro
																				,pElemento->idCliente
																				,TXT_ESTADO[pElemento->estado]);
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
			array[i].estado = 3;
			array[i].rubro = 0;
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
		if(	!utn_getNumero(&bufferAux.rubro,"\n Rubro? [1 al 1000]", "\nError",1,1000,2) &&
			!utn_getDescripcion(bufferAux.textoPublicacion,TEXTO_LEN,"\nTexto de la publicación?\n ", "\nError",2))
		{
			respuesta = 0;
			bufferAux.idCliente = idCliente;
			bufferAux.idPublicacion = *idPublicacion;
			bufferAux.isEmpty = 0;
			bufferAux.estado = 1;
			array[indice] = bufferAux;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un publicacion en una posicion del array de manera forzada
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param idPublicacion Identificador a ser asignado al cliente
 * \param idCliente Identificador cliente
 * \param texto Texto que se asignará a la publicacion
 * \param estado  Estado a asignar a la publicacion
 * \param rubro Rubro a asignar a la publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,int rubro,int estado)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		strncpy(bufferPublicacion.textoPublicacion,texto,TEXTO_LEN);
		bufferPublicacion.estado = estado;
		bufferPublicacion.idCliente = idCliente;
		bufferPublicacion.rubro = rubro;
		respuesta = 0;
		bufferPublicacion.idPublicacion = *idPublicacion;
		bufferPublicacion.isEmpty = 0;
		array[indice] = bufferPublicacion;
		(*idPublicacion)++;

	}
	return respuesta;
}


/**
 * \brief Pausa una publicacion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser pausada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_pausarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	int  estado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNumero(&estado,"\n Confirma pausar la publicación selecionada? [1.Si]\n", "\nLa publicación seleccionada no ha sido pausada\n",1,1,0))
		{
			//Me gustaría añadir una funcion que si están todas pausadas, lo indique.
			respuesta = 0;
			array[indice].estado = 0;
		}
	}
	return respuesta;
}

/**
 * \brief Activa una publicacion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser activada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_activarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	int  estado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNumero(&estado,"\n Confirma activar la publicación selecionada? [1.Si]\n", "\nLa publicación seleccionada no ha sido activada\n",1,1,0))
		{
			//Me gustaría añadir una funcion que si están todas activas, lo indique.
			respuesta = 0;
			array[indice].estado = 1;
		}
	}
	return respuesta;
}



/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de publicaciones
* \param limite int Tamaño del array
* \param valorBuscado ID a encontrar
* \return int Return (-1) si no encuentra el valor buscado sino, devuelve el indice donde se encuentra el valor buscado
*
*/
int pub_buscarId(Publicacion array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].idPublicacion == valorBuscado)
			{
				respuesta = i;
				break;
			}
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


/** \brief Busca un ID en un array y devuelve el ID del cliente
* \param array Array de publicaciones
* \param limite int Tamaño del array
* \param valorBuscado ID a encontrar
* \return int Return (-1) si no encuentra el valor buscado sino, devuelve el ID del cliente
*
*/
int pub_buscarIdCliente(Publicacion array[], int limite, int idPublicacionBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && idPublicacionBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].idPublicacion == idPublicacionBuscado)
			{
				respuesta = array[idPublicacionBuscado].idCliente;
				break;
			}
		}
	}
	return respuesta;
}



/**
 * \brief Calcula cantidad de avisos activos
 * \param array Array de publicaciones a ser inspeccionado
 * \param limite Limite del array de publicaciones
 * \param idCliente Recibe ID a contar avisos activos
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones activas
 *
 */

int pub_contadorAvisosActivosPorId(Publicacion* arrayPublicaciones,int limitePublicaciones, int idCliente)
{
	int retorno=-1;
	int i;
	int contadorAvisosActivos=0;

	if(arrayPublicaciones != NULL && limitePublicaciones > 0 && idCliente >=0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado ==1 && arrayPublicaciones[i].idCliente == idCliente)
			{
				contadorAvisosActivos++;
			}
		}
		retorno = contadorAvisosActivos;
	}
	return retorno;
}



/**
 * \brief Calcula cantidad de avisos pausados
 * \param array Array de publicaciones a ser inspeccionado
 * \param limite Limite del array de publicaciones
 * \param idCliente Recibe ID a contar avisos pausados
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones pausados
 *
 */

int pub_contadorAvisosPausadosPorId(Publicacion* arrayPublicaciones,int limitePublicaciones, int idCliente)
{
	int retorno=-1;
	int i;
	int contadorAvisosPausados=0;

	if(arrayPublicaciones != NULL && limitePublicaciones > 0 && idCliente >=0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].idCliente == idCliente)
			{
				contadorAvisosPausados++;

			}
		}
		retorno = contadorAvisosPausados;
	}
	return retorno;
}

/**
 * \brief Calcula cantidad de avisos activos por rubro
 * \param array Array de publicaciones a ser inspeccionado
 * \param limite Limite del array de publicaciones
 * \param rubro Recibe rubro a contar avisos activos
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones activas por rubro
 *
 */


int pub_informaPublicacionesActivasRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro)
{
	int retorno= -1;
	int i;
	int contadorRubro=0;

	if(arrayPublicacion != NULL && limitePublicaciones > 0 && rubro != NULL)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].rubro == *rubro && arrayPublicacion[i].estado == 1)
			{
				contadorRubro++;
				retorno = contadorRubro;
			}
		}
	}
	return retorno;
}



/**
 * \brief Calcula cantidad de avisos pausados por rubro
 * \param array Array de publicaciones a ser inspeccionado
 * \param limite Limite del array de publicaciones
 * \param rubro Recibe rubro a contar avisos pausados
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones pausadas por rubro
 *
 */


int pub_informaPublicacionesPausadasRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro)
{
	int retorno= -1;
	int i;
	int contadorRubro=0;

	if(arrayPublicacion != NULL && limitePublicaciones > 0 && rubro != NULL)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].rubro == *rubro && arrayPublicacion[i].estado == 0)
			{
				contadorRubro++;
				retorno = contadorRubro;
			}
		}
	}
	return retorno;
}
