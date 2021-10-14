#include "pedidos.h"
#include "clientes.h"
#include "localidad.h"

#ifndef INFORMES_H_
#define INFORMES_H_

void mostrarClientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
int mostrarPedidosPendientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
int mostrarPedidosCompletados(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
void mostrarTodo(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
void pedidosPorLocalidad(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
void ppPromedio(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);



#endif /* INFORMES_H_ */
