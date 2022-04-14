/*
 * validaciones.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Damián
 */
#include <stdio.h>
#include <stdlib.h>

int pedirEnteroPositivo(char mensaje[],char error[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}

int pasajePositivo(int numero)
{
	if(numero<0)
	{
		numero*=-1;
		printf("la diferencia de precios es de $ %d \n \n\n", numero);
	}
	else
	{
		printf("la diferencia de precios es de $ %d \n \n\n", numero);
	}

	return 0;
}
