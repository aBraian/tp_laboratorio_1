#include <stdio.h>
#include <stdlib.h>

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos){
	int bufferInt;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
	  do{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
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
