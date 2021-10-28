#include "localidad.h"


void eLocalidad_inicializarArray(eLocalidad array[], int tam){
	int i;
	for(i=0; i<tam; i++){
		array[i].isEmpty=1;
	}
}

void eLocalidad_listarLocalidades(eLocalidad array[], int tam){
	int i;
	printf("ID         LOCALIDAD\n");
	for(i=0;i<tam;i++){
		if(array[i].isEmpty==0){
			printf("%d         %s\n", array[i].idLocalidad, array[i].localidad);
		}
		}
}


