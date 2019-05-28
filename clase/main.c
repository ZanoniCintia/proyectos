#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"
int main()
{
    Persona *pArrayPersona[1100];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    int auxEstado;
    char auxApellido[51];
    char auxNombre[51];

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Per_new();


    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if(!Per_setId(pArrayPersona[indiceActual],14))
        {
            Per_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Per_setNombre(pArrayPersona[indiceActual],"Matias"))
        {

           Per_getNombre(pArrayPersona[indiceActual], auxNombre);
            printf("\n El nombre es %s",auxNombre);
        }

       if(!Per_setApellido(pArrayPersona[indiceActual],"Moll"))
        {
            Per_getApellido(pArrayPersona[indiceActual], auxApellido);
            printf("\n El apellido es %s",auxApellido);
        }

        if(!Per_setEstado(pArrayPersona[indiceActual],1))
        {
            Per_getEstado(pArrayPersona[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);
        }

    }


    return 0;
}
