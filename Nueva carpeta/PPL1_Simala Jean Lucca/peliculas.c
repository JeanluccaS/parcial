#include "pelicula.h"

void hardcodearPeliculas(ePelicula listaDePeliculas[],int tam)
{
    int i;
    int codigo[]= {1,2,3,4};
    char descripcion[][51]= {"El aro","El joker","Dragon ball super: Broly","IT: capitulo 2"};
    int duracion[]= {120,115,165,180};
    int idGenero[]= {58,59,70,77};
    int dia[]={11,30,24,7};
    int mes[]={3,10,7,9};
    int anio[]={2000,2019,2017,2019};

    for(i=0; i<tam; i++)
    {
        listaDePeliculas[i].codigo=codigo[i];
        strcpy(listaDePeliculas[i].descripcion,descripcion[i]);
        listaDePeliculas[i].duracion=duracion[i];
        listaDePeliculas[i].idGenero=idGenero[i];
        listaDePeliculas[i].fechaDeEstreno.anio=anio[i];
        listaDePeliculas[i].fechaDeEstreno.dia=dia[i];
        listaDePeliculas[i].fechaDeEstreno.mes=mes[i];
        listaDePeliculas[i].estaVacio=OCUPADO;
    }
}
void listarPeliculas(ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG)
{
    int i;
    int index;

    printf("%s %30s %18s %12s %20s\n\n","Cod.","Descripcion ","Duracion","Genero","Fecha de estreno");


    for(i=0; i<tamP; i++)
    {
        index=buscarGenero(listaDeGeneros,tamG,listaDePeliculas[i].idGenero);

        if(index!=-1)
        {
            mostrarPelicula(listaDePeliculas[i],listaDeGeneros[index]);
        }
    }
    printf("\n");

}

void mostrarPelicula(ePelicula pelicula,eGenero genero)
{

    printf("%4d %30s %18d %12s %8d/%d/%d\n",pelicula.codigo,pelicula.descripcion,pelicula.duracion,genero.Descripcion,pelicula.fechaDeEstreno.dia,pelicula.fechaDeEstreno.mes,pelicula.fechaDeEstreno.anio);

}
int validarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int opcion)
{
    int i;
    int retorno=-1;
    if(listaDePeliculas!=NULL && tamP > 0)
    {
        for(i=0; i<tamP; i++)
        {
            if(opcion>0 && opcion==listaDePeliculas[i].codigo)
            {

                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
ePelicula buscarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int codigo)
{
    ePelicula retorno;
    int i;

    if(listaDePeliculas!=NULL && tamP > 0)
    {
        for(i=0; i<tamP; i++)
        {
            if(codigo>0 && codigo==listaDePeliculas[i].codigo)
            {
                retorno=listaDePeliculas[i];
                break;
            }
        }
    }

    return retorno;
}

ePelicula pelicula_ElejirPelicula(ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG)
{
    ePelicula retorno;
    int opcion;
    if(listaDePeliculas!=NULL && tamP>0 && listaDeGeneros!=NULL && tamG>0)
    {
        listarPeliculas(listaDePeliculas,tamP,listaDeGeneros,tamG);
        opcion=pedirEntero("Ingrese el codigo de la pelicula: ");
        while(validarPeliculaPorId(listaDePeliculas,tamP,opcion)==-1)
        {
            printf("Error, ese codigo no existe.\n");
            opcion=pedirEntero("Ingrese el codigo de la pelicula: ");
        }

        retorno=buscarPeliculaPorId(listaDePeliculas,tamP,opcion);
    }
    return retorno;


}
