#ifndef PARCIAL_BIBILIOTECA_H_INCLUDED
#define PARCIAL_BIBILIOTECA_H_INCLUDED
typedef struct
{
   int idAutores;
   char Apellido[31];
   char nombre[31];
   int isEmpty;

}Autores;
typedef struct
{
    int idLibro;
    char titulo[51];
    int idAutores;

}Libros;
typedef struct
{
    int idSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    int telefono[17];
    char mail[31];
    int fechaAsociado;
}Socios;
typedef struct
{
    int idPrestamos;
    int idLibro;
    int idSocio;
    int fechaPrestamo;

}Prestamos;


#endif // PARCIAL_BIBILIOTECA_H_INCLUDED
