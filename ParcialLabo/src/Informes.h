/*
 * Informes.h
 *
 *  Created on: May 8, 2020
 *      Author: Macarena
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Cliente.h"
#include "utn.h"
#include "Informes.h"
#include "Publicacion.h"

int info_bajaArrayTotal(Cliente* array,int limite, int indice,int idCliente, Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_imprimirClientesConContadorAnuncios(Cliente* arrayCliente,int limiteClientes, Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_imprimirPublicacionesConCuit(Cliente* arrayCliente,int limiteClientes, Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_imprimirClienteConMasAvisosActivos(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones);
int info_imprimirClienteConMasAvisosPausados(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones);
int info_imprimirClienteConMasAvisos(Cliente* arrayClientes, int limiteClientes, Publicacion* arrayPublicacion, int limitePublicaciones);
int info_imprimePublicacionesPorRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro);
int info_imprimirRubroConMasAvisosActivos(Publicacion* arrayPublicacion, int limitePublicaciones);
int info_imprimirRubroConMasAvisosPausados(Publicacion* arrayPublicacion, int limitePublicaciones);



#endif /* INFORMES_H_ */
