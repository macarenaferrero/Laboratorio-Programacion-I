/*
 * Publicacion.h
 *
 *  Created on: 8 may. 2020
 *      Author: maculina
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_
#define TEXTO_LEN 64

#define ESTADO_PAUSADO	0
#define ESTADO_ACTIVO	1

typedef struct
{
	char textoPublicacion[TEXTO_LEN];
	int rubro;
	int isEmpty;
	int idPublicacion;
	int idCliente;
	int estado;
}Publicacion;

int pub_imprimir(Publicacion* auxPublicacion);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente);
int pub_getEmptyIndex(Publicacion* array,int limite);


#endif /* PUBLICACION_H_ */
