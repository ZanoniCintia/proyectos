#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn_validaciones.h"

int main()
{
      int option = 0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();
    //char nombre[300];
    //int id;
    //int horasTrabajadas;
   // int sueldo;
   // Employee* pAux;
  //  char c;
    controller_loadFromText("dataClientes.csv",listaClientes);
    controller_loadFromText("dataVentas.csv",listaVentas);
    do{

        getEntero("\nMenu:\n\n 1. Alta de clientes \n 2. Modificacion de clientes \n 3. Baja de clientes \n 4. Listar clientes \n 5. Realizar venta \n 6. Anular venta \n 7. Informar venta \n 8. Informar venta por producto \n 9. Salir \n\nIngrese una opcion:","Error, opcion invalida",0,10,1,&option);
        system("clear");
        switch(option)
        {
            case 1:
                system("clear");
                controller_addClientes(listaClientes);
                controller_saveAsText("dataClientes.csv",listaClientes);
                break;

            case 2:
                system("clear");
                controller_editClientes(listaClientes);
                controller_saveAsText("dataClientes.csv",listaClientes);
                break;

            case 3:
                system("clear");
                controller_removeClientes(listaClientes);
                controller_saveAsText("dataClientes.csv",listaClientes);
                break;
            case 4:
                system("clear");
                controller_ListClientes(listaClientes);
                controller_saveAsText("dataClientes.csv",listaClientes);
                break;
            case 5:
                system("clear");
                controller_ListClientes(listaClientes);
                controller_addVentas(listaVentas);
                controller_saveAsTextVentas("dataVentas.csv",listaVentas);
                break;
            case 6:
                system("clear");
                controller_removeVentas(listaVentas);
                controller_saveAsTextVentas("dataVentas.csv",listaVentas);
                break;
            case 7:
                system("clear");
                controller_ListVentas(listaVentas);
                controller_saveAsTextVentas("dataVentas.csv",listaVentas);
               break;
            case 8:
              /*  if(!controller_saveAsText("dataBkp.csv",listaEmpleados)) //guarda en el archivo
                {
                    printf("Datos guardados correctamente\n");
                }*/
                break;
            case 9:
                //controller_saveAsBinary("dataBkp.bin",listaEmpleados);//guarda
                break;

        }
    }while(option != 9);

return 0;


}
