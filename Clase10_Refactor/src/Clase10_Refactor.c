/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Pantallas
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
#include "Contrataciones.h"


#define CANTIDAD_PANTALLA 10
#define CANTIDAD_CONTRATACIONES 10


int main(void) {

	Pantalla arrayPantalla[CANTIDAD_PANTALLA];
	int idPantalla=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	Contrataciones arrayContrataciones[CANTIDAD_CONTRATACIONES];
	int idContratacion = 0;
	int auxIdContratacion;
	int auxIndiceCont;
	int respuesta;
	char auxCuit[CUIT_LEN];


	if(pan_initArray(arrayPantalla,CANTIDAD_PANTALLA) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	if(con_inicializarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Pantalla"
							"\n2.Modificar un Pantalla"
							"\n3.Eliminar un Pantalla"
							"\n4.Ordenar lista de Pantalla"
							"\n5.Imprimir lista Pantalla"
							"\n6.Adquirir una contratacion"
							"\n7.Modificar condiciones de contratacion"
							"\n8.Cancelar contratacion"
							"\n9.Consultar facturacion"
							"\n10.Listar contrataciones"
							"\n11.Ordenar lista de contrataciones"
							"\n12.Imprimir lista contrataciones"
							"\n13.Informe"
							"\n14.Salir\n\n",
							"\nError opcion invalida",1,14,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = pan_getEmptyIndex(arrayPantalla,CANTIDAD_PANTALLA);
				if(auxiliarIndice >= 0)
				{
					if(pan_updateArray(arrayPantalla,CANTIDAD_PANTALLA,auxiliarIndice,&idPantalla) == 0)
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
				pan_imprimirArray(arrayPantalla,CANTIDAD_PANTALLA);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID de la pantalla a modificar","\nID invalido",0,idPantalla,0) == 0)
				{
					auxiliarIndice = pan_buscarId(arrayPantalla,CANTIDAD_PANTALLA,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						pan_modificarArray(arrayPantalla,CANTIDAD_PANTALLA,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				pan_imprimirArray(arrayPantalla,CANTIDAD_PANTALLA);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID de la pantalla a eliminar","\nID invalido",0,idPantalla,0)==0)
				{
					auxiliarIndice = pan_buscarId(arrayPantalla,CANTIDAD_PANTALLA,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						pan_bajarArray(arrayPantalla,CANTIDAD_PANTALLA,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				pan_ordenarPorNombre(arrayPantalla,CANTIDAD_PANTALLA);
				break;

			case 5:
				pan_imprimirArray(arrayPantalla,CANTIDAD_PANTALLA);
				break;
			case 6:
				do
				{
					pan_imprimirArray(arrayPantalla,CANTIDAD_PANTALLA);

					if(!utn_getNumero(&auxIdContratacion, "Ingrese ID de pantalla que desea contratar\n", "ID incorrecto\n", 0, 1000, 2))
					{
					auxIndiceCont = pan_buscarId(arrayPantalla,CANTIDAD_PANTALLA,auxIdContratacion);

					if(auxIndiceCont >=0)
					{
						pan_imprimir(&arrayPantalla[auxIndiceCont]);
						utn_getNumero(&respuesta, "Es correcto el ID que desea contratar [1.SI / 2.NO]\n", "Valor incorrecto\n", 1, 2, 2);
					}else
					{
						printf("ID inválido\n");
					}
					}
				}while(respuesta != 1);

					auxIndiceCont = con_getEmptyIndex(arrayContrataciones, CANTIDAD_CONTRATACIONES);
					if(auxIndiceCont >=0)
					{
						if(!con_updateArray(arrayContrataciones, CANTIDAD_CONTRATACIONES, auxIndiceCont, &idContratacion))
						{
						printf("\nContratación realizada con exito\n");
						}
					}else
					{
						printf("No hay más espacio\n");
					}
					break;
			case 7:
				do
				{
					if(!utn_getDni(auxCuit, CUIT_LEN, "Ingrese Cuit sin guiones\n", "CUIT incorrecto\n", 2))
					{
						//Que condicion debo usar para corroborar que lo ingresado es un cuit valido?

					}
				}while(1);
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;

			}
		}
	}while(opcion != 14);

	return EXIT_SUCCESS;
}






