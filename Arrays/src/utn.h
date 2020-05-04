/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: maculina
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt (int* pResultado, char* mensaje, char* mError, int min, int max, int reintentos);
float utn_getFloat (float* pResultado, char* mensaje, char* mError, float min, float max, int reintentos);
char utn_getChar (char* pResultado, char* mensaje, char* mError, char min, char max, int reintentos);

/** \brief calcula la suma de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la suma de los 2 parametros
 *
 */

int utn_sumInt (int valorA, int valorB);

/** \brief calcula la resta de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la resta de los 2 parametros
 *
 */
int utn_restarInt (int valorA, int valorB);

/** \brief calcula la multiplicacion entre 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la multiplicacion de los 2 parametros
 *
 */
int utn_multInt (int valorA, int valorB);

/** \brief calcula la division entre 2 parametros ingresados
 *
 * \param el primer parametro ingresado
 * \param el segundo parametro ingresado
 * \return el resultado de la division de los 2 parametros
 *
 */
float utn_divInt (int valorA, int valorB);



int printArray(int pArray[], int tam);


#endif /* UTN_H_ */
