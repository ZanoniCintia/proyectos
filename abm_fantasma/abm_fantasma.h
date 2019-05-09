#ifndef ABM_FANTASMA_H_INCLUDED
#define ABM_FANTASMA_H_INCLUDED
typedef struct
{
    char nombre [50];
    char lastName [50];
    float salario;
    int sector;
    int id;
    int isEmpty;
}Fantasma;

int abm_initFantasma(Fantasma *arrayFantasma, int len);
int abm_addFantasma(Fantasma *arrayFantasma,int len , int *Id,char *nombre,char *apellido,float salario,int sector);
int abm_buscarPorId(Fantasma *arrayFantasma, int len, int id);
int abm_mostrarArray(Fantasma *arrayFantasma, int len);
int abm_borrarFantasma(Fantasma *arrayFantasma, int len,int id);
int abm_ordenarMayoraMenor(Fantasma *arrayFantasma,int len);
int abm_ordenarMenoraMayor(Fantasma *arrayFantasma,int len);
int abm_calcularPromedioSalario(Fantasma *arrayFantasma,int len);
int abm_modificarFantasma(Fantasma *arrayFantasma,int len,int Id);

#endif // ABM_FANTASMA_H_INCLUDED
