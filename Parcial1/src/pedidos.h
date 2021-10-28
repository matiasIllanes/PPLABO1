
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "clientes.h"

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


/// @brief busca un id con isEmpty=1 devolviendo su indice
/// @param array array pedido
/// @param tam tamanio pedido
/// @return devuelve indice encontrado
int ePedido_buscarLibre(ePedido array[], int tam);

/// @brief inicializa todos los isEmpty del array en 1
/// @param array array pedido
/// @param tam tamanio pedido
void ePedido_inicializarArray(ePedido array[], int tam);

/// @brief Asigna un Numero inicializado en la variable estadica
/// @return Devuelve el numero incrementado en 1
int ePedido_obtenerId();

/// @brief da de alta un pedido
/// @param arrayPedido array de pedido
/// @param tamPedido tamanio de pedido
/// @param arrayCliente array de cliente
/// @param tamCliente tamanio de cliente
/// @return devuelve 1 si el alta es valida
int ePedido_altaRecoleccion(ePedido arrayPedido[], int tamPedido, eCliente arrayCliente[], int tamCliente);

/// @brief Clasifica el pedido segun tipo de plastico y cambia su estado a procesado (estado =1)
/// @param arrayPedido array de pedido
/// @param tamPedido tamanio de pedido
/// @return  retorna 1 si el pedido fue clasificado con exito
int ePedido_clasificar(ePedido arrayPedido[], int tamPedido);

/// @brief busca el indice de un id ingresado por el usuario
/// @param arrayPedido array pedido
/// @param tamPedido tamanio del array pedido
/// @param idPedido id del pedido ingresado x el usuario
/// @return retorna -1 si no encuentra ningun id
int ePedido_buscarId(ePedido arrayPedido[], int tamPedido, int idPedido);

/// @brief busca si el pedido elegido (segun indice ingresado) esta pendiente
/// @param array array de pedido
/// @param tam tamanio de pedido
/// @param index indice del array donde se aplica la funcion
/// @return retorna -1 en caso que el pedido no este pendiente, retorna el indice en caso que sea pendiente
int ePedido_buscarPendiente(ePedido array[], int tam, int index);


/// @brief busca si el pedido elegido (segun indice ingresado) esta completado
/// @param array array del pedido
/// @param tam tamanio del pedido
/// @param index indice del array donde se aplica la funcion
/// @return retorna -1 en caso que el pedido no este completado, retorna el indice en caso que sea completado
int ePedido_buscarCompletado(ePedido array[], int tam, int index);

#endif /* PEDIDOS_H_ */
