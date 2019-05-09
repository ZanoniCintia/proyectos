#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TRUE
#define FALSE


int getString ( char* msg,char* msgError,int minimo, int maximo, int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr)-1,stdin);
            //bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}
int isValidName (char* cadena)
{
    int retorno = -1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getFloat(char* msg,char* msgError,float minimo,float maximo,int reintentos,float* resultado)
{
    float buffer;
    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            //fgets()
            scanf("%f", &buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno =0;
                break;
            }else{

                printf("%s",msgError);
            }
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;

}
int isValidFloat(float numero, float minimo,float maximo)
{

    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
        return 0;

}
int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    int buffer;
    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            //fgets()
            scanf("%d", &buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno =0;
                break;
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;

}

int isValidInt(int numero,int minimo,int maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
        return 0;

}

int getFecha(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{

}
//int isValidFecha()
