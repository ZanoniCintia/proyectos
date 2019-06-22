#ifndef Ventas_H_INCLUDED
#define Ventas_H_INCLUDED
typedef struct
{
    int idClientes;
    int codigo;
    int cantidad;
    int idVentas;
}Ventas;

Ventas* ventas_new();
Ventas* ventas_newParametros(char* idVentasStr,char* codigoProductoStr,char* cantidadDeProductosStr,char* idClientesStr);
Ventas* ventas_newFileBinario(Ventas ventas);

void ventas_delete();

int ventas_setId(Ventas* this,int idVentas);
int ventas_getId(Ventas* this,int* idVentas);

int ventas_setCodigoProducto(Ventas* this,int codigo);
int ventas_getCodigoProducto(Ventas* this,int* codigo);

int ventas_setCantidadDeProductos(Ventas* this,int cantidadDeProductos);
int ventas_getCantidadDeProductos(Ventas* this,int* cantidadDeProductos);

int ventas_setIdClientes(Ventas* this,int idClientes);
int ventas_getIdClientes(Ventas* this,int* idClientes);

int ventas_comparacionNombre(void* this1, void* this2);

#endif // Ventas_H_INCLUDED
