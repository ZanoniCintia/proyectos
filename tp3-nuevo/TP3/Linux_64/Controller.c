#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_validaciones.h"
int idMaxArray(LinkedList* pArrayEmpleado);
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
    FILE* fAux;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_EmployeeFromText(fAux,pArrayListEmployee))
            {
                printf("El archivo se cargo existosamente en modo texto!");
                retorno = 0;
            }
        }
        fclose(fAux);
    }
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
    int retorno = -1;
    FILE* pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL && !parser_EmployeeFromBinary(pFile,pArrayListEmployee))
        {
            printf("El archivo se cargo existosamente en modo binario!");
            retorno = 0;
        }
    }
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
    char nombre[51];
    char horasTrabajadas[20];
    char sueldo[20];
    char idTex[20];
    int id;
    int retorno=-1;
    Employee* pAuxiliar;


    if(pArrayListEmployee!=NULL)
    {
        id=idMaxArray(pArrayListEmployee)+1;
        sprintf(idTex,"%d",id);
        if( getName("\n Ingrese nombre de empleado: ", "\n Error",1,51,1,nombre) &&
            getInt("\n Ingrese horas trabajadas: ", "\n Error",1,500,1,horasTrabajadas) &&
            getInt("\n Ingrese sueldo: ", "\n Error",1,500000,1,sueldo))
        {
            pAuxiliar= employee_newParametros(idTex,nombre,horasTrabajadas,sueldo);
            if(pAuxiliar != NULL)
            {
                ll_add(pArrayListEmployee,pAuxiliar);
                retorno = 0;
            }
        }

    }

  return retorno;
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


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    LinkedList* listaEmpleados;// = ll_newLinkedList();
    char nombre[300];
    int id;
    int horasTrabajadas;
    int sueldo;
    Employee* pAux;

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
            }
    }
                //printf("Menu 6 -----
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                //printf("%s\n",pEmployee->nombre);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }

    return retorno;
    //return 1;
}

