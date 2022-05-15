/*
 * ArrayPassenger.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Damián
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char descripcion[10];
	char flycode[10];

} StatusFlight;

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	int statusFlightId;
	int isEmpty;
} Passenger;
/// @brief inicializa todos los pasajeros del array en isEmpty==FALSE(0)
/// @param list: array de pasajeros a inicializar
/// @param len: tamaño del array a inicializar
/// @return retorna 0 si se ejecuto con exito y -1 si no se logro ejecutar con exito
int initPassengers(Passenger* list, int len);

/// @brief agrega en una lista existente de pasajeros los valores recibidos como parametros en la primer posicion vacia
/// @param list: array de pasajeros donde otorgar los valores ya existentes
/// @param index: el indice del array donde se otorgaran los valores
/// @param name: el nombre a pasarle al pasajero
/// @param lastName: el apellido a pasarle al nuevo pasajero
/// @param price: el precio del boleto que se le otorgara al nuevo pasajero
int addPassenger(Passenger list[], int index, char name[], char lastName[], float price);

/// @brief busca un pasajero a traves del id, si este concuerda con el id que se paso como parametro, entonces devuelve el indice donde se encontro
/// @param list: array de pasajeros a recorrer para la busqueda
/// @param len: tamaño del array a recorrer
/// @return id: el id del pasajero que se esta buscando encontrar
int findPassengerById(Passenger* list, int len, int id);

/// @brief	muestra los valores del array de un pasajero por pantalla, encolumnados
/// @param	auxPassenger: el pasajero a imprimir
/// @param	listSt: lista de StatusFlight que nos permitira relacionar al pasajero con su flycode y estado de vuelo
/// @param 	lenSt: el tamaño del array de StatusFlight para recorrer los for y asi relacionar los valores flycode, estado de vuelo y tipo de pasajero
/// @return	retorna 0 si se ejecuto con exito y -1 si no se logro ejecutar con exito
int printPassenger(Passenger auxPassenger, int index, StatusFlight* listSt, int lenSt);

/// @brief muestra los valores del array de los pasajeros por pantalla, encolumnados
/// @param list: el array de pasajeros a imprimir
/// @param lista: parametro que nos permite ejecutar printPassenger dentro de nuestra funcion printPassengers
/// @param lenSt: parametro que nos permite ejecutar printPassenger dentro de nuestra funcion printPassengers
/// @return retorna 0 si se ejecuto con exito y -1 si no se logro ejecutar con exito
int printPassengers(Passenger* list, int len, StatusFlight* lista, int lenSt);

/// @brief nos permite hacer una baja logica dandole un -1 a isEmpty
/// @param passenger: pasajero a eliminar
/// @param id: el id donde se encuentra el pasajero a eliminar
/// @param list: parametro que nos permite ejecutar printPassenger, para mostrar en pantalla si es el pasajero que se desea eliminar
/// @param lenSt: parametro que nos permite ejecutar printPassenger, para mostrar en pantalla si es el pasajero que se desea eliminar
/// @return retorna 0 si se ejecuto con exito y -1 si no se logro ejecutar con exito
int removePassenger(Passenger* passenger, int len, int id, StatusFlight list[], int lenSt);

/// @brief Lista los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
/// @param list: el array de pasajeros a ordenar
/// @param len: el tamanio del array a ordenar
/// @param order: 1 indica ascendente y 0 indica descendente
/// @return retorna 0
int sortPassengers(Passenger* list, int len, int order);



int sortPassengersByCode(Passenger* list, int len, int order, StatusFlight* vec, int lenSt);
int menu(char opciones[]);
int buscarLibre (Passenger list[], int len);
int cargarDatos(Passenger list[], int len, int index);
int altaPassenger(Passenger list[], StatusFlight lista[], int len, int lenStatus);
int bajaPassenger(Passenger passenger[], StatusFlight list[], int len, int lenSt);
int cargarFlycodePorId(StatusFlight lista[], int len);
int cargarTypePassengerPorId();
int hardcodearPasajeros(Passenger list[]);
void hardcodearStatusFlight(StatusFlight list[]);
void modificarPasajero(Passenger* passenger, int len, StatusFlight* lista, int lenSt);
void printOneStatus(StatusFlight list);
void printStatus(StatusFlight* vec, int len);
void printTypePassenger();
int printPassengerOrdenado(Passenger auxPassenger, int index, StatusFlight* listSt, int lenSt);
int printPassengersOrdenado(Passenger* list, int len, StatusFlight* lista, int lenSt);
int menorAlPromedio(Passenger list[], float promedio, float acumuladorImportes, int len);
float totalImportes(Passenger list[], int len );
float informarImportes(Passenger list[], int len );
void elegirInforme(Passenger* list, int len, StatusFlight* lista, int lenSt);

#endif /* ARRAYPASSENGER_H_ */
