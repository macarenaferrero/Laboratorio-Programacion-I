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
float promediarArrayInt(int arrayInt[],int len);

#endif /* UTN_H_ */
