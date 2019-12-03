#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char descripcion[51];
}ePais;

void hardcodearPais(ePais* listaDePaises,int tamPa);
void mostrarPaises(ePais* listaDePaises,int tamPa);
void mostrarUnPais(ePais unPais);
ePais buscarPaisId(ePais* listaDePaises,int tamPa,int IdPais);
ePais elejirPais(ePais* listaDePaises,int tamPa);
