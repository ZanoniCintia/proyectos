#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h"
#include "libros.h"
#include "prestamos.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Prestamos Array of Prestamos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamos_Inicializar(Prestamos array[], int size)                                    //cambiar Prestamos
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
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion)                    //cambiar Prestamos
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
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar Prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPrestamo==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarInt(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar Prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocio==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int Prestamos_buscarString(Prestamos array[], int size, char* valorBuscado, int* indice)                    //cambiar Prestamos
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}*/

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int prestamos_alta(Prestamos array[],Socios *arraySocios,int sizeSocios,Libros *arrayLibros, int sizeLibros,int size, int* contadorID)                          //cambiar Prestamos
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(prestamos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Prestamos
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPrestamo=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            socios_listar(arraySocios,sizeSocios);
            utn_getUnsignedInt("\ningrese id de socio: ","\nError",1,sizeof(int),1,10,1,&array[posicion].idSocio);
            libros_listar(arrayLibros,sizeLibros);
            utn_getUnsignedInt("\ningrese id de libro: ","\nError",1,sizeof(int),1,10,1,&array[posicion].idLibro);           //mensaje + cambiar campo varInt
            //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                                //mensaje + cambiar campo varString
                            //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID prestamo: %d\n ID socio: %d\n ID libro: %d",
                   posicion, array[posicion].idPrestamo,array[posicion].idSocio,array[posicion].idLibro);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_baja(Prestamos array[], int sizeArray)                                      //cambiar Prestamos
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPrestamo=0;                                                                   //cambiar campo id
            array[posicion].idSocio=0;                                                               //cambiar campo varInt
            array[posicion].idLibro=0;                                                             //cambiar campo varFloat
                                                        //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPrestamo==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idPrestamo=0;                                                                   //cambiar campo id
                array[i].idSocio=0;                                                               //cambiar campo varInt
                array[i].idLibro=0;                                                             //cambiar campo varFloat
                                                     //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int prestamos_modificar(Prestamos array[], int sizeArray)                                //cambiar Prestamos
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n id prestamo: %d\n id socio: %d\n id libro: %d",
                       posicion, array[posicion].idPrestamo,array[posicion].idSocio,array[posicion].idLibro);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idPrestamo);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idSocio);         //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idLibro);                       //mensaje + cambiar campo varString
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
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int prestamos_ordenarPorDobleCriterio(Prestamos array[],int size, int orderFirst, int orderSecond)                              //cambiar Prestamos
{
    int retorno=-1;
    int i;
    Prestamos buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((array[i].idLibro<array[i+1].idLibro) && orderFirst) ||
                    ((array[i].idLibro>array[i+1].idLibro) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(array[i].idLibro==array[i+1].idLibro)
                {
                    if( ((array[i].idSocio < array[i+1].idSocio) && orderSecond) ||
                        ((array[i].idSocio > array[i+1].idSocio) && !orderSecond) )
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
* \param array Prestamos Array de Prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int prestamos_listar(Prestamos array[], int size)                      //cambiar Prestamos
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
                printf("\n id prestamo: %d\n id socio: %d\n id libro: %d",
                       array[i].idPrestamo,array[i].idSocio,array[i].idLibro);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId)                      //cambiar Prestamos
{
    //*******************************************************************
    arrayPrestamos[0].idPrestamo=*contadorId;
    arrayPrestamos[0].isEmpty=0;
    arrayPrestamos[0].idSocio=0;
    arrayPrestamos[0].idLibro=0;
    *contadorId=*contadorId + 1;

    arrayPrestamos[1].idPrestamo=*contadorId;
    arrayPrestamos[1].isEmpty=0;
    arrayPrestamos[1].idSocio=0;
    arrayPrestamos[1].idLibro=0;
    *contadorId=*contadorId +1;

    arrayPrestamos[2].idPrestamo=*contadorId;
    arrayPrestamos[2].isEmpty=0;
    arrayPrestamos[2].idSocio=0;
    arrayPrestamos[2].idLibro=0;
    *contadorId=*contadorId +1;

    arrayPrestamos[3].idPrestamo=*contadorId;
    arrayPrestamos[3].isEmpty=0;
    arrayPrestamos[3].idSocio=0;
    arrayPrestamos[3].idLibro=0;
    //contadorId++;
}
