#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Clientes.h"
#include "Ventas.h"
#include "parser.h"
#include "utn_validaciones.h"
int idMaxArray(LinkedList* pArrayClientes);
int idMaxArrayVentas(LinkedList* pArrayVentas);
/** \brief Carga los datos de los Clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListClientes)
{
    int retorno = -1;
    FILE* fAux;
    if(path != NULL && pArrayListClientes != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_ClientesFromText(fAux,pArrayListClientes))
            {
                printf("El archivo se cargo existosamente en modo texto!");
                retorno = 0;
            }
        }
        //fclose(fAux);
    }
    return retorno;
}


/** \brief Carga los datos de los Clientes desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListClientes)
{
    int retorno = -1;
    FILE* pFile = NULL;
    if(path != NULL && pArrayListClientes != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL && !parser_clientesFromBinary(pFile,pArrayListClientes))
        {
            printf("El archivo se cargo existosamente en modo binario!");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Alta de Clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_addClientes(LinkedList* pArrayListClientes)
{
    char nombre[50];
    char apellido[20];
    char dni[20];
    char idTex[20];
    int id;
    int retorno=-1;
    Clientes* pAuxiliar;


    if(pArrayListClientes!=NULL)
    {
        id=idMaxArray(pArrayListClientes)+1;
        sprintf(idTex,"%d",id);

        if( !getName("\n Ingrese nombre de cliente: ", "\n Error",1,50,1,nombre) &&
            !getName("\n Ingrese apellido de cliente: ", "\n Error",1,50,1,apellido)&&
            !getInt("\n Ingrese DNI: ", "\n Error",1,21,1,dni))
        {
            pAuxiliar= clientes_newParametros(idTex,nombre,apellido,dni);
            if(pAuxiliar != NULL)
            {
                ll_add(pArrayListClientes,pAuxiliar);
                retorno = 0;
            }
        }

    }

    return retorno;
}


int idMaxArray(LinkedList* pArrayClientes)
{
    int retorno = -1;
    Clientes* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayClientes != NULL)
    {
        for(int i = 0; i<ll_len(pArrayClientes); i++)
        {
            pAux = ll_get(pArrayClientes,i);
            clientes_getId(pAux, &idAux);
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }
    retorno = idMax;

    }

    return retorno;
}

int controller_addVentas(LinkedList* pArrayListVentas,LinkedList* pArrayClientes)
{
    char codigo[50];
    char cantidad[20];
    char idClientes[20];
    char bufferPrecio[25];
    char idTex[20];
    int id;
    float precio;
    int codigoOpcion=0;
    int retorno=-1;
    Ventas* pAuxiliar;


    if(pArrayListVentas!=NULL && pArrayClientes != NULL)
    {
        id=idMaxArrayVentas(pArrayListVentas)+1;
        sprintf(idTex,"%d",id);

        if(
            !getInt("\n Ingrese id del cliente: ", "\n Error",1,50,1,idClientes) &&
            !getInt("\n Codigo de producto: \n1000-TV_LG_32-$8999.99\n1001-PS4-$12999.99\n1002-IPHONE7-$19480.99\nIngrese codigo : ", "\n Error",1,50,1,codigo) &&
            !getInt("\n Ingrese cantidad: ", "\n Error",1,21,1,cantidad))
        {
            pAuxiliar= ventas_newParametros(idTex,codigo,cantidad,idClientes,bufferPrecio);
            switch(codigoOpcion)
            {
                case 1000:
                    ventas_setCodigoProducto(pAuxiliar,codigo);
                    ventas_setCantidadDeProductos(pAuxiliar,cantidad);
                    precio=8999.99;
                    ventas_setPrecio(pAuxiliar,bufferPrecio);
                    break;
                case 1001:
                    ventas_setCodigoProducto(pAuxiliar,codigo);
                    ventas_setCantidadDeProductos(pAuxiliar,cantidad);
                    precio=12999.99;
                    ventas_setPrecio(pAuxiliar,bufferPrecio);
                    break;
                 case 1002:
                    ventas_setCodigoProducto(pAuxiliar,codigo);
                    ventas_setCantidadDeProductos(pAuxiliar,cantidad);
                    precio=19480.99;
                    ventas_setPrecio(pAuxiliar,bufferPrecio);
                    break;
                }
                ll_add(pArrayListVentas,pAuxiliar);
                printf("La venta se cargo exitosamente\n");
                retorno = 0;

        }

    }

    return retorno;
}

int idMaxArrayVentas(LinkedList* pArrayVentas)
{
    int retorno = -1;
    Ventas* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayVentas != NULL)
    {
        for(int i = 0; i<ll_len(pArrayVentas); i++)
        {
            pAux = ll_get(pArrayVentas,i);
            ventas_getId(pAux, &idAux);
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }
    retorno = idMax;
    }

    return retorno;
}
int buscarPorId(LinkedList* pArrayClientes, int id)
{
    int i;
    int retorno = -1;
    Clientes* auxClientes = NULL;
    int idClientes;
    if (pArrayClientes!=NULL && id>=0)
    {
        for(i=0; i<ll_len(pArrayClientes); i++)
        {
            auxClientes = ll_get(pArrayClientes,i);
            if(auxClientes != NULL)
            {

            clientes_getId(auxClientes,&idClientes);
            if(idClientes == id)
            {
                retorno=i;
                break;
            }

            }
        }
    }

    return retorno;
}

int buscarPorIdVentas(LinkedList* pArrayVentas, int id)
{
    int i;
    int retorno = -1;
    Ventas* auxVentas = NULL;
    int idVentas;
    if (pArrayVentas!=NULL && id>=0)
    {
        for(i=0; i<ll_len(pArrayVentas); i++)
        {
            auxVentas = ll_get(pArrayVentas,i);
            if(auxVentas != NULL)
            {

            ventas_getId(auxVentas,&idVentas);
            if(idVentas == id)
            {
                retorno=i;
                break;
            }

            }
        }
    }

    return retorno;
}
/** \brief Listar Clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_ListClientes(LinkedList* pArrayListClientes)
{
    char nombre[50];
    char apellido[50];
    int retorno = -1;
    int id;
    int dni;
    Clientes* pAux;
    if(pArrayListClientes != NULL)
    {
        for(int i =0; i<ll_len(pArrayListClientes); i++)
        {
            //printf("I:%d - ",i);
            pAux=(Clientes*)ll_get(pArrayListClientes,i);
            if(pAux != NULL)
            {
                clientes_getId(pAux,&id);
                clientes_getDni(pAux,&dni);
                clientes_getNombre(pAux,nombre);
                clientes_getApellido(pAux,apellido);
                printf("ID: %d  Nombre: %s -- Apellido: %s -- DNI: %d\n",id,nombre,apellido,dni);

                retorno = 0;
            }

        }
    }
    //printf("Menu 6 -----
    return retorno;
}

int controller_ListVentas(LinkedList* pArrayListVentas)
{
    int idClientes;
    int codigo;
    int id;
    int cantidad;
    float precio;
    int retorno = -1;
    Ventas* pAux;
    if(pArrayListVentas != NULL)
    {
        for(int i =0; i<ll_len(pArrayListVentas); i++)
        {
          //  printf("I:%d - ",i);
            pAux=(Ventas*)ll_get(pArrayListVentas,i);
            if(pAux != NULL)
            {
                ventas_getId(pAux,&id);
                ventas_getCodigoProducto(pAux,&codigo);
                ventas_getCantidadDeProductos(pAux,&cantidad);
                ventas_getIdClientes(pAux,&idClientes);
                ventas_getPrecio(pAux,&precio);
                printf("ID: %d  CODIGO: %d -- CANTIDAD: %d -- ID CLIENTE: %d -- PRECIO: %f\n",id,codigo,cantidad,idClientes,precio);

                retorno = 0;
            }

        }
    }
    //printf("Menu 6 -----
    return retorno;
}

/** \brief Modificar datos de Clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_editClientes(LinkedList* pArrayListClientes)
{
    int retorno=-1;
    int posClientes=-1;
    int idClientes;
    int opcion;
    Clientes* auxClientes;
    char nombre[51];
    char apellido[51];
    char dni[51];
    if(pArrayListClientes != NULL)
    {
        controller_ListClientes(pArrayListClientes);
        if(!getEntero("Ingrese el ID a modificar","ID invalido",0,ll_len(pArrayListClientes),1,&idClientes))
        {
            posClientes=buscarPorId(pArrayListClientes,idClientes);
            auxClientes = ll_get(pArrayListClientes,posClientes);
            getEntero("1)Modificar Nombre\n2)Modificar apellido\n3)Modificar DNI\n","Opcion invalida!\n",1,3,1,&opcion);
            switch(opcion)
            {
                case 1:
                    if(!getName("Ingrese nuevo nombre:","nombre invalido",2,51,3,nombre))
                    {
                        if(!clientes_setNombre(auxClientes,nombre))
                        {
                            printf("Nombre modificado correctamente");
                        }
                    }
                    break;
                case 2:
                     if(!getName("Ingrese nuevo apellido:","Apellido invalido",2,51,3,apellido))
                    {
                        if(!clientes_setApellido(auxClientes,apellido))
                        {
                            printf("Apellido modificado correctamente");
                        }
                    }

                    break;
                case 3:
                    if(!getInt("Ingrese nuevo DNI:\n","DNI invalido",1,8,3,dni))
                    {
                        clientes_setDni(auxClientes,atoi(dni));
                        printf("DNI modificado correctamente");
                    }
                    break;

            }
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Baja de Clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_removeClientes(LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int IDABorrar;
    int posIDABorrar;
    Clientes* auxClientes;
    if(pArrayListClientes != NULL)
    {
        controller_ListClientes(pArrayListClientes);
        getEntero("Ingrese ID a borrar: \n","ID no encontrado",0,ll_len(pArrayListClientes),1,&IDABorrar);
        posIDABorrar = buscarPorId(pArrayListClientes,IDABorrar);
        auxClientes = ll_pop(pArrayListClientes,posIDABorrar);
        if(auxClientes != NULL)
        {
            clientes_delete(auxClientes);
            printf("Cliente eliminado correctamente");
            retorno = 0;
        }
    }
    return retorno;
}

int controller_removeVentas(LinkedList* pArrayListVentas)
{
    int retorno = -1;
    int IDABorrar;
    int posIDABorrar;
    Ventas* auxVentas;
    if(pArrayListVentas != NULL)
    {
        controller_ListVentas(pArrayListVentas);
        getEntero("Ingrese ID a borrar: \n","ID no encontrado",0,ll_len(pArrayListVentas),1,&IDABorrar);
        posIDABorrar = buscarPorId(pArrayListVentas,IDABorrar);
        auxVentas = ll_pop(pArrayListVentas,posIDABorrar);
        if(auxVentas != NULL)
        {
            ventas_delete(auxVentas);
            printf("Venta anulada correctamente");
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Ordenar Clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_sortClientes(LinkedList* pArrayListClientes)
{
    int retorno = -1;
    if(pArrayListClientes != NULL)
    {
        ll_sort(pArrayListClientes,clientes_comparacionNombre,0);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los Clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListClientes)
{
    int retorno = -1;
    Clientes* auxClientes;
    FILE* pFile;
    int i;
    char nombre[51];
    char apellido[51];
    int dni;
    int id;
    if(path != NULL && pArrayListClientes != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListClientes);i++)
            {
                auxClientes = ll_get(pArrayListClientes,i);
                if(auxClientes != NULL)
                {
                    clientes_getId(auxClientes, &id);
                    clientes_getNombre(auxClientes, nombre);
                    clientes_getApellido(auxClientes, apellido);
                    clientes_getDni(auxClientes, &dni);
                    fprintf(pFile,"%d,%s,%s,%d\n",id,nombre,apellido,dni);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}

int controller_saveAsTextVentas(char* path, LinkedList* pArrayListVentas)
{
    int retorno = -1;
    Ventas* auxVentas;
    FILE* pFile;
    int i;
    int idVentas;
    int codigo;
    int cantidad;
    float precio;
    int idClientes;
    if(path != NULL && pArrayListVentas != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListVentas);i++)
            {
                auxVentas = ll_get(pArrayListVentas,i);
                if(auxVentas != NULL)
                {
                    ventas_getId(auxVentas, &idVentas);
                    ventas_getCodigoProducto(auxVentas,&codigo);
                    ventas_getCantidadDeProductos(auxVentas, &cantidad);
                    ventas_getIdClientes(auxVentas, &idClientes);
                    fprintf(pFile,"%d,%d,%d,%d,%f\n",idVentas,codigo,cantidad,idClientes,precio);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}

/** \brief Guarda los datos de los Clientes en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int i;
    Clientes *pClientes=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListClientes != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListClientes); i++)
            {
                pClientes = ll_get(pArrayListClientes,i);
                //printf("%s\n",pClientes->nombre);
                fwrite(pClientes,sizeof(Clientes),1,pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }

    return retorno;
    //return 1;
}

/*int controller_aumentoVeintePorcientoSueldos(void* p)
{
    int sueldo;
    int horasTrabajo;
     if(p!=NULL)
    {
        Clientes_getHorasTrabajadas(p,&horasTrabajo);
        Clientes_getSueldo(p,&sueldo);
        if(horasTrabajo>=120)
        {
            sueldo += ( sueldo * 20)/100;

        }
       Clientes_setSueldo(p,sueldo);
     }
    return 1;
}*/

/*int controller_menosDeCienHoras(void* p)
{
    int horasTrabajo;
    int retorno = 0;
    if(p!=NULL)
    {
        Clientes_getHorasTrabajadas(p,&horasTrabajo);
        if(horasTrabajo<100)
        {
            retorno = 1;

        }
    }

    return retorno;

}*/

