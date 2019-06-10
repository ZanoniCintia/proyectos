#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    FILE* pFILE=fopen("data.csv","r");
    Employee* pAux;
    char nombre[300];
    int id;
    int horasTrabajadas;
    int sueldo;


   // int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    parser_EmployeeFromText(pFILE,listaEmpleados);
    for(int i =0;i<ll_len(listaEmpleados);i++)
    {
        pAux=(Employee*)ll_get(listaEmpleados,i);
        if(pAux != NULL)
        {
            employee_getId(pAux,&id);
            employee_getHorasTrabajadas(pAux,&horasTrabajadas);
            employee_getSueldo(pAux,&sueldo);
            employee_getNombre(pAux,nombre);
            printf("ID: %d  Nombre: %s -- Horas trabajadas: %d -- Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);
        }
    }
    //fclose(pFILE);
    return 0;
}
