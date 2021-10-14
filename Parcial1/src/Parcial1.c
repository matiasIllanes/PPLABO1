#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"

#define MAXCLIENTES 4
#define MAXPEDIDOS 5

int main(void) {
	setbuf(stdout, NULL);

	int option;


	eCliente cliente[MAXCLIENTES];
	ePedido pedido[MAXPEDIDOS];

	eCliente_inicializarArray(cliente, MAXCLIENTES);
	ePedido_inicializarArray(pedido, MAXPEDIDOS);

/* HARDCODEO PARA PRUEBAS
    eCliente cliente[MAXCLIENTES] = {{1,"Residuos Avellaneda",205,"Mitre 4200","SARANDI",0},
                                         {2,"Residuos Barracas",205,"Alvarado 2500","CABA ",0},
                                         {3,"Residuos Berazategui",205,"Calle 14 540","Berazategui",0},
										 {4,"Residuos Quilmes",205,"Lavalle 200","Quilmes",0}
                                        };

    ePedido pedido[MAXPEDIDOS] =    {{1,1,2000,600,600,500,1,0},  //sarandi
                                     {2,2,1000,400,400,0,1,0},   //caba
                                     {3,3,500,0,0,0,0,0},      //berazategui
                                     {4,2,3000,200,300,2500,1,0},  //caba
                                     {5,1,2000,500,750,100,1,0}    //berazategui
    								};
*/


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
				"11- Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch(option){
		case 1:
			eCliente_alta(cliente, MAXCLIENTES);
			system("pause");
			break;

		case 2:
			eCliente_modificarCliente(cliente, MAXCLIENTES);
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
			mostrarClientes(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
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
			pedidosPorLocalidad(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			system("pause");
			break;

		case 10:
			ppPromedio(cliente, MAXCLIENTES, pedido, MAXPEDIDOS);
			break;
		case 11:
			break;
		}
	}while(option!=11);

	return 0;
}
