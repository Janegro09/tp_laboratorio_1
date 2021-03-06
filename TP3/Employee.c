#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/*Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
*/

Employee* employee_new(void){
	Employee* emple_aux;

	emple_aux = (Employee*)malloc(sizeof(Employee));
	if(emple_aux!=NULL)
	{
		emple_aux->horasTrabajadas=0;
		emple_aux->id=0;
		emple_aux->nombre[0]='\0';
		emple_aux->sueldo=0;
		return emple_aux;
	}else {
		return NULL;
	}
}

void employee_delete(Employee *this)
{
	if(this !=NULL)
	{
		free(this);
	}
}


int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=0;
		*id=this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=0;
		strncpy(this->nombre,nombre,128);
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre!= NULL)
	{
		retorno=0;
		strncpy(nombre,this->nombre,128);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this !=NULL && horasTrabajadas>=0)
	{
		retorno=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		retorno=0;
		*horasTrabajadas=this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo>=0)
	{
		retorno=0;
		this->sueldo=sueldo;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL)
	{
		retorno=0;
		*sueldo=this->sueldo;
	}
	return retorno;
}


//#endif // employee_H_INCLUDED
