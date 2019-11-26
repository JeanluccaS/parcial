#include "parser.h"
int controller_loadFromText(char* path, LinkedList* pArrayListCliente);
int controller_loadFromBinary(char* path, LinkedList* pArrayListCliente);
int controller_saveAsText(char* path, LinkedList* pArrayListCliente);
int controller_saveAsBinary(char* path, LinkedList* pArrayListCliente);
int filtrarPorIdUno(void* pCliente);
int filtrarPorIdDos(void* pCliente);
int filtrarPorIdTres(void* pCliente);
int filtrarPorIdCuatro(void* pCliente);
int filtrarPorIdCinco(void* pCliente);
int controller_listarClientes (LinkedList* pListaClientes); //cambiar en todas las funciones, Clientes/Cliente por "llamada/s"
