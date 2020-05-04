/*
 ============================================================================
 Name        : Clasesabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ingresar números hasta que el usuario lo decida.
 Los números tienen que estar comprendidos entre -100 y 100.
 Determinar:
 a. Cantidad de números positivos.
 b. Cantidad de números negativos.
 c. Promedio de números positivos y negativos.
 d. De los positivos el máximo.
 Aplicar las siguientes funciones:
 a. int getInt(char[], char[], int, int) para el ingreso y validación de datos de tipo entero.
 b. int esPositivo(int) retorna 1 en caso de que el número recibido como parámetro sea positivo,
 0 en caso contrario.
 c. float promediarNumeros(int,int): recibe el acumulador y el contador de números y retorna el promedio.


 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"


int main(void){

	int numeroUno;
	char respuesta;
	int contadorPositivos=0;
	int contadorNegativos=0;
	int acumuladorPositivos=0;
	int acumuladorNegativos=0;
	float promedioPositivos;
	float promedioNegativos;
	int maximoPositivos;
	int valorPositivo;

	do
	{
<<<<<<< HEAD
		numeroUno = utn_getInt(&numeroUno,"Ingrese un numero: [-100 al 100]", "Valor incorrecto. Ingrese un numero: [-100 al 100]", -100, 100, 3);
		if(numeroUno == 0)

		{

			printf("El numero es: %d", numeroUno);

		}

		else

		{

			printf("ERROR");

		}
=======
		numeroUno = getInt("Ingrese un numero: [-100 al 100]", "Valor incorrecto. Ingrese un numero: [-100 al 100]", -100, 100);

>>>>>>> 3d3680727b04bc0a3e3c2ffe17063babc1ad1a2c
		valorPositivo = esPositivo(numeroUno);

		if(valorPositivo==1)
				{
					contadorPositivos++;
					acumuladorPositivos=acumuladorPositivos + numeroUno;

					if(contadorPositivos==1 || maximoPositivos<numeroUno)
					{
						maximoPositivos = numeroUno;
					}

				}else
				{
					contadorNegativos++;
					acumuladorNegativos=acumuladorNegativos+numeroUno;
				}

		printf("¿Desea continuar? [s/n]\n");
		__fpurge(stdin);
		scanf("%c", &respuesta);

	}while(respuesta != 'n');

	//INVOCO FUNCIONES

	promedioPositivos= promediarNumeros(acumuladorPositivos, contadorPositivos);
	promedioNegativos= promediarNumeros(acumuladorNegativos, contadorNegativos);


	printf("La cantidad de numeros negativos es: %d\n", contadorPositivos);
	printf("La cantidad de numeros positivos es: %d\n", contadorNegativos);
	printf("El promedio de los positivos es: %.2f\n", promedioPositivos);
	printf("El promedio de los negativos es: %.2f\n", promedioNegativos);
	printf("El máximo de los positivos es: %d\n", maximoPositivos);


	return EXIT_SUCCESS;
}


//DESARROLLO FUNCIONES


