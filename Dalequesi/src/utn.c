/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: maculina
 */

#include <stdio.h>
#include <stdlib.h>

int promediarNumeros(int operador1,int operador2)
{
	float promedioFinal;

	promedioFinal = (float)operador1/operador2;
	return promedioFinal;
}

int utn_getInt (int* pResultado, char* mensaje, char* mError, int min, int max, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mError != NULL && min <= max && reintentos >= 0)
	{
		printf("%s", mensaje);
		scanf("%d", &bufferInt);
	}else
	{
		printf("s%", mError);
	}
	return retorno;
}

int esPositivo(int operador1)
{

	int positividad;
	if(operador1>=0)
	{
		positividad=1;
	}else
	{
		positividad=0;
	}
	return positividad;
}


