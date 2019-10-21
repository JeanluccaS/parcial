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


int validarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int opcion);
void hardcodearPeliculas(ePelicula[],int tamP);
void listarPeliculas(ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG);
void mostrarPelicula(ePelicula,eGenero);
ePelicula buscarPeliculaPorId(ePelicula*,int tamP,int codigo);
ePelicula pelicula_ElejirPelicula(ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG);
