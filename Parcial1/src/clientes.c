
static int idIncremental=0;



#include "clientes.h"

void eCliente_alta(eCliente array[], int tam){
	int index;
	eLocalidad localidad;
	index = eCliente_buscarLibre(array, tam);

	if(index>=0){

		array[index].idEmpresa = eCliente_obtenerId();
		getString(array[index].empresa, "Ingrese nombre de la empresa: ", TEXT_SIZE);
		getString(array[index].cuit, "Ingrese Numero de CUIT: ", TEXT_SIZE);
		getString(array[index].direccion, "Ingrese dirección de la empresa: ", TEXT_SIZE);

		getString(array[index].localidad.localidad, "Ingrese localidad de la empresa: ", TEXT_SIZE);

		array[index].isEmpty=0;


		printf("\nEl cliente fue dado de alta de forma exitosa con el numero %d\n", array[index].idEmpresa);

    }
	else{
		printf("\nNo hay mas espacio para almacenar clientes.\n");
	}

}



int eCliente_buscarLibre(eCliente array[], int tam){
	int i;
	int index;
	index =-1;

	for(i=0; i<tam; i++){
		if(array[i].isEmpty==1){
			index = i;
			break;
		}
	}
	return index;
}

void eCliente_inicializarArray(eCliente array[], int tam){
	int i;
	for(i=0; i<tam; i++){
		array[i].isEmpty=1;
	}
}



int eCliente_obtenerId(){
	return idIncremental += 1;
}



void eCliente_modificarCliente(eCliente array[], int tam){
	int idMod;
	int index;
	eLocalidad localidad;

	idMod=getInt("Ingrese Numero de cliente a modificar: ");
	index = eCliente_buscarId(array, tam, idMod);

	while(index==-1){
		printf("No se encontro el ID. \n");
		idMod=getInt("Ingrese Numero de cliente a modificar: ");
		index = eCliente_buscarId(array, tam, idMod);
	}


	index = eCliente_buscarId(array, tam, idMod);


	getString(array[index].direccion, "MODIFICACION: Ingrese dirección de la empresa: ", TEXT_SIZE);
	getString(array[index].localidad.localidad, "MODIFICACION: Ingrese localidad de la empresa: ", TEXT_SIZE);


}

int eCliente_buscarId(eCliente array[], int tam, int id){
	int i;
	int retorno;

	for(i=0; i<tam; i++){
		if(array[i].idEmpresa==id){
			retorno=i;
			break;
		}
		else{
			retorno=-1;
		}
	}
	return retorno;
}


int eCliente_mostrarLista(eCliente array[], int tam){
	int i;
	int retorno=0;


		printf("ID        EMPRESA             DIRECCION                LOCALIDAD\n");

		for(i=0;i<tam;i++){
			if(array[i].isEmpty==0){
				printf("%-8d %-15s %-30s %-30s\n", array[i].idEmpresa, array[i].empresa, array[i].direccion, array[i].localidad.localidad );
				retorno=1;
			}
		}


	return retorno;
}

int eCliente_baja(eCliente array[], int tam){
	int flag=0;
	int retorno=0;
	int idMod;
	int index;
	char rta;





	if(eCliente_mostrarLista(array, tam)==1){
		flag = 1;
	}
	if(flag==1){


		idMod=getInt("Ingrese Numero de cliente a dar de baja: ");
		index = eCliente_buscarId(array, tam, idMod);

		while(index==-1){
			printf("No se encontro el ID. \n");
			idMod=getInt("Ingrese Numero de cliente a dar de baja: ");
			index = eCliente_buscarId(array, tam, idMod);
		}

		rta = pedirCaracter("Desea efectuar la baja? s/n: ");
//
		while(rta != 's' && rta != 'n'){
			rta = pedirCaracter("ERROR. Desea efectuar la baja? s/n: ");
		}

		if(rta == 's'){
			array[index].isEmpty=1;
			retorno = 1;
			printf("\nLa baja fue exitosa\n");
		}
		else{
			printf("\nLa baja no fue efectuada.\n");
		}
	}

	return retorno;

}




