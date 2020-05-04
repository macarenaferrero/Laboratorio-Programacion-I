/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Clientes
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del cliente
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "utn.h"

#define CANTIDAD_CLIENTES 4

int main(void) {

	Cliente arrayClientes[CANTIDAD_CLIENTES];
	int idClientes=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Cliente"
							"\n2.Modificar un Clientes"
							"\n3.Eliminar un Cliente"
							"\n4.Ordenar lista de Clientes"
							"\n5.Imprimir lista Clientes"
							"\n6.Salir\n\n",
							"\nError opcion invalida",1,6,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				cli_ordenarPorNombre(arrayClientes,CANTIDAD_CLIENTES);
				break;

			case 5:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				break;

			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}





