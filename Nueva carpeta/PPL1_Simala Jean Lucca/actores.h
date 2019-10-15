#include <string.h>
#include <stdio.h>
#include "pelicula.h"
#include <stdlib.h>


typedef struct{
   int codigo;
   char nombre[51];
   char apellido[51];
   char sexo;
   int estaVacio;// 0 para esta vacio, 1 para cuando esta ocupado

}eActor;


void hardcodearDatos(eActor*,int tam);

/** \brief funcion que incializa el ID y el estado del array de Actores en LIBRE
 *
 * \param eActor* recibe la lista de Actores
 * \param tam int recibe el largo de la lista
 * \return int 0 si se pudo o -1 si no se pudo inicializar el array.
 *
 */
int inicializarActores(eActor*,int tam);

/** \brief muestra todos los Actores siempre y cuando esten ocupando espacio en el array.
 *
 * \param eActor[] recibe la lista de Actores
 * \param tam int recibe el tamaño
 * \return int y retorna 0 si se pudo o -1 si no se pudo listar Actores
 *
 */
int listarActores(eActor[],int tam);
/** \brief muestra un empleado
 *
 * \param eActor recibe un empleado
 * \return void
 *
 */
void mostrarActor(eActor);

/** \brief funcion encargada de devolver el primer indice disponible que no este OCUPADO
 *
 * \param eActor[] recibe el array de Actores
 * \param tam int recibe el tamaño del array
 * \return int -1 si no encontro espacio o retorna el indice disponible.
 *
 */
int dameIndiceLibre(eActor[],int tam);
/** \brief funcion encargada de agregar un empleado al array
 *
 * \param eActor recibe la lista de Actores
 * \param int tam recibe el largo del array
 * \return retorna 0 si se pudo o  -1 no cargar un empleado
 *
 */
int cargarActores (eActor* listaDeActores,int tam);

/** \brief busca un empleado en el array de empelados
 *
 * \param eActor[] el array de Actores
 * \param tam int el tamaño
 * \return int -1 si no se encontro y el indice, en caso de que lo haya encontrado.
 *
 */
int buscarActor(eActor[],int tam);
/** \brief
 *
 * \param eActor[] el array de Actores
 * \param tam int el tamaño
 * \return int -1 si no lo borro y 0, en caso de que lo haya encontrado.
 *
 */
int borrarActor(eActor[],int tam);
/** \brief modifica un empleado
 *
 * \param eActor[] el array de Actores
 * \param tam int el tamaño
 * \return int 0 si se pudo modificar, -1 si no se pudo modificar y 1 si se cancelo la modificacion
 *
 */
int modificarActor(eActor[],int tam);
/** \brief funcion encargada de cargar los datos de un empleado
 *
 * \param eActor* el array de Actores
 * \param tam int el tamao del array
 * \param id int el ID del empleado
 * \param nombre[] char el nombre del empleado
 * \param apellido[] char el apellido del empleado
 * \param salario int el salario de un empleado
 * \param sector int el sector del empleado
 * \return int 0 si se pudo cargar los datos en la estructura o -1 si no pudo.
 *
 */
int cargarActor(eActor* , int tam, int codigo, char nombre[], char apellido[], char sexo);
/** \brief Busca el mayor ID cargado en el array
 *
 * \param eActor el array de Actores de Actores
 * \param int tam el tamaño del array
 * \return El mayor id
 *
 */
int dameMayorCodigo(eActor listaDeActores[],int tam);

int ordenarActores(eActor* listaDeActores,int tam);
int informarActor (eActor* listaDeActores,int tam);

