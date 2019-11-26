#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
    int retorno=-1;
    char ID_Llamada[21];
    char fecha[21];
    char numeroCliente[21];
    char ID_Problema[21];
    char solucionado[21];

    eCliente* unCliente=NULL;
    if(pFile!=NULL && pArrayListCliente!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Llamada,fecha,numeroCliente,ID_Problema,solucionado);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Llamada,fecha,numeroCliente,ID_Problema,solucionado);

        unCliente=Cliente_newParametros(ID_Llamada,fecha,numeroCliente,ID_Problema,solucionado);
        ll_add(pArrayListCliente,unCliente);
    }
    fclose(pFile);
    retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ClienteFromBinary(FILE* pFile , LinkedList* pArrayListCliente)
{
    int retorno;

    if(pFile != NULL && pArrayListCliente!=NULL)
    {
        while(!feof(pFile))
        {


            eCliente* unCliente;
            unCliente=Cliente_new();
            fread(unCliente,sizeof(eCliente),1,pFile);


            if(feof(pFile))
            {
                break;
            }
            ll_add(pArrayListCliente,unCliente);
        }
        fclose(pFile);
        retorno=1;
    }


    return retorno;
}
