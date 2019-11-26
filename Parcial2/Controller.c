#include "Controller.h"



int controller_loadFromText(char* path, LinkedList* pArrayListCliente)
{
    FILE* pArchivo;
    int retorno=-1;
    int estaVacio=0;
    pArchivo = fopen(path,"rb");

    if(pArchivo!=NULL)
    {
        estaVacio=ll_isEmpty(pArrayListCliente);
        if(estaVacio==1)
        {
            retorno=parser_ClienteFromText(pArchivo,pArrayListCliente);

        }
        else
        {
            retorno=2;
        }
    }
    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListCliente)
{
    FILE* pArchivo;
    int retorno=-1;
    int estaVacio=0;
    pArchivo=fopen(path,"rb");

    if(pArchivo!= NULL && pArrayListCliente !=NULL)
    {
        estaVacio=ll_isEmpty(pArrayListCliente);
        if(estaVacio==1)
        {
            retorno=parser_ClienteFromBinary(pArchivo,pArrayListCliente);
        }
        else
        {
            retorno=2;
        }
    }

    return retorno;
}

int controller_listarClientes (LinkedList* pListaClientes)
{
    int retorno = -1;
    int i;
    int len;
    int estaVacio = 0;

    if(pListaClientes != NULL)
    {
        retorno = 0;
        estaVacio = ll_isEmpty(pListaClientes);
        if(estaVacio!= 1)
        {
            len = ll_len(pListaClientes);
            eCliente* auxCliente;
            printf("%4s%20s%20s%22s%25s\n","Id Llamada:", "Fecha:", "Numero del Cliente:","Id Problema:","Esta solucionado:");
            for(i=0; i<len; i++)
            {
                auxCliente= (eCliente*) ll_get(pListaClientes, i);
                mostrarUnCliente(auxCliente);

            }
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListCliente)
{
    int retorno=-1;
    FILE* pArchivo;
    eCliente* unCliente;
    int i;
    int len;
    pArchivo=fopen(path,"w");
    int ID_Llamada;
    char fecha[21];
    int numeroCliente;
    int ID_Problema;
    char solucionado[21];
    if(pArchivo!=NULL && pArrayListCliente != NULL)
    {
        len=ll_len(pArrayListCliente);
        fprintf(pArchivo,"%s,%s,%s,%s,%s\n","Id Llamada","fecha","Numero Cliente","Id Problema","Solucionado\n");

        for(i=0; i<len; i++)
        {
            unCliente =(eCliente*)ll_get(pArrayListCliente,i);
            getID_Llamada(unCliente,&ID_Llamada);
            getFecha(unCliente,fecha);
            getNumeroCliente(unCliente,&numeroCliente);
            getID_Problema(unCliente,&ID_Problema);
            getSolucionado(unCliente,solucionado);
            fprintf(pArchivo,"%d,%s,%d,%d,%s\n",ID_Problema,fecha,numeroCliente,ID_Problema,solucionado);

        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListCliente)
{
    FILE* pArchivo;

    int retorno=-1;
    eCliente* unCliente;
    int len;
    int i;
    pArchivo=fopen(path,"wb");

    if(pArrayListCliente!=NULL && pArchivo !=NULL)
    {
        len=ll_len(pArrayListCliente);
        for(i=0; i<len; i++)
        {
            unCliente=(eCliente*)ll_get(pArrayListCliente,i);
            fwrite(unCliente,sizeof(eCliente),1,pArchivo);
        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

int filtrarPorIdUno(void* pCliente)
{
    int retorno = -1;
    eCliente* unCliente = pCliente;

    if(unCliente != NULL)
    {
        retorno = 1;

        if(unCliente->ID_Problema == 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorIdDos(void* pCliente)
{
    int retorno = -1;
    eCliente* unCliente = pCliente;

    if(unCliente != NULL)
    {
        retorno = 1;

        if(unCliente->ID_Problema == 2)
        {
            retorno = 0;
        }
    }
    return retorno;
}



int filtrarPorIdTres(void* pCliente)
{
    int retorno = -1;
    eCliente* unCliente = pCliente;

    if(unCliente != NULL)
    {
        retorno = 1;

        if(unCliente->ID_Problema == 3)
        {
            retorno = 0;
        }
    }
    return retorno;
}



int filtrarPorIdCuatro(void* pCliente)
{
    int retorno = -1;
    eCliente* unCliente = pCliente;

    if(unCliente != NULL)
    {
        retorno = 1;

        if(unCliente->ID_Problema == 4)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorIdCinco(void* pCliente)
{
    int retorno = -1;
    eCliente* unCliente = pCliente;

    if(unCliente != NULL)
    {
        retorno = 1;

        if(unCliente->ID_Problema == 5)
        {
            retorno = 0;
        }
    }

    return retorno;
}

