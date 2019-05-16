#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socios.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socios Array of socios
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socios_Inicializar(Socios array[], int size)                                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socios_buscarEmpty(Socios array[], int size, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocio==valorBuscado)                                                   //cambiar campo ID
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}*/

//String
/** \brief Busca un string en un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarNombreyApellido ( Socios array[], int size, char* valorBuscado,char* apellidoBuscado, int* indice)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socios_alta(Socios array[], int size, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(socios_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idSocio=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            //utn_getUnsignedInt("\ningrese id ","\nError",1,sizeof(int),1,10,1,&array[posicion].idSocio);           //mensaje + cambiar campo varInt
    //mensaje + cambiar campo varFloat
            utn_getName("\ningrese nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getName("\ningrese apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                    //mensaje + cambiar campo varString
            utn_getTelefono("\ningrese telefono: ","\nError",8,16,100000000,1874919423,1,array[posicion].telefono);
            utn_getEmail("\ningrese email : ","\nerror",1,31,1,array[posicion].mail);
            utn_getChar("\ningrese sexo f/m","\n error",'A','Z',1,&array[posicion].sexo);               //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n nombre : %s\n apellido: %s\n mail: %s\n telefono: %s \n sexo: %c",
                   posicion, array[posicion].idSocio,array[posicion].nombre,array[posicion].apellido,array[posicion].mail,array[posicion].telefono,array[posicion].sexo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_baja(Socios array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idSocio=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
            strcpy(array[posicion].apellido,"");                                                   //cambiar campo varString
            strcpy(array[posicion].mail,"");
            strcpy(array[posicion].telefono,"");
            array[posicion].sexo = 'n';                                                //cambiar campo varLongString
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
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idSocio==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idSocio=0;                                                                   //cambiar campo id
                strcpy(array[i].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
                strcpy(array[i].apellido,"");                                                   //cambiar campo varString
                strcpy(array[i].mail,"");
                strcpy(array[i].telefono,"");
                array[i].sexo ='v';                                                //cambiar campo varLongString
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
int socios_modificar(Socios array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n telefono: %s\n mail : %s, \n sexo : %c",
                       posicion, array[posicion].idSocio,array[posicion].nombre,array[posicion].apellido,array[posicion].telefono,array[posicion].mail,array[posicion].sexo);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idSocio);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getName("\ningrese nombre: ","\nError",1,31,1,array[posicion].nombre);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\ningrese apellido : ","\nError",1,31,1,array[posicion].apellido);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTelefono("\ningrese telefono : ","\nError",1,16,100000000,1874919423,1,array[posicion].telefono);             //mensaje + cambiar campo varLongString
                        break;
                    case 'E':
                        utn_getEmail("\ningrese mail: ","error",1,31,1,array[posicion].mail);
                        break;
                    case 'F':
                        utn_getChar("\ningrese sexo f/m: ","error",'A','Z',1,&array[posicion].sexo);
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond)                              //cambiar socios
{
    int retorno=-1;
    int i;
    Socios buffer;
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socios_listar(Socios array[], int size)                      //cambiar socios
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
                printf("\n ID: %d\n nombre: %s\n apellido: %s\n telefono: %s\n mail: %s \n sexo: %c",
                       array[i].idSocio,array[i].nombre,array[i].apellido,array[i].telefono,array[i].mail,array[i].sexo);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void socios_mock(Socios arraySocios[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    arraySocios[0].idSocio=*contadorId;
    arraySocios[0].isEmpty=0;
    strcpy(arraySocios[0].nombre,"joe");
    strcpy(arraySocios[0].apellido,"morello");
    strcpy(arraySocios[0].telefono,"54342972");
    strcpy(arraySocios[0].mail,"joecapo@joelin.com");
    arraySocios[0].sexo='m';
    *contadorId = *contadorId + 1;

    arraySocios[1].idSocio=*contadorId;
    arraySocios[1].isEmpty=0;
    strcpy(arraySocios[1].nombre,"gaston");
    strcpy(arraySocios[1].apellido,"picazo");
    strcpy(arraySocios[1].telefono,"45552555");
    strcpy(arraySocios[1].mail,"elmississippi@missi.com");
    arraySocios[1].sexo='m';
    *contadorId= *contadorId + 1;

    arraySocios[2].idSocio=*contadorId;
    arraySocios[2].isEmpty=0;
    strcpy(arraySocios[2].nombre,"margot");
    strcpy(arraySocios[2].apellido,"gatienzo");
    strcpy(arraySocios[2].telefono,"20222125");
    strcpy(arraySocios[2].mail,"ohmargo@gato.com");
    arraySocios[2].sexo='f';
    *contadorId = *contadorId + 1;

    arraySocios[3].idSocio=*contadorId;
    arraySocios[3].isEmpty=0;
    strcpy(arraySocios[3].nombre,"matias");
    strcpy(arraySocios[3].apellido,"moll");
    strcpy(arraySocios[3].telefono,"54558825");
    strcpy(arraySocios[3].mail,"matiassabiondo@programacion.com");
    arraySocios[3].sexo='m';
    //*contadorId = *contadorId + 1;

}
