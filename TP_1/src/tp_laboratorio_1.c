/*
Damian Wolf
Tp 1
Div K
*/

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "funcionesAritmeticas.h"
#include "menuTp.h"


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int precioAerolineas;
	int precioLatam;
	int kilometros;

	float tarjetaDeDebitoAerolineas;
	float tarjetaDeCreditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;

	float tarjetaDeDebitoLatam;
	float tarjetaDeCreditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	int diferenciaDePrecios;

	float valorBitcoin;
	valorBitcoin= 4606954.55;

	int banderaCalculos;             //Seteamos una bandera para corroborar que los datos hayan sido calculados (case 3) antes de ser mostrados (case 4)
	int banderaPrecios;
	int banderaKilometros;

	do
	{
		mostrarMenu();               //Llamado a funcion creada para mostrar el menu
		scanf("%d", &opcion);


		switch(opcion)														//Opciones del menu
		{
			case 1:
			kilometros= pedirEnteroPositivo("Ingrese los kilometros: ","Error ingreso cero o un numero no positivo, reingrese los kilometros: "); //Llamado a funcion que valida numeros que sean enteros y positivos para validar los kilometros
			printf("Kilometros: %d\n", kilometros);
			banderaKilometros=1;                                           //Permite validar el ingreso al case 3 (ingreso de kms)
			break;

			case 2:
			//Ingreso de precios de Aerolineas y de Latam
			precioAerolineas= pedirEnteroPositivo("Ingrese el precio de Aerolineas:","Error, ingrese un precio mayor a cero");  // Llamado a funcion para validar el precio de Aerolineas
			printf("El precio del vuelo en Aerolineas es de:%d \n", precioAerolineas);
			precioLatam= pedirEnteroPositivo("Ingrese el precio de Latam:","Error, ingrese un precio mayor a cero"); 			// Llamado a funcion para validar el precio de Latam
			printf("El precio del vuelo con Latam: %d\n",precioLatam);
			banderaPrecios=1;											//Permite validar el ingreso al case 3 (ingreso de precios)
			break;

			case 3:
			if(banderaPrecios==1 && banderaKilometros==1)
			{
			//Calculos aritmeticos de Aerolineas
			tarjetaDeDebitoAerolineas= multiplicar(precioAerolineas, 0.90);		//Llamado a la funcion multiplicar para calcular el 10% de descuento
			tarjetaDeCreditoAerolineas= multiplicar(precioAerolineas, 1.25);	//Llamado a la funcion multiplicar para calcular el 25% de aumento
			bitcoinAerolineas= dividir(precioAerolineas, valorBitcoin);			//Llamado a la funcion dividir para calcular el pasaje a bitcoins
			precioUnitarioAerolineas= dividir(precioAerolineas, kilometros);	//Llamado a la funcion dividir para calcular el precio unitario

			//Calculos aritmeticos de Latam
			tarjetaDeDebitoLatam= multiplicar(precioLatam, 0.90);				//Llamado a la funcion multiplicar para calcular el 10% de descuento
			tarjetaDeCreditoLatam= multiplicar(precioLatam,1.25);				//Llamado a la funcion multiplicar para calcular el 25% de aumento
			bitcoinLatam= dividir(precioLatam, valorBitcoin);					//Llamado a la funcion dividir para calcular el pasaje a bitcoins
			precioUnitarioLatam= dividir(precioLatam, kilometros);				//Llamado a la funcion dividir para calcular el precio unitario
			diferenciaDePrecios= resta(precioLatam, precioAerolineas);			//Llamado a la funcion resta para calcular la diferencia de precios
			banderaCalculos=1;
			}
			else
			{
				printf("Error, debe ingresar kilometros y precio, o cargar los datos con el boton (5) \n\n");
			}
			break;

			case 4:
			//Aerolineas datos ya calculados
			if(banderaCalculos==1 && banderaKilometros==1)					//Si la bandera se inicializo en 1 (case 3), entonces entra al if del case 4 y muestra los valores previamente calculados
			{
				printf("KMs Ingresados: %d km\n\n", kilometros);
				printf("Precio Aerolineas: $%d\n", precioAerolineas);
				printf("a) Precio con tarjeta de debito: $ %2.f\n",tarjetaDeDebitoAerolineas);
				printf("b) Precio con tarjeta de credito: $ %2.f\n",tarjetaDeCreditoAerolineas);
				printf("c) Precio con bitcoin: %f BTC\n",bitcoinAerolineas);
				printf("d) Mostrar precio unitario: $ %2.f\n\n",precioUnitarioAerolineas);

				//Latam datos ya calculados
				printf("Precio Latam: $%d\n", precioLatam);
				printf("a) Precio con tarjeta de debito: $ %.2f\n",tarjetaDeDebitoLatam);
				printf("b) Precio con tarjeta de credito: $ %2.f\n",tarjetaDeCreditoLatam);
				printf("c) Precio con bitcoin: %f BTC\n",bitcoinLatam);
				printf("d) Mostrar precio unitario: $ %2.f\n",precioUnitarioLatam);
				diferenciaDePrecios= pasajePositivo(diferenciaDePrecios);

				banderaCalculos=0;
				banderaPrecios=0;
				banderaKilometros=0;
			}
			else
			{
				printf("\nError, calcule antes de imprimir el resultado (boton 3)");
			}
			break;

			//Carga de datos forzados
			case 5:
				kilometros= 7090;
				precioLatam= 162965;
				precioAerolineas= 159339;
				banderaPrecios=1;
				banderaCalculos=1;
				banderaKilometros=1;

			break;

			//Opcion "Salir"
			case 6:
			printf("Has salido\n");
			break;

			//En caso de no haber seleccionado opcion 1, 2, 3, 4, 5 o 6 imprime un error
			default:
			printf("Error, no ingreso una opcion correcta\n");
			break;


			}

	}while(opcion != 6);	//Mientras la opcion sea distinta de 6 (Salir), vuelve a la iteracion

	return EXIT_SUCCESS;
}




