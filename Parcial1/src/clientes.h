



#ifndef CLIENTES_H_
#define CLIENTES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "localidad.h"
#define TEXT_SIZE 40


typedef struct{
	int idEmpresa;
	char empresa[TEXT_SIZE];
	char cuit[TEXT_SIZE];
	char direccion[TEXT_SIZE];
	int idLocalidad;
	int isEmpty;
}eCliente;

/// @brief Da de alta un cliente
/// @param array cliente
/// @param tam pedido
/// @param arrayLocalidad array localidad
/// @param tamLocalidad tamanio de localidad
void eCliente_alta(eCliente array[], int tam, eLocalidad arrayLocalidad[], int tamLocalidad);

/// @brief Inicializa todos los isEmpty del array en 1
/// @param array array de cliente
/// @param tam tamanio array de cliente
void eCliente_inicializarArray(eCliente array[], int tam);

/// @brief busca el primer indice del array disponible
/// @param array de cliente
/// @param tam de cliente
/// @return retorna el indice encontrado, si no encuentra lugares disponible retorna -1
int eCliente_buscarLibre(eCliente array[], int tam);

/// @brief  Asigna un Numero inicializado en la variable estadica
/// @return retorna ese numero incrementado
int eCliente_obtenerId();

/// @brief busca el indice que corresponda al id ingresado
/// @param array array de cliente
/// @param tam tamanio de cliente
/// @param id id ingresado por usuario
/// @return retorna indice de dicho id
int eCliente_buscarId(eCliente array[], int tam, int id);

/// @brief muestra lista con algunos datos
/// @param array array de cliente
/// @param tam tamanio de cliente
/// @return retorna 0 si no hay clientes dados de alta, caso contrario retorna 1
int eCliente_mostrarLista(eCliente array[], int tam);

/// @brief modifica direccion y localidad del cliente a partir de un id ingresado
/// @param array array de cliente
/// @param tam tamanio de cliente
/// @param arrayLocalidad array de localidad
/// @param tamLocalidad tamanio de localidad
void eCliente_modificarCliente(eCliente array[], int tam, eLocalidad arrayLocalidad[], int tamLocalidad);


/// @brief da de baja un usuario
/// @param array array de cliente
/// @param tam tamanio de cliente
/// @return retorna 1 si la baja fue efectuada
int eCliente_baja(eCliente array[], int tam);


#endif /* CLIENTES_H_ */
