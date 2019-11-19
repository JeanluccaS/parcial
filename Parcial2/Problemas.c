eCliente* Cliente_new()
{

    eCliente* lista = (eCliente*) malloc(sizeof(eCliente));

    if( lista != NULL)
    {
        lista->ID_Llamada = 0;
        strcpy(lista->fecha, "");
        lista->numeroCliente=0;
        lista->ID_Problema = 0;
        lista->Solucionado = 0;
    }

    return this;
}
eCliente* Cliente_newParametros(char* ID_Llamada,char* fecha,char* numeroCliente, char* ID_Problema,char* Solucionado)
{

    Employee* this;

    if (ID_Llamada != NULL && fecha != NULL && numeroCliente != NULL && ID_Problema != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(ID_Llamada))||

                    !employee_setNombre(this, fecha) ||

                    !employee_setHorasTrabajadas(this, atoi(numeroCliente)) ||

                    !employee_setSueldo(this, atoi(ID_Problema)) ||

                    !cliente_setSolucion(this,atoi(Solucionado)))
            {
                free(this);
                this = NULL;
            }
        }
    }

    return this;
}

int getID_LLamada(eCliente* lista,int id)
{
    int todoOk = 0;

    if( lista != NULL && id > 0)
    {

        lista->ID_Llamada= id;
        todoOk = 1;
    }

    return todoOk;
}

int setID_Llamada(eCliente* lista,int* id)
{
        int todoOk = 0;

    if( lista != NULL && id !=NULL)
    {

       *id = lista->ID_Llamada;
        todoOk = 1;
    }

    return todoOk;
}



int getFecha(eCliente lista,int id)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
