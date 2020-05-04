/*
 * Pantalla.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Macarena
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define NOMBRE_LEN 50
#define DESCRIPCION_LEN 250

typedef struct
{
	char nombre[NOMBRE_LEN];
	char direccion[DESCRIPCION_LEN];
	float precio;
	int tipoPantalla;
	int isEmpty;
	int id;
}Pantalla;

int pan_imprimir(Pantalla* auxPantalla);
int pan_imprimirArray(Pantalla* arrayPantalla,int limite);
int pan_initArray(Pantalla* arrayPantalla,int limite);
int pan_updateArray(Pantalla* arrayPantalla,int limite, int indice, int* id);
int pan_getEmptyIndex(Pantalla lista[], int len);
int pan_modificarArray(Pantalla* arrayPantalla,int limite, int indice);
int pan_bajarArray(Pantalla* arrayPantalla,int limite, int indice);
int pan_buscarId(Pantalla array[], int limite, int valorBuscado);
int pan_ordenarPorNombre(Pantalla* array,int limite);





#endif /* PANTALLA_H_ */
