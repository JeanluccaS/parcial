#include "actores.h"

int inicializarActores(eActor* listaDeActores,int tam)
{
    int i;
    int retorno;

    if(listaDeActores != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            listaDeActores[i].estaVacio=VACIO;
            listaDeActores[i].codigo=0;
        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

void hardcodearDatos(eActor* listaDeActores,int tam)
{
    int i;
    int codigo[]= {22,10,11,14,33,5};
    char nombre[][51]= {"pipo","jose","matias","martina","alexis","roberto"};
    char apellido[][51]= {"gutierrez","martinez","herrera","perez","rodriguez","labagna"};
    char sexo[]= {'m','m','m','f','m','m'};
    int idPais[]={22,33,44,77,5,6};

    for(i=0; i<tam; i++)
    {
        listaDeActores[i].codigo=codigo[i];
        strcpy(listaDeActores[i].nombre,nombre[i]);
        strcpy(listaDeActores[i].apellido,apellido[i]);
        listaDeActores[i].sexo=sexo[i];
        listaDeActores[i].idPais=idPais[i];
        listaDeActores[i].estaVacio=OCUPADO;
    }
}
int dameIndiceLibre(eActor* listaDeActores,int tam)
{
    int i;
    int indiceLibre=-1; //fuera de incide, fuerra del array
    for(i=0; i<tam; i++)
    {
        if(listaDeActores[i].estaVacio==VACIO)
        {
            indiceLibre=i;
            break;
        }
    }
    return indiceLibre;
}

int cargarActores (eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    eActor auxActor;
    ePais auxPais;
    int retorno;

    if(listaDeActores!= NULL && tam > 0)
    {
        retorno=dameIndiceLibre(listaDeActores,tam);
        if (retorno != -1)
        {
            auxActor.codigo=dameMayorCodigo(listaDeActores,tam);
            auxActor.codigo++;
            pedirString("Ingrese el nombre del Actor: ",auxActor.nombre,"Error, reingrese un nombre valido (limite: 51 caracteres)");
            pedirString("Ingrese el apellido del Actor: ",auxActor.apellido,"Error, reingrese un apellido valido (limite: 51 caracteres)");
            auxActor.sexo=pedirCaracter("Ingrese el sexo del Actor. 'm' para masculino, 'f' para femenino");
            auxPais=elejirPais(listaDePaises,tamPa);

            while(auxActor.sexo!='m'&& auxActor.sexo!='f')
            {
                printf("Error, ingrese 'm' para masculino, o 'f' para femenino\n");
                system("pause");
                system("cls");
                auxActor.sexo=pedirCaracter("Ingrese el sexo del Actor. 'm' para masculino, 'f' para femenino");
            }
            auxActor.estaVacio=OCUPADO;
            printf("llegue aca2");
             mostrarActor(auxActor,auxPais);
            pedirCaracter("Desea cargar este actor? ingrese 's' para si o 'n' para no");


        }
    }

    return retorno;
}



int dameMayorCodigo (eActor listaDeActores[],int tam)
{
    int i;
    int flag=0;
    int codigoMayor;
    for(i=0; i<tam; i++)
    {
        if(flag==0||listaDeActores[i].codigo>codigoMayor)
        {
            codigoMayor=listaDeActores[i].codigo;
            flag=1;
        }
    }
    return codigoMayor;

}
int listarActores(eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    int i;
    int retorno;
    int iPais;


    if(listaDeActores != NULL && tam > 0)
    {
        printf("%5s %25s %10s %15s\n\n","Codigo","Nombre y Apellido","Sexo","Pais");
        for(i=0; i<tam; i++)
        {
            if(listaDeActores[i].estaVacio==OCUPADO)
            {                                           //id pais en este caso 22, argentina(recorre los id)
                iPais=buscarPaisId(listaDePaises,tamPa,listaDeActores[i].idPais);
                retorno=0;
                mostrarActor(listaDeActores[i],listaDePaises[iPais]);
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

void mostrarActor(eActor Actor,ePais unPais)
{
    printf("%5d %15s %10s %9c \t%5s\n",Actor.codigo,Actor.nombre,Actor.apellido,Actor.sexo,unPais.descripcion);
}


int buscarActor(eActor* Actores,int tam)
{
    int i;
    int numero;
    int loEncontre=-1; //fuera de indice
    numero=pedirEntero("\n\nIngrese el codigo a buscar: ");
    for(i=0; i<tam; i++)
    {
        if(numero==Actores[i].codigo && Actores[i].estaVacio==OCUPADO)
        {
            loEncontre=i;
        }
    }
    return loEncontre;
}

int borrarActor (eActor* listaDeActores, int tam,ePais* listaDePaises,int tamP)
{

    int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    listarActores(listaDeActores,tam,listaDePaises,tamP);
    index=buscarActor(listaDeActores,tam);
    if(index!=-1)
    {
        retorno=0;
        listaDeActores[index].estaVacio=VACIO;
        printf("\nEl Actor a borrar es: \n");
        mostrarActor(listaDeActores[index],listaDePaises[index]);
    }
    return retorno;
}

int modificarActor(eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    int opcion;
    char nombre[51];
    char apellido[51];
    char sexo;
    char respuesta;
    eActor aux;

    if (listaDeActores!=NULL && tam > 0)
    {
        listarActores(listaDeActores,tam,listaDePaises,tamPa);
        index=buscarActor(listaDeActores,tam);
        aux = listaDeActores[index];
        if(index!=-1)
        {

            retorno=0;

            printf("\nEl Actor a Modificar es: \n");
            mostrarActor(listaDeActores[index],listaDePaises[index]);
            opcion=pedirEntero("\n Que dato desea modificar?\n1.Nombre\n2.Apellido\n3.Sexo\nIngrese una opcion: ");
            switch(opcion)
            {
            case 1:
                pedirString("Ingrese nuevo nombre: ",nombre,"Error, reingrese un nombre valido (maximo 51 caracteres)");
                strcpy(aux.nombre,nombre);
                break;
            case 2:
                pedirString("Ingrese nuevo apellido: ",apellido,"Error, reingrese un apellido valido (maximo 51 caracteres)");
                strcpy(aux.apellido,apellido);
                break;
            case 3:
                sexo=pedirCaracter("Ingrese un nuevo sexo: ");
                if(sexo=='m'||sexo=='f')
                {
                    aux.sexo=sexo;
                }
                else
                {
                    printf("Ingrese un sexo valido. 'm' o 'f'");
                }

                break;
            default:
                printf("Opcion no valida");

            }
            if(retorno==0)
            {
                printf("\nEl Actor a modificar va a quedar de la siguiente manera: ");
                mostrarActor(aux,listaDePaises[index]);
                respuesta=pedirCaracter("\nDesea guardas los cambios? presione 's' para guardar");
                if(respuesta=='s')
                {
                    listaDeActores[index]=aux;
                }
                else
                {
                    printf("\nNo se realizo la modificacion");
                    retorno=1;
                }
            }

        }
        else
        {
            retorno=-1;
        }
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

int ordenarActores(eActor* listaDeActores,int tam)
{
    int retorno;
    eActor aux;
    int i;
    int j;

    if(listaDeActores!=NULL && tam > 0)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(listaDeActores[i].apellido, listaDeActores[j].apellido)>0 && listaDeActores[i].estaVacio == OCUPADO && listaDeActores[j].estaVacio==OCUPADO)
                {

                    aux=listaDeActores[i];
                    listaDeActores[i]=listaDeActores[j];
                    listaDeActores[j]=aux;

                }
                else if (strcmp(listaDeActores[i].apellido,listaDeActores[j].apellido)==0 && listaDeActores[i].estaVacio == OCUPADO && listaDeActores[j].estaVacio==OCUPADO)
                {
                    if(strcmp(listaDeActores[i].nombre,listaDeActores[j].nombre)==0 && listaDeActores[i].estaVacio == OCUPADO && listaDeActores[j].estaVacio==OCUPADO)

                    aux=listaDeActores[i];
                    listaDeActores[i]=listaDeActores[j];
                    listaDeActores[j]=aux;
                }
            }
        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

int informarActor (eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    int retorno;
    if (listaDeActores !=NULL && tam > 0)
    {
        retorno=0;
        ordenarActores(listaDeActores,tam);
        listarActores(listaDeActores,tam,listaDePaises,tamPa);
    }
    else
    {
        retorno = -1;
    }



    return retorno;
}
eActor elejirActor(eActor* listaDeActores,int tamA,ePais* listaDePaises,int tamPa)
{
    eActor retorno;

    int actor;
    while(listaDeActores!=NULL && tamA!=0 )
    {
        listarActores(listaDeActores,tamA,listaDePaises,tamPa);

        actor=buscarActor(listaDeActores,tamA);
        if(actor!=-1)
        {
            retorno=listaDeActores[actor];
            break;
        }

        printf("Ese Actor No fue Encontrado\n");
    }
    return retorno;
}

eActor buscarActorPorID(eActor* listaDeActores,int tam,int codigo)
{
    eActor retorno;
    int i;
    if(listaDeActores!=NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            if(codigo > 0 && codigo==listaDeActores[i].codigo)
            {
                retorno=listaDeActores[i];
                break;
            }
        }
    }
    return retorno;
}

