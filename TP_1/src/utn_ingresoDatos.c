//Funciones de mi biblioteca

#include <stdio.h>
#include <stdlib.h>

int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos){
	float bufferFloat;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
    do{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

