/*
 ============================================================================
 Name        : Clase6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 /*
 * Ejercicio 2:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 *
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes.
 *
 *
 * Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define TEMPSIZE 31

int main(void)
{
	setbuf(stdout, NULL);

		float temperaturas[TEMPSIZE]; //Definí previamente el valor, asi es mas facil de modificar
		int i;
		int respuesta;
		int dia;
		float temp;

do
{
			if(utn_getInt (&respuesta, "1.Imprimir array 2.Cargar array 3.Salir","Error. valor incorrecto\n", 1,3,2)==0)
			{
				switch (respuesta)
				{
					case 1:
						for(i=0;i<TEMPSIZE; i++)
						{
							printf("El indice es %d y se registro %d centigrados\n", i+1, temperaturas[i]);
						}
						break;

					case 2:
						if(utn_getInt(&dia, "Ingrese el dia\n", "Dia incorrecto. Reintente.\n", 1, 31, 2)==0)
						{

							if(utn_getFloat(&temp, "Ingrese la temperatura: ", "ERROR, numero invalido", 0, 100, 2)==0)
							{
								// cargar la temp en el array en la pos que corresponde
								temperaturas[i] = temp;
							}

						}
				}


			}else
			{
				printf("Se acabaron tus reintentos");
			}

}while(respuesta !=3);


		return EXIT_SUCCESS;
}
*/
