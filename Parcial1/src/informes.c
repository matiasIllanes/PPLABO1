#include "informes.h"
#include <string.h>

void mostrarClientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido)
{
	int i;
	int j;
	int contPendientes = 0;

	printf("ID         CLIENTE                           CUIT                      DIRECCION              LOCALIDAD         PEDIDOS PENDIENTES\n");
	for(i = 0 ;i < tamCliente; i++){
			for(j = 0;j < tamPedido;j++)
			{
				if(arrayCliente[i].idEmpresa == arrayPedido[j].idEmpresa && arrayPedido[j].isEmpty==0 && arrayPedido[j].estado==0)
				{
					contPendientes++;
				}
			}
			arrayPedido[i].idEmpresa = arrayCliente[i].idEmpresa;

			printf("%-8d %-40s %-20s %-20s %-20s %-20d\n", arrayCliente[i].idEmpresa,
														   arrayCliente[i].empresa,
														   arrayCliente[i].cuit,
														   arrayCliente[i].direccion,
														   arrayCliente[i].localidad,
														   contPendientes);

			contPendientes = 0;

		}


}


void mostrarTodo(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;

	for(i=0; i<tamPedido;i++){
		for(j=0; j<tamCliente; j++){
			if(arrayCliente[j].idEmpresa == arrayPedido[i].idEmpresa){
				printf("%-6d %-15s %-15s      pedido nro:%d    estado:%d    tot:%.1f    hdpe:%.1f  ldpe:%.1f   pp:%.1f\n", arrayCliente[j].idEmpresa,
						   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	  arrayCliente[j].empresa,
																															  arrayCliente[j].cuit,
																															  arrayPedido[i].idPedido,
																															  arrayPedido[i].estado,
																															  arrayPedido[i].plasticoTotal,
																															  arrayPedido[i].hdpe,
																															  arrayPedido[i].ldpe,
																															  arrayPedido[i].pp);
				break;
			}
		}
	}
}




int mostrarPedidosPendientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int flag=-1;
	int retorno = 0;
	for(i=0;i<tamPedido;i++){
		if(ePedido_buscarPendiente(arrayPedido, tamPedido, i) != -1){
			flag=0;
			break;
		}
	}

	if(flag != -1){
		printf("\nID PEDIDO  CUIT                      DIRECCION            CANTIDAD A RECOLECTAR\n");
		for(i=0;i<tamPedido;i++){
			if(arrayPedido[i].estado==0 && arrayPedido[i].isEmpty==0){
				for(j=0;j<tamCliente;j++){
					if(arrayCliente[j].idEmpresa == arrayPedido[i].idEmpresa){
						printf("%-10d %-25s %-20s %-20.1f\n", arrayPedido[i].idPedido, arrayCliente[j].cuit, arrayCliente[j].direccion, arrayPedido[i].plasticoTotal);
						retorno =1;
					}
				}
			}
		}
	}

	return retorno;
}


int mostrarPedidosCompletados(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int flag=-1;
	int retorno = 0;
	for(i=0;i<tamPedido;i++){
		if(ePedido_buscarCompletado(arrayPedido, tamPedido, i) != -1){
			flag=0;
			break;
		}
	}
	if(flag != -1){
		printf("\nID PEDIDO  CUIT                      DIRECCION            HDPE(Kg)             LDPE(Kg)   PP(Kg)\n");
		for(i=0;i<tamPedido;i++){
			if(arrayPedido[i].estado==1 && arrayPedido[i].isEmpty==0){
				for(j=0;j<tamCliente;j++){
					if(arrayCliente[j].idEmpresa == arrayPedido[i].idEmpresa){
						printf("%-10d %-25s %-20s %-20.1f %-10.1f %-10.1f\n", arrayPedido[i].idPedido, arrayCliente[j].cuit, arrayCliente[j].direccion, arrayPedido[i].hdpe, arrayPedido[i].ldpe, arrayPedido[i].pp);
						retorno =1;
					}
				}
			}
		}
	}

	return retorno;
}



void pedidosPorLocalidad(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int contPendientes=0;
	char localidadIngresada[TEXT_SIZE];



		getString(localidadIngresada, "Ingrese una localidad: ", TEXT_SIZE);
		for(i=0;i<tamCliente;i++){


			if(stricmp(localidadIngresada, arrayCliente[i].localidad)==0){

				for(j=0;j<tamPedido;j++){

					if(arrayCliente[i].idEmpresa == arrayPedido[j].idEmpresa && arrayPedido[j].estado==0){
						contPendientes++;

					}
				}

			}
		printf("La localidad %s tiene %d pedidos pendientes.\n", localidadIngresada, contPendientes);
		}
}


void ppPromedio(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	float promedio;
	float acumpp=0;
	int contClientes=0;

	for(i=0;i<tamCliente;i++){
		if(arrayCliente[i].isEmpty==0){
			contClientes++;
		}
		for(j=0;j<tamPedido;j++){
			if(arrayPedido[j].isEmpty==0 && arrayPedido[j].estado==1 && arrayCliente[i].idEmpresa == arrayPedido[j].idEmpresa){
				acumpp = acumpp + arrayPedido[j].pp;

			}
		}
	}
	promedio = acumpp/contClientes;
	printf("El promedio de PP por cliente es: %.2f\n", promedio);
}


