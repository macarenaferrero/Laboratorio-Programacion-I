/*
Ejercicio 1.
Definir un nuevo tipo de dato que represente un producto.
El producto tiene un nombre una descripcion y un precio.
Hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida en la
funcion main.
Imprmir los campos de la variable producto para chequear que
esten cargadas correctamente.

Ejercicio 2.
Tomar el programa del ejercicio anterior y agregarle lo siguiente:
1) Una vez que el usuario ingreso los datos, preguntarle si
quiere aplicar un descuento del 25% al precio del producto.
Si acepta, calcular el nuevo precio.
2) Hacer una funcion que reciba la variable producto definida
y que imprima sus valores.
NOTA: Pude pasarse la variable producto por referencia o por
valor. ¿Cual es la diferencia?

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"



int main(void)
{

	Producto producto;
	char respuesta[2];
	float descuento  = 0.75;


		if(utn_getNombre(producto.nombre, NOMBREARRAY, "Ingrese nombre\n", "Valor incorrecto\n", 2)==0)
		{

			if(utn_getNombre(producto.descripcion, DESCR_ARRAY, "Ingrese Descripcion\n", "Valor incorrecto\n", 2)==0)
			{

				if(utn_getNumeroFlotante(&producto.precio, "Ingrese el precio\n", "Valor incorrecto\n", 0.0, 1000, 2)==0)
				{
					if(utn_getNombre(respuesta, 2, "Desea realizar un descuento del 25%? [s/n]\n", "Error", 2)==0)
					{
					if(strncmp(respuesta, "s",2)==0)
					{
						printf("Aplico descuento!\n");
						producto.precio = producto.precio*descuento;

						prod_imprProdPorReferencia(&producto);
					}
					}
				}
			}
		}



	return EXIT_SUCCESS;
}
