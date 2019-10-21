#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
 {
     int id;
     char Descripcion[51];
 }eGenero;

void hardCodearGenero(eGenero[],int tam);
eGenero obtenerGeneroPorId(eGenero* listaDeGeneros,int tamG,int idGenero);
int buscarGenero(eGenero* listaDeGeneros,int tamG,int idGenero);
