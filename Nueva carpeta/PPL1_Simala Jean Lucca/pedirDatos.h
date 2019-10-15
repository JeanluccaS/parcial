#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/** \brief funcion utilizada para pedir una cadena de caracteres
 *
 * \param char mensaje de peticion
 * \param char array donde se va a guardar la cadena de caracteres
 * \return void
 *
 */
void pedirString (char mensaje[],char contenido[],char mensajeDeError[]);
/** \brief funcion utilizada para pedir un numero entero
 *
 * \param char mensaje de peticion
 * \return int el numero ingresado
 *
 */
int pedirEntero (char mensaje[]);
/** \brief funcion utilizada para pedir un caracter
 *
 * \param char mensaje de peticion
 * \return int el caracter ingresado
 *
 */
 float pedirFlotante(char mensaje[]);
char pedirCaracter (char mensaje[]);
