#include <stdio.h>
#include <stdlib.h>
#include "elenco.h"
#define MAX 10
#define MAX_EL 5
#define MAX_P 4
#define MAX_G 4
#define MAX_PA 6


int main()
{
    ePais listaDePaises[MAX_PA];
    eActor listaDeActores[MAX];
    ePelicula listaDePeliculas[MAX_P];
    eElenco listaDeElencos[MAX_EL];
    eGenero listaDeGeneros[MAX_G];
    int opcionG;
    int opcion;
    int respuesta;
    inicializarActores(listaDeActores,MAX);
//    inicializarElencos(listaDeElencos,MAX_EL);
    hardcodearPeliculas(listaDePeliculas,4);
    hardCodearGenero(listaDeGeneros,MAX_G);
    hardcodearDatos(listaDeActores,6);
    hardcodearPais(listaDePaises,MAX_PA);
    hardcodearElenco(listaDeElencos,MAX_EL);






    do
    {
        system("cls");
        opcionG=pedirEntero("1)Gestionar Actores\n2)gestionar Elenco\n3)Salir \nSeleccion una opcion: ");
        switch(opcionG)
        {
        case 1:
            do
            {
                system("cls");
                opcion = pedirCaracter("\nA.Alta\nB.Modificar\nC.Baja\nD.Informar\nE.Salir\nElija una opcion: ");
                switch(opcion)
                {
                case 'a':
                    system("cls");
                    respuesta= cargarActores(listaDeActores,MAX,listaDePaises,MAX_PA);

                    if(respuesta==-1)
                    {
                        printf("No se pudo cargar un nuevo actor");
                        system("pause");
                    }
                    else if(respuesta==1)
                    {
                        printf("No se pudo cargar un nuevo actor sexo no valido");
                        system("pause");
                    }
                    else
                    {
                        printf("Actor cargado con exito\n");
                    }
                    break;
                case 'c':
                    system("cls");
                    respuesta=borrarActor(listaDeActores,MAX,listaDePaises,MAX_PA);
                    if(respuesta==-1)
                    {
                        printf("No se pudo Borrar al Actor");
                        system("pause");
                    }
                    else
                    {
                        printf("Actor borrado con exito");
                        system("pause");
                    }
                    break;
                case 'b':
                    system("cls");
                    respuesta= modificarActor(listaDeActores,MAX,listaDePaises,MAX_PA);
                    if(respuesta==-1)
                    {
                        printf("No se pudo realizar la modificacion");
                        system("pause");
                    }
                    else if(respuesta==1)
                    {
                        printf("Se cancelo la modificacion");
                        system("pause");

                    }
                    else
                    {
                        printf("Modificacion realizada correctamente");
                        system("pause");
                    }
                    break;
                case 'd':
                    system("cls");
                    respuesta=informarActor(listaDeActores,MAX,listaDePaises,MAX_PA);
                    if(respuesta==-1)
                    {
                        printf("no se pueden mostrar los actores");
                        system("pause");
                    }
                    system("pause");
                    break;
                case 'e':
                    system("cls");
                    printf("Saliendo...");
                    system("pause");
                    break;
                default:
                    printf("Opcion incorrecta");
                    system("Pause");
                }
            }
            while(opcion!='e');
            break;
        case 2:
            do
            {
                system("cls");
                opcion = pedirCaracter("\nA.Cargar Elenco\nB.Listar elenco\nC.Salir\nElija una opcion: ");
                switch(opcion)
                {
                case 'a':
                    system("cls");
                    respuesta=cargarElenco(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G,listaDePaises,MAX_PA);
                    if(respuesta==-1)
                    {
                        printf("Error al cargar el elenco\n ");

                    }
                    else if(respuesta==0)
                    {
                        printf("Se cargo el elenco exitosamente\n");

                    }
                    else if(respuesta==1)
                    {
                        printf("Ya existe ese actor en ese elenco\n");
                    }
                    else
                    {
                        printf("No hay espacio disponible, para un nuevo elenco: \n");
                    }
                    system("Pause");
                    break;
                case 'b':
                    system("cls");
                    ordenarElenco(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P);
                    respuesta= listarElencos(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G);
                    if(respuesta==-1)
                    {
                        printf("Error al listar elencos\n");
                    }
                    system("pause");
                    break;
                case 'c':
                    system("cls");
                    printf("Saliendo");
                    break;
                default:
                    printf("Error, ingrese una opcion valida");
                }
            }
            while(opcion!='c');
            break;
        case 3:
            system("cls");
            printf("saliendo\n");
            break;
        default:
            printf("Opcion incorrecta\n");
            system("pause");
            break;
        }
    }
    while(opcion!=3);

    return 0;
}


