#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 50
#define DNI_LEN 20

typedef struct
{
	char nombre[NOMBRE_LEN];
	char dni[DNI_LEN];
	float altura;
	int isEmpty;
	int id;
}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);
int cli_ordenarPorNombre(Cliente* array,int limite);

#endif /* CLIENTE_H_ */
