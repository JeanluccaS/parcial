#include "elenco.h"


int   cargarElenco (eElenco* listaDeElenco,int tamE,eActor* listadeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG)

{
    int retorno=-1;
    int iElenco;
    int generolist;
    float valorContrato;
    ePelicula auxPelicula;
    eGenero auxGenero;
    eActor auxActor;


    iElenco=dameIndiceDeElencoLibre(listaDeElenco,tamE);
    if(iElenco!=-1)
    {
        auxPelicula=pelicula_ElejirPelicula(listaDePeliculas,tamP,listaDeGeneros,tamG);

        generolist=buscarGenero(listaDeGeneros,tamG,auxPelicula.idGenero);
        auxGenero=listaDeGeneros[generolist];


        auxActor=elejirActor(listadeActores,tamA);
        valorContrato=pedirFlotante("Ingrese el valor del contrato");

        if(validarSiExisteElenco(listaDeElenco,tamE,auxActor,auxPelicula)!=-1)
        {

                listaDeElenco[iElenco].valorContrato=valorContrato;
                listaDeElenco[iElenco].codigoDeActor=auxActor.codigo;
                listaDeElenco[iElenco].codigoDePelicula=auxPelicula.codigo;
                listaDeElenco[iElenco].estaVacio=OCUPADO;
                mostrarUnElenco(listaDeElenco[iElenco],auxActor,auxPelicula,auxGenero);
                retorno=0;

        }
        else
        {
            retorno=-1;
        }
    }
    return retorno;
}
int inicializarElencos(eElenco* listaDeElencos,int tam)
{
    int i;
    int retorno;

    if(listaDeElencos != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            listaDeElencos[i].estaVacio=VACIO;

        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;

}
int dameIndiceDeElencoLibre(eElenco* listaDeElenco,int tamE)
{
    int i;
    int indiceLibre=-1; //fuera de incide, fuerra del array
    for(i=0; i<tamE; i++)
    {
        if(listaDeElenco[i].estaVacio==VACIO)
        {
            indiceLibre=i;
            break;
        }
    }
    return indiceLibre;
}

eElenco cargarUnElenco(int codigoDePelicula, int codigoDeActor, float valorDelContrato)
{
    eElenco unElenco;
    unElenco.codigoDeActor=codigoDeActor;
    unElenco.codigoDePelicula=codigoDePelicula;
    unElenco.valorContrato=valorDelContrato;
    unElenco.estaVacio=OCUPADO;

    return unElenco;
}


int validarSiExisteElenco(eElenco* listaDeElenco,int tamE,eActor elActor,ePelicula laPelicula)
{
    int i;
    int retorno=0;
    for(i=0; i<tamE; i++)
    {
        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            if(listaDeElenco[i].codigoDeActor==elActor.codigo && listaDeElenco[i].codigoDePelicula==laPelicula.codigo)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}


void listarElencos(eElenco* listaDeElencos,int tamE,eActor* listaDeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG)
{
    int i;
    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;
    if(listaDeElencos!=NULL && tamE!=0 && listaDeActores!=NULL && tamA!=0 && listaDePeliculas!=NULL && tamP!=0 && listaDeGeneros!=NULL && tamG!=0)
    {

        printf("%30s %20s %25s %20s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
        for(i=0; i<tamE; i++)
        {
            if(listaDeElencos[i].estaVacio==OCUPADO)
            {
                auxActor=buscarActorPorID(listaDeActores,tamA,listaDeElencos[i].codigoDeActor);
                auxPelicula=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElencos[i].codigoDePelicula);
                auxGenero=obtenerGeneroPorId(listaDeGeneros,tamG,auxPelicula.idGenero);
                mostrarUnElenco(listaDeElencos[i],auxActor,auxPelicula,auxGenero);
            }
        }

    }
}
void mostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero)
{
    printf("%35s %15s %15s %10s %15.2f\n\n",unaPelicula.descripcion,unGenero.Descripcion,unActor.nombre,unActor.apellido,unElenco.valorContrato);
}

void mostrarActorPorId(eActor* listaDeActores,int tam,int idActor)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listaDeActores[i].codigo==idActor)
        {
            printf("%28s%2s",listaDeActores[i].nombre,listaDeActores[i].apellido);
        }
    }
}

void mostrarPeliculaPorId(ePelicula* listaDePeliculas,int tamP,int idPelicula)
{
    int i;
    for(i=0; i<tamP; i++)
    {
        if(listaDePeliculas[i].codigo==idPelicula)
        {
            printf("%7s",listaDePeliculas[i].descripcion);
        }
    }
}

void ordenarElenco(eElenco* listaDeElenco,int tamE,eActor* listaDeActor,int tamA,ePelicula* listaDePeliculas,int tamP)
{
    int i;
    int j;

    eElenco auxElenco;
    ePelicula auxPeliculaUno;
    ePelicula auxPeliculaDos;
    eActor auxActorUno;
    eActor auxActorDos;

    for(i=0; i<tamE-1; i++)
    {
        for(j=i+1; j<tamE; j++)
        {
            auxPeliculaUno=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[i].codigoDePelicula);
            auxPeliculaDos=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[j].codigoDePelicula);
            if(stricmp(auxPeliculaUno.descripcion,auxPeliculaDos.descripcion)>0)
            {
                auxElenco=listaDeElenco[i];
                listaDeElenco[i]=listaDeElenco[j];
                listaDeElenco[j]=auxElenco;
            }
            else if(stricmp(auxPeliculaUno.descripcion,auxPeliculaDos.descripcion)==0)
            {
                auxActorUno=buscarActorPorID(listaDeActor,tamA,listaDeElenco[i].codigoDeActor);
                auxActorDos=buscarActorPorID(listaDeActor,tamA,listaDeElenco[j].codigoDeActor);
                if(stricmp(auxActorUno.apellido,auxActorDos.apellido)>0)
                {
                    auxElenco=listaDeElenco[i];
                    listaDeElenco[i]=listaDeElenco[j];
                    listaDeElenco[j]=auxElenco;
                }
            }

        }
    }

}
