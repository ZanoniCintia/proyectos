#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED


typedef struct
{
    int idInstrumentos;
    int isEmpty;
    //-----------------
    char nombre[50];
    int tipo;

}Instrumentos;

int instrumentos_Inicializar(Instrumentos array[], int size);                                    //cambiar libros
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion);
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion);
int instrumentos_alta(Instrumentos array[], int size, int* contadorID);                          //cambiar libros
int instrumentos_baja(Instrumentos array[], int sizeArray);
                  //cambiar libros
void instrumentos_mock(Instrumentos arrayLibros[], int size,int *contadorId);

#endif // INSTRUMENTOS_H_INCLUDED
