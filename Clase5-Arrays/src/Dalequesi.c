/*
 ============================================================================
 Name        : Clasesabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

#define EDADESSIZE 5

	// EJERCICIO: Pedirle al usuario 5 edades y LUEGO
	// imprimir las 5 edades. Definir un array de 5 posiciones.
	// y usar la funcion utn_getNumero() para pedir los valores


int main(void)
{
	setbuf(stdout, NULL);

	int edades[EDADESSIZE]; //Definí previamente el valor, asi es mas facil de modificar
	int i;
	float promedioEdades;

	for(i=0; i<EDADESSIZE; i++) // de 0 a 4
	{
		if(utn_getInt(&edades[i],"\nCual es la edad?","Error la edad debe ser desde 0 a 199\n",0,199,2) == 0)
		{
			printf("\nSe cargo la edad en la posicion %d",i);
		}
		else
		{
			printf("\nERROR");
		}
	}

	for(i=0; i<EDADESSIZE; i++)
	{

		printf("\nLa edad es %d y su posicion %d ",edades[i],i);
	}


	promedioEdades = promediarArrayInt(edades,EDADESSIZE);

	printf("El promedio es %f", promedioEdades);


	return EXIT_SUCCESS;
}

