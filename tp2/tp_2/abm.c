#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#include "utn.h"

int emp_initEmpleado(Empleado *arrayEmpleado, int len)
{
    int i;
    int retorno = -1;
    if(arrayEmpleado!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            arrayEmpleado[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;

}

int emp_addEmpleado(Empleado *arrayEmpleado,int len, int *Id,char *nombre,char *apellido,float salario,int sector)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty==1)
        {
            arrayEmpleado[i].Id=*Id;
            strncpy(arrayEmpleado[i].name,nombre,51);
            strncpy(arrayEmpleado[i].lastName,apellido,51);
            arrayEmpleado[i].salary=salario;
            arrayEmpleado[i].sector=sector;
            arrayEmpleado[i].isEmpty=0;
            Id++;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int emp_buscarPorId(Empleado *arrayEmpleado, int len, int id)
{
    int i;
    int retorno = -1;
    if (arrayEmpleado!=NULL && len>0 && id>=0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayEmpleado[i].Id==id)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int emp_mostrarArray(Empleado *arrayEmpleado, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty==0)
        {
            printf("posicion %d : estado % d \ n ", i, arrayEmpleado[i].isEmpty);
            printf("posicion %d : nombre : %s \n ",i,arrayEmpleado[i].name);
            printf("posicion %d : apellido : %s \n",i,arrayEmpleado[i].lastName);
            printf("posicion %d : salario : %f \n",i,arrayEmpleado[i].salary);
            printf("posicion %d : sector : %d \n",i,arrayEmpleado[i].sector);

        }
    }
    return 0;
}

int emp_borrarEmpleado(Empleado *arrayEmpleado, int len,int id)
{
    int retorno=-1;
    int auxId=emp_buscarPorId(arrayEmpleado,len,id);
    if(arrayEmpleado!=NULL && len>0 && id>=0)
    {
        if(auxId != -1)
        {
            arrayEmpleado[auxId].isEmpty=1;
            retorno=0;
        }
    }

    return retorno;

}

int ordenarMayoraMenor(Empleado *arrayEmpleado,int len)
{
    int i;
    int j;
    int retorno =-1;
    Empleado aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName,50)<0)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
            else if(arrayEmpleado[i].sector<arrayEmpleado[j].sector)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
        }


    }

    return retorno;

}
int ordenarMenoraMayor(Empleado *arrayEmpleado,int len)
{
    int i;
    int j;
    int retorno =-1;
    Empleado aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName,50)<0)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
            else if(arrayEmpleado[i].sector<arrayEmpleado[j].sector)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
        }


    }

    return retorno;

}






