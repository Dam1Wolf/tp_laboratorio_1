/*
 * ArrayPassenger.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Damián
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "getFunctions.h"

#define TRUE 1
#define FALSE 0

static int idIncremental=6;
static int idGenerico()
{
	return idIncremental++;
}


//Shows isEmpty==TRUE(1) in all slots of the array list
int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;
	retorno=-1;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty=TRUE;
			retorno=0;
		}
	}
	return retorno;
}

//add in a existing list of passengers the values received as parameters in the first empty position
int addPassenger(Passenger list[], int index, char name[], char lastName[], float price)
{
	int retorno=-1;

	if(list !=NULL && name!=NULL && lastName!=NULL )
	{
		list[index].id= idGenerico();
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price= price;
		list[index].isEmpty = FALSE;
		retorno=0;
	}
	return retorno;
}


int findPassengerById(Passenger* list, int len, int id)
{

	int i;
	int retorno= -1;

	for(i=0; i<len; i++)
	{
		if(list[i].id == id && list[i].isEmpty==FALSE)
		{
			retorno= i;
			break;
		}
	}

	return retorno;
}

int printPassenger(Passenger auxPassenger, int index, StatusFlight* listSt, int lenSt)
{
	int retorno;
	int i;
	char descripcion[10];
	char flycode[10];
	char typePassenger[10];


	for(i=0; i<lenSt; i++)
	{
		if(auxPassenger.statusFlightId == listSt[i].id)
		{
			strcpy(flycode, listSt[i].flycode);
			strcpy(descripcion, listSt[i].descripcion);
		}
	}

	for(i=0; i<lenSt; i++)
	{
		if(auxPassenger.typePassenger==1)
		{
			strcpy(typePassenger, "TURISTA");
		}
		if(auxPassenger.typePassenger==2)
		{
			strcpy(typePassenger, "EJECUTIVO");
		}
		if(auxPassenger.typePassenger==3)
		{
			strcpy(typePassenger, "VIP");
		}
	}

	if(auxPassenger.isEmpty==FALSE)
	{
		printf(" ID       NOMBRE        APELLIDO            PRECIO          TIPO DE PASAJE          CODIGO DE VUELO          ESTADO\n");
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
		printf("%2d       %8s        %3s             %7.2f              %4s                %7s                 %5s\n",auxPassenger.id ,auxPassenger.name,
		       auxPassenger.lastName, auxPassenger.price, typePassenger, flycode, descripcion);

			retorno=0;
	}

	else
	{
		printf("Error, el pasajero no existe\n");
		retorno= -1;
	}
	return retorno;
}

int printPassengers(Passenger* list, int len, StatusFlight* lista, int lenSt)
{
	int i;
	int retorno;
	retorno= -1;

	if(list !=NULL && len>=0 )
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				printPassenger(list[i], len, lista, lenSt);
			}
		}
		retorno=0;
	}
	else
	{
		printf("Error, la lista no existe");
	}
	return retorno;
}

//////////////////////////////ADITIONAL FUNCTIONS////////////////////////////////////

//Shows menu, scan the selected option and return option;
int menu(char opciones[])
{
	int opcion;

	printf( opciones );

	printf("\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}


//Search for a free slot in the array and return the index
int buscarLibre (Passenger list[], int len)
{
	int index = -1;
	int i;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}


int altaPassenger(Passenger list[], StatusFlight listaSt[], int len, int lenStatus)
{
	int index;
	int retorno=-1;

	if(list != NULL && len>0)
	{
		index= buscarLibre(list, len);
		if(index!=-1)
		{
			if(cargarDatos(list, len, index)==0)
			{
				list[index].typePassenger= cargarTypePassengerPorId();
				fflush(stdin);
				list[index].statusFlightId= cargarFlycodePorId(listaSt, 4);
				retorno=0;
				printf("Carga exitosa\n");
			}
			else
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int cargarFlycodePorId(StatusFlight lista[], int len)
{
	int id;

	printStatus(lista, len);
	utn_getNumeroEntero(&id, "Ingrese el id del vuelo a cargar: \n","Error", 1, 4, 1);

	return id;
}

int cargarTypePassengerPorId()
{
	int id;

	printTypePassenger();
	utn_getNumeroEntero(&id, "Ingrese el id del tipo de clase a elegir: \n","Error", 1, 3, 1);


	return id;
}

int cargarDatos(Passenger list[], int len, int index)
{
	Passenger auxPassenger;
	int retorno;

		if((utn_getString(auxPassenger.name, "Ingrese su nombre: ", "Error\n", 1)==0)
			&&(utn_getString(auxPassenger.lastName, "Ingrese su apellido: ","Error\n", 1)==0)
			&&(utn_getNumeroFlotante(&auxPassenger.price, "Ingrese el precio: ","Error\n",1, 10000 , 1)==0))
		{
			addPassenger(list, index, auxPassenger.name, auxPassenger.lastName, auxPassenger.price);
			retorno=0;
		}
		else
		{
			printf("\nError al cargar los datos\n");
			retorno=-1;
		}


		return retorno;

}

int hardcodearPasajeros(Passenger list[])
{
	int i;


	int id[]={1, 2, 3, 4, 5};
	char name[][51]= {"Juana","George","Osvaldo","Esteban","Charles"};
	char lastName[][51]= {"De Arco","Harrison","Laport","Quito","Darwin"};
	float price[]= {600, 480, 600, 480, 480};
	int typePassenger[]= {1, 2, 3, 2, 1};
	int statusFlightId[]={1,2,3,4,2};

	for(i=0; i<5; i++)
	{
		list[i].id= id[i];
		strcpy(list[i].name, name[i]);
		strcpy(list[i].lastName, lastName[i]);
		list[i].price= price[i];
		list[i].typePassenger=typePassenger[i];
		list[i].statusFlightId= statusFlightId[i];
		list[i].isEmpty=FALSE;
	}

	return 0;
}

void hardcodearStatusFlight(StatusFlight list[])
{
	int i;
	int id[]={1,2,3,4};
	char descripcion[][10]={{"ACTIVO"},{"INACTIVO"},{"DEMORADO"},{"ACTIVO"}};
	char flycode[][10]={{"DX100F"},{"TR500I"},{"GG8WP"},{"FX300L"}};

	for(i=0; i<4 ;i++)
	{
		list[i].id=id[i];
		strcpy(list[i].descripcion, descripcion[i]);
		strcpy(list[i].flycode, flycode[i]);
	}

}

void modificarPasajero(Passenger* passenger, int len, StatusFlight* listaSt, int lenSt)
{
	int opcionModificar;
	int auxCodigo;



	    utn_getNumeroEntero(&auxCodigo, "Ingrese numero de Id:\n", "Error, ingrese un numero entre 1 y 2000\n", 1, 2000, 1);
		auxCodigo= findPassengerById(passenger, len, auxCodigo);

		if(auxCodigo!=-1 && passenger[auxCodigo].isEmpty==FALSE)
		{
			printPassenger(passenger[auxCodigo], auxCodigo,listaSt, lenSt);
		}
		else
		{
			printf("Error, codigo inexistente");
		}

		do{
		opcionModificar = menu( "\nMENU\n1. id\n2. name\n3. Last Name\n4. Price\n5. Flycode\n6. Type passenger\n7. Volver Atras\n" );
		switch( opcionModificar ){
			case 1:
				utn_getNumeroEntero(&passenger[auxCodigo].id, "\nIngrese su nueva id: ", "\nError, reingrese su nueva id entre 1 y 2000:", 1, 2000,1);
				break;
			case 2:
				printf("Name: ");
				fflush(stdin);
				scanf("%[^\n]", passenger[auxCodigo].name);
				break;
			case 3:
				printf("Last Name: ");
				fflush(stdin);
				scanf("%[^\n]", passenger[auxCodigo].lastName);
				break;
			case 4:
				printf("Price: ");
				scanf("%f", &passenger[auxCodigo].price);
				break;
			case 5:
				if((passenger[auxCodigo].statusFlightId= cargarFlycodePorId(listaSt, lenSt))==0)
				{
					opcionModificar=7;
				}
				break;
			case 6:
				passenger[auxCodigo].typePassenger=cargarTypePassengerPorId();
				printPassenger(passenger[auxCodigo], auxCodigo, listaSt, lenSt);
				break;
			case 7:
				break;

			default:
				printf("La opcion ingresada es incorrecta..");
			break;
		}

	}while( opcionModificar != 7 );
}

////////////////////////////////////ROBADO

void printStatus(StatusFlight* vec, int len)
{
    int flag=0;

    system("cls");

    printf("\n**************** LISTADO DE VUELOS****************\n");
    printf("----------------------------------------------------\n");
    printf("| ID    |      FLYCODE          |            ESTADO|\n");
    printf("----------------------------------------------------\n");

    for(int i=0; i < len; i++)
    {
        	printOneStatus(vec[i]);
            flag=1;
            if(i==len-1)
            {
            	printf("----------------------------------------------------\n");
            }
    }
    if(flag == 0)
    {
        printf("\nNo hay vuelos que listar!\n");
    }

}

void printOneStatus(StatusFlight list)
{

        printf("|%4d   |   %10s          |          %8s|\n", list.id, list.flycode, list.descripcion);

}

void printTypePassenger()
{

    printf("---------------------------------\n");
    printf("| ID    |         CLASE          |\n");
    printf("---------------------------------|\n");
    printf("| 1     |       TURISTA          |\n");
    printf("| 2     |      EJECUTIVA         |\n");
    printf("| 3     |         VIP            |\n");
    printf("---------------------------------\n");
}

int bajaPassenger(Passenger passenger[], StatusFlight list[], int len, int lenSt)
{
	int id;
	int indice;

		utn_getNumeroEntero(&id, "Ingrese el id", "Error\n", 1, 2000, 1);
		indice = findPassengerById(passenger, len, id);


	return indice;
}


int removePassenger(Passenger* passenger, int len, int id, StatusFlight list[], int lenSt)
{
	char confirmar;
	int retorno= -1;

	if(id==-1)
	{
		printf("No existe el codigo ingresado\n");
	}
	else
		{
			printPassenger(passenger[id], id, list, lenSt);

			printf("\nDar de baja? [S|N]: ");
			fflush(stdin);
			scanf("%c", &confirmar);
			confirmar = toupper( confirmar );
			if( confirmar == 'S')
			{
				passenger[id].isEmpty = -1;

				printf("\nSe han borrado los datos...\n\n");
				retorno=0;
			}
			else
			{
				printf("No se han borrado los datos..\n.");
			}
		}

	return retorno;
}

//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
int sortPassengers(Passenger* list, int len, int order)
{
	int i;
	int j;
	Passenger aux;

	for(i=0; i<len; i++)
	{
		for(j=i+1; j<len; j++)
		{
			if(strcmp(list[i].lastName, list[j].lastName)>order)
			{
				aux= list[i];
				list[i]=list[j];
				list[j]= aux;
			}
			else
			{
				if(strcmp(list[i].lastName,list[j].lastName)==0)
				{
					if(list[i].typePassenger> list[j].typePassenger)
					{
						aux= list[i];
						list[i]=list[j];
						list[j]= aux;
					}
				}
			}
		}
	}
	return 0;
}



int printPassengerOrdenado(Passenger auxPassenger, int len, StatusFlight* listSt, int lenSt)
{
	int retorno;
	int i;
	char descripcion[10];
	char flycode[10];
	char typePassenger[10];


	for(i=0; i<lenSt; i++)
	{
		if(auxPassenger.statusFlightId == listSt[i].id)
		{
			strcpy(flycode, listSt[i].flycode);
			strcpy(descripcion, listSt[i].descripcion);
		}
	}

	for(i=0; i<lenSt; i++)
	{
		if(auxPassenger.typePassenger==1)
		{
			strcpy(typePassenger, "TURISTA");
		}
		if(auxPassenger.typePassenger==2)
		{
			strcpy(typePassenger, "EJECUTIVO");
		}
		if(auxPassenger.typePassenger==3)
		{
			strcpy(typePassenger, "VIP");
		}
	}

	if(auxPassenger.isEmpty==FALSE)
	{
		printf("%2d       %8s        %3s             %7.2f              %4s                %7s                 %s\n",auxPassenger.id ,auxPassenger.name,
		       auxPassenger.lastName, auxPassenger.price, typePassenger, flycode, descripcion);

			retorno=0;
	}

	else
	{
		printf("Error, el pasajero no existe\n");
		retorno= -1;
	}
	return retorno;
}

int printPassengersOrdenado(Passenger* list, int len, StatusFlight* lista, int lenSt)
{
	int i;
	int retorno;
	retorno= -1;

	if(list !=NULL && len>=0 )
	{
		for(i=0; i<len; i++)
		{
			if(i==0)
			{
				printf(" ID       NOMBRE        APELLIDO            PRECIO          TIPO DE PASAJE          CODIGO DE VUELO          ESTADO\n");
				printf("--------------------------------------------------------------------------------------------------------------------\n");
			}
				if(list[i].isEmpty==FALSE)
				{
					printPassengerOrdenado(list[i], len, lista, lenSt);
				}
		}
	}
	else
	{
		printf("Error, la lista no existe");
	}
	return retorno;
}

float informarImportes(Passenger list[], int len )
{
	int i;
	float acumuladorImportes=0;
	float promedioImportes;
	int contadorOcupado=0;

		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				contadorOcupado++;
				acumuladorImportes+=list[i].price;
			}
		}

	promedioImportes= (acumuladorImportes/contadorOcupado);

	return promedioImportes;
}

float totalImportes(Passenger list[], int len )
{
	int i;
	float acumuladorImportes=0;



		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				acumuladorImportes+=list[i].price;
			}
		}



	return acumuladorImportes;
}

int mayorAlPromedio(Passenger list[], float promedio, float acumuladorImportes, int len)
{
	int i;
	int contadorMenorAlPromedio=0;

	promedio= informarImportes(list, len);
	acumuladorImportes= totalImportes(list, len);

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==FALSE && list[i].price > promedio)
		{
			contadorMenorAlPromedio++;
		}
	}
	printf("a) El total de los precios de los pasajes es de: $%2.f\n", acumuladorImportes);
	printf("b) El promedio de los precios de los pasajes es de $%2.f\n", promedio);
	printf("c) %d Pasajeros superan el promedio de importes\n", contadorMenorAlPromedio);


	return 0;
}

//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
int sortPassengersByCode(Passenger* list, int len, int order, StatusFlight* vec, int lenSt)
{

	int i;
	int j;
	Passenger aux;
	Passenger auxDos[len];
	int contador=0;

	for(i=0; i<len; i++)
	{
		auxDos[i].isEmpty=TRUE;
	}


	for(i=0; i<len; i++)
	{
		if(vec[i].id == list[i].statusFlightId && (strcmp(vec[i].descripcion, "ACTIVO")==0))
		{
			auxDos[contador].id= list[i].id;
			strcpy(auxDos[contador].name, list[i].name);
			strcpy(auxDos[contador].lastName ,list[i].lastName);
			auxDos[contador].price= list[i].price;
			auxDos[contador].statusFlightId= list[i].statusFlightId;
			auxDos[contador].typePassenger= list[i].typePassenger;
			auxDos[contador].statusFlightId= list[i].statusFlightId;
			auxDos[contador].isEmpty= FALSE;

			contador++;
		}
	}


	for(i=0; i<len; i++)
	{
		if(vec[i].id == auxDos[i].statusFlightId)
		{
			for(j=i+1; j<len; j++)
			{
				if(strcmp(vec[i].flycode, vec[j].flycode)>order)
				{
					aux= auxDos[i];
					auxDos[i]=auxDos[j];
					auxDos[j]= aux;
				}
			}
		}
	}

	printPassengersOrdenado(auxDos, len, vec, lenSt);

	return 0;
}

void elegirInforme(Passenger* list, int len, StatusFlight* lista, int lenSt)
{
	int respuesta;
	float promedio;
	float totalImportes;

	utn_getNumeroEntero(&respuesta, "\nMENU DE INFORMES \n1. Pasajeros ordenados por apellido y tipo de pasajero\n2. Total y promedio de importes y cuantos pasajeros superan el precio promedio \n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n", "Error, ingrese un numero entre 1 y 2000\n", 1, 2000, 1);

	switch(respuesta)
	{
		case 1:
			sortPassengers(list, len, 0);
			printPassengersOrdenado(list, len, lista, 4);
			break;

		case 2:
			promedio=informarImportes(list, len);
			totalImportes=informarImportes(list, len);
			mayorAlPromedio(list,promedio,totalImportes, len);
			break;

		case 3:
			sortPassengersByCode(list, len, 1, lista, 4);
			break;
	}
}
