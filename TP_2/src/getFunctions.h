/*
 * getFunctions.h
 *
 *  Created on: 29 abr. 2022
 *      Author: Damián
 */

#ifndef GETFUNCTIONS_H_
#define GETFUNCTIONS_H_

int getString(char* pResultado);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
int esString(char* cadena, int limite);
int myGets(char* cadena, int longitud);
int getChar(char* pResultado, char* mensaje, char* errorMensaje, char minimo, char maximo, int reintentos);
int esFlotante(char* cadena, int limite);
int esAlfanumerico(char* cadena, int limite);
int utn_getFlycode(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
int esNumerica(char* cadena, int limite);
int getFloat(float* pResultado);
int getStringAlfanumerico(char* pResultado);


#endif /* GETFUNCTIONS_H_ */
