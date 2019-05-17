#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#define TEXT_SIZE_MUSICO 51

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE_MUSICO];
    char apellido[TEXT_SIZE_MUSICO];
    int edad;
    int idOrquesta;
    int idInstrumento;

}Musicos;

int musicos_Inicializar(Musicos array[], int size);                                    //cambiar Musicos
int musicos_buscarEmpty(Musicos array[], int size, int* posicion);                    //cambiar Musicos
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar Musicos
int musicos_buscarInt(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar Musicos
int musicos_buscarString(Musicos array[], int size, char* valorBuscado, int* indice);                    //cambiar Musicos
int musicos_alta(Musicos array[], int size, int* contadorID);                          //cambiar Musicos
int musicos_baja(Musicos array[], int sizeArray);                                      //cambiar Musicos
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado);
int musicos_modificar(Musicos array[], int sizeArray);                                //cambiar Musicos
int musicos_ordenarPorDobleCriterio(Musicos array[],int size, int orderFirst, int orderSecond);                                  //cambiar Musicos
int musicos_listar(Musicos array[], int size);                      //cambiar Musicos
void musicos_mock(Musicos arrayMusicos[], int size,int *contadorId);
int musicos_buscarNombreyApellido ( Musicos array[], int size, char* valorBuscado,char* apellidoBuscado, int* indice);                     //cambiar Musicos


#endif // MUSICO_H_INCLUDED


