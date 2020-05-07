/*
 * >>>> TP N2<<<<
 *
 *Crear biblioteca Empleado
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Empleado.h"
#include "utn.h"

#define CANTIDAD_Empleado 1000

int main(void) {

	Empleado arrayEmpleado[CANTIDAD_Empleado];
	int idEmpleado=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(fan_inicializarArray(arrayEmpleado,CANTIDAD_Empleado) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Empleado"
							"\n2.Modificar un Empleado"
							"\n3.Eliminar un Empleado"
							"\n4.Ordenar lista de Empleado"
							"\n5.Imprimir lista Empleado"
							"\n6.Salir\n\n",
							"\nError opcion invalida",1,6,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = fan_getEmptyIndex(arrayEmpleado,CANTIDAD_Empleado);
				if(auxiliarIndice >= 0)
				{
					if(fan_altaArray(arrayEmpleado,CANTIDAD_Empleado,auxiliarIndice,&idEmpleado) == 0)
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
				fan_imprimirArray(arrayEmpleado,CANTIDAD_Empleado);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Empleado a modificar","\nID invalido",0,idEmpleado,0) == 0)
				{
					auxiliarIndice = fan_buscarId(arrayEmpleado,CANTIDAD_Empleado,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_modificarArray(arrayEmpleado,CANTIDAD_Empleado,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				fan_imprimirArray(arrayEmpleado,CANTIDAD_Empleado);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Empleado a eliminar","\nID invalido",0,idEmpleado,0)==0)
				{
					auxiliarIndice = fan_buscarId(arrayEmpleado,CANTIDAD_Empleado,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_bajaArray(arrayEmpleado,CANTIDAD_Empleado,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				fan_ordenarPorNombre(arrayEmpleado,CANTIDAD_Empleado);
				break;

			case 5:
				fan_imprimirArray(arrayEmpleado,CANTIDAD_Empleado);
				break;

			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}





