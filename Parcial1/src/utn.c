#include "utn.h"


int getString(char string[], char mensaje[], int tam){
	char auxString[1000];
	int ret;
	ret = 0;
	if (string != NULL && mensaje != NULL)
	{
		ret = 1;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxString);
		while (strlen(auxString) > tam)
		{
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxString);
		}
		strcpy(string, auxString);
	}
	return ret;
}

int getInt(char mensaje[]){
    int numeroIngresado;
    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);
    return numeroIngresado;
}


float getFloat(char mensaje[]){
    float numeroIngresado;
    printf("%s", mensaje);
    scanf("%f", &numeroIngresado);
    return numeroIngresado;
}

char pedirCaracter(char mensaje[]){
    char caracterIngresado;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracterIngresado);
    return caracterIngresado;
}


