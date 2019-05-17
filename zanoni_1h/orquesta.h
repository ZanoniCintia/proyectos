#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#define TEXT_SIZE_ORQUESTA 51

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE_ORQUESTA];
    char lugar[TEXT_SIZE_ORQUESTA];
    int tipo;

}Orquesta;




int orquesta_Inicializar(Orquesta array[], int size);                                    //cambiar autor
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);                    //cambiar autor
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar autor
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar autor
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);                    //cambiar autor
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar autor
int orquesta_baja(Orquesta array[], int sizeArray);                                      //cambiar autor
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);                                //cambiar autor
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond);                                  //cambiar autor
int orquesta_listar(Orquesta array[], int size);                      //cambiar autor
void orquesta_mock(Orquesta arrayAutor[], int size,int *contadorId);                      //cambiar autor




#endif // ORQUESTA_H_INCLUDED
