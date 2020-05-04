/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: maculina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int esFlotante (char* cadena);
int getInt (int* pResultado);
int esNumerica (char* cadena, int limite);
int getFloat (float* pResultado);
int myGets(char* cadena, int longitud);

/**
 * \ brief Solicita un numero entero al usuario
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mError Es el mensaje a ser mostrado por error
 * \param min Es el valor minimo a ser aceptado
 * \param max Es el valor maximo a ser acepado
 */

int utn_getInt (int* pResultado, char* mensaje, char* mError, int min, int max, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt)==0 &&
				bufferInt >= min &&
				bufferInt <= max)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
					__fpurge(stdin);
					printf("%s", mError);
					reintentos--;
			}
		}while(reintentos>=0);
	}
			return retorno;
}

/**
 * \ brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mError Es el mensaje a ser mostrado por error
 * \param min Es el valor minimo a ser aceptado
 * \param max Es el valor maximo a ser acepado
 */

float utn_getFloat (float* pResultado, char* mensaje, char* mError, float min, float max, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mError != NULL && min <= max && reintentos >= 0)
	{
		do
		{

			printf("%s", mensaje);
			if(getFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= min && bufferFloat <= max)
				{
						*pResultado = bufferFloat;
						retorno = 0;
						break;
				}
			}
			else
			{
					__fpurge(stdin);
					printf("%s", mError);
					reintentos--;
			}
		}while(reintentos>=0);
	}
			return retorno;
}





/*
char utn_getChar (char* pResultado, char* mensaje, char* mError, char min, char max, int reintentos)
{
	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mError != NULL && min <= max && reintentos >= 0)
	{
		do
		{

			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar >= min && bufferChar <= max)
			{
					*pResultado = bufferChar;
					retorno = 0;
					break;
			}

			else
			{
					__fpurge(stdin);
					printf("%s", mError);
					reintentos--;
			}
		}while(reintentos>=0);
	}
			return retorno;
}
*/

/**
 * \ brief Calcula el valor mayor
 * \param pResultado Puntero al espacio de memoria donde se dejara el mayor valor
 * \param num1 Es el valor a evaluar
 * \param num2 Es el valor a evaluar
 */

int calcularMayor(int* pResultado,int num1,int num2)
{
	int retorno=1;

	if(pResultado !=NULL)
	{
		if(num1==num2)
		{
			retorno=0;
		}else
		{
			if(num1 > num2)
			{
			*pResultado=num1;

			}else
			{	*pResultado=num2;

			}
			retorno=1;
		}
	}

	return retorno;
}



/**
 * \ brief Verifica si la cadena ingresada es entera
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */


int getInt (int* pResultado)
{
	char buffer[70];
	int retorno = -1;

	if(pResultado != NULL &&
		myGets(buffer, sizeof(buffer))==0 &&
		esNumerica(buffer, sizeof(buffer)))
	{
			*pResultado = atoi(buffer);
			retorno = 0;

	}
		return retorno;
}



/**
 * \ brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (VERDADERO) si la cadena es numerica y (0) falso si no lo es
 */


int esNumerica (char* cadena, int limite)
{
	int i;
	int retorno = -1; //ERROR


	if(cadena != NULL && limite> 0)
	{
		retorno = 1;
		for(i=0;i< limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
			{
				continue;
				if(cadena[i]<'0' || cadena[i]>'9')
				{
					retorno=0;
					break;
				}
				//CONTINUE
			}
		}
		//BREAK
	}
		return retorno;
}





/**
 * \ brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */


int getFloat (float* pResultado)
{
	float buffer[70];
	int retorno = -1;

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
		return retorno;
}


/**
 * \ brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (VERDADERO) si la cadena es flotante y (0) falso si no lo es
 */


int esFlotante (char* cadena)
{
	int i;
	int retorno = 1;
	int contadorPunto=0;

	if(cadena != NULL && strlen(cadena)> 0)
	{
		for(i=0; cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
			{
				continue;
				if(cadena[i]<'0' || cadena[i]>'9')
				{
					if(cadena[i]=='.' && contadorPunto ==0)
					{
						contadorPunto++;
					}
				}else
				{
					retorno=0;
					break;
				}
			}
		}
	}
		return retorno;
}



/**
 * \ brief Solicita al usuario una cadena
 * \param cadena Puntero de cadena
 * \param longitud Es el tamaño del array
 */

int myGets(char* cadena, int longitud)
{
	__fpurge(stdin);
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)==cadena)
	{

		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

