#ifndef FANTASMA_H_
#define FANTASMA_H_

#define NOMBRE_LEN 50
#define DNI_LEN 20
#define MAIL_LEN 20
#define TEL_LEN 20
#define DIR_LEN 40


typedef struct
{
	char nombre[NOMBRE_LEN];
	char dni[DNI_LEN];
	char mail[MAIL_LEN];
	char telefono[TEL_LEN];
	char direccion[DIR_LEN];
	float altura;
	float peso;
	int isEmpty;
	int id;
}Fantasma;

int fan_imprimir(Fantasma* auxProducto);
int fan_inicializarArray(Fantasma* array,int limite);
int fan_altaArray(Fantasma* array,int limite, int indice, int* id);
int fan_getEmptyIndex(Fantasma* array,int limite);
int fan_imprimirArray(Fantasma* array,int limite);
int fan_buscarId(Fantasma array[], int limite, int valorBuscado);
int fan_modificarArray(Fantasma* array,int limite, int indice);
int fan_bajaArray(Fantasma* array,int limite, int indice);
int fan_ordenarPorNombre(Fantasma* array,int limite);

#endif /* FANTASMA_H_ */
