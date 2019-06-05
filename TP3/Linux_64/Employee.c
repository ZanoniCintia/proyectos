#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"


Employee* Emp_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* pEmployee=Emp_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL &&  sueldo != NULL && pEmployee != NULL)
    {
        if(isValidNumber(idStr) && isValidNumber(horasTrabajadasStr) && isValidNumber(sueldo))
            if(employee_setId(pEmployee,atoi(idStr)) && employee_setNombre(pEmployee,nombreStr)
                && employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr)) && employee_setSueldo(pEmployee,atoi(sueldo)))
                {
                    pEmployee=NULL;

                }
    }

    return pEmployee;
}

void employee_delete(Employee* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int employee_setId(Employee* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!= NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && horasTrabajadas >29 && horasTrabajadas<43)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo> 0 && sueldo<50000)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;



}
