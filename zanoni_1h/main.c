#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"  //cambiar por nombre entidad
#include "musico.h"
#include "instrumentos.h"

#define QTY_ARRAY_ORQUESTA 51
#define QTY_ARRAY_MUSICO 51
#define QTY_ARRAY_INSTRUMENTOS 51
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdOrquesta=0;
    Orquesta arrayOrquesta[QTY_ARRAY_ORQUESTA];                   //cambiar
    orquesta_Inicializar(arrayOrquesta,QTY_ARRAY_ORQUESTA);                   //cambiar
    orquesta_mock(arrayOrquesta, QTY_ARRAY_ORQUESTA, &contadorIdOrquesta) ;

    int contadorIdMusico=0;
    Musicos arrayMusicos[QTY_ARRAY_MUSICO];                   //cambiar
    musicos_Inicializar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
    musicos_mock(arrayMusicos, QTY_ARRAY_MUSICO, &contadorIdMusico);

    int contadorIdInstrumentos=0;
    Instrumentos arrayInstrumentos[QTY_ARRAY_INSTRUMENTOS];                   //cambiar
    instrumentos_Inicializar(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);                   //cambiar
    instrumentos_mock(arrayInstrumentos, QTY_ARRAY_INSTRUMENTOS, &contadorIdInstrumentos) ;                     //cambiar fantasma

                        //cambiar fantasma                  //cambiar fantasma

    int primeraOpcion;
    do
    {
        utn_getUnsignedInt("\n1-Menu orquesta\n2-Menu musicos \n3-Menu instrumentos\n5-Salir\nIngrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,5,1,&primeraOpcion);
        switch(primeraOpcion)
        {
            case 1:
                do{
                utn_getUnsignedInt("\n\n-------MENU ORQUESTAS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                case 1: //Alta
                    orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);                   //cambiar
                    break;

                case 2: //Modificar
                    orquesta_modificar(arrayOrquesta,QTY_ARRAY_ORQUESTA);                   //cambiar
                    break;

                case 3: //Baja
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                    orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA);                   //cambiar
                    break;

                case 4://Listar
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);                   //cambiar
                    break;

                case 5://Ordenar
                    orquesta_ordenarPorDobleCriterio(arrayOrquesta,QTY_ARRAY_ORQUESTA,SORT_UP,SORT_DOWN);
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);                   //cambiar
                    break;
                case 6:
                    break;
                }
                }while(opcion!=6);
            break;

            case 2:
               do{
                    utn_getUnsignedInt("\n\n-------MENU MUSICOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese su opcion: ",                   //cambiar
                                       "\nError",1,sizeof(int),1,6,1,&opcion);
                    switch(opcion)
                    {
                    case 1: //Alta
                        musicos_alta(arrayMusicos,QTY_ARRAY_MUSICO,&contadorIdMusico);                   //cambiar
                        break;

                    case 2: //Modificar
                        musicos_modificar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;

                    case 3: //Baja
                        musicos_baja(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;

                    case 4://Listar
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;

                    case 5://Ordenar
                        musicos_ordenarPorDobleCriterio(arrayMusicos,QTY_ARRAY_MUSICO,SORT_UP,SORT_DOWN);
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;
                    case 6:
                    break;
                    }
                }while(opcion!=6);
            break;

            case 3:
                do{
                 utn_getUnsignedInt("\n\n-------MENU INSTRUMENTOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n6)Salir\nIngrese su opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                case 1: //Alta
                    instrumentos_alta(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumentos);                   //cambiar
                    break;

                case 2: //Modificar
                    instrumentos_baja(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);                   //cambiar
                    break;


                }
                case 6:
                break;
                }while(opcion!=6);
            break;
 }
        }while(primeraOpcion!=5);
    return 0;
}





