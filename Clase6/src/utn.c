/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: maculina
 */

#include <stdio_ext.h>
#include <stdlib.h>

static int esFlotante (char* cadena);
static int getInt (int* pResultado);
static int esNumerica (char* cadena);
static int getFloat (float* pResultado);







int utn_getInt (int* pResultado, char* mensaje, char* mError, int min, int max, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt)==0)
			{
				if(bufferInt >= min && bufferInt <= max)
				{
						*pResultado = bufferInt;
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




/**
 * \ brief Verifica si la cadena ingresada es entera
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */


static int getInt (int* pResultado)
{
	char buffer[70];
	int retorno = -1;

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
		return retorno;
}



/**
 * \ brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (VERDADERO) si la cadena es numerica y (0) falso si no lo es
 */


static int esNumerica (char* cadena)
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
 * \ brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */


static int getFloat (float* pResultado)
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


static int esFlotante (char* cadena)
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

float promediarArrayInt(int arrayInt[],int len)
{
	int i;
	float promedioFinal;
	int acumulador=0;

	for(i=0; i<len; i++)
	{
		acumulador = acumulador + arrayInt[i];
	}
		promedioFinal = (float)acumulador / len;

		return promedioFinal;
}


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



int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)==cadena)
	{
		__fgurge(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}
