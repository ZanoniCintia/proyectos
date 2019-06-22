#ifndef Clientes_H_INCLUDED
#define Clientes_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int dni;
}Clientes;

Clientes* clientes_new();
Clientes* clientes_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
Clientes* clientes_newFileBinario(Clientes empleado);

void clientes_delete();

int clientes_setId(Clientes* this,int id);
int clientes_getId(Clientes* this,int* id);

int clientes_setNombre(Clientes* this,char* nombre);
int clientes_getNombre(Clientes* this,char* nombre);

int clientes_setApellido(Clientes* this,char* apellido);
int clientes_getApellido(Clientes* this,char* apellido);



int clientes_setDni(Clientes* this,int dni);
int clientes_getDni(Clientes* this,int* dni);

int clientes_comparacionNombre(void* this1, void* this2);

#endif // clientes_H_INCLUDED
