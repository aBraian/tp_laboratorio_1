#include <stdio.h>
#include <stdlib.h>

int utn_Descuento(float * pDescuento, float precio, int descuento){
	int retorno;
	float bufferDescuento;
	retorno = -1;
	if(pDescuento != NULL){
		bufferDescuento = precio - precio * descuento / 100;
		*pDescuento = bufferDescuento;
		retorno = 0;
	}
	return retorno;
}

int utn_Interes(float * pInteres, float precio, int interes){
	int retorno;
	float bufferInteres;
	retorno = -1;
	if(pInteres != NULL){
		bufferInteres = precio + precio * interes / 100;
		*pInteres = bufferInteres;
		retorno = 0;
	}
	return retorno;
}

int utn_Division(float * pResultado, float dividendo, int divisor){
	int retorno;
	float bufferDivision;
	retorno = -1;
	if(pResultado != NULL){
		if(divisor != 0){
			bufferDivision = dividendo / divisor;
			*pResultado = bufferDivision;
			retorno = 0;
		}
	}
	return retorno;
}

int utn_DiferenciaDePrecios(float * pResultado, float numero1, float numero2){
	int retorno;
	float bufferResta;
	retorno = -1;
	if(pResultado != NULL){
		if(numero1 >= numero2){
			bufferResta = numero1 - numero2;
			*pResultado = bufferResta;
		}
		else if(numero1 < numero2){
			bufferResta = numero2 - numero1;
			*pResultado = bufferResta;
		}
	retorno = 0;
	}
	return retorno;
}
