#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define QTY_ALUMNOS 100

/**
 * 1 Alta alumno
 * 2 Baja alumno
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 * 8 Guardar a Archivo
 * 9 Leer desde Archivo
 * 10 Salir
 **/


int main(void)
{
	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];
	int opcion;
	int proximoId = 0;
	float bufferAltura;
	char bufferNombre[NOMBRE_LEN];
	int bufferId;
	int bufferIndice;
	float auxiliarAlturaPromedio;
	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("INIT OK");
		// SOLO PARA TEST
		//alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"BBBBBB",1,0);
		//alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"AAAAAA",2,1);
		//alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"CCCCCC",3,2);
		//proximoId = 3;
		// SOLO PARA TEST
		do
		{
			utn_getNumero(&opcion,"\n1-Alta\n2-Baja\n3-Modificacion\n4-Ordenar\n5-Imprimir\n6-Promedio de alturas\n7-Alumno mas alto\n8-Guardar a Archivo\n9-Leer Archivo\n10-Salir","\nOpcion invalida",1,10,2);
			switch(opcion)
			{
				case 1:
					if(	!utn_getNombre(bufferNombre,NOMBRE_LEN,"\nNombre?","\nNombre invalido",2) &&
						!utn_getNumeroFlotante(&bufferAltura,"\nAltura?","\nAltura incorrecta",0.10,4,2) &&
						alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,bufferNombre,bufferAltura,proximoId) >= 0)
					{
						printf("\nAlta OK");
						proximoId++;
					}
					break;
				case 2:
					alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
					if(	!utn_getNumero(&bufferId,"\nId?","\nId invalido",0,10000,2) &&
						!alumno_borrarPorIdArray(arrayPunterosAlumno,QTY_ALUMNOS,bufferId))
					{
						printf("\n Baja ok");
					}
					else
					{
						printf("\nEl ID: %d no fue encontrado",bufferId);
					}
					break;
				case 3:
					alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
					if(!utn_getNumero(&bufferId,"\nId?","\nId invalido",0,10000,2) )
					{
						bufferIndice = alumno_buscarPorIdArray(arrayPunterosAlumno,QTY_ALUMNOS,bufferId);
						if(bufferIndice >= 0)
						{
							if(	!utn_getNombre(bufferNombre,NOMBRE_LEN,"\nNombre?","\nNombre invalido",2) &&
								!utn_getNumeroFlotante(&bufferAltura,"\nAltura?","\nAltura incorrecta",0.10,4,2))
							{
								alumno_setNombre(arrayPunterosAlumno[bufferIndice],bufferNombre);
								alumno_setAltura(arrayPunterosAlumno[bufferIndice],bufferAltura);
							}
						}
						else
						{
							printf("\nEl ID: %d no fue encontrado",bufferId);
						}
					}
					break;
				case 4:
					alumno_ordenarArray(arrayPunterosAlumno,QTY_ALUMNOS);
					alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
					break;
				case 5:
					alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
					break;
				case 6:
					alumno_calcularAlturaPromedioArray(arrayPunterosAlumno,QTY_ALUMNOS,&auxiliarAlturaPromedio);
					printf("\nLa altura promedio es %.2f",auxiliarAlturaPromedio);
					break;
				case 7:
					alumno_calcularAlturaMaximaArray(arrayPunterosAlumno,QTY_ALUMNOS,&bufferIndice);
					alumno_getNombre(arrayPunterosAlumno[bufferIndice],bufferNombre);
					alumno_getAltura(arrayPunterosAlumno[bufferIndice],&bufferAltura);
					printf("\nEl alumno mas alto es %s y mide %.2f",bufferNombre,bufferAltura);
					break;
				case 8:
					if(!alumno_guardarArrayEnArchivo(arrayPunterosAlumno,QTY_ALUMNOS,"data.csv"))
					{
						printf("\nArchivo generado exitosamente");
					}
					break;
				case 9:
					if(!alumno_leerArrayEnArchivo(arrayPunterosAlumno,QTY_ALUMNOS,"data.csv",&proximoId))
					{
						printf("\nArchivo cargado exitosamente");
					}
					break;


			}
		}while(opcion != 10);
	}
	return 0;
}
