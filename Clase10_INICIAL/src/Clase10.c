/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Fantasma
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del fantasma
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Pantalla.h"
#include "utn.h"

#define CANTIDAD_FANTASMA 4

int main(void) {

	Pantalla arrayFantasma[CANTIDAD_FANTASMA];
	int idFantasma=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(fan_inicializarArray(arrayFantasma,CANTIDAD_FANTASMA) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Fantasma"
							"\n2.Modificar un Fantasma"
							"\n3.Eliminar un Fantasma"
							"\n4.Ordenar lista de Fantasma"
							"\n5.Imprimir lista Fantasma"
							"\n6.Salir\n\n",
							"\nError opcion invalida",1,6,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = fan_getEmptyIndex(arrayFantasma,CANTIDAD_FANTASMA);
				if(auxiliarIndice >= 0)
				{
					if(fan_altaArray(arrayFantasma,CANTIDAD_FANTASMA,auxiliarIndice,&idFantasma) == 0)
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
				fan_imprimirArray(arrayFantasma,CANTIDAD_FANTASMA);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del fantasma a modificar","\nID invalido",0,idFantasma,0) == 0)
				{
					auxiliarIndice = fan_buscarId(arrayFantasma,CANTIDAD_FANTASMA,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_modificarArray(arrayFantasma,CANTIDAD_FANTASMA,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				fan_imprimirArray(arrayFantasma,CANTIDAD_FANTASMA);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del fantasma a eliminar","\nID invalido",0,idFantasma,0)==0)
				{
					auxiliarIndice = fan_buscarId(arrayFantasma,CANTIDAD_FANTASMA,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_bajaArray(arrayFantasma,CANTIDAD_FANTASMA,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				fan_ordenarPorNombre(arrayFantasma,CANTIDAD_FANTASMA);
				break;

			case 5:
				fan_imprimirArray(arrayFantasma,CANTIDAD_FANTASMA);
				break;

			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}





