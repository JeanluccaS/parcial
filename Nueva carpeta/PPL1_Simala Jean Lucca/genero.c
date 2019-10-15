#include "genero.h"
void hardCodearGenero(eGenero listaDeGeneros[],int tam)
{
    int i;
    int id[]={58,59,70,77};
    char descripcion[][51]={"Accion","Terror","Romance","Suspenso"};

    for(i=0;i<tam;i++)
    {
        listaDeGeneros[i].id=id[i];
        strcpy(listaDeGeneros[i].Descripcion,descripcion[i]);
    }
}
