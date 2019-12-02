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



int inicializarElencos(eElenco* listaDeElencos,int tam);
int dameIndiceDeElencoLibre(eElenco* listaDeElenco,int tamE);
void mostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero);
void mostrarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int idPelicula);
void mostrarActorPorId(eActor* listaDeActores,int tam,int idActor);
int listarElencos(eElenco* listaDeElencos,int tamE,eActor* listaDeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG);
int cargarElenco (eElenco* listaDeElenco,int tamE,eActor* listadeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG,ePais* listaDePaises,int tamPa);
int validarSiExisteElenco(eElenco* listaDeElenco,int tamE,eActor elActor,ePelicula laPelicula);
void ordenarElenco(eElenco* listaDeElenco,int tamE,eActor* listaDeActor,int tamA,ePelicula* listaDePeliculas,int tamP);
int hardcodearElenco (eElenco* listaDeElenco, int tam);
