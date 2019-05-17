#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED
#define TEXT_SIZE_INSTRUMENTOS 51

typedef struct
{
    int idInstrumentos;
    int isEmpty;
    //-----------------
    char titulo[TEXT_SIZE_INSTRUMENTOS];
    int tipo;

}Instrumentos;

int instrumentos_Inicializar(Instrumentos array[], int size);                                    //cambiar libros
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion);
int instrumentos_alta(Instrumentos array[], int size, int* contadorID);                          //cambiar libros
int instrumentos_baja(Instrumentos array[], int sizeArray);
                  //cambiar libros
void instrumentos_mock(Instrumentos arrayLibros[], int size,int *contadorId);

#endif // INSTRUMENTOS_H_INCLUDED
