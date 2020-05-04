/*
 * Producto.c
 *
 *  Created on: 23 abr. 2020
 *      Author: maculina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"


void prod_imprProdPorReferencia(Producto* pProd)
{
	printf("%s %s Precio: %.2f\n", pProd-> nombre,
									pProd->descripcion,
									pProd->precio);
}

