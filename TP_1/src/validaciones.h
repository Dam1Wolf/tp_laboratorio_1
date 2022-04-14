/*
 * validaciones.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Damián
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


/// @brief valida el ingreso de un numero entero y positivo
/// @param mensaje	toma un mensaje preseteado para validar un numero/valor mayor o igual a 1
/// @param mensajeError	toma un mensaje preseteado para mostrar que se ingreso mal el numero/valor
/// @return devuelve el int del numero entero y positivio ya validado
int pedirEnteroPositivo(char mensaje[], char mensajeError[]);

/// @brief transforma el numero a positivo en caso de ser negativo
/// @param numero toma el ingreso de un numero entero
/// @return devuelve 0 luego de pasar por el if y transformar el numero a positivo en caso de ser negativo
int pasajePositivo(int numero);

#endif /* VALIDACIONES_H_ */
