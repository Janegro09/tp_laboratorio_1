/*
 ============================================================================
 Name        : TP2.c
 Author      : Javier Sosa
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "arrayEmployee.h"
#include "utn.h"
#include "tp2_utn.h"

int main(void) {
	Employee arrayEmpleados[SIZE_ARRAY];
	int opcion;
	int resultadoGetEntero;
	int resultadoOperacion;
	initEmployees(arrayEmpleados, SIZE_ARRAY);
	generarHarcodeo(arrayEmpleados);
	do {
		resultadoGetEntero=utn_getEntero("Bienvenido, ingresá una opción\n1) Alta\n2) Modificacion\n3) Baja\n4) Informar\n5) Salir\n", "Error - opción invalida\n", 3, 5, 1, &opcion);
		switch(opcion)
		{
			case 1:
				printf(BARRA_SEPARADORA);
				resultadoOperacion=alta(arrayEmpleados,SIZE_ARRAY);
				if(resultadoOperacion==0)
				{
					printf("Alta realizada Correctamente\n");
				} else {
					printf("No se pudo realizar el Alta\n");
				}
				printf(BARRA_SEPARADORA);
				break;
			case 2:
				printf(BARRA_SEPARADORA);
				resultadoOperacion=modificar(arrayEmpleados);
				if(resultadoOperacion==0)
				{
					printf("Modificación realizada correctamente\n");
				} else {
					printf("No se pudo realizar la modificación\n");
				}
				printf(BARRA_SEPARADORA);
				break;
			case 3:
				printf(BARRA_SEPARADORA);
				resultadoOperacion=baja(arrayEmpleados,SIZE_ARRAY);
				printf(BARRA_SEPARADORA);
				break;
			case 4:
				printf(BARRA_SEPARADORA);
				informar(arrayEmpleados, SIZE_ARRAY);
				printf(BARRA_SEPARADORA);
				break;
		}
	}while (opcion != 5 && resultadoGetEntero ==0);

	return EXIT_SUCCESS;
}
