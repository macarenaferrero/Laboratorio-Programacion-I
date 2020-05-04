/*
Ejercicio 4.
Tomar el ejercicio 3 y realizar una funcion que reciba el
array, un indice, y le permita al usuario cargar los datos
 en el item de la posicion especificada por el indice.


Ejercicio 5.
Tomar el ej 4 y agregar a la biblioteca producto funcion que
me devuelva el indice de un item vacio (sin cargar) o -1
en caso de error o de que no haya mas lugar.
Esta funcion debe recibir el array y su longitud:

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"

#define PROD_LEN	100

int main(void) {

	Producto productos[PROD_LEN];
	int i;

		if(prod_initArray(productos,PROD_LEN) == 0)
		{
			printf("Array INIT ok\n");
		}

		if(prod_updateArray(productos,PROD_LEN,2) == 0)
		{
			prod_imprimir(&productos[2]);
		}

		if(prod_getEmptyIndex(productos, PROD_LEN)>0)
		{
			i =prod_getEmptyIndex(productos, PROD_LEN);
			printf("El indice vacio es: %d\n", i);
		}else
		{
			printf("Error. No hay espacio disponible\n");
		}

		return EXIT_SUCCESS;
}
