
#include "Controller.h"

/** Cosas que cambiar: Agregar bibliteca pedir datos, Cambiar clientes por llamada*/
int main()
{
    LinkedList* listaDeLlamadas = ll_newLinkedList();
    LinkedList* listaDeLlamadasFiltradas = ll_newLinkedList();

    int opcion;

    char opcion_continuarFiltrado = 's';
    int opcionFiltrar;
    int retorno;

    if(listaDeLlamadas != NULL)
    {
        do
        {
            system("cls");
            opcion = getInt("MENU DE LLAMADAS:\nIngrese una opcion:\n1.Cargar archivo.\n2.Imprimir llamadas.\n3.Generar archivo de llamadas.\n4.Salir\n");
            switch(opcion)
            {
                case 1:
                    retorno = controller_loadFromText("llamadas.txt", listaDeLlamadas);
                    retorno = controller_loadFromBinary("listaLlamadas.bin", listaDeLlamadas);
                    switch(retorno)
                    {
                    case -1:
                        printf("No se pudieron cargar los datos.");
                        break;
                    case 0:
                        printf("Se cargaron los datos.");
                        break;
                    case 1:
                        printf("La lista es nula.");
                        break;
                    case 2:
                        printf("La lista ya esta cargada");
                        break;
                    }
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    controller_listarClientes(listaDeLlamadas);
                    printf("\n");
                    system("pause");
                    break;
                case 3:
                    do
                    {printf("MENU DE FILTROS\n");
                    printf("1.Llamadas del problema 1.\n");
                    printf("2.Llamadas del problema 2.\n");
                    printf("3.Llamadas del problema 3.\n");
                    printf("4.Llamadas del problema 4.\n");
                    printf("5.Llamadas del problema 5.\n");
                    printf("6.Salir del submenu.\n");
                    opcionFiltrar = getInt("Elija una opcion para crear una lista de llamadas filtradas: ");
                    switch(opcionFiltrar)
                    {
                    case 1:
                        ll_clear(listaDeLlamadasFiltradas);
                        listaDeLlamadasFiltradas = ll_filter(listaDeLlamadas, filtrarPorIdUno);
                        controller_saveAsText("llamadasFiltradasUno.txt", listaDeLlamadasFiltradas);
                        break;
                    case 2:
                        ll_clear(listaDeLlamadasFiltradas);
                        listaDeLlamadasFiltradas = ll_filter(listaDeLlamadas, filtrarPorIdDos);
                        controller_listarClientes(listaDeLlamadasFiltradas);
                        system("pause");
                        controller_saveAsText("llamadasFiltradasDos.txt", listaDeLlamadasFiltradas);
                        break;
                    case 3:
                        ll_clear(listaDeLlamadasFiltradas);
                        listaDeLlamadasFiltradas = ll_filter(listaDeLlamadas, filtrarPorIdTres);
                        controller_saveAsText("llamadasFiltradasTres.txt", listaDeLlamadasFiltradas);
                        break;
                    case 4:
                        ll_clear(listaDeLlamadasFiltradas);
                        listaDeLlamadasFiltradas = ll_filter(listaDeLlamadas, filtrarPorIdCuatro);
                        controller_saveAsText("llamadasFiltradasCuatro.txt", listaDeLlamadasFiltradas);
                        break;
                    case 5:
                        ll_clear(listaDeLlamadasFiltradas);
                        listaDeLlamadasFiltradas = ll_filter(listaDeLlamadas, filtrarPorIdCinco);
                        controller_saveAsText("llamadasFiltradasCinco.txt", listaDeLlamadasFiltradas);
                        break;
                    case 6:
                        opcion_continuarFiltrado = 'n';
                        break;
                    }
                    }while(opcion_continuarFiltrado != 'n');
                    break;
                case 4:

                    controller_saveAsBinary("listaLlamadas.bin", listaDeLlamadas);
                    controller_saveAsText("listaLlamadas.cvs", listaDeLlamadas);
                    printf("\n");
                    system("pause");
                    break;
            }


        }
        while(opcion != 4);
    }

    return 0;
}

