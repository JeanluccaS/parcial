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

int buscarPaisId(ePais* listaDePaises,int tamPa,int IdPais)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamPa;i++)
    {
        if(listaDePaises[i].id==IdPais)
        {
            retorno=i;
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
    int iPais;

    if(listaDePaises!=NULL && tamPa!=0)
    {
        mostrarPaises(listaDePaises,tamPa);
        pais=pedirEntero("Elija un id de Pais ");
        iPais=buscarPaisId(listaDePaises,tamPa,pais);
        retorno=listaDePaises[iPais];
    }


    return retorno;
}
