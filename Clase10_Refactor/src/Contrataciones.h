/*
 * Contrataciones.h
 *
 *  Created on: 30 abr. 2020
 *      Author: maculina
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_

#define ARCHIVO_LEN 50
#define CUIT_LEN 50


typedef struct
{
	char archivo[ARCHIVO_LEN];
	char cuit[CUIT_LEN];
	int dia;
	int idPantalla;
	int isEmpty;
	int id;
}Contrataciones;

int con_imprimir(Contrataciones* auxProducto);
int con_inicializarArray(Contrataciones* array,int limite);
int con_updateArray(Contrataciones* array,int limite, int indice, int* id);
int con_getEmptyIndex(Contrataciones* array,int limite);
int con_imprimirArray(Contrataciones* array,int limite);
int con_buscarId(Contrataciones array[], int limite, int valorBuscado);
int con_modificarArray(Contrataciones* array,int limite, int indice);
int con_bajarArray(Contrataciones* array,int limite, int indice);
int con_ordenarPorNombre(Contrataciones* array,int limite);
int con_buscarCuit(Contrataciones array[], int limite, char valorBuscado[]);



#endif /* CONTRATACIONES_H_ */
