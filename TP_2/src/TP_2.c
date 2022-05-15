/*
 ============================================================================
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "getFunctions.h"
#define CANT 2000


int main(void) {
	setbuf(stdout, NULL);
	Passenger list[CANT];
	StatusFlight lista[4];
	int opcion;
	int id;
//	int indexEncontrado;


	initPassengers(list, CANT);
	hardcodearPasajeros(list);
	hardcodearStatusFlight(lista);

	do{
		 utn_getNumeroEntero(&opcion,"\nMENU\n1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n", "Error, esa opcion no existe", 1, 8, 1);

			switch(opcion)
			{
				case 1:
					altaPassenger(list, lista, CANT, 4);
					break;

				case 2:
					modificarPasajero(list, CANT, lista, 4);
					break;

				case 3:
					id=bajaPassenger(list, lista, CANT, 4);
					removePassenger(list, CANT, id, lista, 4);
					break;

				case 4:
					elegirInforme(list, CANT, lista, 4);
					break;


			 }
		}while(opcion!=6);

	return EXIT_SUCCESS;
}




