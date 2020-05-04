/*
 * Producto.h
 *
 *  Created on: 23 abr. 2020
 *      Author: maculina
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define NOMBREARRAY 50
#define DESCR_ARRAY 50


typedef struct
{
	char nombre[NOMBREARRAY];
	char descripcion[DESCR_ARRAY];
	float precio;

}Producto;

void prod_imprProdPorReferencia(Producto* pProd);
int prod_initArray(Producto array[],int len);
int prod_cargarProducto(Producto array[],int len, int indice);



#endif /* PRODUCTO_H_ */
