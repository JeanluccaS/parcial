#include "elenco.h"

int hardcodearElenco (eElenco* listaDeElencos,int tam)
{
    int i;
    int retorno=-1;
    int codigoDePelicula[]= {1,2,4,2,3};
    int codigoDeActor[]= {22,14,11,33,5};
    float valorDelContrato[]= {10000,15000,33000,44000,55500};
    if(listaDeElencos!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            listaDeElencos[i].codigoDeActor=codigoDeActor[i];
            listaDeElencos[i].codigoDePelicula=codigoDePelicula[i];
            listaDeElencos[i].valorContrato=valorDelContrato[i];
            listaDeElencos[i].estaVacio=OCUPADO;
        }
        retorno=0;
    }

    return retorno;
}


int cargarElenco (eElenco* listaDeElenco,int tamE,eActor* listadeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG,ePais* listaDePaises,int tamPa)

{
    int retorno=-1;
    int iElenco;

    float valorContrato;
    ePelicula auxPelicula;

    eActor auxActor;
    if(listaDeElenco!=NULL && tamE > 0)
    {
        iElenco=dameIndiceDeElencoLibre(listaDeElenco,tamE);
        if(iElenco!=-1)
        {
            auxPelicula=pelicula_ElejirPelicula(listaDePeliculas,tamP,listaDeGeneros,tamG);


            auxActor=elejirActor(listadeActores,tamA,listaDePaises,tamPa);
            valorContrato=pedirFlotante("Ingrese el valor del contrato ");
            if(validarSiExisteElenco(listaDeElenco,tamE,auxActor,auxPelicula)!=-1)
            {
                listaDeElenco[iElenco].valorContrato=valorContrato;
                listaDeElenco[iElenco].codigoDeActor=auxActor.codigo;
                listaDeElenco[iElenco].codigoDePelicula=auxPelicula.codigo;
                listaDeElenco[iElenco].estaVacio=OCUPADO;
                retorno=0;
            }
            else
            {
                retorno=1;
            }

        }
        else
        {
            retorno=2;
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


int listarElencos(eElenco* listaDeElencos,int tamE,eActor* listaDeActores,int tamA,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG)
{
    int retorno=-1;
    int i;
    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;
    if(listaDeElencos!=NULL && tamE!=0 && listaDeActores!=NULL && tamA!=0 && listaDePeliculas!=NULL && tamP!=0 && listaDeGeneros!=NULL && tamG!=0)
    {

        printf("%24s %20s %27s %15s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
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
        retorno=0;
    }
    return retorno;
}
void mostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero)
{
    printf("%24s %20s %17s %6s %18.2f\n\n",unaPelicula.descripcion,unGenero.Descripcion,unActor.nombre,unActor.apellido,unElenco.valorContrato);
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

int listarPeliculasTerror(eElenco* listaDeElenco,int tamE,ePelicula* listaDePeliculas,int tamP,eGenero* listaDeGeneros,int tamG,eActor* listaDeActores,int tam )
{
    int retorno=-1;
    int i;
    eGenero auxGenero;
    ePelicula auxPelicula;
    eActor auxActor;
    auxGenero=obtenerGeneroPorId(listaDeGeneros,tamG,59);
    for(i=0; i<tamE; i++)
    {
        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            auxActor=buscarActorPorID(listaDeActores,tam,listaDeElenco[i].codigoDeActor);

            auxPelicula=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[i].codigoDePelicula);
            if(auxPelicula.idGenero==auxGenero.id)
            {
                if(auxPelicula.fechaDeEstreno.anio>2002)
                {
                    printf("%24s %20s %27s %21s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
                    mostrarUnElenco(listaDeElenco[i],auxActor,auxPelicula,auxGenero);

                    retorno=0;
                }
            }
        }

    }
    return retorno;
}

int listarActoresArgentinos(eElenco* listaDeElenco,int tamE,ePelicula* listaDePeliculas,int tamP,eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa,eGenero* listaDeGeneros,int tamG)
{
    int retorno=-1;
    int i;
    ePais auxPais;
    eActor auxActor;
    eGenero auxGenero;
    ePelicula auxPelicula;

    auxPais=buscarPaisId(listaDePaises,tamPa,22);

    for(i=0; i<tam; i++)
    {
        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            auxActor=buscarActorPorID(listaDeActores,tam,listaDeElenco[i].codigoDeActor);
            auxPelicula=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[i].codigoDePelicula);
            auxGenero=obtenerGeneroPorId(listaDeGeneros,tamG,auxPelicula.idGenero);
            if(auxActor.idPais==auxPais.id)
            {
                printf("%24s %20s %27s %21s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
                mostrarUnElenco(listaDeElenco[i],auxActor,auxPelicula,auxGenero);

                retorno=0;
            }
        }
    }
    return retorno;
}

int listarPeliculasDeActorSeleccionado(eElenco* listaDeElenco,int tamE,ePelicula* listaDePeliculas,int tamP,eActor* listaDeActores,int tam,eGenero* listaDeGeneros,int tamG,ePais* listaDePaises,int tamPa)
{
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;

    int i;
    int retorno=-1;
    auxActor=elejirActor(listaDeActores,tam,listaDePaises,tamPa);
    for(i=0; i<tamE; i++)
    {
        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            if(auxActor.codigo==listaDeElenco[i].codigoDeActor)
            {
                auxPelicula=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[i].codigoDePelicula);
                auxGenero=obtenerGeneroPorId(listaDeGeneros,tamG,auxPelicula.idGenero);
                printf("%24s %20s %27s %21s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
                mostrarUnElenco(listaDeElenco[i],auxActor,auxPelicula,auxGenero);

                retorno=0;
            }
            else
            {
                retorno=1;
            }
        }

    }
    return retorno;

}

int recaudacionDePeliculasRomanticas(eElenco* listaDeElenco,int tamE,ePelicula* listaDePeliculas,int tamP,eActor* listaDeActores,int tam,eGenero* listaDeGeneros,int tamG,ePais* listaDePaises,int tamPa)
{
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;
    ePais auxPais;
    int i;
    int retorno=0;
    auxActor=elejirActor(listaDeActores,tam,listaDePaises,tamPa);
    auxPais=buscarPaisId(listaDePaises,tamPa,auxActor.idPais);

    mostrarActor(auxActor,auxPais);
    for(i=0; i<tamE; i++)
    {

        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            if(auxActor.codigo==listaDeElenco[i].codigoDeActor)
            {
                auxPelicula=buscarPeliculaPorId(listaDePeliculas,tamP,listaDeElenco[i].codigoDePelicula);
                auxGenero=obtenerGeneroPorId(listaDeGeneros,tamG,70);

                if(auxGenero.id==auxPelicula.idGenero)

                {
                    mostrarUnElenco(listaDeElenco[i],auxActor,auxPelicula,auxGenero);
                    retorno+=listaDeElenco[i].valorContrato;
                }
                else
                {

                    retorno=0;
                }
            }

        }

    }
    return retorno;
}

int listarActorSinPeliculas(eElenco* listaDeElenco,int tamE,eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    eActor auxActor;
    ePais auxPais;
    int retorno=-1;
    int noActua;

    int i;
    for(i=0; i<tam; i++)
    {
        if(listaDeActores[i].estaVacio==OCUPADO)
        {


             auxPais=buscarPaisId(listaDePaises,tamPa,listaDeActores[i].idPais);
          noActua=buscarSiActua(listaDeActores[i],listaDeElenco,tamE);
            if(noActua!=-1)
            {
                retorno=0;
                mostrarActor(listaDeActores[i],auxPais);
            }
        }
    }
    return retorno;
}

int buscarSiActua(eActor unActor,eElenco* listadeElenco,int tamE)
{
    int i;
    int retorno=0;
      for(i=0; i<tamE; i++)
            {
                if(listadeElenco[i].estaVacio==OCUPADO && unActor.estaVacio==OCUPADO)
                {
                    if(unActor.codigo==listadeElenco[i].codigoDeActor)
                    {

                        retorno=-1;
                        break; //estos actores no participan en una pelicula.
                    }
                }
            }
            return retorno;
}
