#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int ID_Llamada;
    char fecha[51];
    int numeroCliente;
    int ID_Problema;
    char Solucionado[4];
}eCliente;
eCliente* Cliente_new();
eCliente* Cliente_newParametros(char* ID_Llamada,char* fecha,char* numeroCliente, char* ID_Problema,char* Solucionado);
int getID_Llamada(eCliente* lista,int* ID_Llamada);
int setID_Llamada(eCliente* lista,int ID_LLamada);
int getFecha(eCliente* lista,char* fecha);
int setFecha(eCliente* lista,char* fecha);
int getNumeroCliente(eCliente* lista,int* numeroCliente);
int setNumeroCliente(eCliente* lista,int numeroCliente);
int setID_Problema(eCliente* lista,int ID_Problema);
int getID_Problema(eCliente* lista,int* ID_Problema);
int setSolucionado(eCliente* lista,char* solucionado);
int getSolucionado(eCliente* lista,char* solucionado);
void deleteCliente(eCliente* unCliente);
int mostrarUnCliente(eCliente* unCliente);
int compararPorIdProblema(void* p1,void* p2);
