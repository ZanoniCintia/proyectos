#ifndef EMPLEADO_H
#define EMPLEADO_H
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
}Persona;
#endif

Persona* Per_new(void);
Persona* Per_newStr(char* id,char* nombre, char* apellido, char* estado);

int Per_delete(Persona* this);

int Per_setId(Persona* this, int id);
int Per_getId(Persona* this, int* resultado);

int Per_setApellido(Persona* this, char *apellido);
int Per_getApellido(Persona* this, char *resultado);
int Per_setNombre(Persona* this, char* nombre);
int Per_getNombre(Persona* this, char* resultado);
int Per_setEstado(Persona* this, int estado);
int Per_getEstado(Persona* this, int* resultado);
int Per_getIdStr(Persona* this,char *id);
int Per_setIdStr(Persona* this, char* id);
int Per_setEstadoStr(Persona* this, char *estado);
int Per_getEstadoStr(Persona* this, char *estado);

