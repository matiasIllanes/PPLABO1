#ifndef INFORMES_H_
#define INFORMES_H_
#include "pedidos.h"
#include "clientes.h"

/// @brief imprime lista de clientes con pedidos pendientes junto a todos sus datos
/// @param arrayCliente array cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio de pedido
/// @param arrayLocalidad array localidad
/// @param tamLocalidad tamanio localidad
/// @return retorna 0 si NO hay clientes ingresados y retorna 1 si hay clientes ingresados
int mostrarClientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido, eLocalidad arrayLocalidad[], int tamLocalidad);

/// @brief muestra todos los pedidos pendientes con la cantidad de plastica a retirar, y cuit y direccion del cliente
/// @param arrayCliente array cliente
/// @param tamCliente tamanio cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio pedido
/// @return retorna 0 si no hay pedidos pendientes
int mostrarPedidosPendientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);

/// @briefmuestra listado de pedidos procesados junto con la clasificacion de plasticos procesados
/// @param arrayCliente array de cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio pedido
/// @return retorna 0 si no hay pedidos procesados
int mostrarPedidosCompletados(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);

/// @brief
/// @param arrayCliente
/// @param tamCliente
/// @param arrayPedido
/// @param tamPedido


/// @brief muestra cantidad de pedidos pendientes segun la localidad ingresada
/// @param arrayCliente array cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio pedido
/// @param arrayLocalidad array localidad
/// @param tamLocalidad tamanio localidad
void pedidosPorLocalidad(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido, eLocalidad arrayLocalidad[], int tamLocalidad);

/// @brief Muestra la cantidad de Kg de plastico promedio de PP recicalada por cliente
/// @param arrayCliente array de cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array de pedido
/// @param tamPedido tamanio de pedido
void ppPromedio(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);


/// @brief Muestra el cliente que tiene mayor cantidad de pedidos pendientes
/// @param arrayCliente array cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio de pedido
void clienteMasPendientes(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);

/// @brief Muestra el cliente que tiene mayor cantidad de pedidos procesados
/// @param arrayCliente array cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio de pedido
void clienteMasProcesados(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);

/// @brief Muestra el cliente que tiene mayor cantidad de pedidos
/// @param arrayCliente array cliente
/// @param tamCliente tamanio de cliente
/// @param arrayPedido array pedido
/// @param tamPedido tamanio de pedido
void clienteMasPedidos(eCliente arrayCliente[], int tamCliente, ePedido arrayPedido[], int tamPedido);
#endif /* INFORMES_H_ */
