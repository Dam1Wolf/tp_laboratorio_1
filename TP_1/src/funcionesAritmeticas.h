/*
 * funcionesAritmeticas.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Damián
 */

#ifndef FUNCIONESARITMETICAS_H_
#define FUNCIONESARITMETICAS_H_
#include <stdio.h>
#include <stdlib.h>

/// @brief toma un entero y un flotante y devuelve el resultado de la multiplicacion
/// @param numeroUno toma un numero entero
/// @param numeroDos toma un numero flotante
/// @return	retorna un valor flotante
float multiplicar(int numeroUno, float numeroDos);

/// @brief toma un entero y un flotante y devuelve el resultado de la division
/// @param numeroUno toma un numero entero
/// @param numeroDos toma un numero flotante
/// @return	retorna un valor flotante
float dividir(int numeroUno, float numeroDos);

/// @brief toma dos enteros y devuelve el resultado de la resta
/// @param numeroUno toma un numero entero
/// @param numeroDos toma un numero entero
/// @return	retorna un valor flotante
int resta(int numeroUno, int numeroDos);

#endif /* FUNCIONESARITMETICAS_H_ */
