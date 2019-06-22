
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "Ventas.h"
#include "utn_validaciones.h"


Ventas* ventas_new(void)
{
    return (Ventas*) malloc(sizeof(Ventas));
}

Ventas* ventas_newParametros(char* idVentasStr,char* codigoProductoStr,char* cantidadDeProductosStr,char* idClientesStr)
{
    Ventas* retorno = NULL;
    Ventas* pVentas=ventas_new();
    if(idVentasStr != NULL && codigoProductoStr != NULL && cantidadDeProductosStr != NULL &&  idClientesStr != NULL)
    {
        if(isValidEntero(idVentasStr) && isValidEntero(codigoProductoStr) && isValidEntero(cantidadDeProductosStr) && isValidEntero(idClientesStr))
        {
                if( ventas_setId(pVentas,atoi(idVentasStr))
                    || ventas_setCodigoProducto(pVentas,atoi(codigoProductoStr))
                    || ventas_setCantidadDeProductos(pVentas,atoi(cantidadDeProductosStr))
                    || ventas_setIdClientes(pVentas,atoi(idClientesStr))
                   )
                    {
                        ventas_delete(pVentas);
                    }else
                        {
                            retorno = pVentas;
                        }
        }
    }

    return retorno;
}
Ventas* ventas_newFileBinario(Ventas ventas)
{
    Ventas* retorno = NULL;
    Ventas* pAuxVentas = ventas_new();
    if(pAuxVentas != NULL)
    {
        if(ventas_setId(pAuxVentas,ventas.idVentas)||ventas_setCodigoProducto(pAuxVentas,ventas.codigo)
            ||ventas_setCantidadDeProductos(pAuxVentas,ventas.cantidad)||ventas_setIdClientes(pAuxVentas,ventas.idClientes))
        {
            ventas_delete(pAuxVentas);
        }else
            {
                retorno = pAuxVentas;
            }
    }
    return retorno;
}


void ventas_delete(Ventas* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int ventas_setId(Ventas* this,int idVentas)
{
     int retorno = -1;
    if(this != NULL && idVentas >= 0)
    {
        this->idVentas= idVentas;
        retorno = 0;
    }
    return retorno;

}

int ventas_getId(Ventas* this,int* idVentas)
{
    int retorno = -1;
    if(this != NULL && idVentas != NULL)
    {
        *idVentas = this->idVentas;
        retorno = 0;
    }
    return retorno;

}
int ventas_setIdClientes(Ventas* this,int idClientes)
{
     int retorno = -1;
    if(this != NULL && idClientes >= 0)
    {
        this->idClientes = idClientes;
        retorno = 0;
    }
    return retorno;

}

int ventas_getIdClientes(Ventas* this,int* idClientes)
{
    int retorno = -1;
    if(this != NULL && idClientes != NULL)
    {
        *idClientes = this->idClientes;
        retorno = 0;
    }
    return retorno;

}


int ventas_setCodigoProducto(Ventas* this,int codigo)
{
    int retorno=-1;
    if(this != NULL && codigo>=0)
    {
        this->codigo=codigo;
        retorno=0;
    }
    return retorno;

}
int ventas_getCodigoProducto(Ventas* this,int* codigo)
{
    int retorno = -1;
    if(this != NULL && codigo != NULL)
    {
        *codigo = this->codigo;
        retorno = 0;
    }
    return retorno;

}


int ventas_setCantidadDeProductos(Ventas* this,int cantidad)
{
    int retorno=-1;
    if(this != NULL && cantidad>0)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;

}
int ventas_getCantidadDeProductos(Ventas* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;

}




