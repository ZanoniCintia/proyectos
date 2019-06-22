#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Clientes.h"
#include "Ventas.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int parser_ClientesFromText(FILE* pFile , LinkedList* pArrayListClientes)
{

    int retorno=-1;
    int cantidad;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    Clientes* pClientes;
    if(pFile !=NULL && pArrayListClientes != NULL)
    {
        do
        {
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferDni);
            if(cantidad==4)
            {
                pClientes=clientes_newParametros(bufferId,bufferNombre,bufferApellido,bufferDni);
                if(pClientes !=NULL)
                {
                    ll_add(pArrayListClientes,pClientes);
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{

    int retorno=-1;
    int cantidad;
    char bufferIdVentas[4096];
    char bufferCodigo[4096];
    char bufferCantidad[4096];
    char bufferidClientes[4096];
    char bufferPrecio[4096];
    Ventas* pVentas;
    if(pFile !=NULL && pArrayListVentas != NULL)
    {
        do
        {
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferIdVentas,bufferCodigo,bufferCantidad,bufferidClientes,bufferPrecio);
            if(cantidad==4)
            {
                pVentas=ventas_newParametros(bufferIdVentas,bufferCodigo,bufferCantidad,bufferidClientes,bufferPrecio);
                if(pVentas !=NULL)
                {
                    ll_add(pArrayListVentas,pVentas);
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}



/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int parser_clientesFromBinary(FILE* pFile , LinkedList* pArrayListClientes)
{
    int retorno = -1;
    Clientes auxClientes;
    Clientes* clientes;
    if(pFile != NULL && pArrayListClientes != NULL)
    {
        while(!feof(pFile))
        {
            clientes = clientes_newFileBinario(auxClientes);
            fread(&auxClientes,sizeof(Clientes),1,pFile);
            if(clientes != NULL)
            {
                ll_add(pArrayListClientes,clientes);
            }
            else
            {
                clientes_delete(clientes);
            }
        }
        retorno = 0;
    }
    fclose(pFile);
    return retorno;

}
