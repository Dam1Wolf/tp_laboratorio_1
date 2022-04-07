/*
Damian Wolf
Tp 1
Div K
*/

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int precioAerolineas;
	int precioLatam;
	int kilometros;

	int tarjetaDeDebitoAerolineas;
	float tarjetaDeCreditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;

	int tarjetaDeDebitoLatam;
	float tarjetaDeCreditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;

	float valorBitcoin;
	valorBitcoin= 4606954.55;

	int diferenciaDePrecios;
	int banderaCalculos;

	do
	{
		printf("1-Ingresar Kilometros\n2-Ingresar Precio de Vuelos: \n3-Calcular todos los costos \n4-Informar Resultados \n5-Carga forzada de datos\n6-Salir\n");
		scanf("%d",&opcion);

		switch(opcion)										//opciones del menu
		{
			case 1:
			kilometros= pedirEnteroPositivo("Ingrese los kilometros: ","Error ingreso cero o un numero no positivo, reingrese los kilometros: ");
			printf("Kilometros: %d\n", kilometros);
			break;

			case 2:
			precioAerolineas= pedirEnteroPositivo("Ingrese el precio de Aerolineas:","Error, ingrese un precio mayor a cero");
			printf("El precio del vuelo en Aerolineas es de:%d \n", precioAerolineas);
			precioLatam= pedirEnteroPositivo("Ingrese el precio de Latam:","Error, ingrese un precio mayor a cero");
			printf("El precio del vuelo con Latam: %d\n",precioLatam);
			break;

			case 3:
			tarjetaDeDebitoAerolineas= precioAerolineas*0.90;
			tarjetaDeCreditoAerolineas= precioAerolineas*1.25;
			bitcoinAerolineas= precioAerolineas/valorBitcoin;
			precioUnitarioAerolineas= precioAerolineas/kilometros;

			tarjetaDeDebitoLatam= precioLatam*0.90;
			tarjetaDeCreditoLatam= precioLatam*1.25;
			bitcoinLatam= precioLatam/valorBitcoin;
			precioUnitarioLatam= precioLatam/kilometros;
			diferenciaDePrecios= precioLatam-precioAerolineas;
			banderaCalculos=1;
			break;

			case 4:
			//aerolineas datos
			if(banderaCalculos==1)
			{
				printf("tarjeta de d aerolineas %d\n",tarjetaDeDebitoAerolineas);
				printf("tarjeta de c aerolineas %2.f\n",tarjetaDeCreditoAerolineas);
				printf("el precio en bitcoin aerolineas %f\n",bitcoinAerolineas);
				printf("el precio unitario de aerolineas es %2.f\n",precioUnitarioAerolineas);

			//latam datos
			printf("tarjeta de d Latam %d\n",tarjetaDeDebitoLatam);
			printf("tarjeta de c Latam %2.f\n",tarjetaDeCreditoLatam);
			printf("el precio en bitcoin Latam %f\n",bitcoinLatam);
			printf("el precio unitario de Latam es %2.f\n",precioUnitarioLatam);

			if(diferenciaDePrecios<0)
			{
				diferenciaDePrecios*=-1;
				printf("la diferencia de precios es de %d \n \n\n", diferenciaDePrecios);
			}
			else
			{
				printf("la diferencia de precios es de %d \n \n\n", diferenciaDePrecios);
			}
			}
			else
			{
				printf("\nError, calcule antes de imprimir el resultado (boton 3)");
			}
			break;

			case 5:
			kilometros= 7090;
			precioAerolineas= 162965;
			precioLatam= 159339;
			break;

			case 6:
			printf("Has salido\n");
			break;

			default:
			printf("Error, no ingreso una opcion correcta\n");
			break;


			}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}

