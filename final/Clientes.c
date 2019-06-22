
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "utn_validaciones.h"


Clientes* clientes_new(void)
{
    return (Clientes*) malloc(sizeof(Clientes));
}

Clientes* clientes_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* dniStr)
{
    Clientes* retorno = NULL;
    Clientes* pClientes=clientes_new();
    if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL &&  dniStr)
    {
        if(isValidEntero(idStr)  && isValidEntero(dniStr))
        {
                if( clientes_setId(pClientes,atoi(idStr))
                    || clientes_setNombre(pClientes,nombreStr)
                    || clientes_setApellido(pClientes,apellidoStr)
                    || clientes_setDni(pClientes,atoi(dniStr))
                   )
                    {
                        clientes_delete(pClientes);
                    }else
                        {
                            retorno = pClientes;
                        }
        }
    }

    return retorno;
}
Clientes* clientes_newFileBinario(Clientes clientes)
{
    Clientes* retorno = NULL;
    Clientes* pAuxClientes = clientes_new();
    if(pAuxClientes != NULL)
    {
        if(clientes_setId(pAuxClientes,clientes.id)||clientes_setNombre(pAuxClientes,clientes.nombre)
            ||clientes_setApellido(pAuxClientes,clientes.apellido)||clientes_setDni(pAuxClientes,clientes.dni))
        {
            clientes_delete(pAuxClientes);
        }else
            {
                retorno = pAuxClientes;
            }
    }
    return retorno;
}


void clientes_delete(Clientes* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int clientes_setId(Clientes* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int clientes_getId(Clientes* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int clientes_setNombre(Clientes* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!= NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int clientes_getNombre(Clientes* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}
int clientes_setApellido(Clientes* this,char* apellido)
{
    int retorno=-1;
    if(this != NULL )//&& isValidNumber(horasTrabajadas))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;

}
int clientes_getApellido(Clientes* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }
    return retorno;

}
int clientes_setDni(Clientes* this,int dni)
{
    int retorno = -1;
    if(this != NULL && dni> 0 && dni<=99999999)
    {
        this->dni = dni;
        retorno = 0;
    }
    return retorno;

}

int clientes_getDni(Clientes* this,int* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL)
    {
        *dni = this->dni;
        retorno = 0;
    }
    return retorno;
}

int clientes_comparacionNombre(void* this1, void* this2)
{
    int retorno = 0;
    char nombre[60];
    char nombreDos[60];
    int resultadoComparacion;
    Clientes* auxClientes;
    Clientes* auxClientesDos;
    if(this1 != NULL && this2 != NULL)
    {
        auxClientes = (Clientes*)this1;
        auxClientesDos = (Clientes*)this2;
        clientes_getNombre(auxClientes, nombre);
        clientes_getNombre(auxClientesDos,nombreDos);
        resultadoComparacion = strcmp(nombre,nombreDos);
        if(resultadoComparacion > 0)
            retorno = 1;
        else if(resultadoComparacion<0)
            retorno = -1;
    }
    return retorno;
}

