/*
 * Ejercicio 1:
 * Escribir la funcion calcularMayor(). La funcion debe recibir dos
 * numeros int y devolver por referencia, el numero mayor.
 * La funcion debe retornar un 1 si encontro un mayor, o un 0
 * si ambos numeros son iguales.

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	int resultado;
	int num1,num2;

	utn_getInt(&num1,"Ingrese el primer valor\n","Valor Incorrecto. Reintente\n", -1000, 1000, 2);
	utn_getInt(&num2, "Ingrese el segundo valor\n","Valor incorrecto. Reintente\n", -1000, 1000, 2);

	// luego llamo a la funcion calcularMayor()
	if(calcularMayor(&resultado,num1,num2)==0)
	{
		printf("Los numeros son iguales\n");
	}
	else
	{
		printf("El mayor es:%d\n",resultado);
	}

	return EXIT_SUCCESS;
}
 */
