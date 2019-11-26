#include "Problemas.h"

int setID_LLamada(eCliente* lista,int id)
{
    int todoOk = 0;

    if( lista != NULL && id > 0)
    {

        lista->ID_Llamada= id;
        todoOk = 1;
    }

    return todoOk;
}

int getID_Llamada(eCliente* lista,int* ID_Llamada)
{
    int todoOk = 0;
    if( lista != NULL && ID_Llamada !=NULL)
    {

       *ID_Llamada = lista->ID_Llamada;
        todoOk = 1;
    }

    return todoOk;
}



int setFecha(eCliente* lista,char* fecha)
{
    int todoOk = 0;

    if( lista != NULL && fecha != NULL)
    {

        strcpy(lista->fecha, fecha);
        todoOk = 1;
    }

    return todoOk;
}

int getFecha(eCliente* lista,char* fecha)
{
    int todoOk = 0;

    if( lista != NULL && fecha != NULL)
    {

        strcpy(fecha,lista->fecha);
        todoOk = 1;
    }

    return todoOk;
}

int setNumeroCliente(eCliente* lista,int id)
{
       int todoOk = 0;

    if( lista != NULL)
    {

        lista->numeroCliente=id;
        todoOk = 1;
    }

    return todoOk;
}

int getNumeroCliente(eCliente* lista,int* id)
{
       int todoOk = 0;

    if( lista != NULL && id != NULL)
    {

        *id=lista->numeroCliente;
        todoOk = 1;
    }

    return todoOk;
}
int setID_Problema(eCliente* lista,int id)
{
        int todoOk = 0;

    if( lista != NULL)
    {

        lista->ID_Problema=id;
        todoOk = 1;
    }
    return todoOk;
}
int getID_Problema(eCliente* lista,int* id)
{
        int todoOk = 0;

    if( lista != NULL && id != NULL)
    {

        *id= lista->ID_Problema;
        todoOk = 1;
    }
    return todoOk;
}

int setSolucionado(eCliente* lista,char* solucionado)
{
       int todoOk = 0;

    if( lista != NULL)
    {

        strcpy(lista->Solucionado,solucionado);
        todoOk = 1;
    }
    return todoOk;
}
int getSolucionado(eCliente* lista,char* solucionado)
{
       int todoOk = 0;

    if( lista != NULL && solucionado != NULL)
    {

        strcpy(solucionado,lista->Solucionado);
        todoOk = 1;
    }
    return todoOk;
}

eCliente* Cliente_new()
{

    eCliente* lista = (eCliente*) malloc(sizeof(eCliente));

    if( lista != NULL)
    {
        setID_LLamada(lista,0);
        setFecha(lista,"");
        setID_Problema(lista,0);
        setNumeroCliente(lista,0);
        setSolucionado(lista,0);
    }

    return lista;
}
eCliente* Cliente_newParametros(char* ID_Llamada,char* fecha,char* numeroCliente, char* ID_Problema,char* Solucionado)
{

    eCliente* lista;

    if (ID_Llamada != NULL && fecha != NULL && numeroCliente != NULL && ID_Problema != NULL && Solucionado != NULL)
    {
        lista  = Cliente_new();

        if( lista != NULL)
        {

            if( !setID_LLamada(lista, atoi(ID_Llamada))||

                    !setFecha(lista, fecha) ||

                    !setNumeroCliente(lista, atoi(numeroCliente)) ||

                    !setID_Problema(lista, atoi(ID_Problema)) ||

                    !setSolucionado(lista,Solucionado))
            {
                free(lista);
                lista = NULL;
            }
        }
    }

    return lista;
}

void deleteCliente(eCliente* unCliente)
{

    free(unCliente);
    unCliente=NULL;

}

int mostrarUnCliente(eCliente* unCliente)
{
   int retorno=-1;

    if(unCliente!= NULL)
    {
        printf("%4d", unCliente->ID_Llamada);
        printf("%18s",unCliente->fecha);
        printf("%20d",unCliente->numeroCliente);
        printf("%20d",unCliente->ID_Problema);
        printf("%25s\n",unCliente->Solucionado);
        retorno = 0;
    }
   return retorno;
}

int compararPorIdProblema(void* p1,void* p2)
{
    int compara=-1;
    int idProblema1;
    int idProblema2;

    eCliente* cliente1 = (eCliente*)p1;
    eCliente* cliente2 = (eCliente*)p2; //estos dos empleados van a servir para guardar e1,e2
    getID_Problema(cliente1,&idProblema1);
    getID_Problema(cliente2,&idProblema2);
    if( idProblema1 > idProblema2 ) //si el primero es mayor al segundo
    {
        compara = 1;
    }
    else
    {
        if(idProblema1  == idProblema2 )
        {
            compara = 0;
        }
    }
    return compara;
}




