typedef struct
{
    int ID_Llamada;
    char fecha[51];
    int numeroCliente;
    int ID_Problema;
    int Solucionado;
}eCliente;
eCliente newCliente();
int getID_LLamada(eCliente* lista,int id);
int setID_Llamada(eCliente* lista,int* id);
int getFecha(eCliente* lista,int id);
int setFecha(eCliente* lista,int id);
int getNumeroCliente(eCliente* lista,int id);
int setNumeroCliente(eCliente* lista,int id);
int setID_Problema(eCliente* lista,int id);
int getID_Problema(eCliente* lista,int id);
