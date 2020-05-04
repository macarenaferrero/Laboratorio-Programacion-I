#ifndef PANTALLA_H_
#define PANTALLA_H_

#define NOMBRE_LEN 50
#define DNI_LEN 20

typedef struct
{
	char nombre[NOMBRE_LEN];
	char dni[DNI_LEN];
	float precio;
	int isEmpty;
	int id;
}Pantalla;

int pan_imprimir(Pantalla* auxProducto);
int pan_inicializarArray(Pantalla* array,int limite);
int pan_altaArray(Pantalla* array,int limite, int indice, int* id);
int pan_getEmptyIndex(Pantalla* array,int limite);
int pan_imprimirArray(Pantalla* array,int limite);
int pan_buscarId(Pantalla array[], int limite, int valorBuscado);
int pan_modificarArray(Pantalla* array,int limite, int indice);
int pan_bajaArray(Pantalla* array,int limite, int indice);
int pan_ordenarPorNombre(Pantalla* array,int limite);

#endif /* PANTALLA_H_ */
