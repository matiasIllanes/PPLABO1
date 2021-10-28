#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define TEXT_SIZE 40
#include "utn.h"

typedef struct {
	int idLocalidad;
	char localidad[TEXT_SIZE];
	int isEmpty;
}eLocalidad;

/// @brief inicializa todos los isEmpty del array en 1
/// @param array array localidad
/// @param tam tamanio de localidad
void eLocalidad_inicializarArray(eLocalidad array[], int tam);

/// @brief muestra lista de localidades hardcodeadas junto su numero de id
/// @param array array de localidad
/// @param tam tamanio de localidad
void eLocalidad_listarLocalidades(eLocalidad array[], int tam);



#endif /* LOCALIDAD_H_ */
