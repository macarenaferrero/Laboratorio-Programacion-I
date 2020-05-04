/*
 * Ejercicio 5:
 a) Realizar un programa que le pida 5 numeros int al usuario y los almacene en un array.
 Luego ejecutar la funcion borrarImpares() pasandole el array y que deberá reemplazar
 los numeros que son impares por un cero.
 b) Luego imprimir el array para chequear el funcionamiento.
 c) Ordenar el array de menor a mayor y volver a imprimirlo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/*
int borrarImpares()
{

}

int imprimirNumeros()
{

}
*/
int main(void) {

	int i;
	char numero[5];
	int numeros;

	for(i=0;i<sizeof(numero);i++)
	{
		if(utn_getInt(&numeros, "Ingrese un numero\n", "Error. Valor incorrecto\n", -10,10, 2)==0)
		{
			numero[i]=numeros;
			printf("El indice es: %d y el numero: %d\n", i,numero[i]);
		}

	}

	// borrar impares

	// imprimir

	// ordenar

	// imprimir


	return EXIT_SUCCESS;
}
