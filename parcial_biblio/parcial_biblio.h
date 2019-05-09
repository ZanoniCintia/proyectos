#ifndef PARCIAL_BIBLIO_H_INCLUDED
#define PARCIAL_BIBLIO_H_INCLUDED
typedef struct
{
    int idSocio;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[16];
    int DNI;
    char mail[31];
    int fechaAsociado;
    int isEmpty;
}Socios;
typedef struct
{
    int idAutor;
    char nombre[31];
    char apellido[31];
    int isEmpty;
}Autores;
typedef struct
{
    int idLibro;
    char nombre[51];
    int idAutor;
    int isEmpty;
}Libros;
typedef struct
{
    int idPrestamo;
    char idLibro;
    int idSocio;
    int fechaDePrestamo;
    int isEmpty;
}Prestamos;






#endif // PARCIAL_BIBLIO_H_INCLUDED
