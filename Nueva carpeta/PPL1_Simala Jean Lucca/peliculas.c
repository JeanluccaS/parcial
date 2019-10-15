#include "pelicula.h"

void hardcodearPeliculas(ePelicula listaDePeliculas[],int tam)
{
    int i;
    int codigo[]={1,2,3,4};
    char descripcion[][51]={"El aro","El joker","Dragon ball super: Broly","IT: capitulo 2"};
    int duracion[]={120,115,165,180};
    int idGenero[]={58,59,70,77};

    for(i=0;i<tam;i++)
    {
        listaDePeliculas[i].codigo=codigo[i];
        strcpy(listaDePeliculas[i].descripcion,descripcion[i]);
        listaDePeliculas[i].duracion=duracion[i];
        listaDePeliculas[i].idGenero=idGenero[i];
        listaDePeliculas[i].estaVacio=OCUPADO;
    }
}
int listarPeliculas(ePelicula listaDePeliculas[],int tamP)
{
    int i;
    int retorno;
    if(listaDePeliculas != NULL && tamP > 0)
    {
        printf("\nCodigo\t\t\tNombre\t\tDuracion\n");
        for(i=0; i<tamP; i++)
        {
            if(listaDePeliculas[i].estaVacio==OCUPADO)
            {
                retorno=0;
                mostrarPelicula(listaDePeliculas[i]);
            }
        }
    }
    else
    {
        retorno=-1;
    }
    printf("\n");
    return retorno;
}

void mostrarPelicula(ePelicula pelicula)
{
    printf("\n%7d",pelicula.codigo);
    printf("%28s",pelicula.descripcion);
    printf("%18d",pelicula.duracion);
}
