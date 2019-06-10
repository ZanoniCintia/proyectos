#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    /*
    FILE* fAux;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_EmployeeFromText(fAux,pArrayListEmployee))
            {
                retorno = 0;
            }
        }
    }*/
    return retorno;
}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
int idMaxArray(LinkedList* pArrayEmpleado)
{
	int retorno = -1;
	Employee* pAux;
	int idAux;
	int idMax = -1;
	if(pArrayEmpleado != NULL)
	{
		for(int i = 0; i<ll_len(pArrayEmpleado);i++)
		{
			pAux = ll_get(pArrayEmpleado,i);
			employee_getId(pAux, &idAux);
			if(idAux>idMax)
			{
				idMax = idAux;
			}
		}
	}
	retorno = idMax;
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    /*
    Employee* pAux = NULL;
    char idMax;
    char nombre[4096];
    char horasT[4096];
    char sueldo[4096];
    if(pArrayListEmployee != NULL)
    {

        if( !utn_getName("-> Ingrese nombre : ","Nombre invalido",1,51,1,nombre)
            && !getInt("-> Ingrese horas trabajadas : ","Hora invalida",1,400,1,horasT)
            && !getInt("-> Ingrese sueldo : ","Sueldo invalido",0,100000,1,sueldo))
        {
            idMax = idMaxArray(pArrayListEmployee);
            pAux = employee_newParametros(&idMax,nombre,horasT,sueldo);
            if(pAux != NULL)
            {
                ll_add(pArrayListEmployee,pAux);
                retorno = 0;
            }
        }*/
        return retorno;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    /*
    Employee* pAux;
    char id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    char bufferNombre[4096];
    char bufferHoras;
    char bufferSueldo;
    if(pArrayListEmployee != NULL)
    {
        getInt("-> Ingrese id a modificar : ","Id invalido",0,sizeof(int),1,&id);
        do
            {
                printf(" \n ID: \n Nombre: \n Horas: \n Sueldo: ");
                utn_getChar("\nModificar: \nA-Nombre\nB-Horas \nC-Sueldo \nS:(salir)\ningrese opcion: ","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {

                    case 'A':
                        if(!utn_getName("\nIngrese nombre a modificar: ","\nNombre invalido\n",1,51,1,bufferNombre))
                        {
                            if(!employee_setNombre(pAux,bufferNombre))
                            {
                                printf("\nNombre modificado exitosamente");
                            }
                        }
                        break;
                    case 'B':
                        if(!getInt("\nIngrese Horas a modificar: ","\nHora invalida\n",1,300,1,&bufferHoras))
                        {
                            if(!employee_setHorasTrabajadas(pAux,bufferHoras))
                            {
                                printf("\nHoras modificadas exitosamente");
                            }

                        }
                        break;
                    case 'C':
                        if(!getInt("\nIngrese Sueldo a modificar: ","\nSueldo invalida\n",1,100000,1,&bufferSueldo))
                        {
                            if(!employee_setSueldo(pAux,bufferSueldo))
                            {
                                printf("\nSueldo modificado exitosamente");
                            }
                        }//mensaje + cambiar campo varString
                    break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');


    }else
        {
            printf("ID no encontrado.");
        }
        */
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int retorno = -1;
    int posId=-1;
    int idMax=1;
    int idAux;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idMax += findMaxId(pArrayListEmployee);
        if(!getInt("Ingrese el ID a borrar: ","ID Invalido",0,idMax,1,&idAux))
        {
            posId = findId(pArrayListEmployee,idAux);
            if(posId != -1)
            {
                pAux=ll_pop(pArrayListEmployee,posId);
                if(pAux!=NULL)
                {
                    employee_delete(pAux);
                    printf("Empleado eliminado correctamente");
                    retorno = 0;
                }
            }
        }
    }
    return 1;
}*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}*/

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}*/

