#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			if(pFile != NULL)
			{

				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo)== 4)
					{
						if(employee_newParametros(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo) >= 0)
						{
							auxEmployee = employee_newParametros(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);
							ll_add(pArrayListEmployee,auxEmployee);
							retorno = 0;

						}
					}
				}while(!feof(pFile));
			}
		}
		return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
