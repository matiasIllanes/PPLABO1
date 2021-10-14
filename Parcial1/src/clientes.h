#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define TEXT_SIZE 40



#ifndef CLIENTES_H_
#define CLIENTES_H_



typedef struct{
	int idEmpresa;
	char empresa[TEXT_SIZE];
	char cuit[TEXT_SIZE];
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	int isEmpty;
}eCliente;


void eCliente_alta(eCliente array [], int tam);
void eCliente_inicializarArray(eCliente array[], int tam);
int eCliente_buscarLibre(eCliente array[], int tam);
void eCliente_mostrarUno(eCliente array);
int eCliente_obtenerId();


int eCliente_buscarId(eCliente array[], int tam, int id);
int eCliente_mostrarLista(eCliente array[], int tam);
void eCliente_modificarCliente(eCliente array[], int tam);

int eCliente_baja(eCliente array[], int tam);


#endif /* CLIENTES_H_ */
