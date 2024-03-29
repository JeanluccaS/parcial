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
    char calle[][51]={"Balcarse","Av.9 de julio","Av.Belgrano","Moreno","Piedras","Venezuela"};
    int altura[]={1001,1105,2000,3000,2500,9000};
    int anio[]={2014,2000,1995,1977,1999,1978};
    int dia[]={14,10,28,1,9,21};
    int mes[]={4,10,3,8,7,1};

    char localidad[][51]={"Avellaneda","San telmo","Moreno","San Telmo","Avellaneda","Moreno","Moreno"};
    int idPais[]={22,33,44,77,5,6};
    int cantidadDePremios[]={14,7,6,8,9,1};

    for(i=0; i<tam; i++)
    {
        listaDeActores[i].codigo=codigo[i];
        strcpy(listaDeActores[i].nombre,nombre[i]);
        strcpy(listaDeActores[i].apellido,apellido[i]);
        listaDeActores[i].sexo=sexo[i];
        listaDeActores[i].idPais=idPais[i];
        listaDeActores[i].cantidadDePremios=cantidadDePremios[i];
        strcpy(listaDeActores[i].direccion.calle,calle[i]);
        listaDeActores[i].direccion.altura=altura[i];
        strcpy(listaDeActores[i].direccion.localidad,localidad[i]);
        listaDeActores[i].fechaDeNacimiento.anio=anio[i];
        listaDeActores[i].fechaDeNacimiento.mes=mes[i];
        listaDeActores[i].fechaDeNacimiento.dia=dia[i];
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
    int retorno=-1;
    int lugar;
    char respuesta;

    if(listaDeActores!= NULL && tam > 0)
    {
        lugar=dameIndiceLibre(listaDeActores,tam);
        if (lugar != -1)
        {
            auxActor.codigo=dameMayorCodigo(listaDeActores,tam);
            auxActor.codigo++;
            pedirString("Ingrese el nombre del Actor: ",auxActor.nombre,"Error, reingrese un nombre valido (limite: 51 caracteres)");
            pedirString("Ingrese el apellido del Actor: ",auxActor.apellido,"Error, reingrese un apellido valido (limite: 51 caracteres)");
            auxActor.sexo=pedirCaracter("Ingrese el sexo del Actor. 'm' para masculino, 'f' para femenino ");
            auxActor.fechaDeNacimiento.anio=pedirEntero("Ingrese el anio de nacimiento del actor: ");
            auxActor.fechaDeNacimiento.mes=pedirEntero("Ingrese el mes de nacimiento del actor: ");
            auxActor.fechaDeNacimiento.dia=pedirEntero("Ingrese el dia de nacimiento del actor: ");
            auxActor.cantidadDePremios=pedirEntero("Ingrese la cantidad de premios que gano este actor: ");
            auxActor.direccion.altura=pedirEntero("Ingrese la altura del domicilio del actor: ");
            pedirString("Ingrese la calle en donde vive el actor: ",auxActor.direccion.calle,"Error,reingrese una calle valida (limite: 51 caracteres");
            pedirString("Ingrese la localidad del actor: ",auxActor.direccion.localidad,"Error,reingrese una Localidad valida (limite: 51 caracteres");
            auxPais=elejirPais(listaDePaises,tamPa);
            while(auxActor.sexo!='m'&& auxActor.sexo!='f')
            {
                printf("Error, ingrese 'm' para masculino, o 'f' para femenino\n");
                system("pause");
                system("cls");
                auxActor.sexo=pedirCaracter("Ingrese el sexo del Actor. 'm' para masculino, 'f' para femenino");
            }

            auxActor.estaVacio=OCUPADO;
            printf("\n%5s %20s %10s %12s %15s %12s %20s\n\n","Codigo","Nombre y Apellido","Sexo","Pais","Localidad","CantidadP.","Anio de nacimiento");
            mostrarActor(auxActor,auxPais);
            respuesta= pedirCaracter("Desea cargar este actor? ingrese 's' para si o 'n' para no ");
            if(respuesta=='s')
            {
                listaDeActores[lugar]=auxActor;
                listaDeActores[lugar].idPais=auxPais.id;


                retorno=0;
            }else
            {
                retorno=1;
            }


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
    ePais auxPais;


    if(listaDeActores != NULL && tam > 0)
    {
        printf("%5s %20s %10s %12s %15s %12s %20s\n\n","Codigo","Nombre y Apellido","Sexo","Pais","Localidad","CantidadP.","Anio de nacimiento");
        for(i=0; i<tam; i++)
        {
            if(listaDeActores[i].estaVacio==OCUPADO)
            {                                           //id pais en este caso 22, argentina(recorre los id)
                auxPais=buscarPaisId(listaDePaises,tamPa,listaDeActores[i].idPais);
                retorno=0;
                mostrarActor(listaDeActores[i],auxPais);
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
    printf("%5d %10s %10s %9c %15s %15s %6d %12d\n",Actor.codigo,Actor.nombre,Actor.apellido,Actor.sexo,unPais.descripcion,Actor.direccion.localidad,Actor.cantidadDePremios,Actor.fechaDeNacimiento.anio);
}

void mostrarActorEdad(eActor Actor,ePais unPais)
{
    int edad;
    edad=calcularEdad(Actor.fechaDeNacimiento.anio);
    printf("%5d %10s %10s %9c %15s %15s %6d %12d Anios\n",Actor.codigo,Actor.nombre,Actor.apellido,Actor.sexo,unPais.descripcion,Actor.direccion.localidad,Actor.cantidadDePremios,edad);

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
    ePais idPais;
    listarActores(listaDeActores,tam,listaDePaises,tamP);
    index=buscarActor(listaDeActores,tam);
    idPais=buscarPaisId(listaDePaises,tamP,listaDeActores[index].idPais);
    if(index!=-1)
    {
        retorno=0;
        listaDeActores[index].estaVacio=VACIO;
        printf("\nEl Actor a borrar es: \n");
        mostrarActor(listaDeActores[index],idPais);
    }
    return retorno;
}

int modificarActor(eActor* listaDeActores,int tam,ePais* listaDePaises,int tamPa)
{
    int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    int opcion;
    ePais idPais;
    char nombre[51];
    char apellido[51];
    char sexo;
    char respuesta;
    eActor aux;

    if (listaDeActores!=NULL && tam > 0)
    {
        listarActores(listaDeActores,tam,listaDePaises,tamPa);
        index=buscarActor(listaDeActores,tam);
        idPais=buscarPaisId(listaDePaises,tamPa,listaDeActores[index].idPais);
        aux = listaDeActores[index];
        if(index!=-1)
        {

            retorno=0;

            printf("\nEl Actor a Modificar es: \n");
            mostrarActor(listaDeActores[index],idPais);
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
                mostrarActor(aux,idPais);
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

