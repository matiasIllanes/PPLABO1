#include "pedidos.h"
static int idIncremental=0;


int ePedido_buscarLibre(ePedido array[], int tam){
	int i;
	int index;
	index =-1;


	for(i=0; i<tam; i++){
		if(array[i].isEmpty==1){ // ESTA VACIO
			index = i;
			break;
		}
	}
	return index;
}


void ePedido_inicializarArray(ePedido array[], int tam){
	int i;
	for(i=0; i<tam; i++){
		array[i].isEmpty=1;
		array[i].estado=-1;
	}
}

int ePedido_obtenerId(){
	return idIncremental += 1;
}


int ePedido_altaRecoleccion(ePedido arrayPedido[], int tamPedido, eCliente arrayCliente[], int tamCliente){
	int indexCliente;
	int indexPedido;
	int retorno=0;
	int flag=0;
	int idCliente;



	if(eCliente_mostrarLista(arrayCliente, tamCliente)==1){
		flag = 1;
	}
	if(flag==1){

		idCliente=getInt("Ingrese Numero de cliente para asignar la recoleccion: ");
		indexCliente = eCliente_buscarId(arrayCliente, tamCliente, idCliente);

		while(indexCliente==-1){


			printf("No se encontro el ID. \n");
			idCliente=getInt("Ingrese Numero de cliente para asignar la recoleccion: ");
			indexCliente = eCliente_buscarId(arrayCliente, tamCliente, idCliente);

			}


		indexPedido = ePedido_buscarLibre(arrayPedido, tamPedido);
		if(indexPedido>=0 ){
			arrayPedido[indexPedido].plasticoTotal = getFloat("Ingrese la cantidad de Kg de plastico a retirar: ");
			arrayPedido[indexPedido].idPedido = ePedido_obtenerId();
			arrayPedido[indexPedido].idEmpresa = arrayCliente[indexCliente].idEmpresa;
			arrayPedido[indexPedido].estado = 0;
			arrayPedido[indexPedido].isEmpty=0;

			retorno = 1;
		}
	}

	return retorno;
}

int ePedido_clasificar(ePedido arrayPedido[], int tamPedido){

	int retorno;
	int idPedido;
	int index;
	int i;
	int flag=-1;

	for(i=0;i<tamPedido;i++){
		if(ePedido_buscarPendiente(arrayPedido, tamPedido, i) != -1){
			flag=0;
		}
	}


	if(flag != -1){
		printf("N° PEDIDO PENDIENTE             N° DE CLIENTE\n");


		for(i=0;i<tamPedido;i++){
			index=ePedido_buscarPendiente(arrayPedido, tamPedido, i);
			if(index != -1){
				printf("    %-6d  %27d\n", arrayPedido[index].idPedido, arrayPedido[index].idEmpresa);
			}
		}


		idPedido=getInt("Ingrese Numero de pedido a clasificar: ");
		index = ePedido_buscarId(arrayPedido, tamPedido, idPedido);
		while(arrayPedido[index].estado!=0){
			idPedido=getInt("ERROR. El pedido ingresado no se encuentra pendiente. Ingrese nuevamente: ");
			index = ePedido_buscarId(arrayPedido, tamPedido, idPedido);
		}

		arrayPedido[index].hdpe = getFloat("Ingrese la cantidad de HDPE(kg) obtenido: ");
		arrayPedido[index].ldpe = getFloat("Ingrese la cantidad de LDPE(Kg) obtenido: ");
		arrayPedido[index].pp = getFloat("Ingrese la cantidad de PP(Kg) obtenido: ");
		arrayPedido[index].estado = 1;


		printf("El pedido N° %d fue clasificado con exito\n", arrayPedido[index].idPedido);
		retorno=1;
	}
	else{
		printf("No hay pedidos para ser procesados\n");
	}

return retorno;
}

int ePedido_buscarId(ePedido arrayPedido[], int tamPedido, int idPedido){
	int i;
	int retorno;

	for(i=0; i<tamPedido; i++){
		if(arrayPedido[i].idPedido == idPedido){
			retorno=i;
			break;
		}
		else{
			retorno=-1;
		}
	}
	return retorno;
}


int ePedido_buscarPendiente(ePedido array[], int tam, int index){
	int retorno;
	retorno =-1;

	if(array[index].estado==0){
		retorno = index;
	}
	return retorno;
}

int ePedido_contarPendiente(ePedido arrayPedido[], int tamPedido, int index){
	int i;
	int contadorPendientes=0;

	for(i=0;i<tamPedido;i++){
		if(arrayPedido[i].estado==0){
			contadorPendientes++;
		}
	}
	return contadorPendientes;
}


int ePedido_buscarCompletado(ePedido array[], int tam, int index){
	int retorno;
	retorno =-1;

	if(array[index].estado==1){
		retorno = index;
	}
	return retorno;
}
