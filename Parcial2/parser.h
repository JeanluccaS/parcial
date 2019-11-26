#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Problemas.h"

/** \brief Divide los campos de un archivo de texto
 *
 * \param pFile FILE* El archivo
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no dividir los campos
 *
 */
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente);
/** \brief Divide los campos de un archivo binario
 *
 * \param pFile FILE* El archivo
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no dividir los campos
 *
 */
int parser_ClienteFromBinary(FILE* pFile , LinkedList* pArrayListCliente);
