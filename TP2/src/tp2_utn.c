#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"
#include "tp2_utn.h"

static int generarNuevoId(void);
void generarHarcodeo(Employee array[]);

/*static int obtenerIndice(Employee array[], int* indice);*/

int alta(Employee array[], int size_array)
{
	//int posicion;
	int resultadoGet;
	//int indice;
	int retorno=-1;
	Employee bufferEmpleado;
	//Valido nombre y apellido
		if(
			utn_getCadenaValida("Ingresá un nombre\n", "No ingresaste un nombre válido\n", 3,sizeof(bufferEmpleado.name), bufferEmpleado.name)==0 &&
			utn_getCadenaValida("Ingresá un apellido\n", "No ingresaste un apellido válido\n", 3,sizeof(bufferEmpleado.lastName), bufferEmpleado.lastName)==0
		){
	//valido salario
			resultadoGet=utn_getFloat("Ingresá el salario\n", "Salario incorrecto\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.salary);
			if(resultadoGet==0)
			{
				resultadoGet=utn_getEntero("Ingresá el sector\n", "Error con el dato ingresado\n", 3, MAX_ID, MIN_ID, &bufferEmpleado.sector);
				if(resultadoGet==0)
				{
					bufferEmpleado.id=generarNuevoId();
					retorno=addEmployee(array, size_array, bufferEmpleado.id, bufferEmpleado.name, bufferEmpleado.lastName, bufferEmpleado.salary, bufferEmpleado.sector);
				} else {
					printf("Error con el sector ingresado\n");
				}
			} else {
				printf("Error con el salario ingresado\n");
			}
		} else {
			printf("Error con el Nombre y/o Apellido ingresado\n");
		}

return retorno;
}


int modificar(Employee array[])
{
	int retorno;
	int posicion;
	int opcion;
	int idEmpleado;
	int resultadoGet;
	Employee bufferEmpleado;

	resultadoGet=utn_getEntero("Ingresá un Id valido\n", "Error id ingresado incorrrectamente\n", 3, ID_MAXIMO, ID_MINIMO, &idEmpleado);
	posicion=findEmployeeById(array,SIZE_ARRAY,idEmpleado);
	if(resultadoGet==0 && posicion!=-1)
	{
		bufferEmpleado=array[posicion];
		do
		{
			resultadoGet=utn_getEntero("Elegiste la opcion de modificar,elegí una opción a modificar\n1) Nombre\n2) Apellido\n3) Salario\n4) Sector\n5) Cancelar\n", "Opcion incorrecta", 3, 5, 1, &opcion);
			if(resultadoGet==0)
			{
				switch (opcion)
				{
				case 1:
					resultadoGet=utn_getCadenaValida("Ingrese el nuevo nombre\n", "Error con el nombre ingresado\n", 3, SIZE_NAME, bufferEmpleado.name);
					break;
				case 2:
					resultadoGet=utn_getCadenaValida("Ingrese el nuevo apellido\n", "Error con el apellido ingresado\n", 3, SIZE_LASTNAME, bufferEmpleado.lastName);
					break;
				case 3:
					resultadoGet=utn_getFloat("Ingrese el nuevo salario\n", "Error con el salario ingresado\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.salary);
					break;
				case 4:
					resultadoGet=utn_getEntero("Ingrese el nuevo sector\n", "Error con el salario ingresado\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.sector);
					break;
				default:
					break;
				}

				if(resultadoGet==0)
				{
					retorno=0;
					array[posicion]=bufferEmpleado;
				}else{
					printf("No se pudo realizar la modificacion\n");
					resultadoGet=0;
				}
			}
		}while (opcion!=5 && resultadoGet!=0);
	} else {
		printf("Empleado no encontrado con ese Id\n");
	}
	return retorno;
}

int baja(Employee array[],int len)
{
	int retorno=-1;
	int resultadoGet;
	int idSeleccionado;
	resultadoGet=utn_getEntero("Ingrese un id a dar de baja\n", "Error con el ID ingresado\n", 3, MAX_ID, MIN_ID, &idSeleccionado);
	if(resultadoGet==0)
	{
		removeEmployee(array, SIZE_ARRAY,idSeleccionado);
		retorno=0;
	}
	return retorno;
}

void informar(Employee array[], int len)
{
	int resultadoOperacion;
	//1 de menor a mayor
	//0 de mayor a menor
	ordenarArray(array, len, 1);
	printf("%-6s%-30s%-30s%-10s%-3s\n","id","nombre","apellido","salario","sector");
	resultadoOperacion=	printEmployees(array,SIZE_ARRAY);
	if(resultadoOperacion!=0)
	{
		printf("No se han ingresado empleados\n");
	}
}


//genera ID
static int generarNuevoId(void)
{
	static int id=-1;
	id++;
	return id;
}


int ordenarArray(Employee array[],int len, int orden)
{
	int retorno = -1;
	int i;
	Employee aux;
	Employee aux2;
	int estadoDesordenado=1;

	if(array != NULL && len > 0)
	{
		while(estadoDesordenado)//mientras este desordenado
		{
			estadoDesordenado = 0;
			for(i = 0; i < (len - 1); i++)
			{
				if(
					(orden == 1 &&
					((strncmp(array[i].name, array[i + 1].name,len)>=0)))
						||
					(orden == 0 &&
					((strncmp(array[i].name, array[i + 1].name,len)<=0)))
				  )
				{
					if(
						(orden == 1 &&
						((array[i].sector > array[i + 1].sector)))
							||
						(orden == 0 &&
						((array[i].sector < array[i + 1].sector)))
					  )
					{
					aux = array[i];
					array[i] = array[i + 1];
					array[i + 1] = aux;
					estadoDesordenado = 1;
					}
				}
			}
		}

		retorno = 1;
	}
	return retorno;
}


void generarHarcodeo(Employee array[])
{
	Employee auxBuffer;

	auxBuffer.id=2;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Javier",SIZE_NAME);
	strncpy(auxBuffer.name, "Sosa",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=125;

	array[0]=auxBuffer;

	auxBuffer.id=3;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Bernardo",SIZE_NAME);
	strncpy(auxBuffer.name, "Neustad",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=75;

	array[1]=auxBuffer;

	auxBuffer.id=0;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Bernardo",SIZE_NAME);
	strncpy(auxBuffer.name, "Sosa",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=125;

	array[2]=auxBuffer;

	auxBuffer.id=1;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Juan",SIZE_NAME);
	strncpy(auxBuffer.name, "Sosa",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=120;

	array[3]=auxBuffer;

	auxBuffer.id=12;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Sancho",SIZE_NAME);
	strncpy(auxBuffer.name, "zaras",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=10;

	array[4]=auxBuffer;

	auxBuffer.id=13;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Sancho",SIZE_NAME);
	strncpy(auxBuffer.name, "zaras",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=110;

	array[5]=auxBuffer;

	auxBuffer.id=14;
	auxBuffer.isEmpty=0;
	strncpy(auxBuffer.lastName, "Sancho",SIZE_NAME);
	strncpy(auxBuffer.name, "zaras",SIZE_LASTNAME);
	auxBuffer.salary=75000;
	auxBuffer.sector=5;

	array[6]=auxBuffer;

}

