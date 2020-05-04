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

int main(void)
{
	setbuf(stdout, NULL);

	int edad;
	float peso;
	int respuesta;
	char letra;


	respuesta = utn_getChar(&letra,"\nCual es la letra?","Error. La letra debe ser desde A a J\n",'A','J',2);
		if(respuesta == 0)
		{
			printf("\nLa letra es: %c\n",letra);
		}
		else
		{
			printf("\nERROR");
		}

	respuesta = utn_getInt(&edad,"\nCual es la edad?","Error la edad debe ser desde 0 a 199\n",0,199,2);
	if(respuesta == 0)
	{
		printf("La edad es: %d\n",edad);
	}
	else
	{
		printf("\nERROR");
	}

	respuesta = utn_getFloat(&peso,"\nCual es el peso?","Error peso debe ser desde 0 a 500\n",0,500,3);
	if(respuesta == 0)
	{
		printf("El peso es: %f\n",peso);
	}
	else
	{
		printf("\nERROR");
	}


	return EXIT_SUCCESS;
}


