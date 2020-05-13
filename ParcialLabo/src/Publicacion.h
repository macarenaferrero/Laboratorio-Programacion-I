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
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion array[], int limite, int valorBuscado);
int pub_pausarArray(Publicacion* array,int limite, int indice);
int pub_activarArray(Publicacion* array,int limite, int indice);
int pub_buscarIdCliente(Publicacion array[], int limite, int idPublicacionBuscado);
int pub_contadorAvisosActivosPorId(Publicacion* arrayPublicaciones,int limitePublicaciones, int idCliente);
int pub_contadorAvisosPausadosPorId(Publicacion* arrayPublicaciones,int limitePublicaciones, int idCliente);
int pub_informaPublicacionesActivasRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro);
int pub_informaPublicacionesPausadasRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro);





int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,int rubro,int estado);

#endif /* PUBLICACION_H_ */
