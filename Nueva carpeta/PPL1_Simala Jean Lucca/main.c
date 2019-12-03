#include <stdio.h>
#include <stdlib.h>
#include "elenco.h"
#define MAX 10
#define MAX_EL 10
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
    int opcionI;
    inicializarActores(listaDeActores,MAX);
    inicializarElencos(listaDeElencos,MAX_EL);
    hardcodearPeliculas(listaDePeliculas,4);
    hardCodearGenero(listaDeGeneros,MAX_G);
    hardcodearDatos(listaDeActores,6);
    hardcodearPais(listaDePaises,MAX_PA);
    hardcodearElenco(listaDeElencos,5);





    do
    {
        system("cls");
        opcionG=pedirEntero("1)Gestionar Actores\n2)Gestionar Elenco\n3)Informes\n4)Salir\nSeleccion una opcion: ");
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
                    else
                    {
                        printf("Actor cargado con exito\n");
                        system("pause");
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
                    printf("Saliendo...\n");
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
                    printf("Saliendo\n");
                    system("pause");
                    break;
                default:
                    printf("Error, ingrese una opcion valida");
                }
            }
            while(opcion!='c');
            break;
        case 3:
            do{
                    system("cls");
            opcionI=pedirEntero("1)Mostrar Peliculas de Terror cuyo anio de estreno sea superior al 2002.\n2)Peliculas donde haya participado un actor argentino.\n3)Elejir un actor y mostrar sus peliculas.\n4)Elejir un actor y mostrar cuanto recaudo en total haciendo pelicuals romanticas.\n5)Listar los actores que no participaron en una pelicula.\n6Salir.\nElija una opcion: ");
            switch(opcionI)
            {
            case 1:
                respuesta=listarPeliculasTerror(listaDeElencos,MAX_EL,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G,listaDeActores,MAX);
                if(respuesta!=-1)
                {
                    system("pause");
                    system("cls");
                    printf("Se han podido listar las peliculas correctamente.\n");
                    system("pause");

                }
                else
                {
                    system("pause");
                    system("cls");
                    printf("Error, no se pudieron listar las peliculas\n");
                    system("pause");
                }
                break;
            case 2:
                respuesta=listarActoresArgentinos(listaDeElencos,MAX_EL,listaDePeliculas,MAX_P,listaDeActores,MAX,listaDePaises,MAX_PA,listaDeGeneros,MAX_G);
                if(respuesta!=-1)
                {
                    system("pause");
                    system("cls");
                    printf("Se han podido listar las peliculas correctamente\n");
                    system("pause");

                }
                else
                {
                    system("pause");
                    system("cls");
                    printf("Error, no se pudieron listar las peliculas\n");
                    system("pause");
                }
                break;

            case 3:
                respuesta=listarPeliculasDeActorSeleccionado(listaDeElencos,MAX_EL,listaDePeliculas,MAX_P,listaDeActores,MAX,listaDeGeneros,MAX_G,listaDePaises,MAX_PA);
                if(respuesta!=-1)
                {
                    system("pause");
                    system("cls");
                    printf("Se han podido listar las peliculas correctamente\n");
                    system("pause");
                }
                else if(respuesta==1)
                {
                    system("pause");
                    system("cls");
                    printf("El actor seleccionado no realizo ninguna pelicula\n");
                    system("pause");

                }
                else
                {
                    system("pause");
                    printf("Error, no se pudieron listar las peliculas\n");
                    system("pause");
                }
                break;
            case 4:
                respuesta=recaudacionDePeliculasRomanticas(listaDeElencos,MAX_EL,listaDePeliculas,MAX_P,listaDeActores,MAX,listaDeGeneros,MAX_G,listaDePaises,MAX_PA);
                if(respuesta!=0)
                {
                    system("cls");
                    printf("El actor recaudo: $%d en peliculas Romanticas\n",respuesta);
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("El actor recaudo: $%d en peliculas Romanticas\n",respuesta);
                    system("pause");
                }
                break;

            case 5:
                respuesta=listarActorSinPeliculas(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePaises,MAX_PA);
                if(respuesta!=-1)
                {
                        printf("Se han podido listar los actores correctamente\n");
                        system("pause");
                }
                else if(respuesta==1)
                {
                    printf("todos los actores partician por lo menos en una pelicula\n");
                }else
                {
                        printf("Error, no se pudo listar correctamente");
                }
                break;
            case 6:
                printf("saliendo");
                break;
            default:
                printf("Opcion no valida\n");
                system("pause");
            }
            }while(opcionI!=6);
        case 4:
            printf("saliendo");
            break;

        default:
            printf("Opcion incorrecta\n");
            system("pause");
            break;
        }

    }
    while(opcionG!=4);

    /*
    listarPeliculas(listaDePeliculas,MAX_P,listaDeGeneros,MAX_G);

     ordenarElenco(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P);
     respuesta= listarElencos(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G);*/
    return 0;
}


