#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "abm_fantasma.h"
#include "utn.h"

int abm_initFantasma(Fantasma* arrayFantasma,int len)
{
    int i;
    int retorno = -1;
    if(arrayFantasma!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            arrayFantasma[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;

}
int int abm_addFantasma(Fantasma *arrayFantasma,int len , int *Id,char *nombre,char *apellido,float salario,int sector)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(arrayFantasma[i].isEmpty==1)
        {
            arrayFantasma[i].Id=*Id;
            strncpy(arrayFantasma[i].name,nombre,51);
            strncpy(arrayFantasma[i].lastName,apellido,51);
            arrayFantasma[i].salario=salario;
            arrayFantasma[i].sector=sector;
            arrayFantasma[i].isEmpty=0;
            Id++;
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int abm_buscarPorId(Fantasma *arrayFantasma, int len, int id)
{
    int i;
    int retorno = -1;
    if (arrayFantasma!=NULL && len>0 && id>=0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayFantasma[i].Id==id)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}
int abm_mostrarArray(Fantasma *arrayFantasma, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(arrayFantasma[i].isEmpty==0)
        {
            printf("Id: %d \n", arrayFantasma[i].Id);
            printf("nombre: %s \n",arrayFantasma[i].name);
            printf("apellido: %s \n",arrayFantasma[i].lastName);
            printf("salario: %.2f \n",arrayFantasma[i].salario);
            printf("sector: %d \n\n",arrayFantasma[i].sector);
        }
    }
    return 0;
}
int abm_borrarFantasma(Fantasma *arrayFantasma, int len,int id)
{
    int retorno=-1;
    int auxId=abm_buscarPorId(arrayFantasma,len,id);
    if(arrayFantasma!=NULL && len>0 && id>=0)
    {
        if(auxId != -1)
        {
            arrayFantasma[auxId].isEmpty=1;
            retorno=0;
        }
    }

    return retorno;
}
int abm_ordenarMayoraMenor(Fantasma *arrayFantasma,int len)
{
    int i;
    int j;
    int retorno =-1;
    Fantasma aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayFantasma[i].lastName,arrayFantasma[j].lastName,50)<0)
            {
                aux=arrayFantasma[i];
                arrayFantasma[i]=arrayFantasma[j];
                arrayFantasma[j]=aux;
                retorno =0;
            }
            else if(arrayFantasma[i].sector<arrayFantasma[j].sector)
            {
                aux=arrayFantasma[i];
                arrayFantasma[i]=arrayFantasma[j];
                arrayFantasma[j]=aux;
                retorno =0;
            }
        }
    }
    abm_mostrarArray(arrayFantasma,len);
    return retorno;

}
int abm_ordenarMenoraMayor(Fantasma *arrayFantasma,int len)
{
    int i;
    int j;
    int retorno =-1;
    Fantasma aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayFantasma[i].lastName,arrayFantasma[j].lastName,50)<0)
            {
                aux=arrayFantasma[i];
                arrayFantasma[i]=arrayFantasma[j];
                arrayFantasma[j]=aux;
                retorno =0;
            }
            else if(strcmp(arrayFantasma[i].lastName,arrayFantasma[j].lastName)==0)
            {
                if(arrayFantasma[i].sector<arrayFantasma[j].sector)
                {
                    aux=arrayFantasma[i];
                    arrayFantasma[i]=arrayFantasma[j];
                    arrayFantasma[j]=aux;
                    retorno =0;
                }
            }
        }

    }
    return retorno;
}
int abm_calcularPromedioSalario(Fantasma *arrayFantasma,int len)
{
    int i;
    float acumulador=0;
    int cantidad=0;
    float promedio;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
       if(arrayFantasma[i].isEmpty==0)
       {
            acumulador+=arrayFantasma[i].salario;
            cantidad++;
       }
       retorno = 0;
    }
    promedio=acumulador/cantidad;
    printf("el promedio es: %.2f\n",promedio);
    return retorno;
}
int abm_modificarFantasma(Fantasma *arrayFantasma,int len,int Id)
{
    int retorno=-1;
    int id=-1;
    id=abm_buscarPorId(arrayFantasma,len,Id);
    if(id!=-1)
    {
        if(!getName("ingrese nuevo nombre:\n","nombre invalido",2,51,3,arrayFantasma[id].name)
            && !getName("ingrese nuevo apellido:\n","apellido invalido",2,51,3,arrayFantasma[id].lastName)
            && !getFloat("ingrese nuevo salario:\n","salario invalido",1,50000,3,&arrayFantasma[id].salario)
            && !getInt("ingrese nuevo sector:\n","sector invalido",1,4,3,&arrayFantasma[id].sector))
        {
                printf("datos modificados correctamente");
        }else{
                printf("no fue posible modificar los datos");
        }
        retorno = 0;
    }

    return retorno;

}


