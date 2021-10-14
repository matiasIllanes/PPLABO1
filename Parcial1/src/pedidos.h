#include "clientes.h"

#ifndef PEDIDOS_H_
#define PEDIDOS_H_


typedef struct{
	int idPedido; //PK
	int idEmpresa; //fk
	float plasticoTotal;
	float hdpe;
	float ldpe;
	float pp;
	int estado; //-1 LIBRE 0 PENDIENTE 1 PROCESADO
	int isEmpty;
}ePedido;



int ePedido_buscarLibre(ePedido array[], int tam);
void ePedido_inicializarArray(ePedido array[], int tam);
int ePedido_obtenerId();
int ePedido_altaRecoleccion(ePedido arrayPedido[], int tamPedido, eCliente arrayCliente[], int tamCliente);
int ePedido_clasificar(ePedido arrayPedido[], int tamPedido);
int ePedido_buscarId(ePedido arrayPedido[], int tamPedido, int idPedido);
int ePedido_buscarPendiente(ePedido array[], int tam, int index);
int ePedido_buscarCompletado(ePedido array[], int tam, int index);

#endif /* PEDIDOS_H_ */
