
#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "utn.h"
#include "Informes.h"
#include "Publicacion.h"
#define CANTIDAD_CLIENTES 		100
#define CANTIDAD_PUBLICACIONES 1000



int main(void) {

	Publicacion arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	Cliente arrayClientes[CANTIDAD_CLIENTES];
	int idClientes=0;
	int idPublicaciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int auxiliarIdPublicacion;
	int auxiliarIndicePublicacion;
	int respuesta;
	int auxRubro;


	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array Clientes inicializado correctamente. \n\n");
	}

	if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES) == 0)
	{
		printf("Array Publicaciones inicializado correctamente. \n\n");
	}

	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"Alberto","Fernandez","23456789091");
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"Roberto","Ferrero", "20148743917");
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"Silvia","Dutra", "23177072157");

	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,0,&idPublicaciones,1,"Comela",2,0);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,1,&idPublicaciones,1,"Toda",1,0);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,2,&idPublicaciones,1,"JA",1,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,3,&idPublicaciones,0,"JE",4,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,4,&idPublicaciones,0,"JI",2,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,5,&idPublicaciones,2,"JO",10,1);

	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Dar de alta un cliente"
							"\n2.Modificar un cliente"
							"\n3.Dar de baja un cliente"
							"\n4.Dar de alta una publicidad"
							"\n5.Pausar una publicidad"
							"\n6.Reanudar una publicidad"
							"\n7.Imprimir clientes"
							"\n8.Imprimir publicaciones"
							"\n9.Informar clientes"
							"\n10.Informar publicaciones"
							"\n11.Salir\n\n",

							"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);

				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito, el ID del cliente es: %d\n", idClientes-1);
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
					else
					{
						printf("ID inválido\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,10000,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						!utn_getNumero(&respuesta, "Está seguro de querer eliminar al cliente? [1.SI]\n", "Opción inválida\n", 1, 1, 0) &&
						info_bajaArrayTotal(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,auxiliarId, arrayPublicaciones,CANTIDAD_PUBLICACIONES)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
					else
					{
						printf("\nId inválido\n");
					}
				}
				break;
			case 4:
				auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				if(auxiliarIndicePublicacion >= 0)
				{
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(	utn_getNumero(&auxiliarId,"\nIngrese el Id del Cliente que contratará un anuncio: ","\nError",0,10000,2) == 0 &&
						cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1)
					{
						pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion,&idPublicaciones,auxiliarId);
						printf("Publicación contratada, ID de la publicacion: %d", idPublicaciones-1);
					}
					else
					{
						printf("\nEl ID ingresado no se encuentra en la base de datos\n");
					}
				}
				break;
			case 5:
				pub_imprimirArray(arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				if(!utn_getNumero(&auxiliarIdPublicacion, "\n\nIngrese el ID de la publicación a pausar\n", "\nValor inválido\n", 0, 10000, 1) &&
					pub_buscarId(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion) != -1)
				{
						respuesta = pub_buscarIdCliente(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion);
						cli_imprimir(&arrayClientes[respuesta]);
						auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion);
						if(arrayPublicaciones[auxiliarIndicePublicacion].estado == 1 &&
							auxiliarIndicePublicacion >=0 &&
							!pub_pausarArray(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIndicePublicacion))
						{
							printf("\n\nLa publicacion seleccionada ha sido pausada\n");
							pub_imprimir(&arrayPublicaciones[auxiliarIndicePublicacion]);
						}else
						{
							printf("\n\nLa publicación seleccionada ya se encontraba pausada\n");
						}
				}
				else
				{
					printf("\nEl Id no corresponde a una publicación\n");
				}
				break;
			case 6:
				pub_imprimirArray(arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				if(!utn_getNumero(&auxiliarIdPublicacion, "\n\nIngrese el ID de la publicación a activar\n", "Valor inválido\n", 0, 10000, 1) &&
						pub_buscarId(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion) != -1)
				{
					respuesta = pub_buscarIdCliente(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion);
					cli_imprimir(&arrayClientes[respuesta]);

					auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIdPublicacion);
					if(	arrayPublicaciones[auxiliarIndicePublicacion].estado == 0 &&
						auxiliarIndicePublicacion >=0 &&
						!pub_activarArray(arrayPublicaciones, CANTIDAD_PUBLICACIONES, auxiliarIndicePublicacion))
					{
						printf("\n\nLa publicación seleccionada ha sido activada\n");
						pub_imprimir(&arrayPublicaciones[auxiliarIndicePublicacion]);
					}
					else
					{
						printf("\n\nLa publicación seleccionada ya se encontraba activa\n");
					}
				}
				else
				{
					printf("\nEl Id no corresponde a una publicación\n");
				}
				break;
			case 7:
				info_imprimirClientesConContadorAnuncios(arrayClientes, CANTIDAD_CLIENTES, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				break;
			case 8:
				info_imprimirPublicacionesConCuit(arrayClientes, CANTIDAD_CLIENTES, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				break;
			case 9:
				info_imprimirClienteConMasAvisosActivos(arrayClientes, CANTIDAD_CLIENTES, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				info_imprimirClienteConMasAvisosPausados(arrayClientes, CANTIDAD_CLIENTES, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				info_imprimirClienteConMasAvisos(arrayClientes, CANTIDAD_CLIENTES, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				break;
			case 10:
				utn_getNumero(&auxRubro,"Ingrese el numero de rubro  [1 al 1000]\n", "Rubro inexistente\n", 1, 10000, 2);
				info_imprimePublicacionesPorRubro(arrayPublicaciones, CANTIDAD_PUBLICACIONES,&auxRubro);
				info_imprimirRubroConMasAvisosActivos(arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				info_imprimirRubroConMasAvisosPausados(arrayPublicaciones, CANTIDAD_PUBLICACIONES);
				break;
			}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}




