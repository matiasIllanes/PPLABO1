#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"
#include "localidad.h"



#define MAXCLIENTES 100
#define MAXPEDIDOS 1000
#define MAXLOCALIDADES 4

int main(void){
	setbuf(stdout, NULL);

	int option;


	eCliente cliente[MAXCLIENTES];
	ePedido pedido[MAXPEDIDOS];

	eCliente_inicializarArray(cliente, MAXCLIENTES);
	ePedido_inicializarArray(pedido, MAXPEDIDOS);


	eLocalidad localidades[MAXLOCALIDADES] = {{1, "Gerli", 0},
    										  {2, "Sarandi", 0},
    										  {3, "Villa Dominico", 0},
    										  {4, "Wilde", 0}
    										 };



	do{


		printf( "1- Alta de cliente\n"
				"2- Modificar datos de cliente\n"
				"3- Baja de cliente\n"
				"4- Crear pedido de recoleccion\n"
				"5- Procesar residuos\n"
				"6- Imprimir clientes\n"
				"7- Imprimir pedidos pendientes\n"
				"8- Imprimir pedidos procesado\n"
				"9- Ingresar localidad y cantidad de pedidos pendientes\n"
				"10- Cantidad de de kilos de polipropileno reclicado promedio por cliente\n"
				"11- PARTE 2 - Cliente con mas Pedidos Pendientes\n"
				"12- PARTE 2 - Cliente con mas Pedidos Completados\n"
				"13- PARTE 2 - Cliente con mas pedidos\n"
				"14- Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch(option){
		case 1:
			eCliente_alta(cliente, MAXCLIENTES, localidades, MAXLOCALIDADES);
			system("pause");
			break;

		case 2:
			eCliente_modificarCliente(cliente, MAXCLIENTES, localidades, MAXLOCALIDADES);
			system("pause");
			break;

		case 3:
			eCliente_baja(cliente, MAXCLIENTES);
			system("pause");
			break;

		case 4:
			if(ePedido_altaRecoleccion(pedido, MAXPEDIDOS, cliente, MAXCLIENTES)==1){
				printf("\n La solicitud se genero con exito.");
			}
			else{
				printf("\n No hay mas espacio para almacenar pedidos.\n");
			}
			system("pause");
			break;
		case 5:
			ePedido_clasificar(pedido, MAXPEDIDOS);
			system("pause");
			break;
		case 6:

			if(mostrarClientes(cliente, MAXCLIENTES, pedido, MAXPEDIDOS, localidades, MAXLOCALIDADES)==0){
				printf("NO HAY CLIENTES INGRESADOS.\n");
			}

			system("pause");
			break;
		case 7:
			if((mostrarPedidosPendientes(cliente, MAXCLIENTES, pedido, MAXPEDIDOS)==0)){
				printf("No hay pedidos pendientes\n");
			}
			system("pause");
			break;
		case 8:
			if((mostrarPedidosCompletados(cliente, MAXCLIENTES, pedido, MAXPEDIDOS)==0)){
				printf("No hay pedidos completados\n");
			}

			system("pause");
			break;

		case 9:
			pedidosPorLocalidad(cliente, MAXCLIENTES, pedido, MAXPEDIDOS, localidades, MAXLOCALIDADES);
			system("pause");
			break;

		case 10:
			ppPromedio(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			system("pause");
			break;
		case 11:
			clienteMasPendientes(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			system("pause");
			break;

		case 12:
			clienteMasProcesados(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			system("pause");
			break;

		case 13:
			clienteMasPedidos(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			system("pause");
			break;
		default:
			printf("Ingrese una opcion valida\n");
			break;
		}
	}while(option!=14);

	return 0;
}
