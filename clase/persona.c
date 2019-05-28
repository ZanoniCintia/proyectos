#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

Persona* Per_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}


Persona* Per_newStr(char* id,char* nombre, char* apellido, char* estado)
{
    Persona* retorno=NULL;
    Persona* pAuxPersona;
    if(id != NULL && nombre !=NULL && apellido != NULL && estado != NULL)
    {
        pAuxPersona=Per_new();
        if(pAuxPersona !=NULL)
        {
            if(( !Per_setNombre(pAuxPersona,nombre))&& (!Per_setApellido(pAuxPersona,apellido))&&
              ( !Per_setIdStr(pAuxPersona,id))&& (!Per_setEstadoStr(pAuxPersona,estado)))
            {
                retorno=pAuxPersona;
            }
            else
            {
                Per_delete(pAuxPersona);
            }
        }
    }
    return retorno;
}



int Per_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Per_setIdStr(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
       if(validarEntero(id))
       {
         Per_setId(this,atoi(id));
         retorno = 0;
       }
    }
    return retorno;
}

int Per_getIdStr(Persona* this,char *id)
{
    int retorno =0;
    int buffer;
    if(this != NULL && id !=NULL)
    {
        Per_getId(this,&buffer);
        sprintf(id,"%d",buffer);

    }

    return retorno;

}



int Per_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}
int Per_setApellido(Persona* this, char* Apellido)
{
    int retorno = -1;
    if(this != NULL && Apellido != NULL)
    {
        strcpy(this->apellido,Apellido);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->apellido);
        retorno = 0;
    }
    return retorno;
}
int Per_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}
int Per_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}
int Per_setEstadoStr(Persona* this, char *estado)
{
    int retorno = -1;
    if(this != NULL && estado != NULL)
    {
       if(strcmp(estado,"FALSE"))
       {
         Per_setId(this,atoi(estado));
         retorno = 0;
       }
    }
    return retorno;
}

int Per_getEstadoStr(Persona* this, char *estado)
{
    int retorno =0;
    int buffer;
    if(this != NULL && estado !=NULL)
    {
        Per_getId(this,&buffer);
        sprintf(estado,"%d",buffer);

    }

    return retorno;

}
