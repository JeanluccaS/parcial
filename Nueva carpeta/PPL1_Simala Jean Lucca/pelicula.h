#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "genero.h"
#include "pedirDatos.h"
#define VACIO 0
#define OCUPADO 1
typedef struct
{
int codigo;
char descripcion[51];
int duracion;
int idGenero;
int estaVacio;
}ePelicula;

void hardcodearPeliculas(ePelicula[],int tam);
int listarPeliculas(ePelicula[],int tamP);
void mostrarPelicula(ePelicula);

