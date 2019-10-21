#include <stdio.h>
#include <stdlib.h>
#include "elenco.h"
#define MAX 10
#define MAX_EL 8
#define MAX_P 4
#define MAX_G 4



int main()
{

    eActor listaDeActores[MAX];
    ePelicula listaDePeliculas[MAX_P];
    eElenco listaDeElencos[MAX_EL];
    eGenero listaDeGeneros[MAX_G];
    int opcionG;
    int opcion;

    int respuesta;

    inicializarActores(listaDeActores,MAX);
    inicializarElencos(listaDeElencos,MAX_EL);
    hardcodearPeliculas(listaDePeliculas,4);
    hardCodearGenero(listaDeGeneros,MAX_G);
    hardcodearDatos(listaDeActores,6);
    do
    {
        system("cls");


        opcionG=pedirEntero("1)Gestionar Actores\n2)gestionar Elenco\n3)Salir \nSeleccion una opcion: ");
        switch(opcionG)
        {
        case 1:
            do
            {
                opcion = pedirCaracter("\nA.Alta\nB.Modificar\nC.Baja\nD.Informar\nE.Salir\nElija una opcion: ");
                switch(opcion)
                {
                case 'a':
                    system("cls");
                    respuesta= cargarActores(listaDeActores,MAX);

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
                    respuesta=borrarActor(listaDeActores,MAX);
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

                    respuesta= modificarActor(listaDeActores,MAX);
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

                    respuesta=informarActor(listaDeActores,MAX);
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
                opcion = pedirCaracter("\nA.Cargar Elenco\nB.Listar elenco\nC.Salir\nElija una opcion: ");
                switch(opcion)
                {
                case 'a':
                    cargarElenco(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G);
                    break;
                case 'b':
                    ordenarElenco(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P);
                    listarElencos(listaDeElencos,MAX_EL,listaDeActores,MAX,listaDePeliculas,MAX_P,listaDeGeneros,MAX_G);
                    break;
                case 'c':
                    printf("Saliendo");
                    break;
                default:
                    printf("Error, ingrese una opcion valida");

                }
            }
            while(opcion!='c');
            break;
        case 3:
            printf("saliendo");
            break;
        default:
            printf("Opcion incorrecta");
            system("pause");
            break;
        }
    }
    while(opcion!=3);

    return 0;
}


