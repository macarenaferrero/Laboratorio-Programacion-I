/*
 * Informes.c
 *
 *  Created on: May 8, 2020
 *      Author: Macarena
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Informes.h"
#include "Cliente.h"
#include "Publicacion.h"

static const char TXT_ESTADO[2][8]={"PAUSADO","ACTIVO"};


/**
 * \brief Elimina una posicion del array de clientes y todas las publicaciones contratadas por el ID
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser eliminada
 * \param idCliente Recibe ID a eliminar
 * \param arrayPublicaciones Puntero al array a actualizar
 * \param limitePublicaciones Tamaño del array a modificar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_bajaArrayTotal(Cliente* array,int limite, int indice,int idCliente, Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int respuesta = -1;
	int i;
	if(	array != NULL && limite > 0 && indice < limite && indice >= 0 &&
		array[indice].isEmpty == 0 && idCliente >=0 && arrayPublicaciones != NULL &&
		arrayPublicaciones[indice].isEmpty == 0 &&limitePublicaciones >=0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].idCliente == idCliente)
			{
				arrayPublicaciones[i].isEmpty = 1;
			}
		}
	}
	return respuesta;
}


/**
 * \brief Imprime un array de clientes con cantidad de avisos activos
 * \param array Array de clientes a ser analizado
 * \param limite Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */


int info_imprimirClientesConContadorAnuncios(Cliente* arrayCliente,int limiteClientes, Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int retorno= -1;
	int i;
	int auxIdCliente;
	int cantidadActivos=0;

	if(arrayCliente != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limiteClientes;i++)
		{
			if(arrayCliente[i].isEmpty == 0)
			{
			auxIdCliente = arrayCliente[i].idCliente;
			cantidadActivos = pub_contadorAvisosActivosPorId(arrayPublicaciones, limitePublicaciones, auxIdCliente);
			printf("\nID: %8d - %8s - %8s - %8s - Anuncios activos: %8d",arrayCliente[i].idCliente
																		,arrayCliente[i].nombre
																		,arrayCliente[i].apellido
																		,arrayCliente[i].cuit
																		,cantidadActivos);
			}
		}
	}

	return retorno;
}






/**
 * \brief Imprime un array de publicaciones con cuit del contratador
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a imprimir
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */


int info_imprimirPublicacionesConCuit(Cliente* arrayCliente,int limiteClientes, Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int retorno= -1;
	int i;
	int j;
	char auxCuit[CUIT_LEN];

	if(arrayCliente != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				for(j=0; j<limiteClientes; j++)
				{
					if(arrayCliente[j].isEmpty == 0 && arrayCliente[j].idCliente ==arrayPublicaciones[i].idCliente)
					{
						retorno = 0;
						strncpy(auxCuit,arrayCliente[j].cuit,CUIT_LEN);
						printf("\nId Publicacion: %8d - Rubro: %8d - Texto: %8s - Estado: %8s - Cuit: %8s",arrayPublicaciones[i].idPublicacion
																										,arrayPublicaciones[i].rubro
																										,arrayPublicaciones[i].textoPublicacion
																										,TXT_ESTADO[arrayPublicaciones[i].estado]
																										,auxCuit);
					}
				}
			}
		}
	}

	return retorno;
}

/**
 * \brief Imprime el cliente con más avisos activos
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimirClienteConMasAvisosActivos(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones)
{
	int retorno = -1;
	int j;
	int anunciosMaximos;
	int auxCliente;
	int auxiliarAnuncios;

	for(j=0;j<limiteClientes;j++)
		{
		auxiliarAnuncios = pub_contadorAvisosActivosPorId(arrayPublicacion, limitePublicaciones, j);
		if(j== 0 || (auxiliarAnuncios > anunciosMaximos))
			{
			retorno = 0;

			anunciosMaximos = auxiliarAnuncios;
			auxCliente = 	j;
			}
		}
		printf("\n\n El cliente con mas anuncios activos es: %8s - %8s - %8s - Id: %5d - Cantidad anuncios: %5d",arrayClientes[auxCliente].nombre
																												,arrayClientes[auxCliente].apellido
																												,arrayClientes[auxCliente].cuit
																												,arrayClientes[auxCliente].idCliente
																												,anunciosMaximos);
	return retorno;
}



/**
 * \brief Imprime el cliente con más avisos pausados
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimirClienteConMasAvisosPausados(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones)
{
	int retorno = -1;
	int j;
	int anunciosMaximosPau;
	int auxCliente;
	int auxiliarAnuncios;

	for(j=0;j<limiteClientes;j++)
		{
		auxiliarAnuncios = pub_contadorAvisosPausadosPorId(arrayPublicacion, limitePublicaciones, j);
		if(j== 0 || (auxiliarAnuncios > anunciosMaximosPau))
			{
			retorno = 0;
			anunciosMaximosPau = auxiliarAnuncios;
			auxCliente = 	j;
			}
		}
		printf("\n\n El cliente con mas anuncios pausados es: %8s - %8s - %8s -Id: %5d - Cantidad anuncios: %5d",arrayClientes[auxCliente].nombre
																												,arrayClientes[auxCliente].apellido
																												,arrayClientes[auxCliente].cuit
																												,arrayClientes[auxCliente].idCliente
																												,anunciosMaximosPau);
	return retorno;
}



/**
 * \brief Imprime el cliente con más avisos
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimirClienteConMasAvisos(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones)
{
	int retorno = -1;
	int j;
	int anunciosMaximos;
	int auxCliente;
	int auxAnunciosTotal;
	int auxiliarAnunciosPau;
	int auxiliarAnunciosAct;

	if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicacion != NULL && limitePublicaciones < 0)
	{
	for(j=0;j<limiteClientes;j++)
		{

		auxiliarAnunciosAct = pub_contadorAvisosActivosPorId(arrayPublicacion, limitePublicaciones, j);
		auxiliarAnunciosPau = pub_contadorAvisosPausadosPorId(arrayPublicacion, limitePublicaciones, j);
		auxAnunciosTotal = auxiliarAnunciosAct + auxiliarAnunciosPau;
		if(j== 0 || (auxAnunciosTotal > anunciosMaximos))
			{
			retorno = 0;

			anunciosMaximos = auxAnunciosTotal;
			auxCliente = 	j;
			}
		}
		printf("\n\n El cliente con mas anuncios es: %8s - %8s - %8s - Id: %5d - Cantidad anuncios totales: %5d",arrayClientes[auxCliente].nombre
																												,arrayClientes[auxCliente].apellido
																												,arrayClientes[auxCliente].cuit
																												,arrayClientes[auxCliente].idCliente
																												,anunciosMaximos);
	}
	return retorno;
}


/**
 * \brief Imprime informe de publicaciones activas por rubro
 * \param arrayCliente Array de publicaciones a ser analizado
 * \param limiteClientes Limite del array de publicaciones
 * \param rubro Puntero del rubro a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimePublicacionesPorRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro)
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
				retorno = 0;
			}
		}
		printf("El rubro %5d tiene %5d avisos activos",*rubro, contadorRubro);
	}


	return retorno;
}


/**
 * \brief Imprime el cliente con más avisos
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimirRubroConMasAvisosActivos(Publicacion* arrayPublicacion, int limitePublicaciones)
{
	int retorno = -1;
	int j;
	int anunciosMaximos;
	int auxRubro;
	int auxiliarAnunciosAct;

	if(arrayPublicacion != NULL && limitePublicaciones > 0)
	{
	for(j=0;j<limitePublicaciones;j++)
		{
		auxiliarAnunciosAct = pub_informaPublicacionesActivasRubro(arrayPublicacion, limitePublicaciones, &j);
		if(j== 0 || (auxiliarAnunciosAct > anunciosMaximos))
			{
			retorno = 0;
			anunciosMaximos = auxiliarAnunciosAct;
			auxRubro = 	j;
			}
		}
	printf("\nEl rubro %5d es el que más avisos activos tiene, siendo %5d",auxRubro,anunciosMaximos);
	}
	return retorno;
}



/**
 * \brief Imprime el cliente con más avisos
 * \param arrayCliente Array de clientes a ser analizado
 * \param limiteClientes Limite del array de clientes
 * \param arrayPublicaciones Puntero al array de publicaciones a analizar
 * \param limitePublicaciones Tamaño del array a analizar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int info_imprimirRubroConMasAvisosPausados(Publicacion* arrayPublicacion, int limitePublicaciones)
{
	int retorno = -1;
	int j;
	int anunciosMaximos;
	int auxRubro;
	int auxiliarAnunciosPau;

	if(arrayPublicacion != NULL && limitePublicaciones > 0)
	{
	for(j=0;j<limitePublicaciones;j++)
		{
		auxiliarAnunciosPau = pub_informaPublicacionesPausadasRubro(arrayPublicacion, limitePublicaciones, &j);
		if(j== 0 || (auxiliarAnunciosPau > anunciosMaximos))
			{
			retorno = 0;
			anunciosMaximos = auxiliarAnunciosPau;
			auxRubro = 	j;
			}
		}
	printf("\nEl rubro %5d es el que menos avisos activos tiene, siendo %5d",auxRubro,anunciosMaximos);
	}

	return retorno;
}
