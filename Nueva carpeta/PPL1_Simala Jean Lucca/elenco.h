#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "actores.h"

typedef struct
{

    int codigoDePelicula;
    int codigoDeActor;
    float valorContrato;
    int estaVacio;
}eElenco;

int cargarElenco (eElenco* listaDeElenco,int tamE,eActor* listadeActores,int tamA,ePelicula* listaDePeliculas,int tamP);

int inicializarElencos(eElenco* listaDeElencos,int tam);
int dameIndiceDeElencoLibre(eElenco* listaDeElenco,int tamE);
void mostrarUnElenco(eElenco Elenco,eActor* listaDeActores,int tamA,ePelicula* listaDePeliculas,int tamP, int codigoA,int codigoP,float valorDeContrato);
void mostrarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int idPelicula);
void mostrarActorPorId(eActor* listaDeActores,int tam,int idActor);
int listarElenco (eElenco* listaDeElencos,eActor* listaDeActores,ePelicula* listaDePeliculas,int tamE,int tamA,int tamP);
eElenco cargarUnElenco(int codigoDePelicula, int codigoDeActor, float valorDelContrato);
int validarSiExisteElenco(eElenco* listaDeElenco,int tamE,eElenco unElenco);
void ordenarElenco(eElenco* listaDeElenco,int tamE,eActor* listaDeActor,int tamA,ePelicula* listaDePeliculas,int tamP);
