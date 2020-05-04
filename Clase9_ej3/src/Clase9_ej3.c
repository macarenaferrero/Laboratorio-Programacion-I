/*
Ejercicio 3.
Utilizando la biblioteca "Producto.h" de los ejercicios anteriores,
definir un array de 100 productos.
Realizar una funcion que inicialice el array indicando que los items
no estan cargados con informacion valida.

 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"
#include <string.h>

#define PROD_LEN	100

int main(void) {

	Producto productos[PROD_LEN];

	prod_initArray(productos,PROD_LEN);
	prod_imprProdPorReferencia(productos);

	return EXIT_SUCCESS;
}
