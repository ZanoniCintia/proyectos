#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#include "utn.h"
#include <string.h>
#define PERSONAL 1000

int main()
{
    int opcion=0;
    Empleado lista[PERSONAL];
    emp_initEmpleado(lista,PERSONAL);
    printf("***Registro de personal***");

    lista[0].isEmpty=0;
    strcpy(lista[0].name,"Cintia");
    strcpy(lista[0].lastName,"Zanoni");
    lista[0].salary=1000.20;
    lista[0].sector=1;
    lista[0].Id=0;

    lista[1].isEmpty=0;
    strcpy(lista[1].name,"Joe");
    strcpy(lista[1].lastName,"Morello");
    lista[1].salary=2000.20;
    lista[1].sector=2;
    lista[1].Id=1;

    lista[2].isEmpty=0;
    strcpy(lista[2].name,"Bryanna");
    strcpy(lista[2].lastName,"Barrios");
    lista[2].salary=3000.20;
    lista[2].sector=3;
    lista[2].Id=2;

    do
    {
        printf("1-Alta de empleado\n");
        printf("2-Baja de empleado\n");
        printf("3-Modificacion de datos\n");
        printf("4-visualizar informe de personal\n")
        printf("5-Promedio salarial");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;


        }

    }while(opcion!=5)


   return 0;
}
