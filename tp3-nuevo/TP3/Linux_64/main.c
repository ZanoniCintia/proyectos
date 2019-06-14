#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_validaciones.h"

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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    char nombre[300];
    int id;
    int horasTrabajadas;
    int sueldo;
    Employee* pAux;
    char c;

    do{

        getEntero("\nMenu:\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n 3. Alta de empleado\n 4. Modificar datos de empleado\n 5. Baja de empleado\n 6. Listar empleados\n 7. Ordenar empleados\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n 10. Salir\n\nIngrese una opcion:","Error, opcion invalida",0,10,1,&option);
        system("clear");
        switch(option)
        {
            case 1:
                system("clear");
                //printf("Menu1 ---------------------------------------");
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
                //controller_loadFromBinary();
                break;

            case 3:
                system("clear");
                controller_addEmployee(listaEmpleados);
                break;

            case 6:
                system("clear");
                printf("cantidad:%d\n",ll_len(listaEmpleados));
                for(int i =0;i<ll_len(listaEmpleados);i++)
                {
                    printf("I:%d - ",i);

                    pAux=(Employee*)ll_get(listaEmpleados,i);
                    if(pAux != NULL)
                    {
                        employee_getId(pAux,&id);
                        employee_getHorasTrabajadas(pAux,&horasTrabajadas);
                        employee_getSueldo(pAux,&sueldo);
                        employee_getNombre(pAux,nombre);
                        printf("ID: %d  Nombre: %s -- Horas trabajadas: %d -- Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);
                    }else{printf("salio por el else");}
                }
                //printf("Menu 6 ---------------------------------------");
                break;
        }
    }while(option != 10);

    /*
    FILE* pFILE=fopen("data.csv","r");
    Employee* pAux;
    char nombre[300];
    int id;
    int horasTrabajadas;
    int sueldo;

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
    */
    return 0;
}
