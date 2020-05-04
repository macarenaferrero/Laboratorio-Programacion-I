/*
Ejercicio 6.
Tomar la biblioteca producto del ej5  y realizar un programa
con un menu de dos opciones:

    a) Cargar un producto
    b) Imprimir lista productos

Se debera utilizar la funcion que devuelve una posicion vacia
para indicar en que posicion del array se guardaran los datos
ingresados.


Ejercicio 7.
Agregar al tipo de dato el campo ID que represente un
identificador unico. Modificar el codigo anterior para
que el ID se genere automaticamente. Se debera cargar
el ID automaticamente al cargar un producto, y se debera
 imprimir al imprimir la lista.

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"

#define PROD_LEN	2

int main(void) {

	Producto productos[PROD_LEN];
	int respuesta;
	int indice;
	int idProducto;


		if(!prod_initArray(productos, PROD_LEN))
		{
			printf("Inicializacion ok\n");
		}

do
{
		if(!utn_getNumero(&respuesta, "1) Cargar un producto\n2) Imprimir lista productos\n3) Salir\n", "Opcion incorrecta", 1, 3, 2))
		{
			switch(respuesta)
			{
				case 1:
					if(prod_getEmptyIndex(productos, PROD_LEN, &indice)==0)
					{
						printf("Se cargará en el espacio: %d",indice);

						if(prod_updateArray(productos, PROD_LEN, indice, &idProducto)==0)
						{
							printf("Se cargó correctamente\n");
						}
					}
					else
					{
						printf("No hay más espacio\n");
					}

					break;
				case 2:
					prod_imprimirArray(productos, PROD_LEN);
					break;


			}
		}
}while(respuesta != 3);

		return EXIT_SUCCESS;
}



