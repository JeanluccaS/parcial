#include "pais.h"
#include "pedirDatos.h"
void hardcodearPais(ePais* listaDePaises,int tamPa)
{
    int i;
    int id[]={22,33,44,77,5,6};
    char descripcion[][51]={"Argentina","Mexico","Chile","Estados Unidos","Espania","Venezuela"};

    for(i=0;i<tamPa;i++)
    {
        listaDePaises[i].id=id[i];
        strcpy(listaDePaises[i].descripcion,descripcion[i]);
    }
}

void mostrarPaises(ePais* listaDePaises,int tamPa)
{
    int i;
    printf("%5s %20s\n\n","ID","Paises");

    for(i=0;i<tamPa;i++)
    {
        mostrarUnPais(listaDePaises[i]);
    }


}

ePais buscarPaisId(ePais* listaDePaises,int tamPa,int IdPais)
{
    ePais retorno;
    int i;
    for(i=0;i<tamPa;i++)
    {
        if(listaDePaises[i].id==IdPais)
        {
            retorno=listaDePaises[i];
            break;
        }
    }
    return retorno;

}
void mostrarUnPais(ePais unPais)
{
    printf("%5d %20s\n",unPais.id,unPais.descripcion);
}

ePais elejirPais(ePais* listaDePaises,int tamPa)
{
    ePais retorno;
    int pais;
    ePais idPais;

    if(listaDePaises!=NULL && tamPa!=0)
    {
        mostrarPaises(listaDePaises,tamPa);
        pais=pedirEntero("Elija un id de Pais ");
        idPais=buscarPaisId(listaDePaises,tamPa,pais);
        retorno=idPais;
    }


    return retorno;
}
