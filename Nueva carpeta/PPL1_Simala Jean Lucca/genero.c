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

eGenero obtenerGeneroPorId(eGenero* listaDeGeneros,int tamG,int idGenero)
{
    eGenero retorno;
    int i;
    if(listaDeGeneros!=NULL && tamG!=0)
    {
        for(i=0; i<tamG; i++)
        {
            if(listaDeGeneros[i].id==idGenero)
            {
                retorno=listaDeGeneros[i];
                break;
            }
        }
    }
    return retorno;
}

int buscarGenero(eGenero* listaDeGeneros,int tamG,int idGenero)
{
    int retorno=-1;
    int i;
    if(listaDeGeneros!=NULL && tamG>0)
    {
        for(i=0; i<tamG; i++)
        {
            if(listaDeGeneros[i].id==idGenero)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
