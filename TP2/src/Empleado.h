#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define NAME_LEN 50
#define LASTNAME_LEN 20

typedef struct
{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Empleado;

int emp_imprimir(Empleado* auxProducto);
int emp_inicializarArray(Empleado* array,int limite);
int emp_altaArray(Empleado* array,int limite, int indice, int* id);
int emp_getEmptyIndex(Empleado* array,int limite);
int emp_imprimirArray(Empleado* array,int limite);
int emp_buscarId(Empleado array[], int limite, int valorBuscado);
int emp_modificarArray(Empleado* array,int limite, int indice);
int emp_bajaArray(Empleado* array,int limite, int indice);
int emp_ordenarPorNombre(Empleado* array,int limite);

#endif /* EMPLEADO_H_ */
