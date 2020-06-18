#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		Employee* auxEmployee;
		char auxiliarId[4096];
		char auxiliarNombre[4096];
		char auxiliarHsTrabajadas[4096];
		char auxiliarSueldo[4096];
		int contadorEmployee=0;

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo)== 4)
					{
						if(employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo) >= 0)
						{
							auxEmployee = (Employee*) employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);
							if(ll_add(pArrayListEmployee,auxEmployee)==0)
							{
							retorno = 0;
							contadorEmployee++;

							}

						}
					}
				}while(!feof(pFile));
		}
		printf("Se cargaron %d empleados\n",contadorEmployee);
		return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		Employee* auxPEmployee;
		Employee auxEmployee;
		char auxiliarId[4096];
		char auxiliarNombre[4096];
		char auxiliarHsTrabajadas[4096];
		char auxiliarSueldo[4096];
		int contadorEmployee=0;

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			if(pFile != NULL)
			{

				do
				{
					if(fread(&auxEmployee,sizeof(Employee),1, pFile)==1)
					{
		                sprintf(auxiliarId, "%d", auxEmployee.id);
		                strcpy(auxiliarNombre, auxEmployee.nombre);
		                sprintf(auxiliarHsTrabajadas, "%d",auxEmployee.horasTrabajadas);
		                sprintf(auxiliarSueldo, "%d", auxEmployee.sueldo);

						if(employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo) >= 0)
						{
							auxPEmployee = (Employee*) employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);
							if(ll_add(pArrayListEmployee,auxPEmployee)==0)
							{
								retorno = 0;
								contadorEmployee++;
							}

						}
					}
				}while(!feof(pFile));
			}
		}
		printf("Se cargaron %d empleados\n",contadorEmployee);
		return retorno;
}
