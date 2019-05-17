#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumentos.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musicos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_Inicializar(Musicos array[], int size)                                    //cambiar socios
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_buscarEmpty(Musicos array[], int size, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarNombreyApellido ( Musicos array[], int size, char* valorBuscado,char* apellidoBuscado, int* indice)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0 && strcmp(array[i].apellido,apellidoBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musicos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musicos array[], int size, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musicos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            //utn_getUnsignedInt("\ningrese id ","\nError",1,sizeof(int),1,10,1,&array[posicion].idSocio);           //mensaje + cambiar campo varInt
    //mensaje + cambiar campo varFloat
            utn_getName("\ningrese nombre: ","\nError",1,TEXT_SIZE_MUSICO,1,array[posicion].nombre);
            utn_getName("\ningrese apellido: ","\nError",1,TEXT_SIZE_MUSICO,1,array[posicion].apellido);                    //mensaje + cambiar campo varString
            utn_getUnsignedInt("\n ingrese edad : ","\nError",1,99,1,99,1,&array[posicion].edad);
            utn_getUnsignedInt("\n ingrese id orquesta : ","\nError",0,50,0,50,1,&array[posicion].idOrquesta);
            utn_getUnsignedInt("\n ingrese id instrumento : ","\nError",0,20,0,20,1,&array[posicion].idInstrumento);
                          //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n nombre : %s\n apellido: %s\n edad : %d\n id orquesta: %d \n id instrumento: %d",
                   posicion, array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musicos array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
            strcpy(array[posicion].apellido,"");
            array[posicion].edad=0;                                                  //cambiar campo varString
            array[posicion].idOrquesta=0;
            array[posicion].idInstrumento=0;
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socios Array de socios
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                strcpy(array[i].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
                strcpy(array[i].apellido,"");
                array[i].edad=0;                                                  //cambiar campo varString
                array[i].idOrquesta=0;
                array[i].idInstrumento=0;                                                  //cambiar campo varString

                                                               //cambiar campo varLongString
                retorno=0;                                              //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musicos_modificar(Musicos array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n id orquesta : %d, \n id instrumento : %d",
                       posicion, array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idMusico);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getName("\ningrese nombre: ","\nError",1,31,1,array[posicion].nombre);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\ningrese apellido : ","\nError",1,31,1,array[posicion].apellido);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getUnsignedInt("\ningrese edad : ","\nerror",1,99,1,99,1,&array[posicion].edad);             //mensaje + cambiar campo varLongString
                        break;
                    case 'E':
                        utn_getUnsignedInt("\ningrese id orquesta : ","\nerror",0,50,0,50,1,&array[posicion].idOrquesta);
                        break;
                    case 'F':
                        utn_getUnsignedInt("\ningrese id de instrumento : ","\nerror",1,99,1,99,1,&array[posicion].idInstrumento);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array musicos
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musicos_ordenarPorDobleCriterio(Musicos array[],int size, int orderFirst, int orderSecond)                              //cambiar socios
{
    int retorno=-1;
    int i;
    Musicos buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].apellido < array[i+1].apellido) && orderSecond) ||
                        ((array[i].apellido > array[i+1].apellido) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musicos_listar(Musicos array[], int size)                      //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n id orquesta : %d \n id instrumento: %d",
                       array[i].idMusico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void musicos_mock(Musicos arrayMusicos[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    arrayMusicos[0].idMusico=*contadorId;
    arrayMusicos[0].idMusico=3;
    arrayMusicos[0].isEmpty=0;
    strcpy(arrayMusicos[0].nombre,"joe");
    strcpy(arrayMusicos[0].apellido,"morello");
    arrayMusicos[0].edad=25;
    arrayMusicos[0].idOrquesta=1;
    arrayMusicos[0].idIntrumento=2;
    *contadorId = *contadorId + 1;

    arrayMusicos[1].idMusico=*contadorId;
    arrayMusicos[1].idMusico=3;
    arrayMusicos[1].isEmpty=0;
    strcpy(arrayMusicos[1].nombre,"gaston");
    strcpy(arrayMusicos[1].apellido,"picazo");
    arrayMusicos[1].edad=27;
    arrayMusicos[1].idOrquesta=3;
    arrayMusicos[1].idIntrumento=2;
    *contadorId = *contadorId + 1;

    arrayMusicos[2].idMusico=*contadorId;
    arrayMusicos[2].idMusico=3;
    arrayMusicos[2].isEmpty=0;
    strcpy(arrayMusicos[2].nombre,"bryanna");
    strcpy(arrayMusicos[2].apellido,"barrios");
    arrayMusicos[2].edad=21;
    arrayMusicos[2].idOrquesta=2;
    arrayMusicos[2].idIntrumento=2;
    *contadorId = *contadorId + 1;


    arrayMusicos[3].idMusico=*contadorId;
    arrayMusicos[3].idMusico=3;
    arrayMusicos[3].isEmpty=0;
    strcpy(arrayMusicos[3].nombre,"lolo");
    strcpy(arrayMusicos[3].apellido,"bello");
    arrayMusicos[3].edad=25;
    arrayMusicos[3].idOrquesta=3;
    arrayMusicos[3].idIntrumento=2;


    //*contadorId = *contadorId + 1;

}
