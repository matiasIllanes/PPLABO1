#include "informes.h"
#include <string.h>

int mostrarClientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido, eLocalidad arrayLocalidad[], int tamLocalidad)
{
	int i;
	int j;
	int k;
	int flag=0;
	int contPendientes = 0;
	char auxLocalidad[40];

	printf("ID         CLIENTE                                 CUIT                DIRECCION            LOCALIDAD         PEDIDOS PENDIENTES\n");
	for(i = 0 ;i < tamCliente; i++){
		if(arrayCliente[i].isEmpty==0){
			for(j = 0;j < tamPedido;j++)
			{
				if(arrayCliente[i].idEmpresa == arrayPedido[j].idEmpresa && arrayPedido[j].isEmpty==0 && arrayPedido[j].estado==0)
				{
					contPendientes++;
				}
			}


			for(k=0; k<tamLocalidad; k++){
				if(arrayCliente[i].idLocalidad == arrayLocalidad[k].idLocalidad){
					strcpy(auxLocalidad, arrayLocalidad[k].localidad);
				}
			}


			printf("%-8d %-40s %-20s %-20s %-20s %-20d\n", arrayCliente[i].idEmpresa,
														   arrayCliente[i].empresa,
														   arrayCliente[i].cuit,
														   arrayCliente[i].direccion,
														   auxLocalidad,
														   contPendientes);

			contPendientes = 0;
			flag=1;

		}

	}
return flag;
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



void pedidosPorLocalidad(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido, eLocalidad arrayLocalidad[], int tamLocalidad){
	int i;
	int j;
	int contPendientes=0;
	int auxId;

	eLocalidad_listarLocalidades(arrayLocalidad, tamLocalidad);
	auxId = getInt("Ingrese ID de la localidad: ");


		for(i=0;i<tamCliente;i++){


			if(auxId == arrayCliente[i].idLocalidad){

				for(j=0;j<tamPedido;j++){
					if(arrayCliente[i].idEmpresa == arrayPedido[j].idEmpresa && arrayPedido[j].estado==0){
						contPendientes++;
					}
				}
			}

		}
	printf("La localidad con ID %d tiene %d pedidos pendientes.\n", auxId, contPendientes);
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

void clienteMasPendientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int acumPendiente=0;
	int mayor=0;
	int flag=0;
	int indexCliente;


	for(i=0;i<tamCliente;i++){
		//if(arrayCliente[i].isEmpty == 0){}															//if arrayCliente.isEmpty=1 =>
		for(j=0;j<tamPedido;j++){
			if(arrayPedido[j].idEmpresa == arrayCliente[i].idEmpresa && arrayPedido[j].estado==0){
				acumPendiente++;
			}
			if(acumPendiente>mayor || flag==0){
				flag=1;
				mayor=acumPendiente;
				indexCliente=i;
			}
		}
		acumPendiente=0;
	}
	printf("\nEl cliente con mas pedidos pendientes es:  %s con  %d pedidos\n", arrayCliente[indexCliente].empresa, mayor);
}

void clienteMasProcesados(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int acumProcesado=0;
	int mayor=0;
	int flag=0;
	int indexCliente;


	for(i=0;i<tamCliente;i++){

		for(j=0;j<tamPedido;j++){
			if(arrayPedido[j].idEmpresa == arrayCliente[i].idEmpresa && arrayPedido[j].estado==1){
				acumProcesado++;
			}
			if(acumProcesado>mayor || flag==0){
				flag=1;
				mayor=acumProcesado;
				indexCliente=i;
			}
		}
		acumProcesado = 0;
	}
	printf("\nEl cliente con mas pedidos procesados es:  %s con  %d pedidos\n", arrayCliente[indexCliente].empresa, mayor);
}

void clienteMasPedidos(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido){
	int i;
	int j;
	int acumPedido=0;
	int mayor=0;
	int flag=0;
	int indexCliente;


	for(i=0;i<tamCliente;i++){

		for(j=0;j<tamPedido;j++){
			if(arrayPedido[j].idEmpresa == arrayCliente[i].idEmpresa && (arrayPedido[j].estado==1 || arrayPedido[j].estado==0) ){
				acumPedido++;
			}
			if(acumPedido>mayor || flag==0){
				flag=1;
				mayor=acumPedido;
				indexCliente=i;
			}
		}
		acumPedido = 0;
	}
	printf("\nEl cliente con mas pedidos (procesados o pendientes) es:  %s con  %d pedidos\n", arrayCliente[indexCliente].empresa, mayor);
}


