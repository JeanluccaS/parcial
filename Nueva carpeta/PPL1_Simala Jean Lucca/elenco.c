#include "elenco.h"


int cargarElenco (eElenco* listaDeElenco,int tamE,eActor* listadeActores,int tamA,ePelicula* listaDePeliculas,int tamP)
{
    int retorno;
    int codigoDePelicula;
    int codigoDeActor;
    float valorContrato;
    char respuesta;
    eElenco auxElenco;
    if(listaDeElenco!=NULL && tamE>0)
    {

        retorno=dameIndiceDeElencoLibre(listaDeElenco,tamE);
        {

            if(retorno!=-1)
            {

                retorno=0;
                valorContrato=pedirFlotante("Ingrese el valor del contrato: ");
                listarPeliculas(listaDePeliculas,tamP);
                codigoDePelicula=pedirEntero("Ingrese el codigo de la pelicula ");
                do
                {

                    retorno=dameIndiceDeElencoLibre(listaDeElenco,tamE);
                    if(retorno!=-1)
                    {
                          listarActores(listadeActores,tamA);
                    codigoDeActor=pedirEntero("Ingrese el codigo del actor: ");
                    auxElenco=cargarUnElenco(codigoDePelicula,codigoDeActor,valorContrato);
                    if(validarSiExisteElenco(listaDeElenco,tamE,auxElenco)==-1)
                    {
                        printf("Error fatal");
                        retorno=1;
                    }
                    else
                    {
                        listaDeElenco[retorno]=auxElenco;
                    }
                    respuesta=pedirCaracter("Desea ingresar otro actor para esta pelicula? 's' para si");
                    }
                    else
                        {
                            respuesta='n';
                        }
                }
                while(respuesta=='s');
            }
        }
    }
    else
    {
        retorno=-1;
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

int validarSiExisteElenco(eElenco* listaDeElenco,int tamE,eElenco unElenco)
{
    int i;
    int retorno=0;
    for(i=0;i<tamE;i++)
    {
        if(listaDeElenco[i].estaVacio==OCUPADO)
        {
            if(listaDeElenco[i].codigoDePelicula==unElenco.codigoDePelicula && listaDeElenco[i].codigoDeActor==unElenco.codigoDeActor)
            {
                retorno=-1;
                break;
            }

        }
    }
    return retorno;
}



int listarElenco (eElenco* listaDeElencos,eActor* listaDeActores,ePelicula* listaDePeliculas,int tamE,int tamA,int tamP)
{
    int i;
    int retorno;


    if(listaDeElencos != NULL && tamE > 0)
    {
        printf("Pelicula\t\t\tNombre y Apellido del actor\t\tValor de contrato\n");
        for(i=0; i<tamE; i++)
        {
            if(listaDeElencos[i].estaVacio==OCUPADO)
            {
                retorno=0;
                mostrarUnElenco(listaDeElencos[i],listaDeActores,tamA,listaDePeliculas,tamP,listaDeElencos[i].codigoDeActor,listaDeElencos[i].codigoDePelicula,listaDeElencos[i].valorContrato);
                printf("\n");
            }
        }
    }
    else
    {
        retorno=-1;
    }

    return retorno;


}
void mostrarUnElenco(eElenco Elenco,eActor* listaDeActores,int tamA,ePelicula* listaDePeliculas,int tamP, int codigoA,int codigoP,float valorDeContrato)
{
    mostrarPeliculaPorId(listaDePeliculas,tamP,codigoP);
    mostrarActorPorId(listaDeActores,tamA,codigoA);
    printf("%18.2f",valorDeContrato);
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
    int a;
    eElenco auxElenco;
    ePelicula auxPeliculaUno;
    ePelicula auxPeliculaDos;
    eActor auxActorUno;
    eActor auxActorDos;

    for(i=0;i<tamE-1;i++)
    {
        for(j=i+1;j<tamE;j++)
        {
            for(a=0;a<tamP;a++)
            {
                if(listaDeElenco[i].codigoDePelicula==listaDePeliculas[a].codigo)
                {
                    auxPeliculaUno=listaDePeliculas[a];
                }
                else if(listaDeElenco[j].codigoDePelicula==listaDePeliculas[a].codigo)
                {
                    auxPeliculaDos=listaDePeliculas[a];
                }
            }
            for(a=0;a<tamA;a++)
            {
                if(listaDeElenco[i].codigoDeActor==listaDeActor[a].codigo)
                {
                    auxActorUno=listaDeActor[a];
                }
                else if(listaDeElenco[j].codigoDeActor==listaDeActor[a].codigo)
                {
                    auxActorDos=listaDeActor[a];
                }
            }
            if(stricmp(auxPeliculaUno.descripcion,auxPeliculaDos.descripcion)>0)
            {
                auxElenco=listaDeElenco[i];
                listaDeElenco[i]=listaDeElenco[j];
                listaDeElenco[j]=auxElenco;
            }else if(stricmp(auxPeliculaUno.descripcion,auxPeliculaDos.descripcion)==0)
            {
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
