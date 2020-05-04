/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Macarena
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define NOMBRE_LEN 50
#define DESCRIPCION_LEN 250

typedef struct
{
	char nombre[NOMBRE_LEN];
	char descripcion[DESCRIPCION_LEN];
	float precio;
	int isEmpty;
	int id;
}Producto;

int prod_imprimir(Producto* auxProducto);
int prod_imprimirArray(Producto* arrayProductos,int limite);
int prod_initArray(Producto* arrayProductos,int limite);
int prod_updateArray(Producto* arrayProductos,int limite, int indice, int* id);
int prod_getEmptyIndex(Producto lista[], int len, int* pIndice);
int prod_modificarArray(Producto* arrayProductos,int limite, int indice);
int prod_bajarArray(Producto* arrayProductos,int limite, int indice);



#endif /* PRODUCTO_H_ */
