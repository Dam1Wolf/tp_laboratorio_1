/*
 * validaciones.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Damián
 */

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
